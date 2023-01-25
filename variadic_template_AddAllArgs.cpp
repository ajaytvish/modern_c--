#include<iostream>

//ERRORS - if below fn is not specified
/* .\variadic_template.cpp: In instantiation of 'T sum(T, Args ...) [with T = int; Args = {}]':
.\variadic_template.cpp:5:23:   recursively required from 'T sum(T, Args ...) [with T = int; Args = {int, int, int, int, int}]'
.\variadic_template.cpp:5:23:   required from 'T sum(T, Args ...) [with T = int; Args = {int, int, int, int, int, int}]'
.\variadic_template.cpp:12:21:   required from here
.\variadic_template.cpp:5:23: error: no matching function for call to 'sum()'
    5 |         return t + sum(args...);
      |                    ~~~^~~~~~~~~
.\variadic_template.cpp:3:3: note: candidate: 'template<class T, class ... Args> T sum(T, Args ...)'
    3 | T sum(T t,Args... args)  //if ... is missing then error: parameter_pack was used but not expanded
      |   ^~~
.\variadic_template.cpp:3:3: note:   template argument deduction/substitution failed:
.\variadic_template.cpp:5:23: note:   candidate expects at least 1 argument, 0 provided
    5 |         return t + sum(args...);
 */
template <typename T>
T sum(T t)
{
    return t;
}

template <typename T, typename... Args>
T sum(T t,Args... args)  //if ... is missing then error: parameter_pack was used but not expanded
{
        return t + sum(args...); 
        //t+=args; error: parameter packs not expanded with '...'
        //t + sum(args);  error: parameter packs not expanded with '...'
}

int main()
{
    //std::cout << sum(1,2,3,4,5,6,7);
    std::cout << std::endl << sum(1,2.2f,3,4,5.5,6,7.2f); // O/P - 28
    std::cout << std::endl << sum<float>(1,2.2f,3,4,5.5,6,7.2f); // O/P - 28.2
    std::cout << std::endl << sum<double>(1,2.2f,3,4,5.5,6,7.2f); // O/P - 28.2
}
