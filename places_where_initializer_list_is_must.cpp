#include<iostream>
using namespace std;
class Base {
int i;
public:
    Base() { cout<<"Base()\n"; }
    Base(int x):i(x) { cout<<"Base(int x)\n"; }
    Base(Base& b) { i=b.i;  cout<<"Base(Base& b)\n"; }
    Base& operator= (Base& b):i(b.i) {   cout<<"operator=\n"; return *this; } //i=b.i;
    //Base& operator= (Base& b) { i=b.i; cout<<"operator=\n"; return *this; }
};

int main() {
    Base b1(10);
    Base b2 = b1;
    Base b3;
    b3 = b2;
}
