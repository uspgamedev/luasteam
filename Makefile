SRC=luasteam.cxx
STDLIB_VER=-std=c++11

OSX_OUT=luasteam.so
OSX_IPATHS=-I/usr/local/include/luajit-2.0
OSX_FLAGS=$(OSX_IPATHS) $(STDLIB_VER)

GNU_OUT=luasteam.so
GNU_IPATHS=-I/usr/include/luajit-2.0
GNU_FLAGS=$(GNU_IPATHS) $(STDLIB_VER)

WINDOWS_LIBS=lua51.lib steam_api.lib
WINDOWS_IPATHS=-I.\luajit

.PHONY: all osx linux windows32 windows64

all:
	@echo "choose platform: linux | windows32 | windows64 | osx"

osx:
	$(CXX) $(SRC) -o $(OSX_OUT) -shared -fPIC $(OSX_FLAGS)

linux:
	$(CXX) $(SRC) -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

windows32:
	$(CXX) $(SRC) lua51.lib steam_api.lib $(WINDOWS_IPATHS) /LD /EHsc

windows64:
	$(CXX) $(SRC) lua51.lib steam_api64.lib $(WINDOWS_IPATHS) /LD /EHsc
