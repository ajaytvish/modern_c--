#include <thread>
#include <iostream>
#include <fstream>
#include <mutex>
using namespace std;
// int bal = 0;
// void f1() { ++bal; }
// void f2() { ++bal; }
// int main() {
//     std::thread t1(f1);
//     std::thread t2(f2);
//     t1.join(); //join() ensures program will not terminate until t1 & t2 finishes
//     t2.join();
//     std::cout << bal;
// }

//cout is main process's/thread's resource. so it should be destroyed when main thread finishes
//since join() is used, main thread will wait for it to finish and then only terminate the program
//so how main thread can be freed and other threads run independent of main thread ?
//This can be done using detach() 

// int bal = 0;
// void f1() { ++bal; }
// int main() {
//     std::thread t1(f1);
//     t1.detach();
//     // t1.join(); //CRASH..... ERROR - once detached then cannot join
//     //what to do if want to check if the thread can be joined again later... 
//     //This can be done using joinable()
//     if(t1.joinable())
//         t1.join();     // In this case CRASH WILL AT LEAST NOT HAPPEN
//     std::cout << bal;
// }

///Thread can be called using functor
// //functor is object acting as callable object for which operator() is overloaded
// class Fctor {
// public:
//     //operator()() { std::cout<<"functor fn called."} //ERROR - explicit type is missing ('int' assumed)
//     Fctor& operator()() { std::cout<<"functor fn called."; } 
// };
// int main() {
//     Fctor f;
//     std::thread t(f());
// }



////////////// suppose after thread creation and before t.join() , main executes some code which crashes, so 
//what will happen is pgm will terminate and hence thread also. so how to ensure that the thread finishes its task
// we can implement try...catch and join the thread in catch() & throw
// void f1() { 
//     std::cout << "=> n = ";
//     for(int n=0; n<1000;n++)
//         std::cout << n <<" ";
// }
// int main() {
//     std::thread t1(f1);
//     int i = 5;
//     // int *k = &(++i); // This code will crash because ++i memory location is not allocated but accessed. 
//     //                  // t1 will terminate without finishing its work
//     //                  // How to avoid this situation   ---- by using try...catch() & throw *****
//     // t1.join(); 

// //solution - This try catch will make sure that t1 will be joined with or without exception *******
//     try {
//         int *k = &(++i);
//     }
//     catch(...){
//         t1.join();      //ensures that thread will execute even if expection occurs
//         throw;          //throw - thinking that someone else will handle the exception
//         //******************* VVVVVImp discussion ******************
//         //NOTE: breakpoint for t1.join() does not hit while run/debug. so not sure if exception is 
//         //actually getting handled. Also in run mode, n is getting printed but not completely till 1000
//         //indicating that t1 is also terminate abruptly and not able to complete its task. so this says 
//         //that t1.join() is not happening
//     }
// }






// template <typename T>
// class Wrapper {
// public:
//     Wrapper(T* ti): {}
//     ~Wrapper() {
//         t1.join();
//     }
// };
// int main() {
//     std::thread t1;
//     Wrapper w(t1); //This is not happening. Error always. Trying to create wrapper class for thread to free resources in destructor like smart pointers
//     //no instance of constructor "Wrapper" matches the argument listC/C++(289)
//     //intro_mutitreading.cpp(93, 13): argument types are: (std::thread)
// }




// //A thread object can be called upon a fn, functor, lambda etc i.e on any callable object
// int main() {
//     std::thread t([](){
//         for(int i=0;i<10;++i)
//             std::cout<<i<<" ";
//     });
//     //O/P =>>> *************** note exception is thrown here. no clues why..........
//     //terminate called without an active exception ##############
//     //0 1 2 3 4 5 6 7 8 9 
// }




// class Fctor {
// public:    void operator()() {}
// };
// int main() {
//     Fctor fct;
//     std::thread t(fct); //running thread via callable object functor *****
//     std::thread t(Fctor()); //This will be treated as t is a fn returning std::thread and taking parameter
//                             //parameter is a pointer to another fn that does not take any param and that is returning a Fctor type
//                             //C++ standard says whenever a fn can be treated as a fn declaration it will treated as a fn declaration                        
//      //SOLUTION
//      std::thread t((Fctor())); //enclose it in parenthesis and done
// }




// // How to pass parameter to a functor
// class Fctor {
// public:    void operator()(std::string s) { std::cout<<s;}
// };
// int main() {
//     std::thread t((Fctor()), "Test");
// }




