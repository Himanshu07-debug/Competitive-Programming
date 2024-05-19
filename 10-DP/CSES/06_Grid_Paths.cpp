// Consider an n * n grid whose squares may have traps. It is not allowed to move to a square with a trap.
// Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.

// Constraints -> 1 <= n <= 1000

// 4
// ....
// .*..
// ...*         ( . -> empty cell, * -> obstacle)
// *...
// Ans -> 4


// CONCEPT --->

// Form 2 ... Can solve easily....

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSp;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
	// Write your code here.

	vector<vector<int>> dp(n, vector<int> (m, 0));

	dp[0][0] = 1;

	for(int i=0;i<n;i++){
		for(int j = 0; j< m ;j++){

			if( i == 0 && j == 0) continue;

            if(mat[i][j] == -1) continue;

            int up = 0;
            int left = 0;

			if(i - 1 >= 0) up = dp[i-1][j];

			if(j - 1 >= 0) left = dp[i][j-1];

            dp[i][j] = (up + left) % MOD;

		}
	}

	return dp[n-1][m-1];

}