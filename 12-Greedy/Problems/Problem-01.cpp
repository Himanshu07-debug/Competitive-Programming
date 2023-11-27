// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents 
// your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.


// [2,3,1,1,4] -> YES (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
// [3,2,1,0,4] -> NO

// Constraints:
// 1 <= nums.length <= 10^4
// 0 <= nums[i] <= 10^5


// LOGIC --------------------------->>>

// If arr[i] = 3, means mai 1, 2, 3 tk ka jump le sakta hu

// RECURSION mat sochna, See Constraints

// So, Hum Max Reachable index ka track rkhenge, 

// Agar Kisi bhi moment pe hum maxReachable index se jyade index pe aa gye, means there was no way in Previous indexes to reach at the current
// indx, therefore Not Possible to go further and Hence Return FALSE


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void canJump(vector<int>& arr) {

    int n = arr.size();

    int maxReach = arr[0];

    for(int i=1;i<n;i++){

        if(i <= maxReach){
            maxReach = max(maxReach, i + arr[i]);
        }
        else{
            cout << "NO" << endl;
            return;
        }

    }

    if(maxReach >= n-1) cout << "YES" << endl;

    else    cout << "NO" << endl;
        
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    canJump(arr);
    
        
    return 0;
}