// There are N cities numbered 1 to N. In each city i, the leader VSM has infinite statues. Jenish chooses two cities L and R each day and
//  destroys statues in the range [L, R]. He destroys i-L+1 statues in the ith city (L ≤ i ≤ R). Find the total number of statues destroyed 
// in each city after Q days.

// Constraint --->  1 <= N,Q <= 10^6

// 5 3
// 1 3         ======>>>  [ 2  4  3  1  2 ]
// 1 2
// 4 5

// LOGIC ------------>>

// Here We have a Different variation of Query --> From l to r , we have to add the Numbers Progressively by 1 ...
// For Example --> l = 1 , r = 4, then 1, 2, 3, 4  addition to this range


// This is Similar to differnece Array, But how to handle this Query ???

// [0, 0, 0, 0, 0, 0, 0]  , l = 2, r = 5
// [0, 1, 0, 0, 0, -5, 4]  // Here we will add numbers at r + 1, and r + 2 to nullify the Range

// PREFIX SUM ---> 

// [0, 1, 1, 1, 1, -4, 0]  

// Again PREFIX SUM ---.

// [0, 1, 2, 3, 4, 0, 0]    // The Required Query Effect


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


void solve(){

    // Your code here
    long long n, q; cin >> n >> q;

    vector<long long> diff(n+2,0);

    while(q--){

        int x, y;
        cin >> x >> y;

        diff[x]++;

        int win_size = y - x + 1;

        diff[y+1] -= (win_size + 1);

        if(y+2 <= n+1){        // Aap directly diff ki size >= n+3 bhi kar sakte the
            diff[y+2] += win_size;
        }

    }

    for(int i=1;i<=n;i++){
        diff[i] += diff[i-1];
    }

    for(int i=1;i<=n;i++){
        diff[i] += diff[i-1];
    }
    
    for(int i=1;i<=n;i++){
        cout << diff[i] << " ";
    }

    cout << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
    }
    
    return 0;

}
