// You are in a book shop which sells n different books. You know the price and number of pages of each book.
// You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? 
// You can buy each book at most once.

// n = 4 , x = 10
// price = [4 8 5 3]
// pages = [5 12 8 1]

// 1 <= n <= 1000,  1 <= pages[i], price[i] <= 10^3 ,  1 <= x <= 10^5


// This is same as the Knapsack Problem.. Only we cant take elements fractionally here....

// We know the Greedy Approach (Sorting wla) ..

// Lets see how to Knapsack by using DP ================>>>

// Here We can try out all possibilities of selection of items... i.e Generating all possible subsets...
// Yes, Recursion wla --> Pick , not Pick Logic...

// dp[i][x] = max. value that we can be get from first i elements, such that x weight is allowed to be used

// Transition --> 
// dp[i][k]  --> max( dp[i-1][k]    , val[i] + dp[i-1][k - wt[i]] )
//                   { not picked }       { picked }    


// Smallest Subproblem --> dp[0][k] = 0   where k can by any price ( 0 <= k <= x )

// Final Subproblem --> dp[n][x]


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


// Memoization --------------------->

int f(int i, int x, vector<int>&val, vector<int> &wt, vector<vector<int>> &dp){

    if(i < 0) return 0;

    if(dp[i][x] != -1) return dp[i][x];

    int pick = 0;
    if(x >= wt[i]) pick = val[i] + f(i-1, x-wt[i], val, wt, dp);

    int skip = f(i-1, x, val, wt, dp);

    return dp[i][x] = max(pick, skip);

}

void solve(){

    int n, x;  cin >> n >> x;

    vector<int> val(n) , wt(n);

    for(int i=0;i<n;i++) cin >> wt[i];

    for(int i=0;i<n;i++) cin >> val[i];

    vector<vector<int>> dp(n, vector<int> (x + 1, -1));

    cout << f(n-1, x, val, wt, dp) << endl;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Memoization -->
    solve();

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


    // SPACE OPTIMIZATION ------------------------------>>>

    // Each row i.e index level is dependant on previous row for its value... We can do space optimization .. same as Problem - 07
    // first prev(x sized vector) row will be all fill with 0
    // Now current row vector in loops and then assign to prev

    // space reduced from O(n * x) -> O(x)

    return 0;
}

