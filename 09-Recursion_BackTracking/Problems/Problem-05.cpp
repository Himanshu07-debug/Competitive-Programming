// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the 
// chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the 
// chosen numbers is different.


// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// Constraint --> 1 <= candidates.length <= 30


// LOGIC --> 

// We have two choices -> either continuing with the same indx element or skip the Current element


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(vector<int> &nums, vector<int> &temp, int target, int sum, vector<vector<int>> &ans, int indx){

        if(sum == target){
            ans.push_back(temp);
            return;
        }

        if(sum > target || indx == nums.size())  return;

        // Pick element
        temp.push_back(nums[indx]);
        solve(nums, temp, target, sum + nums[indx], ans, indx);  // not incrementing indx
        temp.pop_back();


        // Do not Pick
        solve(nums, temp, target, sum, ans, indx + 1);    // incrementing indx

}


void fun(){

    // Your code here

    int n;  cin >> n;

    vector<int> nums(n);

    for(int i=0;i<n;i++) cin >> nums[i];

    int target; cin >> target;

    vector<vector<int>> ans;

    // To ensure that Duplicates remains Together
    sort(nums.begin(),nums.end());

    vector<int> temp;

    solve(nums, temp, target, 0 ,ans, 0);

    for(auto &x : ans){
        for(auto y : x) cout << y << " ";
        cout << endl;
    }
    

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        fun();
    }
    
    return 0;

}

