// There are 2 ways we can call a function before main

#include<iostream>
using namespace std;
// 1) calling fn from constructor which is called by creating global object
// 2)  

//========  1) calling fn from constructor which is called by creating global object
// void fun() { cout<<"inside fun() \n"; }
// class Base {
//     public:
//         Base() { fun(); }
// };
// Base b;
// int main() {
//     cout<<"inside main() \n";
// }

//======== 2) create a static mem var and as we have to initialize it outside class 
//so initialize it by calling a function
int fun(){ cout<<"inside fun() \n"; return 1;}
class Base {
    static int s;
};

int Base::s=fun();

int main(){
    cout<<"inside main() \n";
    return 0;
}