// You are given an array a consisting of n (n≥3) positive integers. It is known that in this array, all the 
// numbers except one are the same (for example, in the array [4,11,4,4] all numbers except one are equal to 4 ).

// Print the index of the element that does not equal others. The numbers in the array are numbered from one.

// Constraint : 3 <= n <= 100 , 1 <= arr[i] <= 100


// 3 approach can be done: 

// 1 -> Peak element jaisa first and last ko phle hi if me check krlo and then i=1 to i=n-2 tk traverse kro

// CHECK -> arr[i] != arr[i-1]  && arr[i-1] == arr[i+1]

// 2 -> ( NEW Technique ) Make 3 copies of the Original array and then traverse the 2nd copied array

// xyyy    xyyy    xyyy                 => This will not missout any edge cases and will not give you error
// copy1   copy2   copy3


// 3 -> Freq array lelo

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main() {

    int n;
    cin >> n;

    vector<int> arr(3*n, 0);

    for(int i=0;i<n;i++){
        cin >> arr[i];

        arr[i+n] = arr[i + 2*n] = arr[i];
    }

    for(int i=n ; i< 2*n ; i++){
        if(arr[i] != arr[i-1] && arr[i-1] == arr[i+1]){
            cout << (i-n+1) << endl;
            break;
        }
    }

    return 0;

}