// You are given a binary array nums and an integer k.
// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray 
// to 0.
// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.


// Input: nums = [0,1,0], k = 1
// Output: 2
// Explanation: Flip nums[0], then flip nums[2].

// Input: nums = [0,0,0,1,0,1,1,0], k = 3
// Output: 3
// Explanation: 
// Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
// Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
// Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]

// Constraint --> 
// 1 <= nums.length <= 10^5
// 1 <= k <= nums.length

// LOGIC --------------------------------->>>

// Kisi bhi index ko flip even baar kiye to wahi bit rhngi indx pe...
// As we want minimum flips, we will flip a bit atmost once i.e odd no. of time and wo bhi jab 0 encounter hua, uss indx se samne wale window ko..
//  So that aage jaake unn indx ko bhi 1 kar sake


// Intuition  --->
// 1. We will process given array window by window of length k.
// 2. We iterate the given array from left to right and at any point of time, at ith index if we encouter current bit to be 0, 
// then it should flip from 0 to 1. So we have to flip whole window starting from i and ending at i + k - 1.

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// Solution ------------------------------->>>

int finalbit(int bit, int flips)
{
    if (flips % 2 == 0)
        return bit;
    return !bit;
}

int minKBitFlips(vector<int>& v, int y) {
    int n = v.size();
    vector<int> pref(n + 1);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i)
            pref[i] += pref[i - 1];

        if (i < n - y + 1)
        {
            int flips = pref[i];
            int bit = finalbit(v[i], flips);

            if (bit == 1)
                continue;

            ans++;
            pref[i]++;
            pref[i + y]--;
        }
    }

    int cnt = 0;
    vector<int> after(n);
    for (int i = 0; i < n; i++)
    {
        after[i] = finalbit(v[i], pref[i]);
        cnt += (after[i] == 1);
    }
    
    return cnt == n ? ans : -1;
}