
//Decltype - checks the type of expression
#include <iostream>
using namespace std;

template<typename T1, typename T2>
//decltype checks the final value of the expression and returns val of that type
//& auto is type deduction/type substitutiondd76769 mechanism
auto add (T1 x, T2 y) -> decltype( x+y ) //Its called TRAILING RETURN TYPE Syntax
{ 
    return x+y; 
}
int main()
{
    // int i=20; float f=10.7;
    // auto c = i+f;
    // cout<<c;  //output - 30.7

    int i=20; float f = 10.7;
    cout<< add(10.7, 10) <<endl;
    cout<< add(10, 10.7) <<endl;
}