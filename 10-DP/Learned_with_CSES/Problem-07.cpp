// Consider an n * n grid whose squares may have traps. It is not allowed to move to a square with a trap.
// Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.

// Constraints -> 1 <= n <= 1000

// 4
// ....
// .*..
// ...*         ( . -> empty cell, * -> obstacle)
// *...
// Ans -> 4


// We have learnt this variation in our Concept Folder of Grids..

// dp[i][j] -> no. of ways to go from (i,j) to (n-1,m-1)

// Transition -> dp[i][j] = dp[i+1][j] + dp[i][j+1]

// Base case -> dp[n-1][m-1] -> 1 (if no obstacle) , 0 (if obstacle)

// Final Subproblem -> dp[0][0] ( no. of ways to go from (0,0) to (n-1,m-1) )


// TIME --> O(n * n)

// SPACE --> O( n * n )


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
    int n; cin >> n;

    string arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (n+1));

    // Base case
    if(arr[n-1][n-1] == '.')  dp[n-1][n-1] = 1;
    else dp[n-1][n-1] = 0;

    for(int i=n-1;i>=0;i--){

        for(int j=n-1;j>=0;j--){

            // You cant avoid this in for loop
            if(i == n-1 && j == n-1)  continue;

            if(arr[i][j] == '*'){
                dp[i][j] = 0;
            }
            else{

                int ans1 = 0, ans2 = 0;

                if( i + 1 < n ){
                    ans1 = dp[i+1][j];
                }
                
                if(j + 1 < n){
                    ans2 = dp[i][j+1];
                }

                dp[i][j] = (ans1 + ans2) % MOD;

            }

        }

    }

    cout << dp[0][0] << endl;



    // SPACE OPTIMIZATION ---------------------->>>

    // Our Current row is dependant only on the next immediate row ..
    // See the Transition ...

    // Same like Coin Combinations-2 (Problem - 04) Space Optimized Appraoch

    vector<int> nextRow(n);

    if(arr[n-1][n-1] == '.') arr[n-1][n-1] = 1;
    else arr[n-1][n-1] = 0;

    for(int i=n-2;i>=0;i--){

        if(arr[n-1][i] == '.'){
            nextRow[i] = nextRow[i+1];
        }
        else{
            nextRow[i] = 0;
        }

    } 

    for(int i=n-2;i>=0;i--){

        vector<int> currentRow(n);   // dp[i][j]

        // nextRow[j] = dp[i+1][j]
 
        for(int j=n-1;j>=0;j--){

            if(i == n-1 && j == n-1)  continue;

            if(arr[i][j] == '*'){
                currentRow[j] = 0;
            }
            else{

                int ans1 = 0, ans2 = 0;

                if( i + 1 < n ){
                    ans1 = nextRow[j];
                }
                
                if(j + 1 < n){
                    ans2 = currentRow[j+1];
                }

                currentRow[j] = (ans1 + ans2) % MOD;

            }

        }

        nextRow = currentRow;


    }

    

    return 0;
}

