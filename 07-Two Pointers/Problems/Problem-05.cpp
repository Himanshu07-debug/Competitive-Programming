// In the center of Che city there is a pedestrian street, one of the most popular walking places for city residents. This street is very 
// pleasant to walk, because along the street there are n funny monuments. The girl Masha from the city of Che likes two boys from her school, 
// and she cannot make a choice between them. To make the final decision, she decided to date both boys at the same time. 
// Masha wants to choose two monuments on the pedestrian street, near which the boys will be waiting for her. At the same time, 
// she wants to choose such monuments so that the boys do not see each other. Masha knows that because of the fog, the boys will see each 
// other only if they are on distance not more than r meters. Masha got interested in how many ways there are to choose two different monuments 
// for organizing dates.

// Constraint -> 2 ≤ n ≤ 300000, 1 ≤ r ≤ 10^9 .. array is SORTED

// [1 3 5 8] , k = 4  ==> 2  ( (1,8) & (3,8) only possible )


// LOGIC --->

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, k; cin >> n >> k;

    vector<long long > arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    long long c = 0;

    for(int i=0;i<n;i++){

        int x = upper_bound(arr.begin(),arr.end(),arr[i] + k) - arr.begin();

        c += (n - x);

    }

    cout << c << endl;

        

    return 0;
}

