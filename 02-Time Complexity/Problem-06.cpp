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

// ONE MORE EXAMPLE FOR BETTER UNDERSTANDING:

// Let's call a positive integer composite if it has at least one divisor other than 1 and itself. For example: 
// the following numbers are composite: 1024, 4, 6, 9;
// the following numbers are not composite: 13, 1, 2, 3, 37
// You are given a positive integer n. Find two composite integers a,b such that a − b = n
// It can be proven that solution always exists.

// Constraint : 1 <= n <= 10^7  , 2 <= a,b <= 10^9

// Input n=1  ===> 9 8  [ a=9 & b=8 ]
// Input n = 512  ===> 4608 4096

// Composite numbers are NON-PRIME no.s

// Constraints are TIGHT to find a and b ,Observe and  try to reduce the equation a - b = n

// LOGIC : Any no. multiplied with a Composite number is a Composite Number

// REDUCING THE EQUATION -> 9*n - 8*n = n  [ 9*n, 8*n are Composite Numbers becz 9,8 are both composite number ]

// Other numbers are also Possible, but try to figure out the pairs of composite numbers i.e satisfying here


//  NOTE : In the first Example,  If it was asked that it want Unique Numbers, then -> 

// Run a for loop and find out that till which fibonacci no.s the sum can be upto 10^9, also use dp array to store 
// the Previous sets
 