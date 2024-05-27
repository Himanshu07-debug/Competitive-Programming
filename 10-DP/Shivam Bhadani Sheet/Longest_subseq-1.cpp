#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between 
// adjacent elements is 1.

// n = 7
// a[] = {10, 9, 4, 5, 4, 8, 6}
// Output: 
// 3
// Explaination: 
// The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have a absolute difference of 1.
// No valid subsequence of greater length could be formed.

// NAIVE --> LIS .. O(n^2)

// BETTER --> 
// No need of for loop.. We can get the query answer in O(1) using HashMap

int longestSubseq(int n, const vector<int> &a){
    
    map<int, int> dp;
    int ans = 1;

    for (int i = 0; i < n; i++)
    {

        // for the initial case.. all of them will be must of len 1
        dp[a[i]] = max(dp[a[i]], 1);
        
        if (dp.count(a[i] - 1)) dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);

        if (dp.count(a[i] + 1)) dp[a[i]] = max(dp[a[i]], dp[a[i] + 1] + 1);

        ans = max(ans, dp[a[i]]);

    }

    return ans;

}

// in O(n) + O(n)