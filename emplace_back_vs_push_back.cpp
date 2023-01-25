//emplace_back is available for all the contianers
//It should be used whenever possible for better performance compared to push_back etc.
//Major performance comparison is seen for classes  
//                      viz. only constructor is called for emplace but constructor and copy both happens for push_back
#include<iostream>
#include<vector>
#include<set>
class A {
public:
    int i;
    A(int j=0):i{j} { std::cout<<"constructor"<<std::endl; }
    A(const A& a)  { i=a.i; std::cout<<"copy"<<std::endl; }
};

//if this line is commented then we get the errors
//error: no match for 'operator<' (operand types are 'const A' and 'const A')
//note:   'const A' is not derived from 'const std::reverse_iterator<_Iterator>
//note: candidate: 'template<class _IteratorL, class _IteratorR> constexpr bool std::operator<(const reverse_iterator<_Iterator>&, const reverse_iterator<_IteratorR>&)'
  //     operator<(const reverse_iterator<_IteratorL>& __x,
bool operator < (const A& lhs, const A& rhs) {return lhs.i < rhs.i; } 
//Also note that in both arguments "const" is must otherwise also we will get errors

int main()
{
    std::set<A> Set;
    //Set.insert(A(10));
/*     //OUTPUT
    constructor
    copy       
    copy
    10
 */    

    Set.emplace(20);
/*     //OUTPUT
    constructor
    copy
    20
 */    

    for(auto k : Set)
        std::cout<<k.i;

//------------------------------------------------------------------------------------------
//    std::vector<A> vec;
//    vec.push_back(A(10)); //OUTPUT
                            /*  constructor
                                copy
                                copy
                                10
                            */
//    vec.emplace_back(20); // ***** HERE A(20) is not required. Only passing the value is sufficient
                            //OUTPUT //Notice here. Only 1 copy is there whereas 2 copy is present above
                            /*  constructor
                                copy
                                20
                            */
//    for(auto k : vec)
//        std::cout<<k.i;
//------------------------------------------------------------------------------------------

return 0;
    
}