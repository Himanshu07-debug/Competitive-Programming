// Given two person names. Each person has {"the first name" + "the second name"} . Determine whether they are brothers 
// or not.
// Note: The two persons are brothers if they share the same second name.

// Input Format :                                      
// bassam ramadan                                      
// ahmed ramadan

// Output : Yes Brothers


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string st, str;
    
    getline(cin,st);
    getline(cin,str);
    
    int i = st.find(" ");
    int j = str.find(" ");
    
    string a = st.substr(i+1);
    string b = str.substr(j+1);
    

    // *************************************  REMEMBER **********************************************

    // In CP, in such type of question, never increase the complexity of solving it.. Simply take 4 strings and
    // compare 2nd and 4th one
    // Avoid doing complex things such as taking the complete String and then splitting it, etc...

    string s1, s2, s3, s4;

    cin >> s1 >> s2 >> s3 >> s4;

    if( s2 == s4 ){
        cout<<"ARE Brothers"<<"\n";
    }
    else{
        cout<<"NOT"<<"\n";
    }
    

    return 0;
}