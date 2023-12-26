#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, k; cin >> n >> k;

    vector<long long > arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    long long c = 0;

    for(int i=0;i<n;i++){

        int x = upper_bound(arr.begin(),arr.end(),arr[i] + k) - arr.begin();

        c += (n - x);

    }

    cout << c << endl;

        

    return 0;
}

