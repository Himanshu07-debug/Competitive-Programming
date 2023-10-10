// You are given a system of equations: a^2 + b = n  and a + b^2 = m
// You should count, how many there are pairs of integers (a, b) (0  ≤  a, b) which satisfy the system.

// Input : n = 9 ,  m = 3         Output: 1  ->  (3,0)

// Constraint : 1  ≤  n, m  ≤  1000


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    int cnt = 0;

    for ( int i=0;i <= n*n ;i++){
        for(int j=0;j <= m*m ;j++){

            int t1 = i*i + j;
            int t2 = i + j*j;

            if(t1 == n && t2 == m){
                cnt ++;
            }
        }
    }

    // How we figure out that the a can go maximum upto sqrt(n) and same for b  ???

    // The given equation is : a^2 + b = n , hum b ko decrease krnge so that a ko increase kar sake.. max b ki value
    // decrease upto 0 ho skti hai becz a,b >= 0 (Constraint) 
    // So b=0 pe a^2 = n i.e a value can be maximize upto sqrt(n) , above that It will not satisfy the first equation

    // Similarly, we had find b, minimize a to get max value of b possible

    // This is one of the Popular method of Maths when you are given a Equation : 
    // Keep the equation satisfying, minimize at one side and maximize on other side

    cout << cnt << endl;

    return 0;
} 