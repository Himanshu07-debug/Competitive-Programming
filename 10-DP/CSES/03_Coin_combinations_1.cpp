// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct 
// ways you can produce a money sum x using the available coins.

// n = 3, x = 9
// arr = [2 3 5]
// ==> 8 ways


// Recursion Tree me har ek valid path distinct hi honga in this case ...

// State -> 
// dp[k] => No. of ways of getting the sum k

// Transition -->
// dp[k] = sum of dp[ k - c[i]] , where 0 <= i <= n-1

// Smallest SubProblem That cant be further break-down --->
// dp[0] = 1

// Final Subproblem -->
// dp[x]

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, x;
    cin >> n >> x;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<long long> dp(x+1,0);

    dp[0] = 1;

    for(int i=1;i<=x;i++){

        for(int j=0;j<n;j++){

            if(i - arr[j] >= 0){

                dp[i] = (dp[i] + dp[i-arr[j]])%MOD;

            }

        }

    }

    cout << dp[x] << endl;
    


    return 0;
}