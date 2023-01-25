//functor is object acting as function. It is resulted by overloading operator()
//Benefit is that it helps to save the state of the object without using static variable
//Normal functions do not save state
#include<iostream>
class Mul {
    int x;
public:  
    Mul(int val):x(val) {}
    int operator()(int a) {   return x*a;  }
};
int main()
{
    Mul mul(5);
    std::cout<<mul(10);
}