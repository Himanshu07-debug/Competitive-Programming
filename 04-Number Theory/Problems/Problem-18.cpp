// You are given two positive integer sequences a1,…,an and b1,…,bm . For each j=1, … ,m find the GCD of a[1]+b[j] ,…, a[n]+b[j]

// n = 4, m = 4
// arr = [ 1 25 121 169 ]
// brr = [ 2 7 23 ]

// CONSTRAINT -> 1 <= n, m <= 2 * 10^5 ,, 1 <= arr[i], brr[i] <= 10^18

// LOGIC ------------------>>>

// Apne ko pta hai -> GCD(x, y) -> GCD(x, x - y)
// This can be used for multiple arguments also -> GCD(x, y, z, w) -> GCD(x, y - x, z - x, w)

// We can subtract arr[0] with all other values in array..
// GCD(arr[0], ....., arr[n] )  ==>  GCD(arr[0], arr[1] - arr[0], arr[2] - arr[0], ......, arr[n] - arr[0])

// If we subtract arr[1] - arr[0] at any j -> 
// arr[0] -> arr[0] + brr[j]  ==> arr[1] -> arr[1] + brr[j] - (arr[0] + brr[j]) -> arr[1] - arr[0]


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

typedef long long ll;


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    vector<ll> brr(m);

    for(int i=0;i<n;i++) cin >> arr[i];

    // To ensure arr[0] <= arr[i]  for 1 <= i <= n ... arr[i] - arr[0] >= 0
    sort(arr.begin(),arr.end());

    ll res = 0;

    for(int i=1;i<n;i++){
        res = __gcd(res,arr[i] - arr[0]);
    }

    while(m--){
        ll x; cin >> x;

        cout << __gcd(res, arr[0] + x) << " ";
    }

    cout << endl;

    
    
    return 0;
}

