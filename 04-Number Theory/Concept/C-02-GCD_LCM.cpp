
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// NOTE -->  gcd( a, 0 ) -> a

int gcd(int a, int b){
    if(a==0) {
        return b;
    }

    return gcd( b % a , a);
}

int lcm(int a, int b){
    return (a * b) / gcd(a,b);
}

// ******************************** PROPERTIES OF GCD AND LCM **************************************

/*

1. Any number can be represented as the multiplication of Prime factors . 

    let a = p1^(a1) * p2^(a2) * p3^(a3) .... and b = p1^(b1) * p2^(b2) * p3^(b3)

    THEN GCD is p1^(min(a1,b1)) * p2^(min(a2,b2)) * p3^min(a3,b3)

    LCM -> p1^(max(a1,b1)) * p2^(max(a2,b2)) * p3^max(a3,b3))

2. PROVE -> gcd(a, b) * lcm(a, b) = a * b;

            From Property 1, multiply gcd and lcm formula, You will get a * b value -> Eg => p1^(min(a1,b1) * max(a1,b1)) => p1^(a1 * b1)

3. GCD( a, a + 1 ) =  1

*/

// OEIS website -> to get the sequence of numbers GENERAL equation

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    cout << gcd(2,3) << endl;


    return 0;
}