// You are in a book shop which sells n different books. You know the price and number of pages of each book.
// You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? 
// You can buy each book at most once.

// n = 4 , x = 10
// price = [4 8 5 3]
// pages = [5 12 8 1]

// 1 <= n <= 1000,  1 <= pages[i], price[i] <= 10^3 ,  1 <= x <= 10^5

// Typical Knapsack Problem... 

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
    int n, x;  cin >> n >> x;

    vector<int> val(n) , wt(n);

    for(int i=0;i<n;i++) cin >> wt[i];

    for(int i=0;i<n;i++) cin >> val[i];

    vector<vector<int>> dp(n+1, vector<int> (x + 1, 0));

    for(int i=1;i<=n;i++){

        for(int j=0;j<=x;j++){

            int w = wt[i-1];
            int v = val[i-1];

            // skip the ith element in the sum
            int skip = dp[i-1][j];

            // pick up the ith element in the sum
            int pick = (j >= w ?  v + dp[i-1][j-w] : 0);

            dp[i][j] = max(pick, skip);

        }
        
    }

    cout << dp[n][x] << endl;

    return 0;
}

