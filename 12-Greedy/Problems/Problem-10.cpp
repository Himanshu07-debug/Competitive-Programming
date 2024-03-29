// You are given two 0-indexed integer arrays nums1 and nums2, both of length n.

// You can choose two integers left and right where 0 <= left <= right < n and swap the subarray nums1[left...right] with the subarray 
// nums2[left...right].

// For example, if nums1 = [1,2,3,4,5] and nums2 = [11,12,13,14,15] and you choose left = 1 and right = 2, nums1 becomes [1,12,13,4,5] 
// and nums2 becomes [11,2,3,14,15].
// You may choose to apply the mentioned operation once or not do anything.

// The score of the arrays is the maximum of sum(nums1) and sum(nums2), where sum(arr) is the sum of all the elements in the array arr.
// Return the maximum possible score.


// Input: nums1 = [60,60,60], nums2 = [10,90,10]
// Output: 210
// Explanation: Choosing left = 1 and right = 1, we have nums1 = [60,90,60] and nums2 = [10,60,10].
// The score is max(sum(nums1), sum(nums2)) = max(210, 80) = 210.


// Constraint --> 1 <= n <= 1e5  , nums1.size() == nums2.size()


// LOGIC --------------------------------------->>

// Hum ek hi subarray choose kar sakte hai.. 
// if nums1 me values bigger hai, humko aaisa subarray choose krna padega jiska sum / Contri. nums1 me kam and nums2 me jyada hai.. ussi ko SWAP
// krke profit honga nums1 ke answer me
// Similar case if nums2 me values bigger hai...


// Inorder to do this, humko nums2[i] - nums1[i] se bane array me KADANE lagana padega for sum(nums1) .. So that max diff subarray sum mil jaaye
// For sum(nums2) , humko nums1[i] - nums2[i] se bane array me KADANE lagana padega .. So that maximum difference sum mil jaaye


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

long long max_diff_sum(vector<long long> arr1, vector<long long> arr2, int n){

    vector<long long> diff(n);

    for(int i=0;i<n;i++){
        diff[i] = arr2[i] - arr1[i];
    }    

    long long sum = diff[0];
    long long ans = diff[0];

    for(int i=1;i<n;i++){

        sum = max(diff[i],sum + diff[i]);

        ans = max(ans, sum);

    }

    return ans;

}

void solve() {

    int n; cin >> n;

    vector<long long> arr(n) , brr(n);

    long long t1 = 0, t2 = 0;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        t1 += arr[i];
    }  

    for(int i=0; i<n; i++){
        cin >> brr[i];
        t2 += brr[i];
    }  

    long long sum1 = max_diff_sum(brr,arr,n);

    long long sum2 = max_diff_sum(arr,brr,n);

    cout << max(t1 + sum1 , t2 + sum2) << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}


