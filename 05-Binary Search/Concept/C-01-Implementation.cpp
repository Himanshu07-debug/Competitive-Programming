#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


// *********************************************************** Binary Search Variations *************************************************

// Agar hum teeno indexes ke change handle kar rhe hai i.e mid, mid - 1, mid + 1, Then left <= right

bool search1(vector<int> a, int target) {
    int left = 0, right = a.size() - 1;

    while (left <= right) {

        int mid = (left + right) / 2;

        // Only 3 cases are handled
        if (a[mid] == target)
            return true;

        if (a[mid] < target) left = mid + 1;
        if (a[mid] > target) right = mid - 1;
    }

    return false;
}


// Question -> FIND THE LAST INDEX OF THE TARGET

// Hum log isko bhi variation 1 me ans = -1 variable leke kar sakte hai, But Agar ans use nhi karna hai toh -> 

// In such case, You have to decide ==
// l = mid OR r = mid 
// ---> Koi bhi ek array banake target ke liye check karlo, Easy hai ( OBSERVATION )
// Either to take floor value of mid or ceil value
// ---> Target ke occ ke corners pe check krlo, Ensure kro ki jiss pointer ko mid ke equal kronge.. mera calculated mid wo pointer naa aaye 
// Eg : Smajho Range is [l,r] and app l = mid kar rhe ho.. Then calculate mid kabhi bhi l naa aaye ..(similarly jiss bhi pointer se equate kronge)


int search2(vector<int> a, int target) {

    int left = 0, right = a.size() - 1;

    while (left < right) {

        // Ceil calculation
        int mid = (left + right + 1) / 2;

        // Only 2 cases are Handled
        if (a[mid] <= target) left = mid;
        if (a[mid] > target) right = mid - 1;
    }

    return (a[left] == target) ? left : -1; 
}

// Eg : [2,2] -> floor value liye to mid = 0, l = 0, l != r and Range is not changed, Therefore kitne baar bhi iterate kronge, mid, Range change 
//              nhi honga , left < right condition kabhi break nhi hongi and INFINITE LOOP honga, Isliye humne CEIL liye


// Question -> FIND THE FIRST INDEX OF THE TARGET

int search3(vector<int> a, int target) {
    int left = 0, right = a.size() - 1;

    while (left < right) {

        // FLOOR CALCULATION
        int mid = (left + right) / 2;

        if (a[mid] < target) left = mid + 1;
        if (a[mid] >= target) right = mid;
    }

    return (a[left] == target) ? left : -1;   // left == right .. So left yaa right kisi se bhi check kar sakte ho
}


// ****************************************** POINTS TO NOTE IN BINARY SEARCH ******************************************


// • If you are stopping when L = R, check if (L+R)/2 should be floored or ceiled. It might be an infinite loop otherwise.

// • Whenever You are making Intuition or Testing Your Code of Binary Search, always take Even length arrays, so that multiple conditions can be 
//   test

// • Make sure your boundaries are correct. 

// • You can use L + ((R-L)/2) to avoid errors in some cases where L+R can overflow. For ceil -> L + ((R - L + 1)/2)

// • If you ever need to run binary search on an infinite list, you can use LLONG_MAX or some other appropriate value as the upper-bound


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    
    
    
    return 0;
}