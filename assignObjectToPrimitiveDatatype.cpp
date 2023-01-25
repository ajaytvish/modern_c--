#include<iostream>
using namespace std;
class Test {
    int x=10;
public:
    Test(int i):x(i) {}
    operator int () {
        return x;
    }
};
int main() {
    Test t(10);
    int y = t;
    cout<<y;
}
