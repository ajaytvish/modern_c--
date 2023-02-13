#include<iostream>
#include<vector>
#include<initializer_list>  //// Note this include header initializer_list
using namespace std;


//RULES Compiler uses to do the uniform initilazation
//1) first it searches for initializer_list constructor
//2) then it searches for regular constructor with same no & type of the params
//3) Aggregate initializer ---- this is used for for eg class members direct initialization


// int main() {
// 	vector<int> v {1,2,3,4,5};
// 	for(auto i : v)
// 		cout<<i<<" ";
// }


////////////////////////////// 1 - Initializer_list
// class InitializerListDemo {
// 	vector<int> vec; //{1,2,3,4,5};
// public:
// 	// when vector<int> vec {1,2,3,4,5}; is done then internally constructor with initializer_list<vector> is called
// 	//otherwise if below constructor code is commented then ERROR: error: no matching function for call to 'InitializerListDemo::InitializerListDemo(<brace-enclosed initializer list>)'
//	//Error: note: candidate: 'InitializerListDemo::InitializerListDemo(const InitializerListDemo&)'
// 	// InitializerListDemo(const initializer_list<int>& v){
// 	// 	for(auto i : v)
// 	// 		vec.emplace_back(i);
// 	// }
// 	void printVec() {
// 		for(auto i : vec)
// 			cout<<i;
// 	}
// };
// int main() {
// 	//vector<int> srcVec = {1,2,3,4,5};
// 	//InitializerListDemo ild(srcVec); //ERROR : no instance of constructor "InitializerListDemo::InitializerListDemo" matches the argument list
//     InitializerListDemo ild({1,2,3,4,5});
// 	ild.printVec();
// }

////////////////////////////// 2 - Aggregate initialization. Uniform initialization
class Demo {
public:
	int x; char y; float f; std::string s;
	//Demo(int ip, char cp, float fp, std::string sp):x(ip),y(cp),f(fp),s(sp) {  }
	void print() {
		cout<<"x="<<x<<endl; cout<<"y="<<y<<endl; cout<<"f="<<f<<endl; cout<<"s="<<s<<endl;
	}
};
int main() {
	Demo d {10, 'a', 1.5f, "Ajay"};  /// <====
	d.print();
}

