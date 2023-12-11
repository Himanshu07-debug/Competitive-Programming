// Can you make the Given array sharpened by performing the any no. of operation. In one Operation, You can decrement an arr[i] > 0 by 1
// An array is called sharpened if --> 1 ≤ k ≤ n such that a1 < a2 < … < ak and ak > ak+1 > … > an

// 12 10 8  --> "YES"
// 0 1 1 0 --> "NO"
// 100 11 15 9 7 8 --> "YES" [ can change to 3,11,15,9,7,4 ] --> decrease the first element 97 times and decrease the last element 4 times

// Constraint ==> 1 ≤ n ≤ 3*10^5  ,,, 0 <= arr[i] <= 1e9
 

// LOGIC ---------------------->>

// We will try ki leftmost se min. element rkhna shuru kre i.e 0, 1, 2, 
// Right se bhi same , .. , 2, 1, 0

// Kab aap nhi kar paonge ???
// Let incrementer as cnt, agar LHS se traverse krte agar arr[i] < cnt aa gyi means isko assign nhi kar sakte
// Example --> [1,2,4,2] --> [0,1,2,] --> now cnt = 3 but arr[i] = 2 , so 2 ko 3 nhi bana sakte kyuki hum sirf decrement kar sakte hai 
// Simple logic --> Agar 2 hai to uske piche smaller values 2 hi aa sakte hai i.e 0 and 1


// Here is the Simple way to check -->
// We will keep track of the valid Prefixes and Suffixes
// 3 2 4 5 5 6 2
// 1 1 1 1 1 1 0  --> Valid Prefixes 
// 0 0 1 1 1 1 1  --> Valid Suffixes

// 4 pe 1, 1 hai dono me --> [0, 1, 4, 3, 2, 1, 0]  .. Similarly dusre 1 pe bhi honga



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    long long n;    cin >> n;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<long long> prefix(n,0);
    vector<long long> suffix(n,0);

    for(int i=0; i < n; i++){
        if(arr[i] >= i)  prefix[i] = 1;
        else break;
    }

    for(int i=n-1; i>=0 ;i--){
        if(arr[i] >= n-i-1) suffix[i] = 1;
        else break;
    }

    int f = 0;
    for(int i=0;i<n;i++){
        if(prefix[i]== 1 && suffix[i] == 1) f = 1;
    }

    if(f) cout << "YES" << endl;
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





