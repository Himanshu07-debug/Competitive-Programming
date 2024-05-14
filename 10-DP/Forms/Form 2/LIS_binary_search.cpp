#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSp;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


// LIS ---> O(n^2)

// LIS Binary Search version   &&  PRINTING SOLUTION ----------------------------->>>

// 2 cases to keep in mind for this algo --------------->>

// CASE 1 -> 2 string ending with same value ( For example --> (1, 5, 7, 10) and (1, 5, 10) )
//        ==> Always optimal to keep the bigger one ( Longest increasing subsequence )


// CASE 2 -> 2 string with same value, (1, 2, 3) and (1, 5, 9)
//        ==> smaller ending value is preferrable ( there will be more room for independent )


// so the logic is simple --->
// We are concerned about last position, so for every indx moving from left to right, we have to find its position and put it..
// Remember, current indx i must be placed by getting a last position

// We will maintain a vector LIS...
// 1. if a value greater than last one is appeared, push it at the end.. uski position last hongi... array length increased by 1...
//     longer length will be get

// 2. if a value greater has its last position at the middle, place it there.. do not increase the array size... 
//    example --> curr = 3, (1, 2, 5, 6)
//                put in place of 5.. more room for improvement as it is smaller value


// for every indx element, we are finding the next greater value element position in LIS array....

// At last, array size is our answer.... 

// PRINTING solution ---->

// just start dry run for any input array --->
// LIS indx are the length positions.... Har ek indx ko down se dekhonge to 0 se LIS length tak jo element dikhenge.. wahi LIS hai
// keep track of last inserted positions of every element while building the LIS ----> 
// and use the below logic

int lengthOfLIS(vector<int>& arr) {

    int n = arr.size();

    vector<int> lis;

    // for printing purpose
    vector<int> insertedAt(n);

    for(int i=0;i<n;i++){

        if(lis.size() == 0 || lis.back() < arr[i]){
            lis.push_back(arr[i]);

            insertedAt[i] = lis.size();
        }
        else{
            // find the closest greater element position
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

            *it = arr[i];

            insertedAt[i] = it - lis.begin() + 1;
        }

    }

    vector<int> finalArray;
    int currLen = lis.size();

    for(int i=n-1;i>=0;i--){

        if(insertedAt[i] == currLen){
            finalArray.push_back(arr[i]);
            currLen--;
        }

    }

    reverse(finalArray.begin(), finalArray.end());

    // array size === LIS length
    return lis.size();    
 
}




int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    

    return 0;
}

