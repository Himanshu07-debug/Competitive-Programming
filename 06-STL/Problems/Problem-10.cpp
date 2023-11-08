// Given a circular integer array arr (i.e., the next element of arr[arr.length - 1] is arr[0]), return the next greater number 
// for every element in arr.

// Input: arr = [1,2,1]
// Output: [2,-1,2]
// The first 1's next greater number is 2
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.


// LOGIC --> 

// We had used STACK to solve(optimize) the Problem in a non-circular array.. 

// Jab bhi circular array aaye, either append the array to the back of the original array or If k given, go for Sliding window

// Appending is the Most used Techinque as it is then easy to make LOGIC


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// NAIVE ------------------------>> 

void naive(){

    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> ans;

    for(int i=0;i<n;i++){

        int e = -1;
        int j = (i+1)%n;

        // moving Circular
        while(j != i){
            if(arr[j] > arr[i]){
                e = arr[j];
                break;
            }
            j = (j+1)%n;
        }

        ans.push_back(e);
    }

}


void solve(){

    // Your code here

    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];


    vector<int> ans(n,-1);
    stack<int>s;

    for(int i=2*n-2;i>=0;i--){

        while(!s.empty() && s.top() <= arr[i%n] ){
            s.pop();
        }

        ans[i%n] = s.empty() ? -1 : s.top();

        s.push(arr[i%n]);

    }

    for(int x: ans) cout << x << " ";

    cout << endl;
    
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
    }
    
    return 0;

}