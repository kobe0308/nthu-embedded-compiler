LLVM_CONFIG=llvm-config

#CXX=g++
CXX=`$(LLVM_CONFIG) --bindir`/clang
CXXFLAGS=`$(LLVM_CONFIG) --cppflags` -std=gnu++11 -fPIC -fno-rtti -g
LDFLAGS=`$(LLVM_CONFIG) --ldflags`

all: LLVMKYPass.so

LLVMKYPass.so: KYPass.o
	$(CXX) -shared KYPass.o -o KYPass.so  -fPIC

KYPass.o: KYPass.cpp
	$(CXX) -c KYPass.cpp -o KYPass.o $(CXXFLAGS)

clean:
	rm -f *.o *.so
