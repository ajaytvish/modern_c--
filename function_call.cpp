#include <iostream>
using namespace std;

//function declaration 
//void greet(int, int);

//  a function definition
/* void greet(int a = 11, int b = 12) 
{
    cout << "Add = " << a+b;
}
int main()
{
    // calling the function
    greet(10,20);
    return 0;
} */

int add(int a, int b)
{
   return a+b; 
}

int main()
{
    int ret;
    ret = add(10,20);
    cout << ret << endl;

    ret = add(30,60);
    cout << ret << endl;

    ret = add(50,100);
    cout << ret << endl;

/*     int a; int b; //declare 
    a = 10;
    b = 20;
    cout << a+b << endl;
    a = 50;
    b = 100;
    cout << a+b << endl;
    a = 500;
    b = 1000;
    cout << a+b << endl;
    a = 50000;
    b = 10000000;
    cout << a+b << endl;
 */
return 0;
}
























