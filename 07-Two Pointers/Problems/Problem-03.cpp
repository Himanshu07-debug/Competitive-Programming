// Given an array of n integers ai . Let's say that a segment of this array a[l..r] (1 ≤ l ≤ r ≤ n ) is good if the difference between the 
// maximum and minimum elements on this segment is at most k . Your task is to find the number of different good segments.

// Input -> k = 3, [2 6 4 3 6 8 9]  
// Output -> 16

// 1 <= n <= 10^5


// LOGIC ------------------------>>

// A segment in which mx - mi <= k, there any other pairs will also have the diff <= k in the segment.. becz mx - mi is the max diff possible

// Increasing Good Segment technique...

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

    int i=0 , j = 0;

    multiset<int> s;

    long long res = 0;

    while(j < n){

        s.insert(arr[j]);

        while( i<=j && (*s.rbegin() - *s.begin()) > k){
            
            s.erase(s.find(arr[i]));

            i++;
        }

        res += (j - i + 1);

        j++;

    }

    cout << res << endl;


    return 0;
}

