// How to stop copying a object into another
// 1) Make Copy constructor and assignment operator private
// 2) Mark copy constructor and assignment operator as delete
// 3) Inherit class A from a Dummy class in which Copy constructor and assignment operator are private

// 1) Make Copy constructor and assignment operator private
// class NoCopy {
// private:
//     int i;
//     NoCopy(NoCopy&) {}
//     NoCopy& operator=(NoCopy& ) {}
// public:
//     NoCopy(){}
//     NoCopy(int x):i(x){}
// };
// int main() {
//     NoCopy nc(10); //constructor should be implemented to create obj. because copy constructor is implemented so both has to be there
//     NoCopy nc1 = nc; //copy constructor call fails as it is private
//     NoCopy nc2;
//     nc2 = nc; //Assignment operator call fails as it is private
// }
//==================================================================================
// 2) Mark copy constructor and assignment operator as delete
// class NoCopy {
// private:
//     int i;
// public:
//     NoCopy(){}
//     NoCopy(NoCopy&) = delete;
//     NoCopy& operator=(NoCopy& ) = delete;
//     NoCopy(int x):i(x){}
// };
// int main() {
//     NoCopy nc(10); 
//     NoCopy nc1 = nc; //function "NoCopy::NoCopy(NoCopy &)" (declared at line 29) cannot be referenced -- it is a deleted function
//     NoCopy nc2; 
//     nc2 = nc; //function "NoCopy::operator=(NoCopy &)" (declared at line 30) cannot be referenced -- it is a deleted function
// }
//==================================================================================

// 3) Inherit class A from a Dummy class in which Copy constructor and assignment operator are private
//                                                                          and check deleted case as well
//Play with constructor here making them private/public and check all combinations
class NoCopyBase {
    NoCopyBase(NoCopyBase& ncb){}
    NoCopyBase& operator= (const NoCopyBase& ncb){}
public:
    NoCopyBase(){}
};
class Der : public NoCopyBase {
    Der(Der&){}
public:
    Der(){}
};
int main() {
    Der d1;
    Der d2 = d1; //function "Der::Der(Der &)" (declared implicitly) cannot be referenced -- it is a deleted function
    Der d3;
    d3 = d2; //function "Der::operator=(Der &)" (declared implicitly) cannot be referenced -- it is a deleted function


}
