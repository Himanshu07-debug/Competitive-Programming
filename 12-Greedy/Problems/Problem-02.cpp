// There are n pearls in a row. Let's enumerate them with integers from 1 to n from the left to the right. The pearl number i has the type ai.
// Let's call a sequence of consecutive pearls a segment. Let's call a segment good if it contains two pearls of the same type.
// Split the row of the pearls to the maximal number of good segments. Note that each pearl should appear in exactly one segment of the partition.
// No partition possible -> return -1

// 5
// 1 2 3 4 1
// OUTPUT ------>
// 1  --> no. of partitions
// 1 5  --> indexes of all partition


// 7
// 1 2 1 3 1 2 1
// OUTPUT ------>
// 2
// 1 3
// 4 7

// Constraint -> 1 <= n <= 3 * 10^5     , 1 <= arr[i] <= 1e9



// LOGIC -------------------->>

// Sliding Window jaisa socho hi mat, past se lena dena nhi ..

// Hum SET use krnge and Each time segment banane ke baad empty SET start krnge


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    int st = 0;

    set<int> s;

    vector<pair<int,int>> ans;

    for(int i=0;i<n;i++){

        if(s.find(arr[i]) != s.end()){
            ans.push_back({st+1,i+1});
            st = i+1;
            s.clear();
        }
        else{
            s.insert(arr[i]);
        }

    }

    if(ans.size() == 0) cout << -1 << endl;
    else{
        
        // if set empty nhi hai means last decided segment ke baad kuch elements hai jo GOOD nhi hai, to usko last wale me daaldo
        // "Note that each pearl should appear in exactly one segment of the partition." 
        // ---> This was mention in Question, koi bhi pearl ko leave nhi kar sakte
        if(s.size()){
            ans.back().second = n;
        }

        cout << ans.size() << endl;
        for(auto [a,b] : ans){
            cout << a << " " << b << endl;
        }
    }
    
        
    return 0;
}
