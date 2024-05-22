#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// Consider a money system consisting of n coins. Each coin has a positive distinct integer value. Your task is to produce a sum of 
// money X using the available coins in such a way that the number of coins is minimal.
// For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

// CONSTRAINT ---> 1 <= n < = 100, 1 <= X, arr[i] <= 10^6

// LOGIC -------------------->>>

// FORM 2

// NOTE 1 --> CSES ke starting 4 problems are just like climbing stairs, frog jump in min. no. of steps.... Keep this standard problems in mind to
//          detect such FORM 2 problems

// PATH / SEQUENCE / MOVES / STEPS ---> always FORM 2

// NOTE 2 --> FORM 1 are just like ordered ways --> 0th indx le liye then agar usko skip kiye to dobara nhi .. 
//           but if in question 2 + 5 + 2 and 2 + 2 + 5 are considered different --> pick/not pick will give wrong answer here...
// REMEMBER --> if FORM 1 can be applied on the problem but unordered ways are allowed --> FORM 2 is optimized in space and best.. use that
//              (ex --> in 1st and this problem, you can go with knapsack but not optimized)

// Now if you are saying that i will keep dp(i, sum) --> space 1e8 (constraint) ==> TLE

// Observe, no need of indx, dp(sum) is enough [ each time hum sum ko array ke coins se subtract kar sakte hai ]

// just like BFS --> the one with min coints is my answer

// dp(sum) --> min( dp(sum - arr[i]) + 1 ) 

// dp[0] = 0



int main(){

    int n,x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0;i<n;i++)  cin >> arr[i];

    vector<int> dp(x + 1, 1e9);
    // dp[i] -> minimum coins to generate a sum of i

    // Base case -> 
    dp[0] = 0;

    for(int i = 1;i <= x; i++){
        for(int j=0;j<n;j++){
            if(i - arr[j] >=0){
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    
    // Final SubProblem
    cout << (dp[x] < 1e9 ? dp[x] : -1 ) << endl;

}