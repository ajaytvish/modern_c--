//can be used to change CONST & VOLATILE qualifier of a POINTER OR a REFERENCE.....  
#include<iostream>

//Never use this
//Use only when necessary & when the var is non-const
//Use in case of thirdPartyLibrary

// OUTPUT is CONTROVERTIAL because if const int a is changed using const_cast into c and it compiles
// then too output is undefined.

void thirdPartyLibraryFn(int *b) 
{

}
int main() 
{
 // Situation 1
 //suppose u have a library and its fn takes int* param but you have const int var then const_cast is used
 const int a = 10;
 //libraryFn(&a); //argument of type "const int *" is incompatible with parameter of type "int *"
 thirdPartyLibraryFn(const_cast<int*>(&a)); //THIS WORKS FINE *****

 // Situation 2   
 const int a = 10;  //Original address is const so it will not change later even with const_cast
 std::cout<<"a = "<<a<<std::endl;
 std::cout<<"&a = "<<&a<<std::endl;
 //int b = const_cast<int>(a);//Error. const_cast works with pointers or references only NOT normal variables   
            //the type in a const_cast must be a pointer, reference, or pointer to member to an object type
 const int *b = &a;
 std::cout<<"b = " << b << std::endl;
 std::cout<<"*b = " << *b << std::endl;

 int *c1 = const_cast<int *>(&a);
 std::cout<<"c1 = " << c1 << std::endl;
 std::cout<<"*c1 = " << *c1 << std::endl;
 *c1 = 55;
std::cout<<"c1 = " << c1 << std::endl;
 std::cout<<"*c1 = " << *c1 << std::endl;
 std::cout<<"&a = " << &a<<std::endl;
 std::cout<<"a = " << a<<std::endl;
 // OUTPUT - note: a does not change because it is declared as const int
// a = 10
// &a = 0x3a483ff894
// b = 0x3a483ff894
// *b = 10
// c1 = 0x3a483ff894
// *c1 = 10
// c1 = 0x3a483ff894
// *c1 = 55
// &a = 0x3a483ff894
// a = 10




//  int *b1 = const_cast<int *>(&a);
//  std::cout<<"b1 = " << b1 << std::endl;
//  std::cout<<"*b1 = " << *b1 << std::endl;
//  *b1=77;
//  std::cout<<"*b1 = " << *b1 << std::endl;
//  std::cout<<"b1 = " << b1 << std::endl;
//  std::cout<<"a = " << a<<std::endl<<std::endl;

 
//  int *c = const_cast<int *>(&a);  
//  *c = 20; //Here const is removed using const_cast & reference

//  std::cout<<"c = " << c<<std::endl;
//  std::cout<<"*a = " << a<<std::endl;
//  std::cout<<"*c = " << *c<<std::endl;
// Output  ---  unexpected & undefined behaviour 
// 0x2d98dffb24
// 0x2d98dffb18
// 10
// 20

//==============================
//int *x = 100; //Error
//int *x {100}; //Error
int *x;
*x = 100; 

}
