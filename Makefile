
SRC=luasteam.cxx
STDLIB_VER=-std=c++11

OSX_OUT=steam.so
OSX_IPATHS=-I/usr/local/include/luajit-2.0
OSX_LPATHS=-L./lib/osx32 -lsteam_api -L/usr/local/lib -lluajit-5.1
OSX_FLAGS=$(OSX_IPATHS) $(OSX_LPATHS) $(STDLIB_VER)

GNU_OUT=steam.so
GNU_IPATHS=-I/usr/include/luajit-2.0
GNU_LPATHS=-L./lib/linux64 -lsteam_api -L/usr/lib/x86_64-linux-gnu -lluajit-5.1
GNU_FLAGS=$(OSX_IPATHS) $(GNU_LPATHS) $(STDLIB_VER)


.PHONY: all osx gnu

all:
	@echo "choose platform: osx | linux"

osx:
	$(CXX) $(SRC) -o $(OSX_OUT) -shared -fPIC $(OSX_FLAGS)

gnu:
	$(CXX) $(SRC) -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

