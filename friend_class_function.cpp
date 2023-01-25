#include <iostream>
using namespace std;

//friend function example
class A {
    private: int a = 10;
    public: friend void fun( A*);
};

void fun(A *obj) {
    cout<<obj->a;
}

int main() {
    fun(new A); //Key is here. Class whose private member is accessed is passed here.
                //Then the outside function or class's function that is called is made friend
return 0;
}


//========================================================================================
/* //friend class example
class A {
    private: int a = 10;
    public:
        friend class B;
};
class B {
    public:
        void AccessClassAVar(A *obj) {
            cout<<obj->a;
        }
};

int main()
{
    B b;
    b.AccessClassAVar(new A());
} */