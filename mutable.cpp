
//mutable applies to non-const & non-static
class M
{
private: 
    int i = 10;
    static int k = 100; //a member with an in-class initializer must be const
    mutable int j = 20;
    static int n; const static int l;
    const int c;
public: 
    static int m;
    void fun() const {
        i = 20; // error: expression must be a modifiable lvalue if i is not declared as mutable
        j = 30;
        m = 12;
        n = 15;
        l = 20;
        c = 40;
    }
};

M::m = 0; // mutable applies to non-const & non-static
          // this declaration has no storage class or type specifier

int main() {}