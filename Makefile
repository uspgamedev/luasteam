SRC=luasteam.cxx
STDLIB_VER=-std=c++11

OSX_OUT=steam.so
OSX_IPATHS=-I/usr/local/include/luajit-2.0
OSX_FLAGS=$(OSX_IPATHS) $(STDLIB_VER)

GNU_OUT=steam.so
GNU_IPATHS=-I/usr/include/luajit-2.0
GNU_FLAGS=$(GNU_IPATHS) $(STDLIB_VER)


.PHONY: all osx gnu

all:
	@echo "choose platform: osx | linux"

osx:
	$(CXX) $(SRC) -o $(OSX_OUT) -shared -fPIC $(OSX_FLAGS)

linux:
	$(CXX) $(SRC) -o $(GNU_OUT) -shared -fPIC $(GNU_FLAGS)

