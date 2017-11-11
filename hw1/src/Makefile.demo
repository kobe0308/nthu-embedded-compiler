LLVM_CONFIG=llvm-config

#CXX=g++
CXX=`$(LLVM_CONFIG) --bindir`/clang
CXXFLAGS=`$(LLVM_CONFIG) --cppflags` -std=gnu++11 -fPIC -fno-rtti -g
LDFLAGS=`$(LLVM_CONFIG) --ldflags`

all: LLVMDemo.so

LLVMDemo.so: Demo.o
	$(CXX) -shared Demo.o -o LLVMDemo.so  -fPIC

Demo.o: Demo.cpp
	$(CXX) -c Demo.cpp -o Demo.o $(CXXFLAGS)

clean:
	rm -f *.o *.so
