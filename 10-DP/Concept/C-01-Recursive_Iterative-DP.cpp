// Agar Recursion TLE de rha then before thinking for another Approach ---->

// See that is Your Recursion Tree have Overlapping SubProblems, If YES , DP can help

// Inorder to see Overlapping Subproblems, Observe the Recursion Tree of FIB1ONACCI ... fib1(3) , etc baar-baar call ho rhe hai.. 
// Why to Do again Computation if we had done Previously...


// MEMOIZATION is simply storing the nodes in the Recursive tree that we have already Computed previously...

// We can Use Array and Map to store the subproblems in key-value pair...

// NOTE --> Figure out that is there something that uniquely determines each Sub-problems .... So You have a Unique Key .. You can store

// If Unique Key is an Integer, then only Array can help as they have Indexes , BUT
// MAP can store KEY of any datatype... MAP is the Superset for Storing values


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


// RECURSION ----------------------->>

int fib1(int n){
    
    if(n <= 2)  return 1;

    return fib1(n-1) + fib1(n-2);

}


// Recursive DP ( Memoization ) --------------->>

vector<int> dp(100,-1);

int fib2(int n){

    if(n <= 2)  return 1;

    if(dp[n] != -1)   return dp[n];

    dp[n] = fib2(n-1) + fib2(n-2);

    return dp[n];

}


// Iterative DP ( TABULATION ) ---------------------->>

int fib3(int n){

    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;

}


void solve(){

    // Your code here

    int n;
    cin >> n;

    cout << fib1(n) << endl;
    cout << fib2(n) << endl;
    

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
    }
    
    return 0;

}

