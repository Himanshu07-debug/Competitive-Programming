#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSp;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// see such type of problems cant be get in any FORM ..
// Pure Recurrence problem.. try to visualize better.. see the options...

// here the logic is that --> 2 types of paint are happening in the grid when n=1 as shown in INPUT...

// Painted grid only by 2 colors or 3 colors

// see photo


int numOfWays(int n) {

    // starting case --> n = 1
    int twoCol = 6;
    int threeCol = 6;

    for(int i=2;i<=n;i++){

        int t = twoCol;

        twoCol = (2*threeCol + 3*twoCol)%MOD;

        threeCol = (2*t + 2*threeCol)%MOD;

    }

    return (twoCol + threeCol)%MOD;
        
}