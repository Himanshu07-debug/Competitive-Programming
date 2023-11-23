#include<bits/stdc++.h>
using namespace std;

int main(){

    // REMEMBER : String and String literals are not same thing

    // String -> a set of characters. You can change the Characters.
    // String literal -> a set of Characters . It is not editable

    string s = "abcd";   // This is String

    auto i = "abcd";   // This is literal of type const char*


    // Vector functions are availbale in String :

    cout << s.back() << endl;
    s.pop_back();
    s.push_back('a');   // In string, the elements can be accessed as char only with single quotes
    cout << s << endl;

    reverse(s.begin(),s.end());

    // Initialization in String: 

    string t(s.size(),'a');   
    // NOTE : In vector, initializing value was optional, here mandatory

    string ans = s.substr(0,2); 
    // This takes time = length of Substring i.e O(2) in this case


    // TIPS : 
    // In CP, if it is said that insert a character, delete a character, no need to do complex operation on given string..
    // cout the inserted one or if not possible, take an auxilary string

    s[0] = toupper(s[0]);


    // DIFFERENCE IN Increasing and Non-decreasing :

    // Increasing -> equal values are not allowed, always it should increase by value [ 1, 2, 3 , 4 ]
    // Non-Decreasing -> equal values are allowed [ 1, 2, 3, 3, 4, 5, 5, 6 ]

    return 0;

}


