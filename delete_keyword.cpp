Delete keyword specifies the fn is deleted and cannot be used anymore

class Demo {
    void A() = delete; //cannot be used
    Demo(int a){}    
}
int main() {
    Demo d(10); //work
    Demo d1(20.30) //work
    d = d1; //work as assignment operator is internally implemented by compiler
            //HOW TO AVOID THIS SITUATION AND NOT ALLOW FLOAT FOR INT  or ASSIGNMENT TO HAPPEN
}
//------------------------------------------------------
class Demo {
    void A() = delete; //cannot be used
    Demo(int a){}    
    Demo(float f) = delete;
    Demo& operator=(const Demo& d)  = delete;
}
int main() {
    Demo d(10); //work
    Demo d1(20.30) //FAIL
    d = d1; // FAIL           
}

