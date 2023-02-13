#include<iostream>
#include<vector>
#include<thread>
using namespace std;

// //If you only want to pass some value to lambda function, look at my code below:
// int main()
// {
//     int a = 10;
//     [](int arg)
//     {
//         cout << "arg = " << arg << endl;
//     }
//     (a);

//     return 0;
// }

// //If you want to make thread with lambda function and passing to it some arguments see next code example:
// int main()
// {
//     int a = 10;
//     thread thd([](int arg) { cout << "arg = " << arg << endl; }, a);
//     thd.join();

//     return 0;
// }


//===========================================================
// auto add = [](int x) { return x*2; } ; 
// //Notice this auto otherwise if int is return type specified then error no suitable conversion function from "lambda [](int x, int y)->int" to "int" exists
// // and ; in the end is required

// template <typename T>
// void Test(T a, const vector<int>& v)
// {
//     // //Test-1
//     // for(auto i : v) {
//     //     if(a(i)>2)
//     //         cout<<i;
//     // }

//     //Test-2
//     for(auto i : v) {
//         if(a(i))
//             cout<<i;
//     }

// } ;

// int main() {
//     vector<int> vec {1,2,3,4,5};
//     //Test-1
//     //Test(add, vec); // 2345

//     //Test-2
//      Test([](int x){ return x>2 && x<5; }, vec); //34
// }

//-------------------------------------------------------------------------------
//variable capture - [&] - to capture local var. powerful technique as compared to traditional pgmg
int main() {
    int x=10, y=20;
    //int add = [&](){ return x+y; }; //ERROR - no suitable conversion function from "lambda []()->int" to "int" exists
    auto add = [&](){ return x+y; }; //VVVVImp   lambda return type changed to auto and above error solved
    cout << add();    
}
