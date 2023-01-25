#include <iostream>
#include <string>
#include <string_view>
#include <ranges>
#include <cctype>
#include <iomanip>

int main() {
    // Even if red errors are shown here BUT code compiles and runs perfectly using "g++ --std=c++20 .\std_stringview_imp.cpp"
    // Output:
    // "qwe"
    // "asd"
    // "zxc"
    // "lkj"

    constexpr std::string_view str{ "qwe ade , asd , zxc , lkj" };
    constexpr std::string_view delim{ "," };
    constexpr std::string_view substr { "zxc" }; 
       
    // for (std::string_view s : std::ranges::split_view(str, delim)) {     //solved the error by specifying auto below
    for (auto s : std::ranges::split_view(str, delim)) {
        auto word{ s | std::views::drop_while(isspace) | std::views::reverse | std::views::drop_while(isspace) | std::views::reverse };

        std::cout << std::quoted(std::string{ word.begin(), word.end() }) << '\n';
    }
}


/* #include <string_view>
#include <ranges>
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int main() 
{
    std::string_view sv{"ajay , singh"}; //"ajay , , vish , nimbu, , singh"
    std::string_view delim{","};
    //auto split = std::ranges::split_view(sv, delim);
    for(auto &split : std::ranges::split_view(sv, delim))
        cout<<split;
    
}
 */













