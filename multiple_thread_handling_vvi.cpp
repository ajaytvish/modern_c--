#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include <atomic>
using namespace std;

int main()
{
// Execute Programs Example 1 & 2 first and see the outputs below
// As can be seen below, outputs pattern with a nnumber and then space is not uniform. so synchronization is required
// 012  5 47 9 3 8   6
// 10  2 4 5 3 8 9 6 7
// 0 12 4 35 6 8 9 7
// 0 213   5 47 9  6 8
// 01 2 3  5 7 4 6 9 8

// Execute Programs Example 3 and see the outputs below
// PS D:\code\modern_c++> .\critical_section.exe
// 0 1 2 t3erminate called without an active exception              //EXCEPTION
//  4 5 6 7 8 9 10
// PS D:\code\modern_c++> .\critical_section.exe
// 0 1 2 3 4 5t erminate called without an active exception         //EXCEPTION
// 6 7 8 9 10

    std::atomic<int> iVal = {0};
    int val = 0;
    thread t[10];
    mutex m;
    condition_variable cv;

    //Example 4 - synchronization implemented to relaize uniform output - BUT this time we are getting EXCEPTION
    // 0 1 2 3 4 5t erminate called without an active exception
    // 6 7 8 9 10
    // HOW TO SOLVE EXCEPTION PROBLEM ??????

    std::unique_lock<std::mutex> lock(m);

    for(int i=0;i<10;i++) {
        t[i] = thread([&val, &iVal, i, &m, &cv, &lock]() -> void {

/*          //Exception exists
            std::lock_guard<std::mutex> lock(mtx);
            0 1 2 3 4t erminate called without an active exception
            5 7 6 8 9 10
 */
          //Still exception exists
            // std::unique_lock<std::mutex> lock(m);
            // cv.wait(lock);
            // lock.lock();
            //     val = i; //this is a critical section code where actual updation is happening. so synchronization is required here with the exception handling between the threads
            //     cout<<val<<" ";
            // //cv.notify_all();
            // cv.notify_one();
            // lock.unlock();
 
/*            //Exception still persists
             try {
            lock.lock();
                val = i; //this is a critical section code where actual updation is happening. so synchronization is required here with the exception handling between the threads
                cout<<val<<" ";
            lock.unlock();
            }
            catch(exception ex) {
                cout<<"Exception => " << ex.what() <<endl;
            }
 */ 
            // Exception not seen now...
            // 01, , 3, 4, 6, 8, 5, 7, 2, 9, 
            // 012, 359, , , 7, , 4, 6, , 8,
            // 01, 2, 9, 5, , 7, 3, 6, 4, 8,
            // 012, , , 3, 5, 7, 9, 6, 4, 8, 

            // mutex mtx;
             //std::unique_lock<std::mutex> lock(m);
             //m.try_lock();
            //lock.lock(); // Error : terminate called recursively. Resource deadlock avoided
                iVal.load(); //this is a critical section code where actual updation is happening. so synchronization is required here with the exception handling between the threads
                iVal.store(i);
                cout<<iVal<<", ";
            //lock.unlock() // Error : terminate called recursively. Resource deadlock avoided
             //m.unlock();

            }
        );
    }

    for(int i=0;i<10;i++) {
        t[i].join();
    }

    //Example 3 - synchronization implemented to relaize uniform output - BUT this time we are getting EXCEPTION
    // 0 1 2 3 4 5t erminate called without an active exception
    // 6 7 8 9 10
/*     for(int i=0;i<10;i++) {
        t[i] = thread([&val, i, &m]() -> void {
            m.lock();
            val = i; //this is a critical section code where actual updation is happening. so synchronization is required here
            cout<<val<<" ";
            m.unlock();
        }
        );
    }
    for(int i=0;i<10;i++) {
        t[i].join();
    }
 */

    //Example 1 - creating lambda first and later passing the lambda name to the thread
/*     auto disp = [&](int in) -> void {
        val = in;
        cout<<val<<" ";
    };
    for(int i=0;i<10;i++) {
        t[i] = thread(disp,i);
    }
    for(int i=0;i<10;i++) {
        t[i].join();
    }
 */

    //Example 2 - passing the whole lambda itself as parameter to the thread
/*     for(int i=0;i<10;i++) {
        t[i] = thread([&val, i]() -> void {

            val = i; //this is a critical section code where actual updation is happening
            cout<<val<<" ";
        }
        );
    }
    for(int i=0;i<10;i++) {
        t[i].join();
    }
 */
return 0;
}

