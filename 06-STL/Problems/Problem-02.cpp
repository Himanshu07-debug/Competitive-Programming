// There are n positive integers a1,a2,…,an . For the one move you can choose any even value c and divide by two all elements that equal c . 
// For example, if a = [6,8,12,6,3,12] and you choose c = 6 , and a is transformed into a = [3,8,12,3,3,12] after the move. 
// You need to find the minimal number of moves for transforming a to an array of only odd integers (each element shouldn't be divisible by 2 ).

// Constraint -> 1 <= n <= 2 * 10^5   , 1 <= arr[i] << 10^9


// Logic --> Reducing one by one the largest even number will lead to minimal operation, also SET will help to keep distinct numbers and giving 
//              min operation

// [6,8,12,6,3,12]  -> Dividing first 6 then 12 ---> 1(6) + 2(12) + 3(8)
// [6,8,12,6,3,12]  -> Dividing first 12 then 6 ---> 1 + 1 + 3


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(){

    // Your code here
    int n; cin >> n;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    set<long long>s;

    for(auto x:arr){
        if(!(x&1))  s.insert(x);
    }

    long long ans = 0;

    while(s.size()){
        long long i = *s.rbegin();
        s.erase(i);
        i/=2;
        if(!(i&1)) s.insert(i);
        ans++;
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