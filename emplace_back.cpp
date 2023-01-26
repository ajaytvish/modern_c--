// vector::emplace_back
#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    std::vector<int> vec = {10};
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (20);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (30);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (40);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (50);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (60);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (70);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (80);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (90);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;
    myvector.emplace_back (100);
    cout<< vec.size(); << "\t" << vec.capacity() << endl;

  std::cout << "myvector contains:";
  for (auto& x: myvector)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}