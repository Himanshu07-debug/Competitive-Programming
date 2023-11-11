// Given an integer array nums that may contain duplicates, return all possible subsets
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Constraints : 1 <= nums.length <= 10


// LOGIC --> 

// Observations From Recursion Tree -->
// Element Ko non-pick krne ke baad non-pick wale value ka element exactly next aa rha hai uss Subtree me, then Duplicates ban rhe hai becz  
// Uss element ko Pick krke hum left subtree me saare possible subsets bana chuke hai

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int indx){

        if(indx == nums.size()){
            ans.push_back(temp);
            return;
        }

        // Pick element
        temp.push_back(nums[indx]);
        solve(nums,temp,ans,indx + 1);
        temp.pop_back();

        while(indx + 1 < nums.size() && nums[indx] == nums[indx + 1]) indx++;

        // Do not Pick
        solve(nums,temp,ans,indx + 1);

}


void fun(){

    // Your code here

    int n;  cin >> n;

    vector<int> nums(n);

    for(int i=0;i<n;i++) cin >> nums[i];

    vector<vector<int>> ans;

    // To ensure that Duplicates remains Together
    sort(nums.begin(),nums.end());

    vector<int> temp;

    solve(nums, temp, ans, 0);

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