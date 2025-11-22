SRC=src/*.cpp
STDLIB_VER=-std=c++11

# -Wno-invalid-offsetof prevents STEAM_CALLBACK from giving out warnings
CPP_FLAGS=-Wno-invalid-offsetof -Wall

THIRD_PARTY=./third-party

OSX_OUT=luasteam.so
OSX_IPATHS=-I$(THIRD_PARTY)/include/
# Compile for 10.11 (El Capitan, 2015) and up. At the time of writing, 10.11 is the
# minimum version libluajit-5.1.a is compiled for; targeting earlier versions will
# raise compiler warnings.
OSX_MIN_VERSION=-mmacosx-version-min=10.11
OSX_FLAGS=$(OSX_IPATHS) $(STDLIB_VER) $(OSX_MIN_VERSION)

GNU_OUT=luasteam.so
# You might need to change this to luajit-2.1 depending on your install. Don't commit it.
GNU_IPATHS=-I/usr/include/luajit-2.0
GNU_FLAGS=$(GNU_IPATHS) $(STDLIB_VER) -lluajit-5.1

.PHONY: all osx linux32 linux64 windows32 windows64

all:
	@echo "choose platform: linux64 | linux32 | windows32 | windows64 | osx"

STEAM_LIB=sdk/redistributable_bin

osx:
	$(CXX) $(SRC) $(CPP_FLAGS) -arch arm64 ${STEAM_LIB}/osx/libsteam_api.dylib ${THIRD_PARTY}/lib/libluajit-5.1.a -o $(OSX_OUT).arm64 -shared -fPIC $(OSX_FLAGS)
	$(CXX) $(SRC) $(CPP_FLAGS) -arch x86_64 ${STEAM_LIB}/osx/libsteam_api.dylib ${THIRD_PARTY}/lib/libluajit-5.1.a -o $(OSX_OUT).x86_64 -shared -fPIC $(OSX_FLAGS)
	lipo -create -output $(OSX_OUT) $(OSX_OUT).arm64 $(OSX_OUT).x86_64

linux32:
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux32/libsteam_api.so -m32 -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

linux64:
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux64/libsteam_api.so -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

ifeq ($(OS),Windows_NT)
# Windows stuff
SHELL=cmd
WINDOWS_IPATHS=-I./cache/include
WINDOWS_OPT=-LD -EHsc -Feluasteam
VARSALL="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat"

cache:
	@echo "Downloading LuaJIT source"
	mkdir cache\include
	git clone --branch v2.0.5 https://github.com/LuaJIT/LuaJIT.git LuaJIT-2.0.5
	cp LuaJIT-2.0.5/src/*.h cache/include

cache/win32_lua51.lib:
	@echo "Compiling LuaJIT 32 bits"
	if not exist cache $(MAKE) cache
	cd LuaJIT-2.0.5/src && call $(VARSALL) x86 && call msvcbuild.bat
	cp LuaJIT-2.0.5/src/lua51.lib cache/win32_lua51.lib

cache/win64_lua51.lib:
	@echo "Compiling LuaJIT 64 bits"
	if not exist cache $(MAKE) cache
	cd LuaJIT-2.0.5/src && call $(VARSALL) x64 && call msvcbuild.bat
	cp LuaJIT-2.0.5/src/lua51.lib cache/win64_lua51.lib

windows32:
	if not exist cache\win32_lua51.lib $(MAKE) cache/win32_lua51.lib
	call $(VARSALL) x86 && cl $(SRC) cache/win32_lua51.lib ${STEAM_LIB}/steam_api.lib $(WINDOWS_OPT) $(WINDOWS_IPATHS)

windows64:
	if not exist cache\win64_lua51.lib $(MAKE) cache/win64_lua51.lib
	call $(VARSALL) x64 && cl $(SRC) cache/win64_lua51.lib ${STEAM_LIB}/win64/steam_api64.lib $(WINDOWS_OPT) $(WINDOWS_IPATHS)
endif
