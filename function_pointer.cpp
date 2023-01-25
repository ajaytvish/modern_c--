#include<iostream>

int add(int a, int b) { return a+b; }
int show( int (*calculate)(int, int))   //?? why can't i sepecify int x, int y as param and then 
                                        //call calculate(x,y). Why does it show error
{ 
    return calculate(2,3); //calculate(x,y); //Error: x & y undefined
}
int main() {
    //new way
    int (*fun)(int, int) = add;  // assinging add will resolve the exact function to call or nothing will happen
    std::cout << fun(1,2) << std::endl;

    //traditional way
    int (*fun1)(int, int) = &add;
    std::cout << (*fun1)(2,3) << std::endl;

    //Pass function pointer as an argument
    //show(fun(3,3)); //assinging add will resolve the exact function to call or nothing will happen
                    //argument of type "int" is incompatible with parameter of type "int (*)(int x, int y)"
    // show(add(3,3)); This is not working. ToDo: how to pass parameters from client app itself
    std::cout << show(add) << std::endl ;
}