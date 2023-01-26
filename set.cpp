#include <iostream>
#include <set>
using namespace std;

int main() {
    std::set s {1,2,3,4,5};
    for(auto i : s) 
        cout<<i<<endl;
} 