SRC=src/*.cpp
STDLIB_VER=-std=c++11

# -Wno-invalid-offsetof prevents STEAM_CALLBACK from giving out warnings
CPP_FLAGS=-Wno-invalid-offsetof -Wall

THIRD_PARTY=./third-party
LUAJIT_PATH=./luajit
STEAM_LIB=sdk/redistributable_bin

OSX_OUT=luasteam.so
OSX_IPATHS=-I$(THIRD_PARTY)/include/
# Compile for 10.11 (El Capitan, 2015) and up. At the time of writing, 10.11 is the
# minimum version libluajit-5.1.a is compiled for; targeting earlier versions will
# raise compiler warnings.
OSX_MIN_VERSION=-mmacosx-version-min=10.11
OSX_FLAGS=$(OSX_IPATHS) $(STDLIB_VER) $(OSX_MIN_VERSION)

GNU_OUT=luasteam.so
# You might need to change this to luajit-2.1 depending on your install. Don't commit it.
IPATHS=-I$(LUAJIT_PATH)/src
GNU_FLAGS=$(IPATHS) $(STDLIB_VER)


.PHONY: all osx linux32 linux64 win32 win64 clean linux32-build linux64-build win32-build win64-build osx-build

clean:
	cd $(LUAJIT_PATH) && $(MAKE) clean
	rm -f luasteam.so luasteam.dll

all:
	@echo "choose platform: linux64 | linux32 | win32 | win64 | osx"


osx:
	$(CXX) $(SRC) $(CPP_FLAGS) -arch arm64 ${STEAM_LIB}/osx/libsteam_api.dylib ${THIRD_PARTY}/lib/libluajit-5.1.a -o $(OSX_OUT).arm64 -shared -fPIC $(OSX_FLAGS)
	$(CXX) $(SRC) $(CPP_FLAGS) -arch x86_64 ${STEAM_LIB}/osx/libsteam_api.dylib ${THIRD_PARTY}/lib/libluajit-5.1.a -o $(OSX_OUT).x86_64 -shared -fPIC $(OSX_FLAGS)
	lipo -create -output $(OSX_OUT) $(OSX_OUT).arm64 $(OSX_OUT).x86_64


luajit-64:
	cd $(LUAJIT_PATH) && $(MAKE) -j

luajit-32:
	cd $(LUAJIT_PATH) && $(MAKE) -j HOST_CC='gcc -m32'


linux64: luajit-64
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux64/libsteam_api.so -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS) ./luajit/src/libluajit.so
	cp luasteam.so mwe && cp ${STEAM_LIB}/linux64/libsteam_api.so mwe && cd mwe && ls && LD_LIBRARY_PATH=.:../luajit/src ../luajit/src/luajit main-nolove.lua

linux32: luajit-32
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux32/libsteam_api.so -m32 -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS) ./luajit/src/libluajit.so
	cp luasteam.so mwe && cp ${STEAM_LIB}/linux32/libsteam_api.so mwe && cd mwe && ls && LD_LIBRARY_PATH=.:../luajit/src/ ../luajit/src/luajit main-nolove.lua

WINDOWS_LUAJIT_LIB=$(LUAJIT_PATH)/src/lua51.dll
WINDOWS_STEAM_LIB=$(STEAM_LIB)/win64/steam_api64.lib
WINDOWS_OUT=luasteam.dll

win64: luajit-64
	g++ $(SRC) $(CPP_FLAGS) $(IPATHS) $(WINDOWS_LUAJIT_LIB) $(WINDOWS_STEAM_LIB) -shared -o $(WINDOWS_OUT)
	cp luasteam.dll mwe && cp $(STEAM_LIB)/steam_api.dll mwe && cd mwe && ../luajit/src/luajit.exe main-nolove.lua

win32: luajit-32
	i686-w64-mingw32-g++ $(SRC) $(CPP_FLAGS) -m32 $(PATHS) $(WINDOWS_LUAJIT_LIB) $(STEAM_LIB)/steam_api.lib -shared -o $(WINDOWS_OUT)
	cp luasteam.dll mwe && cp ${STEAM_LIB}/steam_api.lib mwe && cd mwe && ../luajit/src/luajit.exe main-nolove.lua


# Build-only targets (without running tests) for CI
linux64-build: luajit-64
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux64/libsteam_api.so -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS) ./luajit/src/libluajit.so

linux32-build: luajit-32
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux32/libsteam_api.so -m32 -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS) ./luajit/src/libluajit.so

win64-build: luajit-64
	g++ $(SRC) $(CPP_FLAGS) $(IPATHS) $(WINDOWS_LUAJIT_LIB) $(WINDOWS_STEAM_LIB) -shared -o $(WINDOWS_OUT)

win32-build: luajit-32
	i686-w64-mingw32-g++ $(SRC) $(CPP_FLAGS) -m32 $(PATHS) $(WINDOWS_LUAJIT_LIB) $(STEAM_LIB)/steam_api.lib -shared -o $(WINDOWS_OUT)

osx-build:
	$(CXX) $(SRC) $(CPP_FLAGS) -arch arm64 ${STEAM_LIB}/osx/libsteam_api.dylib ${THIRD_PARTY}/lib/libluajit-5.1.a -o $(OSX_OUT).arm64 -shared -fPIC $(OSX_FLAGS)
	$(CXX) $(SRC) $(CPP_FLAGS) -arch x86_64 ${STEAM_LIB}/osx/libsteam_api.dylib ${THIRD_PARTY}/lib/libluajit-5.1.a -o $(OSX_OUT).x86_64 -shared -fPIC $(OSX_FLAGS)
	lipo -create -output $(OSX_OUT) $(OSX_OUT).arm64 $(OSX_OUT).x86_64