// // //Pass parameter to thread as reference std::ref()  ***** New thing to learn   std::ref()
// class Fctor {
// public:    
//     void operator()(string& s) { 
//         std::cout<< s <<"\n";
//         s = "World";
//     }
// };
// int main() {
//     string str = "Hello";
//     thread t((Fctor()), std::ref(str));
//     //STD::REF
//     //if std::ref() is not used then error
//     //error: static assertion failed: std::thread arguments must be invocable after conversion to rvalues
//
//     //------- ******   NEW FOR ME. PARAMETER CAN BE PASSED AS REFERENCE TO THE THREAD ***** --------
//     //------  SO MAIN THREAD AND CHILD THREAD ARE SHARING RESOURCE ***** ---------
//     t.join();
//     cout<< str ;
// }
// O/P => 
// Hello
// World





                    // STD::MOVE *********
//class Fctor {
//public:    
//    void operator()(string& s) { 
//        std::cout<< s <<"\n";
//        s = "World";
//    }
//};
//int main() {
//    string str = "Hello";
//    //std::move() will move the resource from main thread to child thread ******************
//    thread t((Fctor()), std::move(str)); // 1) move resource
//    //another example
//    //thread t1 = t; //ERROR : cannot be referenced -- it is a deleted function
//    thread t1 = std::move(t); // 2) move thread
//    //t.join();   //t is empty now
//    t1.join();
//    cout<< str ;
//}

//                     // Thread ID  SLEEP -  main & child threads
// class Fctor1 {
// public:
//     void operator()() { 
//         for(int i=0; i<10; ++i)
//             cout << i;
//      }
// };
// int main() {
//     cout << std::this_thread::get_id();
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::thread t((Fctor1()));
//     cout << t.get_id();
//     t.join();    
// }


// std::lock_guard



//                 // How to know max no threads that should be created depending on h/w ?
// int main() {
//     unsigned int max_t = std::thread::hardware_concurrency();
//     cout << max_t;
// }
// //This probably will give the number of cores



                        //Deadlock - How to avoid
// 1) prefer locking single mutex
// 2) avoid locking a mutex and then calling a user defined fn as the fn may lock the same mutex again
// 3) use std::lock() to lock the mutex and then use. it needs to be unlocked as well
// 4) if more than 1 mutex needs to be locked then it should be locked in the same sequence/order
//         if 2 m1 m2 both are locked in both f1 f2 then order of locking should be same say m1 first and then m2



                                //Mutex locking
// There are couple of ways to lock the mutex
// 1) m.lock()   // Not so good to use
// 2) std::lock_guard<mutex> mlg(m)
// 3) std::unique_lock




                            //Threads already seems to be synchronized without using lock
//Unique_lock is better than lock_guard. It provides a better way to implement a finer grained lock.
//With Unique_lock we can construct the locker/object without actually locking the mutex using deferred param
//e.g.  std::unique_lock<mutex> ulock(m, std::defer_lock)
std::mutex m;
void f(int x) {
    unique_lock<mutex> ulock(m, std::defer_lock);
    //do something
    ulock.lock();
    //do something
    ulock.unlock();
    //..... do something
    ulock.lock();
    //..... do something
    ulock.unlock();
    //This again and again locking we cannot do with lock_guard <================


    //******* lock_guard & unique_lock cannot be copied....
    //unique_lock can be moved from 1 to other unique_lock      
    //unique_lock<mutex> ul1;  unique_lock<mutex> ul2 = std::move(ul1);
            //*** unique_lock is much more flexible but bit heavy. 
            //so if more flexibility is not required than lock_guard should be used


    for(int i=0;i<500;++i) {
        if(x==1) cout<< "t1" <<" -> "<<i<<endl;
        else cout<< "t2" <<" -> "<<i<<endl;
    }
    //ulock will be released at fn end 
}
int main() {
    thread t1(f,1); t1.join();
    thread t2(f,2); t2.join();
    cout<<"m - ";    
    for(int i=0;i<500;++i)
        cout<<" "<<i;    
}



// Log File opening in multithreading   ----   Open log file ONLY ONCE between mutiple threads
int main() {
    ofstream f;  //#include<fstream> otherwise error incomplete type is not allowed
    std::once_flag oFlag;
    std::call_once(oFlag, [&](){ f.open("log.txt" , std::ios::app); });
}