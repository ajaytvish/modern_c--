#include<iostream>
//FIND MINIMUM MAXIMUM VALUE
template<typename T>
T maximum(T it){
    return it;
}
template <typename T, typename... Args> 
T maximum(T firstValue, Args... args){
    auto nextValue = maximum(args...);
    return firstValue < nextValue ? firstValue : nextValue ; 
}

int main(){
    std::cout << maximum(8.89,10.53,8.4) << std::endl;
    return 0;
}