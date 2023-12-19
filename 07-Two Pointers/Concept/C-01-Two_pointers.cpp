// Two Pointers are used to Optimize the O(nlogn) solution to O(n)
// They are used mostly in Subarray type of Problems, etc..


// Two types of Problems in Two Pointers ===>

// 1. Ad-hoc Problems ( Click based for 2 pointers, no fixed pattern )

// 2. Good Segments Technique ( Have Patterns )


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// OBSERVE --------------------->>

// 1. Two sorted arrays are given. Merge them into single sorted array.
// SORTING ---> O((n + m)* log(n + m))
// TWO POINTERS --> O(n + m)


// -----------------------------------------------------------------------------------------------------------------------------------------------


// 2. Given Two sorted arrays, for each element in 1st array, find number of elements smaller than that in 2nd array..
// Approach 1 => For each element in first array, Binary search on the second array (UpperBound)
// TIME --> O(n * log(m))

// APPROACH 2 => TWO POINTERS .. x elements are smaller than arr[i] , then no. of elements smaller than arr[i+1] will be >= x , becz arr[i] ke
//               less than elements arr[i+1] se bhi less rhnge, unko check krne ki need nhi, directly start from indx of brr where brr[i] > arr[i]
// TIME --> O(n + m)


void Ques2(vector<int> arr, int n, vector<int> brr, int m){

    vector<int> ans(n);

    int i=0, j=0;

    while(i < n){

        while(j<m && brr[j] < arr[i]){
            j++;
        }

        ans[i] = j;
        i++;
    }


    for(int x : ans) cout << x << " ";

    cout << endl;

}



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    
    

    return 0;
}



