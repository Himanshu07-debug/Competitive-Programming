// In this problem, you are initially given an empty multiset. You have to process two types of queries:

// ADD x — add an element equal to 2^x to the multiset;
// GET w — say whether it is possible to take the sum of some subset of the current multiset and get a value equal to w

// Each query with t and v --> t = 1 means ADD v and If t = 2, means GET v

// For ADD, 0 <= v <= 29 ,,, for GET,  0 <= v <= 10^9

// 5
// 1 0
// 1 0
// 1 0
// 2 3
// 2 4
// YES
// NO



// LOGIC ------------------------------------>>>

// Yha pe GET me, v ki range 1e9 tk hai, which means bit array ko use nhi kar sakte bit number ka representation btane ke liye, becz 1e9 bits 
// lagenge and aur carry ke bhi lagenge aur indexes


// Hum bitwise array sirf 29 bits tk 2^x ka occ. store krne ke liye use krnge and then -
// We want w from this array, Hum one by one traverse krnge and jha pe 2^i <= W honga, uske occ. lenge ensuring W < 0 na ho

// For ensuring W 0 na ho kisi bhi bit position pe -->
// Suppose y is the occ. of bit position i, then y * 2^i <= W ... i.e y <= W/2^i



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

    vector<int> arr(31,0);

    for(int i=0;i<n;i++){
        
        int t, v; cin >> t >> v;

        if(t==1){

            arr[v]++;

        }
        else{

            for(int i=29;i>=0;i--){
                int min_Occ_Take = min(v >> i , arr[i]);   // v >> i --> v/2^i
                v -= min_Occ_Take * (1 << i);               // 1 << i --> 2^i
            }

            cout << (v == 0 ? "YES" : "NO") << endl;

        }

    }

    
    

    return 0;
}




