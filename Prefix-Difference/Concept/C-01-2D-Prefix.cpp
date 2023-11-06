// In 2D - Array, For any cell (i,j) ==>
// Prefix sum -> Sum from (0,0) to (i,j)

// For 2 cells (a,b) & (c,d) , PREFIX SUM -
// ==> For each row from a to c, b se d col tak ka sum ... i.e Subgrid havind cols. b to d , and row a to c


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    int n, m;
    cin >> n >> m;

    int arr[n+1][m+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }

    int q; cin >> q;

    // NAIVE -------------------------> 

    while(q--){
        
    }

}
