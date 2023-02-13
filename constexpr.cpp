//constexpr =>
// 1) compile time entity
// 2) fast execution
#include<iostream>

// 1) compile time entity
//Looks like constexpr needs to be defined outside the class only and that's looks but obvious
constexpr int A1() { return 3; } //Error IF this constexpr is deleted
class Demo {
public:
    int A() { return 3;}
    int B() { 
         int arr[A() + 10]; //ERROR => 'this' cannot be used in a constant expression
    }
    //constexpr int A1() { return 3; } //ERROR - constexpr should not be defined in the class. I got error
    void C() { 
         int arr[A1() + 10]; //Works when A1() constexpr is defined outside the class. 

    }   
};

// 2) fast execution
constexpr int A(int x) { return x^3; }
int main() {
    int res = A(10); // computation will happen at compile time
}

