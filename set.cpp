#include <iostream>
#include <set>
using namespace std;

int main() {
    std::set s {1,2,3,4,5};
    for(auto i : s) 
        cout<<i<<endl;
    std::set s1 {10,2,7,1,9,6};
    for(auto i : s1) 
        cout<<i<<endl;
}
