
#include<iostream>
struct Base {
    int b;
    // Base(int x):b(x) {} ////Implicit call to Base(int x) happens from the line  =>  Base b1 = 20;
    //To avoid implicit call, specify the constructor as explicit 
    explicit Base(int x):b(x) {} ////Implicit call to Base(int x) happens from the line  =>  Base b1 = 20;
};
int main() {
    Base b1 = 20; //Implicit call to Base(int x) happens.. line 5
    // Because explicit is specified for constructor so implicit call will not happen hence the error
    std::cout<<b1.b;
}