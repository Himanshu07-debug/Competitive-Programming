// You are given two arrays a and b, sorted in non-decreasing order. Find the number of pairs (i,j) for which a[i] == b[j]

// a = [1 1 3 3 3 5 8 8]
// b = [1 3 3 4 5 5 5]
// Output -> 11

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n , m; cin >> n >> m;

    vector<int> arr(n), brr(m);

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<m;i++) cin>> brr[i];

    int i=0, j = 0;

    long long cnt = 0;

    while(i < n && j<m){

        if(arr[i] < brr[j]){
            i++;
        }
        else if(arr[i] > brr[j]){
            j++;
        }
        else{
            long long c = 0;
            
            int x = arr[i];

            while(j < m && brr[j] == x){
                c++;  
                j++;
            }

            while(i < n && arr[i] == x){
                cnt += c;
                i++;
            }

        }

    }

    cout << cnt << endl;
        

    return 0;
}

