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

bool predicate(vector<long long> &arr, long long k, long long n, double m){

    double c = 0;

    for(int i=0;i<n;i++){

        c += (double)arr[i]/m;

    }

    return ((long long)c >= k);

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    long long n , k; cin>> n >> k;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    double l = 0 , r = 1e15;

    while ( r - l > 1){

        double m = (l + r)/2.0;

        if(predicate(arr,k,n,m)) l = m;
        else r = m;

    }

    cout << l << endl;
    

    return 0;
}

