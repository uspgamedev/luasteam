SRC=src/*.cpp
STDLIB_VER=-std=c++11

# -Wno-invalid-offsetof prevents STEAM_CALLBACK from giving out warnings
CPP_FLAGS=-Wno-invalid-offsetof -Wall

OSX_OUT=luasteam.so
OSX_IPATHS=-I/usr/local/include/luajit-2.0
OSX_FLAGS=$(OSX_IPATHS) $(STDLIB_VER) -lluajit-5.1

GNU_OUT=luasteam.so
GNU_IPATHS=-I/usr/include/luajit-2.0
GNU_FLAGS=$(GNU_IPATHS) $(STDLIB_VER) -lluajit-5.1

.PHONY: all osx linux32 linux64 windows32 windows64

all:
	@echo "choose platform: linux64 | linux32 | windows32 | windows64 | osx"

STEAM_LIB=sdk/redistributable_bin

osx:
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/osx32/libsteam_api.dylib -o $(OSX_OUT) -shared -fPIC $(OSX_FLAGS)

linux32:
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux32/libsteam_api.so -m32 -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

linux64:
	$(CXX) $(SRC) $(CPP_FLAGS) ${STEAM_LIB}/linux64/libsteam_api.so -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

ifeq ($(OS),Windows_NT)
# Windows stuff
SHELL=cmd
WINDOWS_IPATHS=-I./cache/include
WINDOWS_OPT=-LD -EHsc -Feluasteam
VARS32="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
VARS64="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

luajit.zip:
	curl -sL -o luajit.zip http://luajit.org/download/LuaJIT-2.0.5.zip

cache: luajit.zip
	unzip -qo luajit.zip
	mkdir -p cache\include
	cp LuaJIT-2.0.5/src/*.h cache/include

cache/win32_lua51.lib: cache
	cd LuaJIT-2.0.5/src && call $(VARS32) && call msvcbuild.bat
	cp LuaJIT-2.0.5/src/lua51.lib cache/win32_lua51.lib

cache/win64_lua51.lib: cache
	cd LuaJIT-2.0.5/src && call $(VARS64) && msvcbuild.bat
	cp LuaJIT-2.0.5/src/lua51.lib cache/win64_lua51.lib

windows32: cache/win32_lua51.lib
	call $(VARS32) && cl $(SRC) cache/win32_lua51.lib ${STEAM_LIB}/steam_api.lib $(WINDOWS_OPT) $(WINDOWS_IPATHS)

windows64: cache/win64_lua51.lib
	call $(VARS64) && cl $(SRC) cache/win64_lua51.lib ${STEAM_LIB}/win64/steam_api64.lib $(WINDOWS_OPT) $(WINDOWS_IPATHS)
endif
