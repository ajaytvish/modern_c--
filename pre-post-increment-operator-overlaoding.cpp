#include<iostream>
using namespace std;
class PrePostIncr {
    int var;
public:
    PrePostIncr(int x):var(x) { }
    void show() { cout<< "val = " << var <<endl;}
    PrePostIncr& operator++() {  //Pre increment. no input dummy parameter
        cout << "PRE incr => ";
        var++;
        return *this;
    }
    //Post increment - in this dummy parameter distinguishes its a post increment operator
    PrePostIncr operator++(int dummy) { //Post increment    
        //very imp lines to note
        cout << "POST incr => ";
        PrePostIncr temp = *this;
        ++(*this).var;
        //return temp; //warning: reference to local variable 'temp' returned
        return temp;
    }
};
int main() {
    PrePostIncr p(10);
    p.show();
    (++p).show();
    (p++).show();
    cout << "After post increment => ";
    p.show();

}