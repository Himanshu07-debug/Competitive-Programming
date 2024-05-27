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

// We know LIS concept in 1 dimension...
// Sorting will help here to reduce the problem complexity from 2 dimension to 1 dimension...

// We will sort the array.... Now no worry about width..
// now we can apply simple LIS on height array only to get the longest length possible --> similar to Box stacking

// The main logic is here that we dont have to take the similar width value pair twice .. it should be monotonic...

// its good to sort the array in decreasing order when the width are same... 
// (2, 3) , (3, 10), (3, 7), (3, 5), (3, 2) (4, 6)

// Array states -
// [3]
// [3, 10] 
// [3, 7]
// [3, 5]
// [2, 5]
// [2, 5, 6]

// See similar element will not increase the array size... but if we keep --> [2, 5, 7, 10] --> then in place of 3, 2 comes and then array size 
// will increase continously....

// also no need to worry about 3 gone and 2 came of same element, becz 3 height se jo bda tha 5, wo already aage hai.. they both are considered


class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];

        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& arr) {

    sort(arr.begin(), arr.end(), cmp);

    int n = arr.size();

    vector<int> lis;

    for(int i=0;i<n;i++){
        
        auto it = lower_bound(lis.begin(), lis.end(), arr[i][1]);

        if(it == lis.end()) lis.push_back(arr[i][1]);
        else{
            *it = arr[i][1];
        }

    }

    return lis.size();
        
}

};
