
//C# like feature. one i had seen in Q
//calling all the functions one by one in one line to complete the task
//for eg save an employee all details or set all the car configurations
#include <iostream>
using namespace std;

class Employee {
    string name;
    string surname;
    string profile;
    string address;

public:
    string getName()
    {
        return name;
    }
    Employee& setName(string n)  
    {
        name = n;
        return *this;
    }
    string getSurname()
    {
        return surname;
    }
    Employee& setSurname(string sn)
    {
        surname = sn;
        return *this;
    }
    string getProfile()
    {
        return profile;
    }
    Employee& setProfile(string p)
    {
        profile = p;
        return *this;
    }
    string getAddress()
    {
        return address;
    }
    Employee& setAddress(string add)
    {
        address = add;
        return *this;
    }
};

int main()
{
    Employee e;
    // NOTE: All set fns are returning by reference Employee&. That's why all values are set on the same object.
    // Otherwise return if done by value then all set fns will set value for diff objects
    // So, return *this; returns the object AND Employee& states that retun is done using reference
    e.setName("ajay").setSurname("vish").setProfile("dev").setAddress("goregoan");
    std::cout<<e.getName()<<" "<<e.getSurname()<<" "<<e.getProfile()<<" "<<e.getAddress();
}