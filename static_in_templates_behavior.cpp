// How static behaves in templates
// 1) in function
// 2) in class

// 1) in function
#include<iostream>
using namespace std;
template<typename T>
void fun(T x) {
    static T i = 10;
    cout<<++i<<" ";
}
int main() {
    fun(1); fun(2); fun(3);//int 
    fun('a'); fun('b');    //char
    fun(10.5f); fun(10.5f); //float
}
// O/P
// 11 12 13 ♂ ♀ 11 12 
// 11 12 13 output shows that for same type "int" static var will be global to all the int type param calls 
// & last 11 12 shows that since float/double datatype is used static var will is global to all the float type param calls

//2) in class
template<typename T>
class Test
{
    static T s;
public:
    Test(int i):s(i) {}
};

template<typename T>


int main() {
    Test<int> st(10);

    return 0;
}




