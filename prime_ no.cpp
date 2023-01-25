#include <iostream>       // std::cout
#include <future>         // std::async, std::future

bool prime_no(int &input_val)
{
    for(int i=2; i<input_val; ++i)
        if(input_val%i==0) return false;
    return true;

}
int main()
{
    int input;
    std::cout<<"Enter no: ";
    std::cin>>input;
    bool b = prime_no(input); 
    if(b) std::cout<<"no "<<input<<" is a prime no";
    else std::cout<<"no "<<input<<" is NOT prime no";
    std::cout<<"Enter no: ";
    std::cin>>input;
}



/* // a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
  std::cout << "Calculating. Please, wait...\n";
  for (int i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

int main ()
{
  // call is_prime(313222313) asynchronously:
  std::future<bool> fut = std::async (is_prime,7);

  std::cout << "Checking whether 313222313 is prime.\n";
  // ...

  bool ret = fut.get();      // waits for is_prime to return

  if (ret) std::cout << "It is prime!\n";
  else std::cout << "It is not prime.\n";

  return 0;
}
 */
