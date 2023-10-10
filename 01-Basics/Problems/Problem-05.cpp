// Given a number N. Determine whether N is float number or integer number.

// Input : 234.000                             Output : int 234
// Input : 534.958                             Output : float 534 0.958


#include<bits/stdc++.h>
using namespace std;

int main(){

    double n;

    cin>>n;

    if( ( n - (int)n) == 0 ) {             // ceil(n) == floor(n)
        cout << "int" << n << endl;
    }
    else{
        cout << "float" <<" "<< (int)n <<" "<< n - (int)n << endl;   // floor(n) && n - floor(n)
    }

    return 0;
}