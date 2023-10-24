// You are given two integers X & K .  determine whether there is an integer A such that it has exactly X positive 
// integer divisors and exactly K of them are prime numbers.

// X = 4, K = 2 ---> YES 
// A=6 has  X=4 factors: : 1, 2, 3 ,6. It also has exactly  K=2 prime factors: 2  and 3 

// Constraint : 1 <= X, K <= 10^9


// LOGIC :

// "A" must have k prime factors. A = p1^a1 * p2^a2 ...
// Total number of Divisors is (a1 + 1) * (a2 + 1) ....

// Agar hum X ko k values greater than 1 me reduce kar paaye, then we can say that "A" is having K prime factors.

// So Our Problem get reduced to determining is it possible to write X as a product of K values greater than 1 or not.


// This reduced values of X can be even, odd. Only it must be greater than 1 becz in formula it is (1 + ?)
// Also If reduced Values > K, then we can merge the reduced values to make them equal to K .
// Eg -> X = 12 , K = 2 .. reduced(X) = 2, 2, 3  ...  Merge any two value i.e 4, 3 OR 2, 6


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