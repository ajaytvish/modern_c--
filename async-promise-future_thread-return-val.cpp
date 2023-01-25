// std::promise & std::future in threading
// NOTES:
// 1. std::promise
//     Used to set values or exceptions
// 2. std::future
//     1) get the return value from promise
//     2) ask promise if the value is avaialble. 
//     3) if not then wait for the promise

#include<iostream>     
#include<thread>
#include<future>

// ****** NOTE - std::async is successor to promise. so use async feature
int doWork()
{
    std::cout<<"Hi";
    return 20;           //Note: with promise I had to set the promise value but here I can simply use return statement to return the value
}
void doWork_2()
{
    std::cout<<"Hi"; //Hi does not print when std::launch::deferred is used 
}

int main()
{
    // Looks like - in case of "deferred", if return type is void then nothing is printed or even debug point is hit. so the fuction is not executed.

    //std::future<void> f = std::async(std::launch::async, doWork);         //Creates new thread //Works //Prints Hi20
    //std::future<void> f = std::async(doWork);                             //Does not create new thread //works well //prints Hi
    std::future<void> f1 = std::async(std::launch::deferred, doWork_2);   //SURPRISING RESULT - Hi not printed. so not sure if really executes. //Debug point also does not get hit
    //std::future<int> f = std::async(std::launch::deferred, doWork);       //Does not create new thread //compiles Hi20 is printed //Debug point hits
    //std::cout<<f.get();


}

//===========================================================================================
/* // PROMISE & FUTURE - perfect program. BUT STD::ASYNC IS SUCCESSOR VERSION OF IT. 
void doWork(std::promise<int> && pp)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pp.set_value(10);
}

int main()
{
    std::promise<int> p;
    std::future<int>  f = p.get_future();
    std::thread t(doWork, std::move(p)); // std::move() is very imp. difficult to understand the error
    t.join();
    std::cout<<f.get();
} */
