If parameterized constructor is defined then default constructor will not be 
implemented by the compiler internally

then how to tell the compiler that I need the default constructor

thats by using "default" keyword


class Demo {
    Demo(int a){}
    Demo() = default; //If we do not do this then we get error and will have to implement our own default constructor
};

So bottom line is if parameterized constructor is defined then we have to have default constructor 
either by programmer or by compiler by specifying =default