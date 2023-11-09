// Greg has an array a = a1, a2, ..., an and m operations. Each operation looks as: li, ri, di, (1  ≤  li  ≤  ri  ≤  n). 
// To apply operation i to the array means to increase all array elements with numbers li, li + 1, ..., ri by value di.

// Greg wrote down k queries on a piece of paper. Each query has the following form: xi, yi, (1  ≤  xi  ≤  yi  ≤  m). 
// That means that one should apply operations with numbers xi, xi + 1, ..., yi to the array.

// Now Greg is wondering, what the array a will be after all the queries are executed. Help Greg.

// N = 3 , M = 3 , K = 3
// arr = [ 1 2 3 ]
// M queries ---->>
// 1 2 1
// 1 3 2
// 2 3 4
// K queries ---->>
// 1 2
// 1 3
// 2 3

// CONSTRAINT ---> 
// 1  ≤  n, m, k  ≤  10^5
// 0  ≤  ai  ≤  10^5
// 1  ≤  li  ≤  ri  ≤ n , 0  ≤  di  ≤  10^5
// 1  ≤  xi  ≤  yi  ≤  m




// LOGIC --------------------------->>>

// This Question is DIFFERENT...
// In all other Question, Array diya hai aur list of Queries answer krna hai...

// In this Question, array ke sath sath Array pe lagane wale Queries ka bhi ARRAY diya hai and then further K queries me hume asked range ke 
// queries array of Queries se lgana hai....


// We cant exceed O(nlogn)  ... 

// Yha pe Hume Each applied Queries ka occurence nikalna padega so that we can find the Final Array...
// For this, we will use Difference Array on Array of Queries..

// Then we add the contribution to the Final Array


#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

struct temp{
    int l;
    int r;
    long long d;
};


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> arr(n+1,0);

    for(int i=1;i<=n;i++) cin >> arr[i];

    vector<temp> brr(m+1);    // In place of Struct, You can use 2D-VECTOR .. vector<vector<long long >> brr;

    for(int i=1;i<=m;i++){
        cin >> brr[i].l >> brr[i].r >> brr[i].d;
    }

    vector<int> diff(m+2,0);     // diff array for array of Queries
   
    while(k--){
        long long x, y;
        cin >> x >> y;

        diff[x]++;
        diff[y+1]--;
    }

    for(int i=1;i<=m;i++){
        diff[i] += diff[i-1];
    }

    vector<long long> ans(n+2,0);    // Difference Array for the range specified in M operations 

    for(int i=1;i<=m;i++){

        int l = brr[i].l;
        int r = brr[i].r;
        long long d = brr[i].d;
        long long add = diff[i]*d;

        ans[l]+= add;
        ans[r+1]-=add;

    }

    for(int i=1;i<=n;i++){

        ans[i]+=ans[i-1];
        arr[i] += ans[i];

    }

    for(int i=1;i<=n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    
    return 0;
}