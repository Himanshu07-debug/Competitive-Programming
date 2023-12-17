// Can You make the Array non-decreasing by doing the following operation ------->>
// hooses two adjacent elements a[i] and a[i+1] (1 ≤ i ≤ n−1), and increases both of them by 1 or decreases both of them by 1. 
// Note that, the elements of the array can become negative.

// Constraint -> 2 <= n <= 1e5 , 1 <= arr[i] <= 10^9

// 1 3 2  ---> YES
// 2 1  ---> NO
// 5 4 3 2 1 --> YES


// LOGIC ----------->> 

// Observe that ki agar apan equal value pairs bana paaye array me .. Then usko sort kar lenge koi bhi no. of operation use krke( increase/decrease

// Example [5,4,3,2,1] --> [3] [2,2] [1,1]  ==> Now ab [2,2] and [1,1] ko increase 3 se jyada
// [2,1,4,3]  --> [2,0] [3,3]  ==> in [2,0] apne pass 2 ke piche elements nhi hai jinka use krke 2 ko decrement kar saku 0 me.. NOT POSSIBLE

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    bool flag = true;

    for(int i=n-1; i >= 1 ; i-=2){

        if(arr[i-1] > arr[i]){

            if(i == 1){
                flag = false;
            }
            else{
                arr[i-2] -= arr[i-1] - arr[i];
            }

        }
        else{
            if(i >= 2)  arr[i-2] += arr[i] - arr[i-1];
            // Making arr[i-1] equal to arr[i] , arr[i-2] also gets updated
        }

    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

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
