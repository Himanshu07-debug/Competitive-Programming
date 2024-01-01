// After attending Amrita summer training camp, N programmers, getting bored of programming, decided to have a car race. 
// Each of them bring their own car to the race. As the camp also includes school children, to level the playing field, some of the coders are 
// allowed to have a head start. The ith programmer starts his race at a distance Di ahead of the starting line at time T = 0. 
// The speed of the car of the ith coder is equal to Si. 
// After time T, the position of ith coder will be Pi(T) = Si * T + Di. Let's define f(T) = max(Pi(T)) - min(Pj(T)). The race ends at time T = K. 
// You need to find the minimum value of f(T) during the whole race.


// N = 2, k = 10
// s[i] = {20, 10}  , d[i] = {10, 10}
// ==> 0.000000 (at time 1, both will be at the dist differnce 0)

// Constraint --->
// 1 ≤ N ≤ 10^5   ,,, 1 ≤ K ≤ 10^5 ,,,  1 ≤ Si ≤ 10^5  ,,, 0 ≤ Di ≤ 10^5


// LOGIC ------------------>>

// Let A & B are two Racers ...

// CASE 1 ---> 
// A moves with speed > B  AND dist of A > B ... Graph will be Monotonic ... 
// Minimum dist difference will be at  t = 0

// CASE 2 --->>
// A dist > B but speed A < B 
// dist diff will decrease until B overtake A and then dist diff again increase .... Graph is not Monotonic..
// TERNARY SEARCH


// So here, our Graph is not Monotonic, we will use Ternary search..  This are called as Unimodal graph (single local min/max)


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

long long n, k;
vector<long double> s, d;

long double check(long double t){

    long double maxD = -1e18;
    long double minD = 1e18;

    for(int i=0;i<n;i++){

        maxD = max(maxD, s[i]*t + d[i]);
        minD = min(minD, s[i]*t + d[i]);

    }

    return (maxD - minD);

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    cin >> n >> k;

    s.resize(n);
    d.resize(n);

    for(int i=0;i<n;i++){
        cin >> s[i] >> d[i];
    }

    long double ans = 1e18;

    long double l = 0, h = k;

    for(int i=0;i<100;i++){

        long double m1 = l + (h-l)/3;
        long double m2 = h - (h - l)/3;

        if(check(m1) < check(m2)){
            h = m2;
            ans = check(m2);
        }
        else{
            l = m1;
            ans = check(m1);
        }

    }

    cout << fixed << setprecision(6);
    cout << ans << endl;
    

    return 0;
}


