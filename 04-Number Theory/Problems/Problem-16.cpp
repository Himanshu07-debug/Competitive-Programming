// You are given an array of n non-negative integers a1,a2,…,an . You can make the following operation: choose an integer x≥2 and replace 
// each number of the array by the remainder when dividing that number by x , that is, for all 1≤i≤n set ai to aimodx . 
// Determine if it is possible to make all the elements of the array equal by applying the operation zero or more times.

// Constraint --> 1 <= m <= 10^5  ,, 0 <= arr[i] <= 10^9

// [ 2 5 6 8 ]  ---> YES
// one can apply the operation with x=3 to obtain the array [2,2,0,2] , and then apply the operation with x=2 to obtain [0,0,0,0] .

// [ 4 1 7 0 8 ]  --> NO

// LOGIC ------------------------>>

// OBSERVATION ---> 

// 1. If there is no 1, then I can make all elements equal to 0  --> mx se min. tk ek-ek baar modulo lenge array me.. each time mx zero honga
//      others will be most probably not changed

// 2. What if there is 1 ???

// CASES ----------------->>
// 1. If 1 and 0 sath me hai array me --> NO    .. x >= 2 ... BOTH CANT BE REDUCED
// 2. If 1 and 2 sath me hai array me --> NO  .. x >= 2 ... so 2 can only be reduced to 0 , not 1

// 3. If no 0 and 2 in array and there is 5 and 6 , THEN ---> 
// Suppose [1, 5, 6]
// Can we make 5 -> 1 ? ==> We will take 4 , array will be [1, 1, 2] -> 1 and 2 sath me ==> NO
// Can we make 6 -> 1 ? ==> We will take 5, array will be [1, 0, 1] -> 1 and 0 sath me ==> NO

// THEREFORE, If there are consecutive elements in Array in case 3 condition, Answer will be No


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve(){

    // Your code here
    long long n; cin >> n;

    bool one = false, two = false , zero = false;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];

        if(arr[i] == 1)  one = true;

        if(arr[i] == 2)  two = true;

        if(arr[i] == 0)  zero = true;
    }

    if(one && (zero || two))  cout << "NO" << endl;

    else if(!one) cout << "YES" << endl;

    else{
        
        sort(arr.begin(),arr.end());

        int i;
        for(i=1;i<n;i++){
            if(arr[i] == arr[i-1] + 1){
                cout << "NO" << endl;
                break;
            }
        }

        if(i==n) cout << "YES" << endl;

    }


}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}


