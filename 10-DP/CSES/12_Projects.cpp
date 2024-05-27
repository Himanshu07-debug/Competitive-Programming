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

// There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. 
// You can only attend one project during a day. What is the maximum amount of money you can earn?

// 1 <= n <= 2 * 10^5
// 1 <= a_i <= b_i <= 10^9
// 1 <= p_i <= 10^9

// Input:
// 4
// 2 4 4
// 3 6 6
// 6 8 2
// 5 7 3

// Output:
// 7


// LOGIC ---->

// SORT with the ending point
// Yha pe last ending pt ka track rkhe to ho jayega... 
// but in Array description problem, we kept the dimension 2D becz constraint were friendly...
// Here if we go 2D, i.e n^2 --> MLE --> (4 * 1e10)

// We have to do in O(n) or O(nlogn)

// DP me O(nlogn) LIS hi hai, but it will not work here even after you will try to reduce dimension by sorting...
// No increasing length, maximum value we want...


// SORT with starting points....
// Now use our take not-take logic  --> FORM 1
// if I take the current interval, I will take other interval for it with the starting point >= ending pt of current
// otherwise will skip it....


// AWESOME problem to find the maximum profit value in the Disjoint weighted interval scenarios...

#define MP make_pair
const int val = 1000000001; 


void solve(){

    int n; cin >> n;
    pair<int,pair<int,int>> arr[n];

    for(int i=0;i<n;i++){
        int l, r, p;
        cin >> l >> r >> p;

        arr[i] = {l, {r, p}};
    }

    sort(arr, arr + n);

    vector<long long> dp(n+1, 0);

    // FORM 1 --> n to 0
    for(int i=n; i>=0;i--){

        if(i == n){
            // base case
            dp[i] = 0;
        }
        else{

            // skip
            dp[i] = dp[i+1];

            // take

            int nextgreater = arr[i].second.first;  // extracting ending point

            auto indx = upper_bound(arr, arr + n, MP(nextgreater, MP(val, val))) - arr;  
            // do not put 1e9 here in place of INF --> they are floating point values, error

            dp[i] = max(dp[i], arr[i].second.second + dp[indx]);
            // if indx comes n, then also dp vector have 0 there

        }

    }

    cout << dp[0] << endl;
    
}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    solve();

    

    return 0;
}

