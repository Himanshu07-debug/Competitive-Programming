// You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.
// The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and 
// we assume that the median is the smaller of them.

// 8 3
// 2 4 3 5 8 1 2 1
// Output:
// 3 4 5 5 2 1

// LOGIC --> 

// For getting the median, we have to keep the data of the window in SORTED ORDER... Set can Help but how you will find the middle element index..
// Set + Indx --> PBDS will help


#include<bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds; 
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
 
#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
 
// ERASE FUNCTION
void myerase(PBDS &t, int v){
    int rank = t.order_of_key(v);
    auto it = t.find_by_order(rank);
    t.erase(it);
}
 
 
int main(){
 
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    // Your code here
    
    int n, k;
    cin >> n >> k;
 
    vector<int> arr(n);
 
    int m = k/2;
 
    if(!(k&1)) m--;
 
    for(int i=0;i<n;i++) cin >> arr[i];
 
    PBDS st;
 
    for(int i=0;i<k-1;i++){
        st.insert(arr[i]);
    }
 
    for(int i=k-1;i<n;i++){
        st.insert(arr[i]);
        auto it = st.find_by_order(m);
        cout << *it << " ";
        myerase(st,arr[i-k+1]);
    }
 
    
    return 0;
}