// a1 , a2 ,a3 ..... an (An array A of all distinct elements)
// b1 , b2 ,b3 ..... bm (An array B of all distinct elements)

// TASK -> Make pairs by choosing one element from a & other from b

// Make N + M - 1 count of pairs such that sum of every pair should be different

// Constraint -> 1 <= n,m <= 2 * 10^5

// OUTPUT --> Print indexes of elements selected for pairs


// LOGIC --> 

// First element of a saare m ke sath bana lenga, i.e M pairs done, but what about n - 1 pairs.. Humko ensure krna hai ki A ke baaki N - 1 elements
// Unke sath pair banaye jinka sum first element ne nhi banaya ho M pairs me

// Consider first element = min(A) -> then wo max sum --> first element + max(B) hi bana sakta hai

// SORTING WILL HELP HERE

// a1 < a2 < a3 < ... < an  &&& b1 < b2 < b3 < ...... < bm

// M pairs --> a1 ki (b1 , b2 , b3 ..... bm)

// N - 1 pairs ----> (a2, bm) , (a3, bm) ...

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> arr(n),brr(m);

    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    for(int i=0;i<m;i++){
        cin >> brr[i].first;
        brr[i].second = i;
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());

    for(int i=0;i<m;i++){
        cout << arr[0].second << " " << brr[i].second << endl;
    }

    for(int i=1;i<n;i++){
        cout << arr[i].second << " " << brr[m-1].second << endl;
    }

    
    return 0;
}

