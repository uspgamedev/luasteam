SRC=src/*.cpp src/auto/*.cpp

# -Wno-invalid-offsetof prevents STEAM_CALLBACK from giving out warnings
CPP_FLAGS=-Wno-invalid-offsetof -Wall $(STDLIB_VER)

THIRD_PARTY=./third-party
LUAJIT_PATH=./luajit
STEAM_LIB=sdk/redistributable_bin
SPHINXBUILD=sphinx-build
MWE_DIR=examples/basic
LUAJIT=$(abspath $(LUAJIT_PATH)/src/luajit)

-include .env

GNU_OUT=luasteam.so
IPATHS=-I$(LUAJIT_PATH)/src -Isdk/public
GNU_FLAGS=$(IPATHS)

OSX_OUT=luasteam.so
# Compile for 10.11 (El Capitan, 2015) and up. At the time of writing, 10.11 is the
# minimum version libluajit-5.1.a is compiled for; targeting earlier versions will
# raise compiler warnings.
OSX_MIN_VERSION=10.11
OSX_FLAGS=$(IPATHS) -mmacosx-version-min=$(OSX_MIN_VERSION)


.PHONY: all osx linux32 linux64 win32 win64 clean docs check-luals fmt

all:
	@echo "choose platform: linux64 | linux32 | win32 | win64 | osx"

clean:
	cd $(LUAJIT_PATH) && $(MAKE) clean
	rm -f luasteam.so luasteam.dll

luajit-osx:
	# Build x86_64
	cd $(LUAJIT_PATH) && MACOSX_DEPLOYMENT_TARGET=$(OSX_MIN_VERSION) $(MAKE) clean
	cd $(LUAJIT_PATH) && MACOSX_DEPLOYMENT_TARGET=$(OSX_MIN_VERSION) $(MAKE) -j CC="clang" TARGET_FLAGS="-arch x86_64"
	mv $(LUAJIT_PATH)/src/libluajit.a $(LUAJIT_PATH)/src/libluajit_x86_64.a
	mv $(LUAJIT_PATH)/src/luajit $(LUAJIT_PATH)/src/luajit_x86_64
	# Build arm64
	cd $(LUAJIT_PATH) && MACOSX_DEPLOYMENT_TARGET=$(OSX_MIN_VERSION) $(MAKE) clean
	cd $(LUAJIT_PATH) && MACOSX_DEPLOYMENT_TARGET=$(OSX_MIN_VERSION) $(MAKE) -j CC="clang" TARGET_FLAGS="-arch arm64"
	mv $(LUAJIT_PATH)/src/libluajit.a $(LUAJIT_PATH)/src/libluajit_arm64.a
	mv $(LUAJIT_PATH)/src/luajit $(LUAJIT_PATH)/src/luajit_arm64
	# Create Universal Binaries
	lipo -create -output $(LUAJIT_PATH)/src/libluajit.a $(LUAJIT_PATH)/src/libluajit_x86_64.a $(LUAJIT_PATH)/src/libluajit_arm64.a
	lipo -create -output $(LUAJIT_PATH)/src/luajit $(LUAJIT_PATH)/src/luajit_x86_64 $(LUAJIT_PATH)/src/luajit_arm64

osx: luajit-osx
	$(CXX) $(SRC) $(CPP_FLAGS) -arch arm64 ${STEAM_LIB}/osx/libsteam_api.dylib -undefined dynamic_lookup -o $(OSX_OUT).arm64 -shared -fPIC $(OSX_FLAGS)
	$(CXX) $(SRC) $(CPP_FLAGS) -arch x86_64 ${STEAM_LIB}/osx/libsteam_api.dylib -undefined dynamic_lookup -o $(OSX_OUT).x86_64 -shared -fPIC $(OSX_FLAGS)
	lipo -create -output $(OSX_OUT) $(OSX_OUT).arm64 $(OSX_OUT).x86_64
	codesign -s - $(OSX_OUT)
	# Test
	lipo -archs $(OSX_OUT) | grep -F "x86_64 arm64"
	cp $(OSX_OUT) $(MWE_DIR) && cp ${STEAM_LIB}/osx/libsteam_api.dylib $(MWE_DIR) && cd $(MWE_DIR) && DYLD_LIBRARY_PATH=. $(LUAJIT) main.lua


luajit-64:
	cd $(LUAJIT_PATH) && $(MAKE) -j

luajit-32:
	cd $(LUAJIT_PATH) && $(MAKE) -j CC="gcc -m32"
	
WINPREF32=i686-w64-mingw32-

# The TARGET=strip is needed because otherwise it tries to use WINPREF32-strip
# which doesn't exist. It's not actually the 32-bit one but I thin things work.
luajit-32-win:
	cd $(LUAJIT_PATH) && $(MAKE) -j HOST_CC=$(WINPREF32)gcc CROSS=$(WINPREF32) TARGET_STRIP=strip

linux64: luajit-64
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux64/libsteam_api.so -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)
	cp luasteam.so $(MWE_DIR) && cp $(LUAJIT_PATH)/src/libluajit.so $(MWE_DIR)/libluajit-5.1.so.2 && cp ${STEAM_LIB}/linux64/libsteam_api.so $(MWE_DIR) && cd $(MWE_DIR) && ls && LD_LIBRARY_PATH=. $(LUAJIT) main.lua


linux32: luajit-32
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux32/libsteam_api.so -m32 -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)
	cp luasteam.so $(MWE_DIR) && cp $(LUAJIT_PATH)/src/libluajit.so $(MWE_DIR)/libluajit-5.1.so.2 && cp ${STEAM_LIB}/linux32/libsteam_api.so $(MWE_DIR) && cd $(MWE_DIR) && ls && LD_LIBRARY_PATH=. $(LUAJIT) main.lua


WINDOWS_LUAJIT_LIB=$(LUAJIT_PATH)/src/lua51.dll
WINDOWS_STEAM_LIB=$(STEAM_LIB)/win64/steam_api64.lib
WINDOWS_OUT=luasteam.dll
WINDOWS_FLAGS=-static

win64: luajit-64
	g++ $(SRC) $(CPP_FLAGS) $(IPATHS) $(WINDOWS_LUAJIT_LIB) $(WINDOWS_STEAM_LIB) $(WINDOWS_FLAGS) -shared -o $(WINDOWS_OUT)
	cp luasteam.dll $(MWE_DIR) && cp $(STEAM_LIB)/win64/steam_api64.dll $(MWE_DIR) && cd $(MWE_DIR) && $(LUAJIT) main.lua


win32: luajit-32-win
	i686-w64-mingw32-g++ $(SRC) $(CPP_FLAGS) -m32 $(IPATHS) $(WINDOWS_LUAJIT_LIB) $(STEAM_LIB)/steam_api.lib $(WINDOWS_FLAGS) -shared -o $(WINDOWS_OUT)
	cp luasteam.dll $(MWE_DIR) && cp $(STEAM_LIB)/steam_api.dll $(MWE_DIR) && cd $(MWE_DIR) && $(LUAJIT) main.lua

generate:
	cd generator && cargo run

docs:
	python -m sphinx docs docs/_build/html

check-luals:
	$(LUA_LANGUAGE_SERVER) --check=luals --configpath=luals/.luarc.json --check_format=pretty --checklevel=Warning

fmt:
	cd generator && cargo fmt
	$(CLANG_FORMAT) -i src/*.cpp src/*.hpp
