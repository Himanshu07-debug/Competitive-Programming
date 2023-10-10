// Given 4 numbers A,B,C and D. If A^B > C^D print "YES" otherwise, print "NO".

// Constraint : 1 ≤ A,C ≤ 10^7, 1 ≤ B,D ≤ 10^12

// LOGIC : 
// Brute will not work, Constraint are very Tight

// ***************************************** REMEMBER ****************************************************

// In this type of questions, the main thing we should do it is to reduce the given expression/equation
// Try to observe and analyze it carefully to come out with some logic to reduce it

// IN THIS QUESTION, taking both side log()  will work

#include<bits/stdc++.h>
using namespace std;

int main(){

    long double a,b,c,d;

    cin >> a >> b >> c >> d;

    long double ans1 = b * log10(a);   // When base is not mentioned, 2 is default

    long double ans2 = d * log10(c);

    if(ans1 > ans2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;

}
