// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?

// 1 <= n <= 10^6

// n = 27
// ans -> 5 (27 -> 20 -> 18 -> 10 -> 9 -> 0)


// LOGIC ---->

// We can use the Subproblems to get the Bigger Problem ans..

// Also, there exist Overlapping Subproblems

// 234  -> 232 , 231,  230
// 232 -> 230 , 229 ..., (230 is here also)


// STATE --->
// dp[x] -> Minimal no. of Steps to reduce x to 0

// Transition -> 
// dp[i] -> min{ dp[i - d] } + 1         where d = digits in ith number and d != 0 (becz no effect on current no. after subtraction)


// Smallest Subproblem -> dp[0] = 0

// Final Subproblem -> dp[n]

// Default value -> 1e9


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;




int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n; cin >> n;

    vector<int> dp(n + 1, 1e9);

    dp[0] = 0;


    for(int i=1; i<=n; i++){

        string a = to_string(i);

        for(char c : a){

            int digit = c - '0';

            if(digit != 0){
                dp[i] = min(dp[i] , dp[i - digit] + 1);
            }

        }

    }

    cout << dp[n] << endl;

    return 0;
}

