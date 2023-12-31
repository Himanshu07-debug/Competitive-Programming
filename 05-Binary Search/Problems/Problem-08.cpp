// Help Vlad choose gifts for his friends so that the value of X is as high as possible. Please note that each friend must receive one gift. 
// Vlad can visit at most n−1 shops (where n is the number of friends). In the shop, he can buy any number of gifts.
// X is min(a1,a2,a3...an) where a[i] -> Is the joy given to ith frnd
// arr[i][j] -> Gift from ith shop is allocated to jth frnd..

// Constraint -> 2 <= n,m <= 10^5  ,,  2 <= n*m <= 10^5   ,  1 <= arr[i][j] <= 10^9

// m = 4, n = 2
// 1 2
// 3 4 
// Ans -> 3 (possible combos -> (1,2) , (2,3) , (3,4))


// LOGIC ------------------------------>>>

// Search Space -> T T T T T T F F F F F F
// We have to maximize the minimum joy allocated to a frnd

// Predicate Function -> 
// Since I have to take n gifts from n-1 shops, So if I get Atleast 2 gifts of joy >= mid from the Same shop and the remaining frnd can also get
// Their joys from remaining n-2 shops or <= n-2 shops (atmost n-1 shops), I will return true... Otherwise False
// This means, Koi bhi ek shop se 2 gift mil jaaye and remaining shop se sabko ek-ek mil jaaye to allocation possible hai (n-1 shops for n frnds )



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


bool fun(vector<vector<long long>> arr, long long n, long long m, long long mi){

        vector<vector<long long >> ans(n); // -> This stores that the ith frnd can take gift from which shops

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                // j -> shop, i -> frnd

                if(arr[j][i] >= mi){

                    ans[i].push_back(j);

                }

            }

            //  No shop allocated to ith frnd i.e ith frnd do not get any Gift
            if(ans[i].size() == 0){
                return false;
            }

        }

        // Checking for two gifts from same shop i.e there is a shop, from which I can take gift for atleast 2 frnds...
        vector<long long> visited(m,0);

        for(int i=0;i<n;i++){

            for(auto x:ans[i]){

                if(visited[x]) return true;

                visited[x] = 1;
            }

        }

    return false;


}



void solve() {

    // Your Code here
    long long n, m; cin >> m >> n;

    vector<vector<long long>> arr(m, vector<long long>(n));

    for(int i=0;i<m;i++){
        for(int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }

    long long l = 0, r = 1e9+1;

    while(r-l > 1){

        long long mi = (l+r)/2;

        if(fun(arr,n,m,mi)) l = mi;
        else r = mi;

    }

    cout << l << endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}