// A factory has n machines which can be used to make products. Your goal is to make a total of t products.
// For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can 
// freely decide their schedule.
// What is the shortest time needed to make t products?

// Constraints -> 1 <= n <= 2 * 10^5  ,, 1 <= t <= 10^9  ,,  1 <= arr[i] <= 10^9

// n = 3, t = 7,  [3,2,5]   ==> 8  ( 8 sec me 3 sec wla 2, 2 sec wla 4, 5 sec wla 1 products ===> Total 7 Products )


// LOGIC -------------------->>

// Simultaneously working is allowed  ---> Similar to P - Parathas Problem

// Search Space -> Will be of Time ( desired output is time )

// We have to Minimize the time required to make the t Products..
// Search Space --> F F F F F F  T T T T T T T   --> First wla true nikalana hai

// Smaller Range -> 0 sec, Bigger -> Cant guess ( 1e18 )



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

bool predicate(vector<long long> &arr, long long n, long long t, long long m){

    long long p = 0;

    for(int i=0;i<n;i++){

        p += m/arr[i];

        if(p >= t){
            return true;
        }

    }

    return false;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, t; cin >> n >> t;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    long long l = 0, r = 1e18;

    while( r - l > 1){

        long long m = (l+ r)/2;

        if(predicate(arr,n,t,m)) r = m;
        else l = m;

    }

    cout << r << endl;
    

    return 0;
}

