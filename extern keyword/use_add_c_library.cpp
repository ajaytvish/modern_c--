#include <iostream>
extern "C" {
#include "add.h"
}
void function(int i) {}
void function(float f) {}
int main() {
    std::cout << add();
    //std::cout << add(10.7f,20);
}

// VVVVVImp Stuff
// ultimate cppnuts video  @01:04:00  https://www.youtube.com/watch?v=bFtkHJy9kIU	70 interview questions

//How to compile the source code
// PS D:\code\modern_c++\extern keyword> gcc -c add.c
// PS D:\code\modern_c++\extern keyword> g++ -c .\use_add_c_library.cpp 
// PS D:\code\modern_c++\extern keyword> g++ add.o .\use_add_c_library.o
// PS D:\code\modern_c++\extern keyword> .\a.exe

// How to see .o file details and check the names of the functions whether mangled or not
// PS D:\code\modern_c++\extern keyword> nm .\use_add_c_library.o  
// 0000000000000000 b .bss
// 0000000000000000 d .ctors
// 0000000000000000 d .data
// 0000000000000000 p .pdata
// 0000000000000000 r .rdata$.refptr._ZSt4cout
// 0000000000000000 r .rdata$zzz
// 0000000000000000 R .refptr._ZSt4cout
// 0000000000000000 t .text
// 0000000000000000 r .xdata
//                  U __main
// 0000000000000044 t __tcf_0
// 00000000000000a4 t _GLOBAL__sub_I__Z8functioni
// 0000000000000062 t _Z41__static_initialization_and_destruction_0ii
// 000000000000000a T _Z8functionf  <==============
// 0000000000000000 T _Z8functioni  <==============
//                  U _ZNSolsEi
//                  U _ZNSt8ios_base4InitC1Ev
//                  U _ZNSt8ios_base4InitD1Ev
//                  U _ZSt4cout
// 0000000000000000 b _ZStL8__ioinit
//                  U add   <==============
//                  U atexit
// 0000000000000016 T main  <==============
