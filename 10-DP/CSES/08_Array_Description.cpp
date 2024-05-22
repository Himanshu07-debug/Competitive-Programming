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

// You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
// Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

// Constraints

// 1 <= n <= 10^5
// 1 <= m <= 100
// 0 <= x_i <= m

// Example
// Input:
// 3 5
// 2 0 2

// Output:
// 3

// Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.



// FORM 1 

// Have to make following choices on each day.... FORM 1 always when it is for each possible Day

// some way, sequence, some elements --> FORM 2

// We have to keep the track of last element ....
// if arr[i] == 0  --> then can put last - 1, last, last + 1 on the current place
// if arr[i] == x --> check from last , and take current x as last for next call


// IMP CONCEPT ------------------------------>>>>>

// NOTE --> whenever in question, current element have constraint with i+1 and i-1 elements, you only consider one side always and starts 
//          writing DP, another side will be handle in DP flow



int dp[100001][107];
int n, m;

int rec(int i, int last, vector<int> &arr){

    if(i == n) return 1;

    if(dp[i][last] != -1) return dp[i][last];

    long long ans = 0;

    if(arr[i] == 0){

        if(last == 105){
            for(int j=1;j<=m;j++){
                ans = (ans + rec(i+1, j, arr))%MOD;
            }
        }
        else{
            ans = (ans + rec(i+1, last, arr))%MOD;
            if(last - 1 >= 1) ans = (ans + rec(i+1, last - 1, arr))%MOD;
            if(last + 1 <= m) ans = (ans + rec(i+1, last + 1, arr))%MOD;
        }

    }
    else{

        if(last == 105){
            ans = rec(i+1, arr[i], arr);
        }
        else if(abs(arr[i] - last) <= 1){
            ans = rec(i+1, arr[i], arr);
        }

    }

    return dp[i][last] = ans;

}

void solve(){

    cin >> n >> m;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << rec(0, 105, arr) << endl;

    
}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    solve();
    

    return 0;
}

