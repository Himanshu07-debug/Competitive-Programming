// We guessed some integer number x. You are given a list of almost all its divisors. Almost all means that there are all divisors except 1 and x
// in the list.

// Your task is to find the minimum possible integer x that can be the guessed number, or say that the input data is contradictory and it is 
// impossible to find such number.

// n = 8 & [8 2 12 6 4 24 16 3] -> 48
// n = 1 & [2]  -> 4


// LOGIC : Divisors always occurs in pair, so We can find the Number from it and then for checking contradiction, will find the actual divisors of
//         number


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    long long n;
    cin >> n;

    vector<long long >arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    long long original = arr[0] * arr[n-1];

    sort(arr.begin(),arr.end());

    vector<long long> brr;

    for(int i=2;i<original;i++){

        if( original % i == 0 ){
            brr.push_back(i);
            if(i != original/i){
                brr.push_back(original/i);
            }
        }
    }

    sort(brr.begin(),brr.end());

    if(arr == brr) {
        cout << 'YES' << endl;
    }
    else cout << 'NO' << endl;


    return 0;
}