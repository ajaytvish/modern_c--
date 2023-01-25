
// atoi() is already available. It converts string to int. It requires that string(char[]) contains numbers only
#include<iostream>
#include<array>
#include<cstring>
using namespace std;

class Atoi {
    int val = 0;
public:
    int stoi(char* s) {
        bool b = true; int sign = 0;
        int i; 
        //First check if the input value is negative value
        if(s[0]=='-') i=1;  //skipping 1st character if it is a -ve sign indicating negative no
        //Second check of the input is a valid no. i.e it contains only 0-9 
        for(; i<strlen(s); ++i) {
            // if(  !((s[i]-'0')>=0 && (s[i]-'0')<=9)) { //this line if(!((s[i]-'0')>=0 && (s[i]-'0')<=9)) does not 
            //                                         //handle -ve number. i.e string starting with "-"
            if(!((s[i]-'0')>=0 && (s[i]-'0')<=9)) { //This line checks -ve no condition also if string starts with "-" sign

                cout<<"string does not have a valid number \n"; 
                b = false; 
                val = -1; //to indicate the return value is false
                break; 
            }
        }
        //string has been confirmed to have a valid no. +ve or -ne no. just process it
        if(b) {  
            cout<<"string has a valid number \n";
            if(s[0]=='-') i=1; //skipping 1st character if it is a -ve sign indicating negative no
            for(; i<strlen(s); ++i) {
                if(s[i]=='-') { sign = -1; continue; }
                    // ***** ULTIMATE LOGIC TO GET INT VAL OF A VALUE AVAILABLE as CHARACTER ****
                    val = val*10 + (s[i]-'0'); 
            }
        }
        if(sign == -1)
            val = sign*val;
        return val;
    }
};
int main() {
    char str[] {"-99990129"}; //Test strings: "-99990129", "1234567890", "x123", "7938x", 
    Atoi a;
    int val = a.stoi(str);
    cout << "val = " << val;
}

//==========================================================================
// // Online code for learning - works perfectly. input - 12345
// #include <stdio.h>
// #include <string.h>

// main() {
//   char num[50];
//   int  i, len;
//   int result = 0;
  
//   printf("Enter a number: ");
//   gets(num);
//   len = strlen(num);

// 	for(i=0; i<len; i++){
// 		result = result * 10 + ( num[i] - '0' );
// 	}

// 	printf("%d", result);
// }
