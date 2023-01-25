// How to stop someone from taking address of an object
// overlaod "& operator" and keep it private ............
// Such beautiful and simple logic it is
class Base {
    // 1) Keep it private OR 2) mark it as delete
    // Base* operator & () {
    //     return this;
    // }
    // 2
public:    Base* operator & () = delete;  //doesn't matter if its pub or pri. 
                                //=delete indicates to the compiler to not create the operator& internally
};
int main() {
    Base t;
    Base *t1 = &t; //should not be allowed
                // Error: function "Base::operator&" (declared at line 4) is inaccessible
                // if operator & is kept private then above error

                //if kept public then code compiles 
}

// ERROR
// error: use of deleted function 'Base* Base::operator&()'
//    15 |     Base *t1 = &t; //should not be allowed