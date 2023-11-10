// Harry has a binary matrix A of size NxM. Each element A[i][j] is either 0 or 1. He performs Q queries on the matrix, where each query 
// is defined by (x1, y1) as the top-left cell and (x2, y2) as the bottom-right cell of a rectangle. The task is to flip all bits inside 
// the rectangle (0 to 1 and 1 to 0). After all queries, print the updated matrix.


// 0 0             Queries -> 1 1 1 1  , 2 2 2 2 , 1 1  2 2     ===========>>> 0 1
// 0 0                                                                         1 0


// Constraint --> 1 <= N,M <= 1000,    1 <= Q <= 10^6


// LOGIC --> 

// We have to flip betwwen two numbers only, so agar pta chal jaaye ki all queries me Particular cell kitne baar flip ho rha hai to.. We can guess
// The final number .. For example -> Cell pe 0 hai, Agar Cell flip even times hua, 0 hi rhnga, Odd times hua to 1


// We have to Get occurence of each cell in all Queries .... SAME LIKE DIFFERENCE ARRAY.....

// But Matrix ka Difference Array kaise banate hai ?????????

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
            if(diff[i][j]&1){
                cout << (arr[i][j]^1) << " ";
            }   
            else{
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
    

    
    return 0;
}