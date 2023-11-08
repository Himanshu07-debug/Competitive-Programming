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

    int q1 = q;

    // NAIVE -------------------------> 

    while(q--){

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int sum = 0;
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                sum += arr[i][j];
            }
        }

        cout << sum  << endl;
 
    }

    // Optimized ------------------------>>

    // First we will make Prefix Matrix i.e each cell with Prefix sum from (0,0)

    int pref[n+1][m+1] = {0};

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            pref[i][j] = arr[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            // Just see by making the Matrix, You will recognize How we came to the above formula, Also minus is for 
            // removing the repetative Elements of the Previous Two SUB-GRID ...
            
        }
    }

    // NOTE -> You can do the following calculation while taking Input of the Matrix


    // For Answering Queries ------------------->>

    while(q1--){

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1] << endl;

    }

    // Precomputation will take O(N * M) time and O(1) for answering all query
    // O( N*M + Q )


}
