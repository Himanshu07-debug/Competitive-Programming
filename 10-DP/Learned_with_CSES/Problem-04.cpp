// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct 
// ordered ways you can produce a money sum x using the available coins.

// For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
// 2+2+5
// 3+3+3
// 2+2+2+3


// Here in Selection of Coins, we have to imposed this 2 condition ------------>
// 1. Koi bhi coin ek contigous subarray me hi le sakte ho
// 2. Agar Coin i pe ho then koi bhi coin before i cant be used


// We want Ordered, We can go with Pick-not pick logic , It will ensure order ...
// ex ==> X reduced to X - c[i] with indx = i   AND     X with indx = i + 1

// Therefore (i,k) -> (i , k - c[i]) {pick}   , (i+1 , k) {not - pick}

// We came up with by drawing the Recursion tree... For single indx, there can be diff sums..


// Defining Our State ---->
// dp[i][k] --> no. of ways to get a sum of k such that all coins from c[i] to c[n] are pickable and all coins before c[i] are non-pickable

// Transition -------->>

// dp[i][k] --> dp[i + 1][k]  +  dp[i][k - c[i]]

// Why we had considered dp[i + 1][k] , dp[i][k - c[i]] as the Subproblems, not Problem ??
// Becz both have a Smaller Space to Solve as Compare to (i,k) , So considering the smaller for the bigger one
// dp[i + 1][k] -> smaller range of pickable coins  ,,   dp[i][k - c[i]]  -> Smaller range of sum to solve



// Smallest Subproblem that can be reduced ---->
// dp[i][0] = 1

// Final SubProblem --->
// Observe The state Defination ===> dp[0][X]  i.e All coins from c[0] are pickable and getting a Sum X

// TIME COMPLEXITY ------------->>
// No. of states => i from 0 to n-1 and K from 0 to X ... Therefore, N * X
// Time on each state --> O(1)
// O(N * X)

// Space Complexity  ------------>>
// O(N * X) 


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


// Memoization ------------------------->>

// For Priyansh Bhaiya Approach 

int f(int i, int sum, vector<vector<int>> &dp, vector<int> &arr){

    if(sum < 0 || i >= arr.size()) return 0;

    if(sum == 0) return 1;

    if(dp[i][sum] != -1) return dp[i][sum];

    int pick = f(i, sum - arr[i], dp,arr);
    int skip = f(i+1, sum, dp, arr);

    dp[i][sum] = (pick + skip)%MOD;

    return dp[i][sum];

}

void solve(){

    int n, x;  cin >> n >> x;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, -1));

    cout << f(0,x,dp,arr) << endl;

}



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

    // Deciding of loops
    // i,k depend on ->
    // i and i + 1  ---> means aage wale state pe dependant .. So we have to go from n-1 to 0
    // k and k - c[i] --> means piche wale state pe dependant .. So we have to go from 0 to X

    // For same indx, there can be different sum

    for(int i=n-1;i>=0;i--){

        for(int sum = 1; sum <= x ; sum++){

            int skip = dp[i+1][sum];
            int pick = 0;
            if(sum - arr[i] >= 0){
                pick = dp[i][sum - arr[i]];
            }

            dp[i][sum] = ( pick + skip )%MOD;

        }

    }

    cout << dp[0][x] << endl;

    // Memoization ---> 
    solve();

    // ******************************** IMP ********************************************************

    // This will be a Top-down Appraoch... But for Iterative , Bottom up is expected by interviewer

    // How to change ???
    
    // Change the dp state --> 
    // dp[i][k] --> no. of ways to get a sum of k such that all coins from c[1] to c[i] are pickable and all coins after c[i] are non-pickable

    // Eg -> X = 9, {2,3,5}
    // Root --> X - 5, X ===> 4 (choosen coin 5) , 9 (not choosen coin 5)
    // First child --> 4 - 5, 4 ===> -1 (choosen coin 5 -> INVALID) , 4 (not choosen coin 5)
    // Second Child --> 9 - 3, 9 ==> 6 (choosen coin 3) , 9 (not choosen coin 3)  

    // Make the Recursion Tree -> 
    // In one child, nth coin is choosen and In other child, nth coin is not choosen

    // (i,k) -> (i, k - c[i]) {pick}  AND  (i-1,k) {not picked}
    // At every indx, we have to only decide either to include the arr[i] in the previous sum or not include..


    // Transition -->
    // dp[i][k] --> dp[i - 1][k]  +  dp[i][k - c[i]]


    // Smallest Subproblem --> dp[i][0] --> 1

    // Biggest Subproblem --> dp[n][x]  ==> Coins from 0 to n are pickable and getting a sum x

    
    // Base case Code.. Same

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

    // Remember , in Recursive Appraoch(Memoization) , as state is dependant on both i, k , Therefore Take both n, x are parameters and do not use
    //            for loop inside... You can use ... But not a Good Approach


    return 0;
}

