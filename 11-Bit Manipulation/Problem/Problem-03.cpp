// Find X such that A ^ X * B ^ X is maximum ... 0 <= X , A, B < 2^N
// N, A , B are given

// 1 <= N <= 30


// LOGIC --> 

// From A & B, we can guess X for maximum Product ..
// A = 0 & B = 0 --> X = 1
// A = 1 & B = 1 --> X = 0
// If A & B are different -> 
// A ka first bit 1 then b ke saare 1 

// NEW TECHINQUE HERE --> As the no. of bits are fixed , We can create Binary arrays of 30 to represent different numbers


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



void solve(){

    // Your code here
    int n, a , b;
    cin >> n >> a >> b;

    int arr[31] = {0} , brr[31] = {0};

    for(int i=0;i<31;i++){

        if((a & (1 << i))) arr[i] = 1;

        if((b & (1 << i))) brr[i] = 1;

    }

    int x = 0;

    bool first = true;

    for(int i=0;i<31;i++){

        if(arr[i] == brr[i]){
            if(arr[i] == 0) x += (1 << i);
        }
        else{

            if(first){

                if(arr[i] == 0){
                    x += (1 << i);
                }

                first = false;

            }
            else{

                if(brr[i] == 0) x += (1 << i);

            }

        }

        cout << x << endl;

    }

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}