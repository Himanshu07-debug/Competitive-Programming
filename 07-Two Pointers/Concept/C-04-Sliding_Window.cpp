#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


// SLIDING WINDOW =================>>

// Sliding window is of 2 types, -> variable sized Sliding window and Fixed sized Sliding window

// Whatever we had seen by Two pointers till now ==> Variable Sized Sliding window...
// NOTION --> So hum usko 2 pointers hi consider krnge

// We will assume Sliding window means only Fixed Sized window Questions .. Two pointers ke liye Good Segment Technique


// Fixed Sized Sliding Window => The Size of the window is Provided in the Question i.e Fixed Length ke Window [i .. j] banege

// This is Easy than Variable one.. fixed sized Window ko check kro


// Q.s --> 
// 1. Maximum Sum Possible among all the Subarrays of Size 3 .. [ Subarray i.e Window size is FIXED ]


void maxSumSubarray(vector<int> arr, int n,int k){

    long long ans = 0;

    long long sum = 0;

    for(int i=0;i<k-1;i++){
        sum += arr[i];
    }

    for(int i=k-1;i<n;i++){

        sum += arr[i];

        ans = max(ans, sum);

        sum -= arr[i - k + 1];

    }

}

// REMEMBER -> Time Complexity of Sliding Window is do not depend on K becz O(k) + O(n - k)  --> O(n) .. Hum n se upar iteration nhi kar rhe


// Find the first negative elements in every subarray of size K ... 

void maxSumSubarray(vector<int> arr, int n,int k){

    vector<int> ans;

    queue<int> q;

    for(int i=0;i<k-1;i++){
        if(arr[i] < 0){
            q.push(i);
        } 
    }

    for(int i=k-1 ,l = 0 ; i<n ;i++ ,l++){

        if(arr[i] < 0){
            q.push(i);
        } 

        if(q.size()) ans.push_back(q.front());

        if(q.front() == l){
            q.pop();
        }

    }

    for(int x : ans) cout << x << " ";

    cout << endl;

}


// 3. Find the Median of all the Subarray of Size K

// [5,1,2]  -> Median ==> 2 ( [1, 2, 5] )

// NOTE -> Yha pe window ke elements Sorted Chahiye, SET, but Set me k/2 index pe jaane ke liye O(k/2) time lagega, set + indx => PBDS


void Median(vector<int> arr, int n,int k){

    vector<int> ans;

    PBDS s;

    for(int i=0;i<k-1;i++){

        s.insert({arr[i],i});

    }

    int mid = (k&1) ? k/2 : (k/2) - 1;

    for(int i=k-1 ,l = 0 ; i<n ;i++ ,l++){

        s.insert({arr[i], i});

        pair<int,int> x = *s.find_by_order(mid);

        ans.push_back(x.first);

        s.erase({arr[l], l});

    }

    for(int x : ans) cout << x << " ";

    cout << endl;

}

// REMEMBER -> In Linear based Data Structures like Array, vector, etc -> elements are stored in Contigous Memory location so there it + 3 takes 
//              O(1) time ... 
//              But in Non-Linear DS like set, List, tree, map, etc -> no contigous memory allocated elements and In this, a element store 
//              only the address of its next connected element and Hence there, it + 3 takes O(3) time .. Ek-Ek krke jayenge 




// *************************************** TIP *******************************************

// In Sliding Window, Your current window should store enough Information to get the answer for that Window...
// This means, Try to fulfill all the Q.s need for the Window so that Our Window se hum answer nikal paaye

// NOTE -> You have to ensure this While Solving Fixed Sized Sliding Window Question ... 

// In Sliding Window, queue, list, deque are used .. 




