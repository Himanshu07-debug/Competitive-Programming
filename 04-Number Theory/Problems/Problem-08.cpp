// You are given two integers X & K .  determine whether there is an integer A such that it has exactly X positive 
// integer divisors and exactly K of them are prime numbers.

// X = 4, K = 2 ---> YES 
// A=6 has  X=4 factors: : 1, 2, 3 ,6. It also has exactly  K=2 prime factors: 2  and 3 

// Constraint : 1 <= X, K <= 10^9


// LOGIC :

// "A" must have K prime factors . A = p1^a1 * p2^a2 ... pk^ak
// Total no. of divisors of A will be -> (a1 + 1) * (a2 + 1) .... (ak + 1)

// OBSERVE -> Dono me No. of values multiplication me equal hai i.e K (no. of Prime factor)
//           Agar mai X ko K values me reduce kar pau each value greater than 1 , then I can get A with K prime factors.


// Why Greater than 1 ?? 
// Total no. of divisors me each value min. 1  rhngi (1 + ?)

// NOTE -> So Our Problem get reduced to determining is it possible to write X as a product of K values greater than 1 or not.

// If reduced value cnt > k aaya to merge kar denge K krne ke liye cnt kyuki X ke reduction me value Non-Prime bhi rhi to chalta Kyuki 
// X me to (powers + 1) multiply ho rhe hai.....
// Eg -> X = 12 , K = 2 ... Reduced(X) = 2, 2, 3
// Merko X me 2 hi terms chahiye becz K = 2, Therfore Merge any two values -> 4, 3  OR  2, 6


// GUESSING THE VALUE A ???
// Above wla hi Example lo .. A = 2^(4-1) * 3^(3-1) ==> 8 * 9 => 72
// This A will have only two prime divisors -> 2 and 3


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    long long x, k;
    cin >> x >> k;

    long long ans = 0;

    while(x%2 == 0){
        ans++;
        x/=2;
    } 

    for(int i = 3 ; i*i <= x ; i += 2)
	{
	    while(x%i == 0)
	    {
	        ans++;
	        x /= i;
	    }
	}
	
	if(x > 1) ans++;

    if(ans>=k) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}