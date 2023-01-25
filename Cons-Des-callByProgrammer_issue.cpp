// It is dangerous and rather destructor should not be called by programmer manually. 
// this is because compiler guarantees that it will call it. 
// so 2 times Des gets called resulting in Dangerous consequences
// How to call => int main() { Base(); //this will create a temporary obj & we can call Des on that obj itself.
//                 Base().~Base()    }
#include<iostream>
class Base {
public:    
    Base(){ std::cout<<"Base()\n"; }
    ~Base(){ std::cout<<"~Base()\n"; }
};
int main() {
    // Base();          // ***** Cons //This is temp obj. so Destructor will also be called on this line only, 
    //                 //  not at end of scope/pgm
    // Base().~Base();  //Des Dangerous to call explicitly because already compiler will call it 1 time
    //POC
    Base();
    std::cout<<"Hi\n";
    // Base()
    // ~Base()  //Des is called before Hi is printed
    // Hi
}