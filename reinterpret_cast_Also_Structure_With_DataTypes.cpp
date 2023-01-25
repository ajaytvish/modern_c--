// 1) 2 things can be seen here. If a structure contains different data types then 
//        how to access each type
// 2) Use of reinterpret_case and example - reinterpret cast converts any type to any other type
// 3) reinterpret_cast when used the product becomes non portable

#include <iostream>
using namespace std;
struct Composite {
    int i;
    int ii;
    char c;
    bool b;
    float f; 
};
int main() {
    Composite st { 5, 10, 'x', true, 2.7};
    //int *p = &st; //Error: a value of type "Composite *" cannot be used to initialize an entity of type "int *"
    int *ip = reinterpret_cast<int*>( &st ); //casting struct* to int* - any type to any type
    cout<< *ip << endl; //5
    ++ip;   cout<< *ip << endl; //10
    ++ip;   cout<< *ip << endl; //376 or random val //Incorrect because its a char val and we are outputting using int 
    --ip;   cout<< *ip << endl; //10
    ++ip;
    char *cp = reinterpret_cast<char*>(ip);
    cout<< *cp << endl; // x
    ++cp;
    bool *bp = reinterpret_cast<bool*>(cp);
    cout<< *bp << endl; // 1 => true
    ++bp;
    float* fp = reinterpret_cast<float*>(bp);
    cout << *fp << endl; // -1.07804e+08 //Incorrect output //How to get the correct output ?? challenge

    
    


    
}
