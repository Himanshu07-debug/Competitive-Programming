// Given three numbers A, B, C. Print these numbers in ascending order followed by a blank line and 
// then the values in the sequence as they were read.

// Input : 3 -2 1
// Output:
// -2
// 1
// 3

// 3
// -2
// 1



#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    
    // 1 way :
    int mx = max(a,max(b,c));
    int mi = min(a,min(b,c));
    int t = (a+b+c) - (mx + mi);

    // Without min , max
    
    int x = a, y = b , z = c;
    
    if(a > b){
        swap(a,b);
    }


    if(b>c){
        swap(b,c);
        if(a > b){
            swap(a,b);
        }
    }

    // Remember -> Both way takes same time
    
    cout<<mi<<endl;
    cout<<t<<endl;
    cout<<mx<<endl;
    cout<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    
    return 0;
    
}
