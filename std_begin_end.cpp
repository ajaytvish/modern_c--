#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
int CountNoOfTwos(const T& container) 
{
    return std::count_if(std::begin(container), std::end(container), [](int i){
        return i==2;
    });

    //Even this works fine
    //return std::count(std::begin(container), std::end(container), 2);
}

int main()
{
    std::vector<int> vec = {2,3,4,3,2,5,2,6};
    std::list<int> lst = {2,3,4,3,2,5,2,6};
    int arr[] = {2,3,4,3,2,5,2,6};  //Raw array is not in STL but still std::begin & std::end works well on this as well.
    auto count = CountNoOfTwos(vec);
    std::cout<< "Two's count for vec = " << count << std::endl;
    auto count1 = CountNoOfTwos(lst);
    std::cout<< "Two's count for lst = " << count1 << std::endl;
    auto count2 = CountNoOfTwos(arr);
    std::cout<< "Two's count for arr = " << count2 << std::endl;
return 0;
}


