
#include<bits/stdc++.h>
using namespace std;


int main(){

    string s;
    cin>>s;
    
    int x = s.find('.');
    
    string j = s.substr(x+1);
    
    if(stoi(j) > 0){
        cout<< "float"<<" "<<s.substr(0,x) << " " << "0."<<j<<'\n';
    }
    else{
        cout<< "int"<<" "<<s.substr(0,x) << '\n';
    }

    return 0;
}