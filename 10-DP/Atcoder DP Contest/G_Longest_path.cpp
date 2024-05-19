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


// There is a directed graph G with N vertices and M edges. The vertices are numbered 1,2,…,N.
// G does not contain directed cycles.

// Find the length of the longest directed path in 
// G. Here, the length of a directed path is the number of edges in it.

// LINK -> https://atcoder.jp/contests/dp/tasks/dp_g

// DAG --> Topo sort
// TOPOLOGICAL SORT for Longest path...
// here no weights are there , so normal BFS

// if want to do by DP , then it is more simple ----> 

// STATE --> dp[x] -> longest path starting at x

// transition  --> dp[x] = max(1 + dp(y)) ... y ==> neighbour of x


// TIME --> O(N + M)

// how ?
// states --> N 
// transition --> worst --> O(M) but average O(M/N) (becz directed edges hai, ek node ki rhngi to dusre jispe hai uspe nhi)

// Final TC --> N * (1 + M/N) --> O(N + M)

int dp[100100];
vector<int> gr[100100];
int n, m;

int rec(int x){

    if(dp[x] != -1) return dp[x];

    int ans = 0;

    for(auto ngh : gr[x]){
        ans = max(ans, 1 + rec(ngh));
    }

    return dp[x] = ans;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    cin >> n >> m;

    while(m--){

        int a, b; cin >> a >> b;

        gr[a].push_back(b);

    }

    memset(dp, -1, sizeof(dp));

    int res = 0;

    for(int i=1;i<=n;i++){

        // no need of visited, DP cache step will take care of it
        res = max(res, rec(i));

    }

    cout << res << endl;

    return 0;
}

