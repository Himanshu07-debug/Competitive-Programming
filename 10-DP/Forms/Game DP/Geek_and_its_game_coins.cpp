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

// Given three numbers n, x, and y, Geek and his friend are playing a coin game. In the beginning, there are n coins. In each move, 
// a player can pick x, y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to
//  determine whether Geek will win the game or not if both players play optimally.

// Input: 
// n = 5
// x = 3
// y = 4
// Output: 
// 1
// Explanation:
// There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. Geek can win by picking 3 coins in first chance. 
// Now 2 coins will be left so his friend will pick one coin and now Geek can win by picking the last coin.


// GAME DP..............

int dp[100005];

int rec(int n, int x, int y){

    // last move .. 
    if( n == 1 || n == x || n == y ){
        return dp[n] = 1;
    }

    if(dp[n] != -1) return dp[n];
    
    // let the opponent will win
    int c1 = 1, c2 = 1, c3 = 1;

    if(n >= x) c1 = rec(n-x, x, y);

    if(n >= y) c2 = rec(n-y, x, y);

    if(n >= 1) c3 = rec(n-1, x, y);

    if(c1 == 0 || c2 == 0 || c3 == 0) return dp[n] = 1;

    return dp[n] = 0;

}

int findWinner(int n, int x, int y) {

    memset(dp, -1, sizeof(dp));

    return rec(n, x, y);
    
}

// TIME --> O(n)


// One more way of solving... Keeping track of the height of our Recursion Tree..... We can decide.. who had made the last move...


int solve(int n, int x, int y, vector<int> &dp){

    if (n == 0) return 0;

    if (dp[n] != -1)  return dp[n];

    // height as zero for the current node
    int take1 = 0, take2 = 0, take3 = 0;

    if (n >= x) take1 = 1 + solve(n - x, x, y, dp);

    if (n >= y) take2 = 1 + solve(n - y, x, y, dp);

    take3 = 1 + solve(n - 1, x, y, dp);

    // if height from this node to the last node is odd. this means the current node player had made the last move...
    // Mere niche even height.. maine usme +1 add kiya... odd ho gyi
    if (take1 % 2 == 1 || take2 % 2 == 1 || take3 % 2 == 1) return dp[n] = 1;

    return dp[n] = 0;

}

int findWinner(int n, int x, int y){

    vector<int> dp(n + 1, -1);

    return solve(n, x, y, dp);

}