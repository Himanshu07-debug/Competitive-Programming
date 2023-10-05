
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string s1, s2;
    
    getline(cin,s1);
    getline(cin,s2);
    
    int i = s1.find(" ");
    int j = s2.find(" ");
    
    string a = s1.substr(i+1);
    string b = s2.substr(j+1);
    
    if(a==b){
        cout<<"ARE Brothers"<<"\n";
    }
    else{
        cout<<"NOT"<<"\n";
    }
    

    return 0;
}