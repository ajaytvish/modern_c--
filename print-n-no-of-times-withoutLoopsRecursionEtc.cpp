//print-n-no-of-times-withoutUsingLoopsRecursionEtc
#include<iostream>
class Count {
    //int i=0;  //a member with an in-class initializer is always const
    static int i;
public:
    Count() { std::cout<<"Constructor printed "<<++i<<" time"<<std::endl; }
    ~Count() { std::cout<<"Destructor printed "<<++i<<" time"<<std::endl; }
};
int Count::i=0;
int main() {
    Count c[10];
}