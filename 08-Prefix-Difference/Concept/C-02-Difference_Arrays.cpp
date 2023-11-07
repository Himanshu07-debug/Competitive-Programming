// QUESTION FOR UNDER-STANDING ---------------------->>>

// You are Given Q queries of the Form [L, R] , K 
// K is given to add the value K to the range [L, R]. The array is initially filled with 0's. What is the Final Array ???


// BRUTE FORCE ----->>

// Update the Array for each Query by traversing the range and adding K and then Output the Array at the end..
// Time Complexity --> O(Q * N)



// This will give TLE in such type of Questions, Can You Optimize it to O(N + Q) ????


// PREFIX SUM CAN BE USED TO SOLVE THIS ---> 
// LOGIC Same like Prefix sums on Ranges.. 
// [0, 0, 0, 0] , l = 1 to r = 2 , k = 1 
// [1, 0, -1, 0]   
// After Prefix Sum ===> [1, 1, 0, 0]

#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    int n, q;
    cin >> n >> q;

    int arr[n+2] = {0};   // n+1 for 1-based Indexing and n+2 for not getting error while accessing r+1

    while(q--){

        int l, r, k;
        cin >> l >> r >> k;
        arr[l] += k;     // Adds K from L to R
        arr[r+1] -= k;   // Removes K from R+1 to N
        // Finally, this two lines Add k from L to R

    }

    for(int i=1;i<=n;i++){
        arr[i] += arr[i-1];
    }

    for(int i=1;i<=n;i++){
        cout << arr[i] << " ";
    }

    // Time --> O(N + Q)
   

    
    return 0;
}