// There are n models in the shop numbered from 1 to n , with sizes s1,s2,…,sn . Orac will buy some of the models and will arrange them in 
// the order of increasing numbers (i.e. indices, but not sizes). 
// Orac thinks that the obtained arrangement is beatiful, if for any two adjacent models with indices i and j (note that i < j , because Orac 
// arranged them properly), j is divisible by i and si < sj .
// Orac wants to know the maximum number of models that he can buy..

// 5 3 4 6 --> 2 
// Orac can buy models with indices 2 and 4.

// 1 ≤ n ≤ 10^5

// STATE --->
// dp[i] ==> length of the longest beautiful sequence ending at index i.

// 1 2 3 4 5 6 
// 1 -> 1 2 3 4 5 6 (kisi bhi ek ke sath bana sakta hai)
// 2 -> 2 4 6
// 3 -> 3 6

// TRANSITION -->
// dp[i] = max( dp[j] + 1 )  .. where j -> all factors of i and s[j] < s[i]


// Base Case -->
// dp[1] = 1      ( 1 - based indexing )

// Final Subproblem -->
// Ans = max(dp[i])  ( all indexes in array )


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



void solve() {

    // Your Code here
    int n; cin >> n;

    vector<int> arr(n+1);

    for(int i=1;i<=n;i++) cin >> arr[i];

    vector<int> dp(n+1);

    dp[1] = 1;

    long long ans = -INF;

    for(int i=2;i<=n;i++){

        dp[i] = 1;      // Each sequence must be of length 1

        // Going through all the factors of i
        for(int j=1; j*j <= i ; j++){

            if(i % j == 0){

                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                if(j!=1 && arr[i] > arr[i/j]){
                    dp[i] = max(dp[i], dp[i/j] + 1);
                }

            }

        }

        ans = max(ans, dp[i] * 1ll);

    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}











