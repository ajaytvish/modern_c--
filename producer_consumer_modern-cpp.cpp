
#include<iostream>
#include<deque>
#include<thread>
#include<condition_variable>
using namespace std;

#include <atomic>
#include <cassert>
#include <string>
#include <assert.h>
std::atomic<std::string*> ptr;
int data;
 
void producer()
{
    std::string* p  = new std::string("Hello");
    ::data = 42;
    ptr.store(p, std::memory_order_release);
    cout<<"pdata: "<<::data<<endl;
}
 
void consumer()
{
    std::string* p2;
    while (!(p2 = ptr.load(std::memory_order_consume)))
        ;
    assert(*p2 == "Hello"); // never fires: *p2 carries dependency from ptr
    assert(::data == 44); // may or may not fire: data does not carry dependency from ptr
    cout<<"cdata: "<<::data<<endl;

}
 
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join(); t2.join();

/*     std::thread tp(producer);
    thread t[10];
    for(int i=0;i<10;i++)
        t[i] = std::thread(consumer);
    for(int i=0;i<10;i++)
        t[i].join();
 */
    cout<<"mdata: "<<::data;
}






// void disp_dq(deque<int> &od) {
//     for(auto i : od)
//         cout<<i<<" ";
// }

// int main() {
//     bool notified = false;
//     condition_variable cv;
//     mutex m;
//     deque<int> d;
//     auto pro = [&](){
//         unique_lock<mutex> lock(m);
//         for(int i=0; i<1000; i++) {
//             lock.lock();
//             d.push_back(i);
//             notified = true;
//             //lock.unlock();
//             cv.notify_all();   
//         }
//         disp_dq(d);
//     };
//     auto con = [&](){
//         unique_lock<mutex> lock(m);
//         while(!notified) {
//             cv.wait(lock);
//         }
//         lock.unlock();
//         if(!d.empty()) {
//             for(auto i : d)
//                 d.pop_front();
//             //lock.unlock();
//         }

//     };

//     thread t_pro(pro);
//     thread t_con1(con);
//     thread t_con2(con);
//     thread t_con3(con);
//     t_pro.join();
//     t_con1.join();
//     t_con2.join();
//     t_con3.join();

// return 0;
// }
