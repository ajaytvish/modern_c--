// https://stackoverflow.com/questions/48918923/c-async-future-deferred-vs-async

#include <iostream>
#include <future>
using namespace std;
    
thread_local int g_num;
    
int read_it(int x) {
    return g_num + x;
}

int main()
{
    g_num = 100;

    int arg = 1;
    future<int> fut = async(launch::deferred, read_it, arg);
    arg = 2;
    future<int> fut2 = async(launch::async, read_it, arg);

    cout << "Defer: " << fut.get() << endl;
    cout << "Async: " << fut2.get() << endl;

    return 0;
}

// OUTPUT
// Defer: 101
// Async: 2

//###################################################################################
/* #include <thread>
#include <chrono>
#include <future>
#include <iostream>
int foo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return 1000;
}

int main()
{
    std::future<int> ret = std::async(std::launch::async, foo);   //std::launch::deferred
    std::cout << ret.get() << std::endl;

    for(int i=1; i<20; i++)
    {
        std::cout << "i = " << i << std::endl;
    }
} */

//###################################################################################
/* auto handle = std::async(std::launch::async, foo);  // create an async task
auto result = handle.get();  // wait for the result */