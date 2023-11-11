// There are n apples with known weights. Your Task is to divide the apples into two grps so that the diff. between the weights of the groups is
// minimal

// [3, 2, 7, 4 ,1]  ==> 1 .. [3, 2, 4] & [1, 7]

// Constraint --> 
// 1 <= n <= 20
// 1 <= arr[i] <= 10^9


// LOGIC ---> 

// Pick - Not_Pick logic se saare possible subsets ka sum generate kar sakte hai... 
// CAN WE USE RECURSION ?? 
// YES, becz the constraint of N is very Small .. Allowing You to do 2^n operations

#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// In RECURSION for CP, take variables as Global to avoid some errors...
int n;
int arr[23];
int total_sum = 0;

int solve(int i=0, int current_sum=0){

    // TIP --> Agar aap sirf -1 ke alawa bhi bade no. se minus kar rhe ho, then USE --> (i >= n)
    if(i == n){
        int other_set_sum = total_sum - current_sum;
        return abs(current_sum - other_set_sum);
    }

    int pick  = solve(i+1,current_sum + arr[i]);
    int not_pick = solve(i+1, current_sum);

    // For DEBUGGING ---> cout << i << " " << current_sum << endl;

    return min(pick ,not_pick);

}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        total_sum += arr[i];
    }
   
    cout << solve() << endl;
    
    return 0;
}