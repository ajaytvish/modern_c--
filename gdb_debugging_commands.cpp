// How to use gdb to debug C/C++ program   -----  Youtube CPPNUTS "70 interview questions" 01:40:47
// Ans - Using below mentioned commands    -----  https://www.youtube.com/watch?v=bFtkHJy9kIU

//Terminal commands for debugging
// g++ -g gdb_debugging_commands.cpp    // -g switch is required to debug the program
// gdb a.out/a.exe                      // now the executable is in gdb mode. debuggable mode
// b main                               // set breakpoint at main() i.e function name to break into
// b fun1                               // set breakpoint at fun1() 
// r                                    // run. i think restart also
// f                                    // see the stack frame say when breakpoint is hit
                                           // after bt command. number wise fns will be seen
                                           // f 2 command will open f2() call trace and we can check values of the vars in that fn
// n                                    // execute
// s                                    // step into
// c                                    // continue    - run till next breakpoint end of pgm
// p var_name                           // print a variabe
// bt                                   // backtrace... see the call stack. will list fns called in sequence each with a no
// info b                               // breakpoint info. all breakpoints numbered
// delete 1                             // breakpoint no 1 will be deleted

void f3() {
    int v3 = 30;
}
void f2() {
    int v2 = 20;
    f3();
}
void f1() {
    int v3 = 10;
    f2();
}
int main() {
    int m = 1;
    f1();
}

