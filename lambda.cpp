#include<iostream>
#include<thread>
using namespace std;

//If you only want to pass some value to lambda function, look at my code below:
int main()
{
    int a = 10;
    [](int arg)
    {
        cout << "arg = " << arg << endl;
    }
    (a);

    return 0;
}

//If you want to make thread with lambda function and passing to it some arguments see next code example:
int main()
{
    int a = 10;
    thread thd([](int arg) { cout << "arg = " << arg << endl; }, a);
    thd.join();

    return 0;
}