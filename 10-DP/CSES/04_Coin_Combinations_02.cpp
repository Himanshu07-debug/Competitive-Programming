// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct 
// ordered ways you can produce a money sum x using the available coins.

// For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
// 2+2+5
// 3+3+3
// 2+2+2+3


// FORM 2

// We want Ordered, We have to go with knapsack logic of FORM 1 , It will ensure order ... 

// this are the cases, where FORM 2 is used with overlap FORM 1 in logic



#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n, x;  cin >> n >> x;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    // Base case 
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=n; i++){

        for(int sum = 1; sum <= x ; sum++){

            int skip = 0;
            if(i - 1 >= 0) skip = dp[i-1][sum];
            
            int pick = 0;
            if(sum - arr[i] >= 0) pick = dp[i][sum - arr[i]];

            dp[i][sum] = ( pick + skip )%MOD;

        }

    }

    cout << dp[n][x] << endl;


    // see this, more optimized --> we can use FORM 2 and directing my sum with indexes

    long long dp1[1000001];

	dp1[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int sum = 0; sum <= x; sum++) {
			if (sum - arr[i - 1] >= 0) {  // prevent out of bounds cases
				dp1[sum] += dp1[sum - arr[i - 1]];
				dp1[sum] %= MOD;
			}
		}
	}
	cout << dp1[x] << '\n';


    return 0;
}

