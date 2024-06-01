// Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.

// Return the total count modulo 1e9+7.

// s1 = geeksforgeeks
// s2 = gks
// Output:
// 4
// Explaination: 
// We can pick characters from s1 as a subsequence from indices {0,3,4}, {0,3,12}, {0,11,12} and {8,11,12}.So total 4 subsequences of s1
// that are equal to s2.

// 1 ≤ n, m ≤ 500

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int dp[505][505];

int rec(int i, int j, string &s1, string &s2){

    if(j == s2.size()) return 1;

    if(i == s1.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){

        // 2 choices --> either to match it or leave it
        // Form 3 string matching pattern
        return dp[i][j] = (rec(i+1, j+1, s1, s2) + rec(i+1, j, s1, s2))%MOD;

    }
    else{

        return dp[i][j] = rec(i+1, j, s1, s2);

    }

}

int countWays(string s1, string s2) {

    memset(dp, -1, sizeof(dp));

    return rec(0, 0, s1, s2);

}