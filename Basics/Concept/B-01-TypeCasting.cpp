#include<bits/stdc++.h>
using namespace std;

int main(){

    // \ is called as escape character
    cout << "\t" << "Hello" << "\n";


    // Type casting
    cout << (char)('f' + 1) << "\n";            // 'f' + 1 gives 103 without type casting

    // NOTE : difference between 'a' and 'A' in ASCII is 32. This will help in conversion from lowercase to upper
    //        without using functions



    char c = '4';
    // How to convert this 4 to integer 4 
    cout << c - '0' << endl;


    // NOTE : Character must be in single quotes

    // NOTE : String is a Derived Datatype same as other Vector, map, set, etc  built on characters

    // INPUT way -> Ek value krne ke baad aap kitna bhi space leke second value, no issue

    // REMEMBER : In C++, by BODMAS all calculation is done



    // String input :
    string s;
    getline(cin,s);



    // Float divison: 

    int a, b;
    cin >> a >> b;

    cout << (float)a/b << "\n";
    cout << a * 1.0 / b << endl;     // Remember -> a / b * 1.0 will give integer (BODMAS) -> a / ( b * 1.0 )  
    // Or you can take input variables in FLOAT

    

    return 0;

}