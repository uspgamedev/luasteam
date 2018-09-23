SRC=luasteam.cxx
STDLIB_VER=-std=c++11

OSX_OUT=luasteam.so
OSX_IPATHS=-I/usr/local/include/luajit-2.0
OSX_FLAGS=$(OSX_IPATHS) $(STDLIB_VER) -lluajit-5.1

GNU_OUT=luasteam.so
GNU_IPATHS=-I/usr/include/luajit-2.0
GNU_FLAGS=$(GNU_IPATHS) $(STDLIB_VER) -lluajit-5.1

WINDOWS_LIBS=lua51.lib steam_api.lib
WINDOWS_IPATHS=-I.\luajit

.PHONY: all osx linux32 linux64 windows32 windows64

all:
	@echo "choose platform: linux64 | linux32 | windows32 | windows64 | osx"

osx:
	$(CXX) $(SRC) libsteam_api.dylib -o $(OSX_OUT) -shared -fPIC $(OSX_FLAGS)

linux32:
	$(CXX) $(SRC) libsteam_api.so -m32 -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

linux64:
	$(CXX) $(SRC) libsteam_api.so -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

windows32:
	$(CXX) $(SRC) lua51.lib steam_api.lib $(WINDOWS_IPATHS) /LD /EHsc

windows64:
	$(CXX) $(SRC) lua51.lib steam_api64.lib $(WINDOWS_IPATHS) /LD /EHsc
