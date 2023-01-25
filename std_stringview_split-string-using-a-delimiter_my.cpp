#include <iostream>
#include <string>
#include <string_view>
#include <ranges>
#include <cctype>
#include <iomanip>
using namespace std;

int main() 
{
    std::string_view sv{"ajay , singh"}; //"ajay , , vish , nimbu, , singh"
    std::string_view delim{","};
    //auto split = std::ranges::split_view(sv, delim);
    for(auto splt : std::ranges::split_view(sv, delim))
        auto word{splt | std::views::drop_while(isspace)};
    cout<< string{ word.begin(), word.end()};
    
}