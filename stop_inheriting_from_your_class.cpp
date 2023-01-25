
//How to stop other class to inherit from your class
// I can think of 2 ways

//MUST USE (1) BELOW ONE ONLY BECAUSE THIS IS LATEST SO OLDER IDEAS SHOULD NOT BE USED
// 1) Using final keyword. Making the class final. so inheritance will not be allowed from that class
class Base final {};
class Der : public Base {}; // ERROR: a 'final' class type cannot be used as a base class


// 2) keep the base constructor private
// class Base {
//     Base(){}
// };
// class Der : public Base {
// public:
//     Der(){} //ERROR: "Base::Base()" (declared at line 2) is inaccessible
//             //error: 'Base::Base()' is private within this context
//             //note: declared private here Base(){}
// };          
// int main() {
//     Der d;
// }
