// There are n ropes, you need to cut k pieces of the same length from them. Find the maximum length of pieces you can get.

// n = 4 , k = 11 , [ 802, 743, 457, 539 ]
// Answer -> 200.5

// CONSTRAINT --->
// 1 ≤ n,k ≤ 10000  ,  1 <= arr[i] <= 10^7
// The answer will be considered correct if the relative or absolute error does not exceed 10^−6

// The above line mean -> if the difference between your answer and the correct answer is < (10 ^ -6), it will be considered as correct

// LOGIC ---------------------------->>

// We have to maximize the equal length of K pieces.

// We can do it by BS very easily, but here double answers are expected i.e If 200 is the answer, check for 200.5 , .... l + precision < r

// Let say our answer range is 1e8 integers and each integer have a precision of 1e-6 i.e there are 1e6 decimal places for each integer.
// Therefore, total no. of places to search -> 1e8 * 1e6...
// Therefore, Using Binary Search, We have to do atleast log2(1e14) number of iterations.. 

// log2(1e18) --> 63.. 
// So what we can do, we will run 100 iterations, so that we can get highly precised value and also we will be sure with our answer..

// TIME --> O( 100 * n )  [ 100 times iteration and O(n) for predicate function ]

// r values in our case -> 1e3 * 1e7 / 1e3  --> (n * arr[i]) / k


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

bool fun(vector<long long> &arr, long long k, long long n, long double m){

    long long c = 0;

    for(int i=0;i<n;i++){

        c += arr[i]/m;

    }

    return (c >= k);

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    long long n , k; cin>> n >> k;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    cout << fixed << setprecision(6) << endl;

    long double l = 0, r = 1e8, ans = 0; 

    for(int i=1;i<=100;i++){

        long double m = (l + r)/2;

        if(fun(arr,k,n,m)) l = m;
        else r = m;

    }

    cout << l << endl;

    // NOTE -> Yha pe l ke jagah r nhi kar sakte , l hamara true answer store kar rha hai (Highly Precised)
    
    // No l = mid - 1 or r = mid + 1 becz ans can be lied in between l and r when r = l + 1 .. i.e (l = 1, r = 2 -> ans -> 1.01, 1.10, 1.001, etc)

    return 0;
}

