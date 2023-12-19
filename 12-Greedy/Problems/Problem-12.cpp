// Given an Array of length n. You have to make it in a valid Permutation. Two operations are allowed -->
// 1. Removal of any array element cost C
// 2. Insertion of a number cost D

// Find the minimum Cost to make it will required to make it a Permutation

// Constraint --> 1 <= n <= 1e5   ,  1 <= arr[i] <= 1e9

// n=5, c = 2, d = 3
// [1,1,3,1,3]   --> 8 
// Possible Permutation -> [1,2,3]  --> Removal 3 and Insertion 1 ==> Cost ==> 3*2 + 1*3 ==> 9
// [1,2] --> Removal 4 and Insertion 1 ==> 4*2 + 1*3 ==> 11
// [1] --> Removal 4 and Insertion 0 ==> 4*2 + 0*3 ==> 8

// OUTPUT --> 8 is the Minimum in all Possible Permutation

// c = 1000000000 , d = 1 , arr = [1000000000 1]  ==> OUTPUT --> 999999998


// LOGIC ------------------------------------>>

// REMEMBER , Input ka Explanation Question me bhut kam diya tha, itne Detail me nhi, You have to Think in this way
// TIP --> Never Go with INPUT, Question ke Based pe operation try kro

// Hum har ek array elements ka Permutation banake unka Cost nikalenge and unme se Min. answer..
// Ek array element ko test kar liye, now ab usko remove kar denge and Other Array element se calculate
// Normal Traversal se nhi kar sakte becz --> arr[i] can be 1e9 and n can be 1e5


// We will use MAP


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    int n, c, d; cin >> n >> c >> d;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    map<int,int> m;

    for(int x : arr) m[x]++;

    sort(arr.begin(),arr.end());

    long long ans = INF;

    // Calculate all Possible cost
    for(int i=n-1;i>=0;i--){

        int curr_size = i + 1;

        int add = arr[i] - m.size();
        int del = curr_size + add - arr[i];

        long long cost = del * c + add * d + (n - i - 1) * c;

        ans = min(ans, cost);

        m[arr[i]]--;

        if(m[arr[i]] == 0){
            m.erase(arr[i]);
        }

    }

    ans = min(ans, c*n*1ll + d);

    cout << ans << endl;

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
