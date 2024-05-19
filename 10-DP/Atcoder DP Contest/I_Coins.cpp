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


// Let N be a positive odd number. There are N coins, numbered 1,2,…,N. For each i ( 1≤i≤N), when Coin i is tossed, it comes up 
// heads with probability p i ​ and tails with probability 1−p i ​ . Taro has tossed all the N coins. Find the probability of having 
// more heads than tails.

// n = 3
// Head probability --> 0.30 0.60 0.80
// answer --> 
// The probability of each case where we have more heads than tails is as follows:

// The probability of having (Coin1,Coin2,Coin3)=(Head,Head,Head) is 0.3×0.6×0.8=0.144;
// The probability of having (Coin1,Coin2,Coin3)=(Tail,Head,Head) is  0.7×0.6×0.8=0.336;
// The probability of having (Coin1,Coin2,Coin3)=(Head,Tail,Head) is 0.3×0.4×0.8=0.096;
// The probability of having (Coin1,Coin2,Coin3)=(Head,Head,Tail) is 0.3×0.6×0.2=0.036.

// Thus, the probability of having more heads than tails is 0.144 + 0.336 + 0.096 + 0.036 = 0.612.

// FORM ?? --> form 1 ( for each day, choice to make )

// state -> dp(i, head_count_till)

// transition --> either to take tail or head on the ith day


int n, m;

double dp[10001][10001];
vector<double> p(n);

double rec(int i, int head_count){

    if(i == n){
        if(head_count > (n - head_count)) return 1;
        else return 0;   // make the whole probabilty as 0
    }

    if(dp[i][head_count] != -1.01) return dp[i][head_count];

    double h = p[i]*rec(i+1, head_count + 1);

    double t = (1 - p[i])*rec(i+1, head_count);

    return dp[i][head_count] = h + t;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    memset(dp, -1.01, sizeof(dp));

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    cout << fixed << setprecision(10) << rec(0, 0) << endl;
    

    return 0;
}

