// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
// Each throw produces an outcome between 1 and  6. Print the number of ways modulo 10^9+7.

// For example, if n = 3, there are 4 ways:
// 1+1+1 ,,  1+2  ,, 2+1  ,, 3


// Constraint ==> 1 <= n <= 10^6


// FORM 2 
// all frog jumps, dices roll , where you want a certain a way / sequence of move --> form 2

// dp[i] --> no. of ways to create i

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int dp[1000001];

long long solve(long long s) {
    
    if (s == 0) {
        return 1;
    }
    if (dp[s] != -1) {
        return dp[s];
    }

    long long ans = 0;

    for (long long i = 1; i <= min(6LL, s); i++) {
        ans = (ans + solve(s - i)) % MOD;
    }

    return dp[s] = ans;
}


int main(){

    int n; cin >> n;

    for(int i=0;i<=n;i++){

        // base case
        if(i == 0){
            dp[i] = 1;
        }
        else{
            dp[i] = 0;
            for(int j=1;j<=6;j++){
                if(j <= i) dp[i] = (dp[i] + dp[i-j])%MOD;
            }
        }

    }

    cout << dp[n] << endl;

    return 0;

}