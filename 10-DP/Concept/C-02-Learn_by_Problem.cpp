// Covered After DP-2
// CSES problem -> REMOVAL GAME 



// One thing is very Clear.. You can't go with GREEDY .. Sample Testcase Proves this thing .... 
// We have to try out all Possibilities of elements picking .. 


// STATE ---------------->
// dp[i][j] = maximum score that current player can get when the array from indx i to j is remaining...



// TRANSITION ------------------------->

// See from starting.. Player 1 will start ...
// (i,j) --> If Player 1 picked first element -> arr[i] + dp[i+1][j] 
// WRONG , becz See the State Defination, in (i+1,j) -> Player 2 turn will be there and dp[i+1][j] -> max. score that player 2 can get...
// Hum isko Player 1 me add nhi kar sakte .... 
// Therefore, we will consider sum of the subarray(i+1,j) and usase subtract kar denge dp[i+1][j] ( player 2 ne jo elements pick kiye the )

// Same will happen Jab player 2 ka turn honga, uske liye player 1 ka subtract kronge.. Its all Going Recursively.. Apna State defination fair hai
// dono ke liye


// Therefore , Transition --->

// If (i,j) --> If player picked first element -> arr[i] + sum[i+1][j] - dp[i+1][j]
//          --> If player picked last element -> arr[j] + sum[i][j-1] - dp[i][j-1]

// dp[i][j] -> max( arr[i] + sum[i+1][j] - dp[i+1][j] , arr[j] + sum[i][j-1] - dp[i][j-1] )



// Smallest Subproblem --> When (i == j) -> dp[i][j] = arr[i]

// Final Subproblem --> dp[0][n-1] ... ( Player 1 ka chahiye Q.s ko and Player 1 hi start krnga.. So uske liye array remaining pura rhnga)

// Default value -> max/min value possible are -5 * 1e12 to 5 * 1e12 ... Use "1e15"



// ************************************ NOTE ****************************************************

// Observe, State Defination is V.V.IMP... Yeah Pura Logic Build hua only becz of States.. you have to be very Clear.. State with parameters
// Kya represent kar rhe hai... 
// We do not go under the constraint that which Player is Picking becz it can get more Complicated.. extra Parameter Handle krna... Our State was
// fair for both Players....


// FOLLOW-UP Question --> Player 2 ka max. score ---> sum[0][n-1] - dp[0][n-1] ... ( POWER OF STATE DEFINATION )

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
    
    

    return 0;
}

