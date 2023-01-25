#include<iostream>
using namespace std;
int main() {
    int a = 2; //0010
    int b = 5; //0101
    int c = a&b; cout<<c <<"\n";     //0
    int d = a|b; cout<<d <<"\n";     //7
    int i = a^b; cout<<i <<"\n";     //7
    int e = ~(a|b); cout<<e <<"\n";  //-8
    int f = a<<b; cout<<f <<"\n";    //64
    int g = a>>b; cout<<g <<"\n";    //0
    int h = a>>1; cout<<h <<"\n";    //1




}