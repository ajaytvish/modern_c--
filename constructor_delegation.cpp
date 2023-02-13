class Demo {
    Demo(){}
    Demo(int a):Demo(){ dosomething_here } 
    //Here Demo() cannot be called anywhere else. 
};

//Also
class Demo {
    int a = 10; // ***** This is called in-place initialization. Note - it will be called upon every 
                //constructor call or say when object will be created
};