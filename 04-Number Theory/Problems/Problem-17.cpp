// Given the boundaries of 2 intervals. Print the boundaries of their intersection. Note: Boundaries mean the two ends of an interval which 
// are the starting number and the ending number.

// Constraint -> 1 <= l1,r1,l2,r2 <= 10^9
// It's guaranteed that l1 ≤ r1 and l2 ≤ r2

// l1 = 1 , r1 = 15, l2 = 5, r2 = 27
// Output -> 5 15


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long l1,r1,l2,r2;

    cin >> l1 >> r1 >> l2 >> r2;

    if(l1 > l2){
        swap(l1,l2);
        swap(r1,r2);
    }

    if(l2 <= r1){
        cout << l2 << " " << min(r1,r2) << endl;   // If l1 == l2, printing any one of them will fulfill the NEED
    }
    else 
        cout << -1 << endl;
    
    
    return 0;
}
