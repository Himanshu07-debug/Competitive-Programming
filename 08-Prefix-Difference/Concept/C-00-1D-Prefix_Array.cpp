// Important searching algorithms: 
// --> Prefix Sum
// --> Frequency Array Useful when the count of each character is required multiple times
// --> Binary Search



// ******************************************** PREFIX SUMS **********************************************************

// Used in Sum of Range or Other Range related Problems. It gives answer in O(1)  , Only Precomputation takes O(N)

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    vector<int> a{1,2,3,4,5};

    int n = a.size();

    vector<int> prefix_sum(n,0);

    // O(N^2) :

    for (int i = 0; i < n; i++) {

        prefix_sum[i] = 0;
        for (int j = 0; j <= i; j++)
            prefix_sum[i] += a[j];

    }

    // O(N) :

    vector<int> prefix(n,0);

    prefix[0] = a[0];

    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    
   for(auto x : prefix) cout << x << " ";

}

// Time Complexity for the Queries -> O(N) + O(Q)


