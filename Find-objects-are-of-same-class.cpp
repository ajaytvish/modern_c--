#include<typeinfo>
#include<iostream>
using namespace std;
class Base {
};
class Base1 {
};
int main() {
    Base b1, b2;
    Base1 b11, b12;
    if(typeid(b1) == typeid(b2))
        cout<<"same";               //O/P same
    else
        cout<<"different";

    if(typeid(b1) == typeid(b12))
        cout<<"same";
    else
        cout<<"different";          //O/P different
}