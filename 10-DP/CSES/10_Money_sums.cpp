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

// You have n coins with certain values. Your task is to find all money sums you can create using these coins.

// 4
// 4 2 5 2

// Output:
// 9
// 2 4 5 6 7 8 9 11 13



// LOGIC ------------------------------------>>>

// We can do it easily but with returntype as void.. 
// becz all of our subsets sum are generated at the base case of the tree


// but with dp, we have to store, for that we require return type to store the current state... 


// we will take the bool datatype in DP under consideration....

// also it seems FORM 1 , as we dont know final sum, You cant have a base case, like dp[X] = .... 
// chnage the state defination in FORM 1 to FORM 2 ....

// as we can write the base case for FORM 2....
// (x == 0) return 1;


// At any moment, we have 2 choices, pick or not pick....

// dp[sum] = dp[sum - arr[i]] | dp[sum] 
//             pick             skip

// just apply this, all 

// so dp[sum] = 1  if dp[sum - arr[i]] = 1

// The code helps in finding all possible subset sum...

// 1 0 0 0 0 0 0 0
// 2 comes -->
// 1 0 1 0 0 0 0 0
// 3 comes -->
// 1 0 1 1 0 1 0 0         --> all possible sum like 0, 2, 3, 5 are here


int dp[101][101];
int m;
const int N = 1e5;


void solve(){

    int n;
    cin >> n;

    vector<int> a(n);

    for (auto& x : a) {
        cin >> x;
    }

    vector<int> dp(N + 5);

    // base case
    dp[0] = 1;

    // moving sum from bigger to 
    for (int i = 0; i < n; i++) {
        for (int j = N; j >= 0; j--) {
            if(j >= a[i]){
                dp[j] |= dp[j - a[i]];   // if dp[j - a[i]] = 1, then dp[j] should also be 1
            }
        }
    }

    vector<int> ans;

    for (int i = 1; i <= N; i++) {
        if (dp[i]) ans.push_back(i);
    }

    cout << ans.size() << '\n';

    for (auto& x : ans) {
        cout << x << ' ';
    }

}


// more optimized using bitset


void solve(){

    cin >> n;

    vector<int> arr(n);

    bitset<100001> temp;

    // must initialize base case
    temp[0] = 1;

    for(int i=0;i<n;i++){
        cin >> arr[i];

        temp |= (temp<<arr[i]);

        // after every iteration, we are getting which sums can be formed by element till indx i
        // ex --> [4, 2, 5, 2]
        // initially --> 1 0 0 0 0 0 0 ....
        // 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0   --> see sum of 0 and 4 -> both are possible
        // 1 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 
        // 1 0 1 0 1 1 1 1 0 1 0 1 0 0 0 0 
        // 1 0 1 0 1 1 1 1 1 1 0 1 0 1 0 0 

        // bitset helps in finding all possible subsets sum of an array
        // in bitset, see the bitposition, left shift and right shift works like an bits number 

    } 

    vector<int> ans;

    for(int i=1;i<100001;i++){
        if(temp[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;

    for(auto x : ans) cout << x << " ";

    cout << endl;
    
}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    solve();

    

    return 0;
}

