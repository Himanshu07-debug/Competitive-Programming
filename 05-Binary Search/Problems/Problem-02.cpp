
// Apne ko order se lena dena nhi as i < j & j < i --> Both pairs are VALID
// For Each element, we have to find that either arr[i] + k exists or not...

// We will use MAP , not set as If k = 0 , then we have to check frequeny of element


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


void solve(){

    // Your code here
    long long n,k;
    cin >> n >> k;

    vector<long long> arr(n+1,0);

    for(int i=1;i<=n;i++) cin >> arr[i];

    map<int,int> m;

    for(int i=1;i<=n;i++)  m[arr[i]]++;

    long long ans = 0;

    if(k > 0){
        for(auto x: m){
            if(m.count(x.first + k)) ans++;
        }
    }
    // if k == 0, then arr[i] kitne baar present hai
    else{
        for(auto x:m){
            if(x.second > 1) ans++;
        }
    }

    cout << ans << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
    }
    
    return 0;

}