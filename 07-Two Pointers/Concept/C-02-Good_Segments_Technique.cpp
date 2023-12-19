#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// GOOD SEGMENTS TECHNIQUE ( Increasing ) -------------------------------->>

// Learn by Problems

// 1. Find the Longest Subarray with sum <= k

// Appraoch 1 ==> We can do the Binary Search on the All Possible Lengths of the Subarrays i.e 0 to n 
//               [ BINARY SEARCH + SLIDING WINDOW(predicate) ]
//               a) If I know that there exists a Subarray of Length X with sum <= k, then array me [1,..,X-1] length ke bhi subarrays honge with
//               sum <= k , So we can directly move l = X i.e l = mid
//               b) If Array me X length ka Subarray nhi hai with sum <= k, then array me length > X ka bhi koi valid subarray nhi honga becz
//               all the elements in array are Positive
// TIME ---> O(n * logn)

// NOTE --> As all the array elements are Positive, We can use Binary Search .. If negatives are allowed, BS cant be used
//          Ex -> [100, 100, -10, 100, -10] , k = 80  
//          Any Subarray with length 2 and sum <= 80 do not exist, but there exists Subarray with length 3 with sum <= 80 , no Monotonicity



// GOOD SEGMENT TECHNIQUE ------------------->>

// Define the Notion ( IMP to do ) -->
// GOOD SEGMENT --> A segment in the array that satisfies the condition Provided by the Question ...




