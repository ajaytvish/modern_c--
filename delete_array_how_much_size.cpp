//How delete[] knows how much size of memory to deallocate
// 2 Techniques => 1) Overallocation   2) Associative array

//NOTE: 1 Question... what is PLACEMENT NEW. Allocating obj on the already allocated address. Find below the exact comment

// 1) Overallocation
// See  ALLOCATION  & DEALLOCATION CODE  below & here
// ----------------------------------------------------------------------------
//Since programmer has to specify how many times he wants memory the specified type (n=10 & type Base here)
//so memory will be allocated for storing value n + (n*Base) => 4 byte + 10*4(Base has int var) byte => 44 bytes in total
//SO 10 WILL BE STORED in the memory JUST BEFORE n*Base n times Base type memory will be 
class Base {
    int i;
public:    
    ~Base() { }
};
int main() {
    int n=10;
    Base* bp = new Base[n];  //start_address_bp will hold the start address of the memory location
    delete[] bp;
}
//Above code is internally replaced by compiler into couple of lines of code
//each for allocating and deallocating
//Cppnuts https://www.youtube.com/watch?v=bFtkHJy9kIU  02:05 

// All below procress is What will happen internally is
    // so operator new [n] + WORDSIZE will be allocated
    // n=10 will be stored in the FIRST 4 BYTE and then 40 bytes(n*Base) will be stored //Base has int i & n=10 => 40 bytes
    // since operator new [n] is called so it is PROGRAMMER'S DUTY TO DELETE 
    // but before that till now since memory is allocated but object is not created. let's see object creation on that memory
    // new (WORDSIZE+start_address_bp) Base(); //so actual object allocation starts after leaving WORDSIZE 
    //                                      //where n will be stored. i.e at the start location
    // Simillarly delete[] bp;  will go bp-WORDSIZE and fetch n which will give 10
    //             and delete will start deallocating n*(Base+WORDSIZE) type while(n!=0) in reverse order
    //             by calling operator delete[]  as we had used operator new[]

// memory allocation & bp base pointer    
// 0 1 2 3 4 5 6 7 8 9 10 11.........30 40 41 43              ===> 44 bytes
// |_____| |_____| |_______|         |_________|
//    10    Base1    Base2              Base10
//    n     bp ptr
//          points
//          here at
//          4
// so to get value 10 => bp-WORDSISE happens

// Iterate in loop & Allocate
//     for(int i=0; i<n; i++) 
//      { new(bp+i) Base(); }   //THIS IS CALLED PLACEMENT NEW. Allocating obj on the already allocated address
// Iterate in loop & Deallocate in reverse order
//     while(n-- != 0) { (bp+n)->~Base(); } //All memory for Base[] will be deleted
// operator delete[] (char*(bp)-WORDSIZE)   //memory for n holding 10 will also be deleted

// 2) Associative array
// This is simple like using map with key & value. key will be bp the base pointer and value will be n. so map(key,val) = map(bp,n) 
// the map equivalent implemented using array i guess
