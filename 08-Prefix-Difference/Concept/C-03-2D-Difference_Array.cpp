// Suppose (1,1) to (2,2) -->

// 0 0 0              1  0  -1                                    1   1   0                         1   1   0
// 0 0 0    ====>>>   0  0  0    ===> Prefix Sum ==> Row-wise --> 0   0   0  --> Col. wise ===>     1   1   0
// 0 0 0              -1 0  1                                     -1  -1  0                         0   0   0




#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n, m;
    cin >> n >> m;

    vector<vector<int>>arr(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }

    int q; cin >> q;

    vector<vector<int>>diff(n+2,vector<int>(m+2,0));

    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        diff[a][b]++;
        diff[c+1][d+1]++;   

        diff[a][d+1]--;
        diff[c+1][b]--;

    }

    // Prefix sum

    // Col. wise Prefix --->
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            diff[i][j] += diff[i][j-1];
        }
    }
    
    // Row wise Prefix --> 
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            diff[i][j] += diff[i-1][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}