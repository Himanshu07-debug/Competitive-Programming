// TIME COMPLEXITY ------------------->>

// 1. If all States have same time   --> no. of States * avg transition time per State  .. ( O(n)  --> O(n) --> O(n) --> .... )

// 2. If all States have varying time ---> Sum of transition time for each state i from 1 to n .. (O(n) --> O(n/2) --> O(n/3) --> .....)


// SPACE COMPLEXITY ------------------->>

// No. of states * Space Complexity of each state



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

// Memoization is same as Memorization ....

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


// *************************** ITERATIVE vs RECURSIVE *************************************

// 1. ==>
// In Recursion, For subproblem answers, You calls the function becz you are not sured that the Subproblem is already solved or not...
// Yeah subproblem jab call hota hai, then if(dp[n] != -1) yha pe check hota hai computed hai ki nhi...
// That's why -->  dp[n] = fib2(n-1) + fib2(n-2);

// In Iterative, You make ensured for the state i that all of its required subproblems are already solved ....
// That's why --> dp[i] = dp[i-1] + dp[i-2];
// We are assured that dp[i-1] and dp[i-2] are solved ..


// 2. ==>
// In Memoization, You give any random input and you are assured that you will get an answer becz You handle every edge cases...
// But in Iterative, you cant give Random Input 
// That's why, Recursive DP is EASY.. becz any random I/P can be given , they will be handled...  

// ************************* FLOW OF STATES MATTER while writing the ITERATIVE CODE ****************************************



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

