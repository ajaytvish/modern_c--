#include <iostream>
#include <variant>
#include <string>
using namespace std;
int main() 
{
    //std::variant<string, int, float> v {1};      //ok
    //std::variant<string, int, float> v {1.5};    //ok
    std::variant<string, int, float> v {"ajay"}; //ok
    visit(v);
}