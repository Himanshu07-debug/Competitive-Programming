// At some points on the road there are n friends, and i-th of them is standing at the point x[i] meters and can move with any speed no greater 
// than v[i] meters per second in any of the two directions along the road: south or north.

// You are to compute the minimum time needed to gather all the n friends at some point on the road. 
// Note that the point they meet at doesn't need to have integer coordinate.


// 2  ≤  n ≤  60 000 , 1 <= x[i] , v[i] <= 1e9

// INPUT --> n = 3, x = [7,1,3] , v = [1,2,1] ==> 2 sec ( All meeting at pt. 5 with their max speed )


// LOGIC -------------------------->>>

// We have to minimize the time needed for gathering...

// Search Space -> Time
// If the friends can gather at t time, then they can also gather at t + 1 time ...
// So, F F F F F F T T T T T T T

// Here, the main thing is -> How to write the Predicate function for checking if there is a common pt. or intersection within the friends ???

// Observe, at any time t, a i-th friend can get anywhere within the segment [xi - t*vi, xi + t*vi]..
// This means all the friends have a fixed segment or Range where they can move...
// Now, our Task is to find is there exist a common point within all this ranges ....

// We will keep track of the max l and min r value and will check the validity of each frnd...
// max l and min r will keep track of the common range between all 



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


bool fun(vector<long double> &x,vector<long double> &v, long long n, long long t){

    vector<pair<long double,long double>> arr;

    for(int i=0;i<n;i++){

        long double l = x[i] - t*v[i];
        long double r = x[i] + t*v[i];

        arr.push_back({l,r});

    }

    long double l = -INF, r = INF;

    for(int i=0;i<n;i++){

        if(arr[i].first > r || arr[i].second < l ){
            return false;
        }

        l = max(l, arr[i].first);
        r = min(r, arr[i].second);

    }

    return true;

}



int main(){

    cout << fixed << setprecision(10);
    long long n; cin >> n;

    vector<long double> x(n),v(n);

    for(int i=0;i<n;i++) cin >> x[i];

    for(int i=0;i<n;i++) cin >> v[i];

    long double l = 0 , r = 1e10;

    // Precision -> 100 times iteration
    for(int i=1;i<=100;i++){

        long double m = (l + r)/2;

        if(fun(x,v,n,m)) r = m;
        else l = m;

    }

    cout << r << endl;

    

}


