#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


// RECURSIVE ( MEMOIZATION ) --->

int fun(vector<int> &arr,int n, vector<int> &dp, int X){

    if(X < 0)  return 0;

    if(X == 0) return 1;

    if(dp[X] != 0)  return dp[X];

    for(int i=0;i<n;i++){
        dp[X] = (dp[X] + fun(arr,n,dp,X - arr[i]))%MOD;
    }

    return dp[X];

}



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n,x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0;i<n;i++)  cin >> arr[i];

    vector<int> dp(x + 1, 0);
    // dp[i] -> minimum coins to generate a sum of i

    // Base case -> 
    // dp[0] = 1;

    // for(int i = 1;i <= x; i++){
    //     for(int j=0;j<n;j++){
    //         if(i - arr[j] >=0){
    //             dp[i] = (dp[i] + dp[i - arr[j]])%MOD;
    //         }
    //     }
    // }

    
    // // Final SubProblem
    // cout << dp[x] << endl;

    int ans = fun(arr,n, dp, x);

    cout << ans << endl;


    return 0;
}