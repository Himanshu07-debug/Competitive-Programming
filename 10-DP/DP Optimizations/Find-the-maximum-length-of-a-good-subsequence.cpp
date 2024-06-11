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

// You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i 
// in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
// Return the maximum possible length of a good subsequence of nums.

// Input: nums = [1,2,1,1,3], k = 2
// Output: 4

// Explanation:
// The maximum length subsequence is [1,2,1,1].

// 1 <= nums.length <= 500
// 1 <= nums[i] <= 10^9
// 0 <= k <= min(nums.length, 25)


// SUBSEQUENCE --->  FORM 2
// eg --> LIS, FROG JUMP, CLIMBING STAIRS...


// State --> dp(i, last, j) = Max length subseq in nums[0 .. i] ending at i taken last element of last indx and with j mismatch 

// dp(i, last, j) --> 
// skip --> dp(i-1, last, j)
// take --> if(arr[i] == arr[last]) 1 + dp(i-1, i, j)     
//          if(arr[i] != arr[last]) 1 + dp(i-1, i, j-1)     , we only call valid calls, therefore j > 0 for this call


// TIME --> O(n*n*k)
// SPACE --> O(n*n*k)

class Solution {
public:
   int dp[501][501][26];

int rec(int i, int last, int k, vector<int> &arr){

    if(i < 0) return 0;

    if(dp[i][last][k] != -1) return dp[i][last][k];

    int c1 = 0;

    if(last == 500 || arr[i] == arr[last]) c1 = 1 + rec(i-1, i, k, arr);
    else if(arr[i] != arr[last] && k > 0) c1 = 1 + rec(i-1, i, k - 1, arr);

    int c2 = rec(i-1, last, k, arr);

    return dp[i][last][k] = max(c1, c2);

}


int maximumLength(vector<int>& arr, int k) {

    memset(dp, -1, sizeof(dp));

    int n = arr.size();

    return rec(n-1, 500, k, arr);

        
}
};


// NEW CONSTRAINT ------------------------------>>>

// 1 <= nums.length <= 5 * 10^3
// 1 <= nums[i] <= 10^9
// 0 <= k <= min(50, nums.length)


// OPTIMIZE --------------------------------->>>

// Yeah Question leetcode contest me aaya tha and we were known that ki isse optimize krna padega..

// Always try to keep less things in State and more thing or loops in Transition....
// REMEMBER --> State Optimization is HARD.. Sometimes it happens with Space Optimization... BUT Transition optimization is something that can
//              thought for optimization 

// MISTAKE YOU DID ??
// Apko pta tha Optimize krna padega... But you keep it Straight forward in your First logic.. n^2*k states banake .. yeah pakka MLE denga
// Apko states kam rkhne ka try krna tha and Transition ko TDS rkhna tha...

// However having 3 parameters in state was straightforward .. and easy to guess...

// lets make transition TDS and state with less parameters ....


// FORM 2 only

// last can be removed... i index ke liye 0 --> i-1 last ho skte hai.. loop chala denge for each state
// dp(i, j) --> Max len subseq in arr[0...i] ending at i with j mismatch


// dp(i, k) --> if(arr[i] == arr[last]) 1 + dp(last, k)  otherwise 1 + dp(last, k-1)      ..  0 <= last < i


// TIME --> O(n^2 * k)
// SPACE --> O(n * k)


int dp[5001][52];

int rec(int i, int j, vector<int> &arr){

    if(i < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // You can freely take teh current element
    int ans = 1;

    for(int last = 0; last < i; last++){

        if(arr[i] == arr[last]) ans = max(ans, 1 + rec(last, j, arr));
        else{
            if(j > 0) ans = max(ans, 1 + rec(last, j-1, arr));
        }

    }

    return dp[i][j] = ans;

}

int maximumLength(vector<int>& arr, int k) {

    memset(dp, -1, sizeof(dp));

    int n = arr.size();

    // REMEMBER --> Whenever You use ending Form i.e FORM 2 ... answer koi na koi indx pe jaake end krnga... 
    //              So we find out the Final answer by making the subseq ending at each indx 

    int res = 0;

    for(int i=0;i<n;i++){
        res = max(res, rec(i, k, arr));
    }

    return res;


}

// NOTE --> This is the more General Template of form 2 .. using for loop to get the prev ones.. not by state.. See frog jump, LIS, humne state
//          me nhi liye kuch bhi...
//          first appraoch aapne straight forward kar diye and isliye wo simple take-skip logic jo FORM1 ka hai usase bhi chal gya...



// STEP 5 ---> LETS THINK FOR OPTIMIZATIONS FOR NEW CONSTRAINTS -------------->>


// Whenever You have to Optimize, mark this Simple trick.. Try to observe the Dependencies of my current state.. 
// Find that dependency window for the current state... 

// Grid banalo n * k , transitions dekho.. and dekho region where we are dependent...

// dp(i, k) --> if(arr[i] == arr[last]) 1 + dp(last, k)         ..  0 <= last < i
//               otherwise 1 + dp(last, k-1)        

// We want max
 
// for a state, I am dependent on only 2 columns, k-1 and k wla ... 
// k-1 se muje max chahiye.. Lekin kth column se muje wahi elements consider krne hai jha pe value mere equal ho and unme se bhi muje max chahiye
// len ...
// Something like LIS ho rha hai idhar kth col ke liye.. But as a Coder, We have not stick to the standard ones from the start, use Observations...


// Move Your code to iterative so that you can optimize it... 
// ITERATIVE --> OPTIMIZATIONS..
// Simple way


// SIMPLE ITERATIVE ONE -->

int dp[5001][52];

int maximumLength(vector<int>& arr, int k) {

    memset(dp, 0, sizeof(dp));

    int n = arr.size();


    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){

            int ans = 1;

            for(int last = 0; last < i; last++){

                if(arr[i] == arr[last]) ans = max(ans, 1 + dp[last][j]);
                else{
                    if(j > 0) ans = max(ans, 1 + dp[last][j-1]);
                }

            }

            dp[i][j] = ans;

        }
    }

    int res = 0;

    for(int i=0;i<n;i++){
        res = max(res, dp[i][k]);
    }

    return res;

}


// TAKING MAP to get the max of similar elements of the current row
// Also will take max to get the max of elements till last col

// Will move j * i here, as we want to traverse array for each j

int dp[5001][52];

int maximumLength(vector<int>& arr, int k) {

    memset(dp, 0, sizeof(dp));

    int n = arr.size();

    for(int j=0;j<=k;j++){

        map<int,int> same_val_best;
        int max_dp_i_j_1 = 0;

        for(int i=0;i<n;i++){

            int ans = 1;

            ans = max(ans, 1 + same_val_best[arr[i]]);

            if(j > 0) ans = max(ans, 1 + max_dp_i_j_1);

            dp[i][j] = ans;

            same_val_best[arr[i]] = max(same_val_best[arr[i]], ans);

            if(j > 0) max_dp_i_j_1 = max(max_dp_i_j_1, dp[i][j-1]);

        }
    }

    int res = 0;

    for(int i=0;i<n;i++){
        res = max(res, dp[i][k]);
    }

    return res;

}

