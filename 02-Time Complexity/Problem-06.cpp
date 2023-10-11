// Fibonacci :

// Constraints are TIGHT , try to find out something from the equation

// LOGIC : Question is simple as it states that given n is also a fibonacci number and duplicates are allowed
//          Answer will be ( 0 , 0 , n )

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    cout << 0 << " " << 0 << " " << n << endl;

    return 0;

}


// ******************************************* REMEMBER ************************************

// ------------------------>> DO NOT WASTE TIME

// The constraints are very tight, If you think I will use the Previous two fib. numbers of n with 0 for sum.. 
// Apko pta hai wo TLE denga and Apko lag rha hai koi aur Optimization nhi kar sakte, that means Apka Logic 
// Wrong hai , DO NOT WASTE TIME BY STUCKING INTO IT, Leave that Logic and TRY TO FIND OUT SOME OTHER LOGIC

// PROBLEM SETTER NEVER MAKE A QUESTION THAT IS NOT DOABLE


//  NOTE : If it was asked that it want Unique Numbers, then -> 

// Run a for loop and find out that till which fibonacci no.s the sum can be upto 10^9, also use dp array to store 
// the Previous sets
 