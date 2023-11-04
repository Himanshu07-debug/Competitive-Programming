// Chef can make N pieces of cake from 1 to N stored in an array. For each valid  i, the  i-th piece of cake has a flavour arr[i].
// There are K possible types of Flavour available
// Find the longest length subarray in which atleast one flavour out of K does not occur

// Constraint -> 1 <= N <= 10^5 ,, 2 <= K <= 10^5

// LOGIC --> 

// Max length of subarray having atmost K - 1 flavours

// SLIDING WINDOW can be Used And Remember, In choice of Map and Set with it, Map if duplicates are there in Array otherwise SET
// (Always use this funda for SET / MAP)

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(){

    // Your code here

    int n, k;
    cin >> n >> k;

    vector<int>arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    map<int,int>m;

    int st = 0;

    long long res = LLONG_MIN;

    for(int i=0;i<n;i++){

        m[arr[i]]++;

        while(m.size() == k && st < i){
            m[arr[st]]--;
            if(m[arr[st]]==0){
                m.erase(arr[st]);
            }
            st++;
        }

        res = max(res, (i - st + 1)*1ll );

    }

    cout << res << endl;
    
}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
    
    }

    return 0;

}


