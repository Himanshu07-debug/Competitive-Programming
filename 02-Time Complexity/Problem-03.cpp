// The positive odd numbers are sorted in ascending order as 1,3,5,7,9,11,13.. and 
// grouped as (1) , (3,5), (7,9,11), (13,15,17,19)  and so on.
// Given , find the sum of the elements of the kth group. For example, for k=3 ,ans is 27 ( 7 + 9 + 11)

// Constraint : 1 <= k <= 10^6


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int k; cin >> k;

    // Finding the Number of elements before kth grp
    long long x = k * 1ll * (k-1)/2;
    
    // Finding the xth Odd number from the Odd series
    long long n = 2*x - 1;
    
    long long sum = 0 ;
    
    for(int i=1 ; i<=k;i++){
        n += 2;
        sum += n;
    }

    // O(1) :

    // we can use Sum formula of A.P

    // here when we get the starting number of the kth grp : a = st. no , d = 2, n = k i.e number of elements in series

    // sn = n/2 * (2a + (k-1)*d)  -> n*(a+(k-1)) becz d=2,take 2 common from the bracket and cancel it with denominator

    long long a = n + 2;
    long long ans = k * ( a + (k -1) );
    
    cout << ans << endl;

    return 0;
}
