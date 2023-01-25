#include<iostream>
#include <variant>
using namespace std;
class C {
public:
    void fun() {
    }
    void f1(C &o) const {
        o.fun(); //const functions can call non-const functions
    }
    void f(const C &o1) {
        o1.fun(); //the object has type qualifiers that are not compatible with the member function "C::fun"C/C++(1086)
                  //(15, 9): object type is: const C
        C c2;
        o1.f1(c2);
    }
};
int main() {
    C c, c1; 
    c.f(c1);
}