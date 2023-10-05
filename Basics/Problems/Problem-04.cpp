// Given a mathematical expression. The expression will be one of the following expressions:
// A + B = C, A - B = C and A * B = C
// where A, B, C are three numbers, S is the sign between A and B, and Q the '=' sign

// Print "Yes" If the expression is Right , Otherwise print the right answer of the expression.

// Constraint: 0 ≤  A, B  ≤ 100 , - 10^5  ≤  C  ≤  10^5

// INPUT :  5 + 10 = 15                           Output : Yes
// INPUT :  2 * 10 = 19                           Output : 20

#include<bits/stdc++.h>
using namespace std;

int main(){

    // See the Question Properly, we misread the question and consider whole input as a String and done in a more 
    // Complex way

    int a,b,c;

    char c1, c2;

    cin >> a >> c1 >> b >> c2 >> c;

    if(c1=='+'){
        if(a+b==c) cout<<"Yes";
        else cout<< a+b;
    }
    else if(c1=='-'){
        if(a-b==c) cout<<"Yes";
        else cout<< a-b;
    }
    else if(c1=='*'){
        if(a*b==c) cout<<"Yes";
        else cout<< a*b;
    }

    return 0;
}