//
// 7.3.critical.section.b.cpp
// chapter 7 parallelism and concurrency
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
int v = 1;

void critical_section(int change_v) {
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    // do contention operations
    v = change_v;
    std::cout << v << " ";
    // release the lock
    lock.unlock();

    // during this period,
    // others are allowed to acquire v

    // start another group of contention operations
    // lock again
    lock.lock();
    v += 1;
    std::cout << v << ", ";
}

int main() {

//Original code  -  O/P -  2 3, 4 5, 3 4, 7 8, 8 9, 10 11, 6 7, 9 10, 2 3, 5 6, 
//                         2 2 3 4, 5, 5 6, 8 9, 9 10, 11, 4 5, 6 7, 7 8, 10 11,
    std::thread t1(critical_section, 2), t2(critical_section, 2), t3(critical_section, 3), t4(critical_section, 4), t5(critical_section, 5), t6(critical_section, 6), t7(critical_section, 7), t8(critical_section, 8), t9(critical_section, 9), t10(critical_section, 10);
//for(int i=0; i<10; i++) {
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
//}

//My code - O/P - 0 1 2, 3 4, 5, 5 6, 7 8, 9 10, 4 5, 8 9, 6 7, 2 3,
/* thread t[10];
for(int i=0; i<10; i++)
    t[i] = thread(critical_section, i);
for(int i=0; i<10; i++)
    t[i].join();
 */
return 0;
}