// Consider a money system consisting of n coins. Each coin has a positive distinct integer value. Your task is to produce a sum of 
// money X using the available coins in such a way that the number of coins is minimal.
// For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

// CONSTRAINT ---> 1 <= n < = 100, 1 <= X, arr[i] <= 10^6


// LOGIC --->

// Solving sum < X will be easier than Solving for X ... Therefore We can think for SubProblems

// X can be break down as X - c1, X - c2, ......, X - c[n]

// If We know the No. of ways of Forming sun = X - c1, then we can get X by just adding c1 to it ...
// Similarly for X - c2, X - c3 .......

// Defining the STATE --> dp[K] = minimum no. of coins required to construct a Sum of K

// NOTE --> In Previous Problem, We aim to get all no. of ways so we were adding all the Subproblems, But in this Question, We want that 
//          subproblem that had consumed minimal no. of coins... 
//          Here, we have to choose a Best One out of All subProblems ....

// Therefore TRANSITION WILL BE --> dp[K] = min( dp[K - c[i] ] ) + 1    ....   where 1 <= i <= n  

// NOTE -> + 1 becz You have to add one coin to the Subproblems to get the Sum as X ( X - C1 + C1 ==> X )

// Smallest Subproblem -> dp[0] = 0

// Biggest SubProblem --> dp[X]


// TIME COMPLEXITY ---> No. of States * avg. time taken by each state ==> O(X) * O(N)  ==> O(NX)

// SPACE COMPLEXITY --> No. of States => O(X)

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
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

    return 0;
}