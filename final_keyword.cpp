class Demo final {}; //No class can derive from Demo class
class Demo {
    virtual void A() final {} //No class derived from Demo can inherit/override fn A() from Demo
};