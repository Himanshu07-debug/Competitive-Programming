// Given an array of n integers ai . Let's say that the segment of this array a[l..r] (1≤l≤r≤n ) is good if the sum of elements on this 
// segment is at most s . Your task is to find sum of lengths of all good segments.

// LOGIC -------->>

// Here Sum of the length of Subarrays chahiye....
// Number of Subarrays wale Question me hum current j se end hone wale kitne subarray find kar rhe the.. 
// To koi bhi Valid Window ko observe kronge to usme Length 1 + 2 + .. + window size
// EXAMPLE --> [1,2,3] => 3 se end hone wale 3 subarrays -> [1,2,3] , [2,3] , [3] -> Length ko dekho ..  3 + 2 + 1... 

// So for valid window of length x , Sum of all length of all subarrays ending with current indx j is x * (x + 1)/2 (kyuki series A.P hai)


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, k; cin >> n >> k;

    vector<long long > arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    int i=0 , j = 0;

    long long sum = 0;

    long long res = 0;

    while(j < n){

        sum += arr[j];

        while( i<=j && sum > k){
            
            sum -= arr[i];

            i++;
        }

        long long x = (j - i + 1);

        res += (x * (x + 1))/2;

        j++;

    }

    cout << res << endl;


    return 0;
}

