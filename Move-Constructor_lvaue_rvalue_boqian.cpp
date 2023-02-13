#include <iostream>
using namespace std;

//Simple rule - 
//it it has memory alloated and if we can get the address then its lvalue
//if it's not lvalue then its rvalue

//--------------------------------------------------------------
//Interview question I was asked for Synecron Technologies
//What are different ways to call copy constructor
//********************MOVE CONSTRUCTOR / Move SEMANTICS **************************
                    // *********************************** 
                    // move constructor will be called in 2 cases
                    // 1) When rvalue is passed as param 
                    // 2) when std::move() is used
                    // ***********************************


class Test {
    int i = 0;
    char *str = nullptr; //here memory freeing, ptr is a concern for this concept. so we are taking char*/double* and not string
public:
    Test(){}
    Test(int k, char* istr):i(k) {
        int l = sizeof(*istr);
        str = new char[l+1];
        copy(str, istr.str); //strcpy(str,istr);
        str[l]='\0';
    }
    Test(const Test& t) { //Copy constructor
        std::cout<<"COPY constructor called\n";
        i=t.i;
        int l = sizeof(t.str); //Very expensive // Deep copy
        str = new char[l];
        strcpy(str, t.str);
        str[l]='\0';
    }
    Test(/*const*/ Test&& t) {    //MOVE CONSTRUCTOR  //not at all expensive
                                                      //**** Imp Note : Here const should not be there 
                                                      //otherwise error as we are changing the values of the object
        cout<<"MOVE constructor called\n";
        i = t.i;
        str = t.str;
        t.str = nullptr;
    }
    void print() {
        cout<<"object=> "<<this<<"\t"<<i<<"\t"<<&str<<"\t"<<str<<"\n";
    }
    ~Test() {
        delete str;
    }
};

void func(Test t) {} //calls copy constructor because t1 is received as t by value & copy will happen
Test createTestObject() { Test t; return t;}  //returns Test class's object

int main() {
    Test t1(10,"Ajay"); //calls parameterized constructor
    t1.print();
    Test t2(t1); //Calls copy constructor
    func(createTestObject()); //calls MOVE constructor as createTestObject()) will create temporary object i.e rvalue. 
                                //and it is passed to func()
    t1.print();
}


//---------------------------------------------------------------




// int i = 5; //i is lvalue //r is rvalue
// int &x = i; //i is lvalue but in this line its implicitly converted to rvalue. //x is lvalue reference or earlier called only reference
// *(arr+2) = 10; //lvalue *(arr+2)
// sum(1,2) = 5; // ?


//--------------------------------
//void f(int i){ return i*2;} //1     //If this line is commented then error will be seen
// This & and && kind of overloading should be done without f(int i) call
// void f(int& i){ return i*2;} //2

// void f(int&& i){ return i*2; } //3  Here  rvalue is denoted by  &&
//     //This kind of overloading becomes very useful when say like resource managing is used 

// int main() {
//     int a = 20;
//     f(a); //Error because this line confuses compiler which one to call //1 or //2
//     f(5); //Error because this line confuses compiler which one to call //1 or //3
// }


