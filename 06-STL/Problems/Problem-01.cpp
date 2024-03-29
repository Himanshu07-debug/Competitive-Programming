// You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.
// T-Prime --> Having Exactly 3 divisors

// Constraint -> 1 <= arr[i] <= 10^12   , 1 <= n <= 10^5

// 3
// 4 5 6
// Yes No No

// LOGIC -->

// Let p be a prime. As noted by others before, the only (positive) divisors of p^2 are 1 , p , and p2 . Therefore p^2 has exactly 
// three (positive) divisors. 

// Conversely, note that 1 has exactly one positive divisor. And if n has at least two prime divisors, say p and q ,
// then n has at least the four (positive) divisors 1 , p , q , and pq . So in order that n has exactly three (positive) divisors,
// n must be a prime power. Since n = p^a( p is a prime) has exactly the a+1 (positive) divisors 1,p,p^2,…,p^a , we must have a=2 . 

// In other words, n = p^2 .

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<long long> seive(1000002,0);

    seive[0] = seive[1] = 1;

    for(int i=2;i*i<=1e6;i++){
        if(seive[i] == 0){
            for(int j=i*i;j<=1e6;j+=i){
                seive[j] = 1;
            }
        }
    }


    // Your code here
    int n;
    cin >> n;

    while(n--){
        long long x; cin>> x;

        long long sq = sqrt(x);

        // Checking x was a perfect sqaure or not ???  --> for 10 -> 3 * 3 != 10
        if( (sq * sq) == x ){
            if(seive[sq] == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }

    }    

    
    return 0;
}