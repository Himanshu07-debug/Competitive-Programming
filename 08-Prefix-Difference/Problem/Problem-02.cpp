// Given a m x n matrix mat and an integer k, return a matrix answer where 

// Each answer[i][j] is the sum of all elements mat[r][c] for:
// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.

//  Mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//  [[12,21,16],[27,45,33],[24,39,28]]


// CONSTRAINT --> 1 <= n, m <= 10^5  , 1 <= k <= 100


// LOGIC -->


// NAIVE ------------------->>>


// for(i = 0 to r)
//      for(j=0 to c)
//          for(a = max(i-k,0)  to  cl = min(i+k,r-1))
//              for(b = max(j-k,0) to d = min(j+k,c-1))

// TIME ----> O(r * c * k^2 )




// If You Observed how subgrids are making for each cell, You will see that Prefix sum can be used to solve the Problem, first Prepare the
// Prefix Matrix and then Generating the Range Points for each cell


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r = mat.size(), c = mat[0].size();

        // Making the Prefix array with 1-based Indexing so that while solving range, no need to handle Corner case
        vector<vector<int>> pref(r + 1, vector<int>(c + 1, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }

        vector<vector<int>> ans(r, vector<int>(c, 0));

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int a, b, cl, d;
                cl = min(i + k, r);
                d = min(j + k, c);
                a = max(i - k, 1);
                b = max(j - k, 1);
                ans[i - 1][j - 1] = pref[cl][d] - pref[a - 1][d] - pref[cl][b - 1] + pref[a - 1][b - 1];
            }
        }

        return ans;
    }
};

int main() {

    int m, n, k;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution solution;
    vector<vector<int>> result = solution.matrixBlockSum(mat, k);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




 