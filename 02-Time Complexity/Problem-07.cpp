// Given an array of student skills, your task is to find the maximum size `x` for which you can compose two teams, 
// each with same size `x`, satisfying the following conditions:

// 1. The first team should consist of students with distinct skills.
// 2. The second team should consist of students with the same skills.
// 3. Both team with same size

// You need to return the maximum possible size `x` for a valid pair of teams.

// Consider some examples (skills are given): 
// [1,2,3] , [4,4] is not a good pair of teams because sizes should be the same; 
// [1,1,2] , [3,3,3] is not a good pair of teams because the first team should not contain students with the same skills;
//  [1,2,3] , [3,4,4] is not a good pair of teams because the second team should contain students with the same skills; 
// [1,2,3] , [3,3,3] is a good pair of teams;
// [5] , [6] is a good pair of teams. 

// Constraint : 1 <= n <= 2 * 10^5


// LOGIC : Hum max cnt wla element nikalenge, and uss element ko second team me rkhnge and compare krnge uske cnt 
//         ko other distinct elements of array se.. becz apne ko dono same size ka rkhna hai

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


void solve(){

    // Your code here

    int n;

    cin >> n;

    vector<int>arr;

    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr.push_back(a);
    }

    unordered_map<int,int>m;
    unordered_set<int>s;

    int cnt = 0;
    int mx = -1;

    for(int x:arr){
        m[x]++; 
        if(m[x] > cnt) {
            cnt = m[x];
            mx = x;
        }
    }

    for(int x:arr) {
        if(x!=mx){
            s.insert(x);
        }
    }

    // Check max cnt wale element ko first team me include kar sakte hai kya
    if(cnt >= (s.size() + 2)) {
        cout << s.size() + 1 << endl;
        return;
    }

    cout << min((int)s.size(),cnt) << endl;

}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
    
    }

    return 0;

}
