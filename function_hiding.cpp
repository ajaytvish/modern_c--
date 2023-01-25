#include<iostream>


//===================================== Example 3 - correct input

// class Base
// {
// public:
//     void fun() {
//         std::cout<<"Base void"<<std::endl;
//     }
//     void fun(int aa) {
//         std::cout<<"Base int"<<std::endl;
//     }
// };
// class Derived : public Base
// {
// public:
//     using Base::fun; // If this is not used then the Base::fun() & Base::fun(int) both remaims hidden 
//                      // in the Derived class and hence cannot be called directly using Derived object 
//     void fun(char bb) {
//         std::cout<<"Derived char"<<std::endl;
//     }
// };
// int main() {
//     Derived d;
//     d.fun();
//     d.fun(1);
//     d.fun('a');
//     d.Base::fun(5);
// // O/P
// // Base void
// // Base int
// // Derived char
// // Base int
// }

//========================================================================



//============================== Eg 1.   1 incorrect output ===================
// class Base
// {
// public:
//     void fun(int aa) {
//         std::cout<<"Base"<<std::endl;
//     }
// };
// class Derived : public Base
// {
// public:
//     void fun(char bb) {
//         std::cout<<"Derived"<<std::endl;
//     }
// };
// int main() {
//     Derived d;
//     d.fun(1); //Derived
//     d.fun('a'); //Derived
//     d.Base::fun(5); //Base
// // O/P
// // Derived
// // Derived
// // Base
// }


//============================= Example 2  still there's a catch =====================================

class Base
{
public:
    // fun(int aa) is extended to fun(int aa, char c) still it will not be called
    void fun(int aa, char c) {
        std::cout<<"Base"<<std::endl;
    }
};
class Derived : public Base
{
public:
    void fun(char bb) {
        std::cout<<"Derived"<<std::endl;
    }
};
int main() {
    Derived d;
    //d.fun(1, 'a'); //Error: too many arguments in function call. 
            //so derived obj d is not able to resolve the call to the base class fun with 2 parameters
    d.fun(1); //Derived
    d.fun('a'); //Derived
    //d.Base::fun(5); //Base
// O/P
// Derived
// Derived
// so here call to base::fun(int aa, char c) did not happen so it does not depend upon the number of parameters
// it depends upon "using Base::fun" in the Derived class as shown in the example 3
}

