
//program that prints 1,2,3...X
#include <iostream>
using namespace std;

//============================= using lambda ============================================================
int i = 0;
auto g = [k=0]() mutable { // if only "[i]" is specified then error: a variable with static storage duration cannot be captured in a lambda
                       // if only "[&]" is specified then error: non-local lambda expression cannot have a capture-default
    return k++;     // if "mutable" is not specified then k shows error: expression must be a modifiable lvalue
};
int main()
{
    cout<<g()<<endl;
    cout<<g()<<endl;
    cout<<g()<<endl;
    return 0;
}

//============================= Call using object =======================================================
/* class gen {
    int i = 0;
public:
    //call of an object of a class type without appropriate operator() or conversion functions to pointer-to-function type
    //int operator() {
    //    return i;
    //}

    int operator()() {   //extra () is required otherwise above error
        return i++;
    }
};
int main() {
    gen g;
    cout<<g()<<endl;
    cout<<g()<<endl;
    cout<<g()<<endl;
}
 */