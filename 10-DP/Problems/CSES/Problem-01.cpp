// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
// Each throw produces an outcome between 1 and  6. Print the number of ways modulo 10^9+7.

// For example, if n=3, there are 4 ways:
// 1+1+1 ,,  1+2  ,, 2+1  ,, 3


// Constraint ==> 1 <= n <= 10^6


// ******************************************* LOGIC ************************************************************

// STEP - 1 ==> Thinking About Subproblem --------------------------------------------> 

// Suppose n = 10, n = 6 , kaunsa easy honga solve karna, n = 6, n = 2 will be more easier
// Therefore, Solving Subproblems will be easy


// STEP - 2 ==> Breaking into SubProblems --------------------------------------------> 

// 6 possibilities of dice .. So N can be divide as N - 1 , N - 2, ......., N - 6 in the RECURSION TREE


// STEP - 3 ==> Thinking About Relation And Building the DP solution --------------------------------------------> 

// Agar apko N - 1 tk pahuchane ka no.of ways pta hai let X, Aur agar merko N pe jaana hai wha se in One go, Total No. of ways will be X i.e
// N - 1 tk pahuchane ke X paths me ek common line append ho gyi .. So X paths rhe

// Similar Case for all N - 2, ......., N - 6

// MOST IMP --> Define the state ( Write it in your Book ) 
// dp[K] = no. of ways to get a sum of K

// TRANSITION --> dp[K] = SUM of dp[K - i] for 1 <= i <= 6


// STEP - 4 ===> Smallest Subproblem That I can solve  --------------------------------------------> 

// dp[0] =  1  ==> [ BASE CASE ]


// STEP - 5 ===> Biggest PROBLEM to solve ( FINAL SubProblem )  --------------------------------------------> 

// dp[N] = no. of ways to get sum of N




// ************************************** What Happens if we Reverse the IDEA ????


// IDEA --> Apne pass sum K hai and We have to reach to N

// Breaking will be K into K + 1, K + 2, ..... K + 6

// Relation will be K + 1 jaane ke ways X then wha se K tk jaane ke ways X honge
// Define the state  ===> dp[K] = no. of ways to reach to N starting from K

// TRANSITION --> dp[K] = SUM of dp[K + i] for 1 <= i <= 6

// SMALLEST SUB-PROBLEM --> dp[N]
// BIGGEST SUB-PROBLEM -->  dp[0]



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


// APPROACH - 1 ===>
void solve1(){

    // Your code here
    int n; cin >> n;

    // state => dp[i] -> Number of ways to get a sum of i
    vector<int> dp(n + 1);

    // Base Case
    dp[0] = 1;

    // You are finding ans by using Previous values
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i - j >=0){
                // transition
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    // Final SubProblem
    cout << dp[n] << endl;

}

// APPROACH - 2 ===>
void solve2(){

    int n;
    cin >> n;

    vector<int> dp(n + 1);

    // base case
    dp[n] = 1;
    
    // Hume further values lag rhi hai for finding ans
    for(int i = n - 1; i >=0 ;i++){
        for(int j=1;j<=6;j++){
            if(i+j <= n){
                // transition
                dp[i] = (dp[i] + dp[i+j])%MOD;
            }
        }
    }

    // Final
    cout << dp[0] << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve1();
        solve2();
    }
    
    return 0;

}