// Is used to do correct down casting.   however up casting is also done
// Rules: 1) 1 virtual fn is must in base  2) if down cast successful then it will return new_type i.e type in which casting is done. 3) if casting fails & pointer is used then nullptr will be returned. 4) if casting fails & reference is used then bad_alloc exception will be thrown
//          B                               Der -> B     is called UP cast                                                   struct B { virtual f(){} };  struct D1 : B { f(){} };  struct D2 : B { f(){} };  int main() { D1 d1; B *b = dynaic_cast<B*> (&d1);  D2 *d2 = dynaic_cast<B*> (&b);//nullptr ret val       
//         /  \                             B   -> Der   is called DOWN cast                                                                                                                                                                                     D1 *d11 = dynaic_cast<D1*> (&b); //success     }//main
//        D1   D2
// Using virtual it uses runtime type information
// It has runtime overhead
// If we are sure that the casting we are doing is correct then we should use static_cast
#include<iostream>
#include<exception>
struct Base {
    virtual void f() {}
    // 1 virtual fn is must in base      
                                    //if virtual is removed then below error occurs
    // error: cannot 'dynamic_cast' 'b' (of type 'struct Base*') to type 'struct Der1*' (source type is not polymorphic)
    // Der1 *d4 = dynamic_cast<Der1*>(b);
};
struct Der1 : Base {
    void f() {}
};
struct Der2 : Base {
    void f() {}
};
int main()
{
    ////////////////////// this is for pointers
    Der1 d1;
    Base *b = &d1;
    b->f();
    //Der2 *d2 = b; //a value of type "Base *" cannot be used to initialize an entity of type "Der2 *"
    //Der1 *d3 = b; //a value of type "Base *" cannot be used to initialize an entity of type "Der1 *"
    Der1 *d4 = dynamic_cast<Der1*>(b);
    if(d4 != nullptr)
        std::cout<<"dynamic_cast success";
    else
        std::cout<<"fail";

    //////////////////////  this is for references
    Der1 &d11 = d1;
    Base &b11 = dynamic_cast<Base &>(d11); //a reference of type "Der2 &" (not const-qualified) cannot be initialized with a value of type "Base"
    //Der1 &d23 = dynamic_cast<Der1 &>(b11); // works well
    try {
        Der2 &d22 = dynamic_cast<Der2 &>(b11); //Here b11 is holding Der1 and is converted into d22 so exception will occur. Exception because we are using references
    }
    catch (std::exception e) {
        std::cout<<e.what();
    }
}