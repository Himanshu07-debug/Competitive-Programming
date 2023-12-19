// We have an array of length n. Initially, each element is equal to 0 and there is a pointer located on the first element.
// Operations can be done infinitely --
// 1. If the pointer is not on the last element, increase the element the pointer is currently on by 1. Then move it to the next element.
// 2. If the pointer is not on the first element, decrease the element the pointer is currently on by 1. Then move it to the previous element.

// Finally You have to be to the First element
// You are given an array a. Determine whether it's possible to obtain a after some operations or not.

// Constraint --> -10^9 <= arr[i] <= 10^9  , 1 <= n <= 10^5

// [1, 0] --> NO
// [2, -1, -1, 0] --> YES
// [1, -4, 3, 0]  --> NO
// [1, -1, 1, -1] --> NO


// LOGIC -------------------->>

// OBSERVATION ---------------->>
// 1. Kyuki 0 i.e leftmost se start hua and Ussi me wapas jaana hai, Total sum will be 0 ... Weight distribute hue hai

// 2. First array element se sirf aage jaa sakte hai i.e arr[0] < 0 nhi ho skta And last wale se piche i.e arr[n-1] > 0 nhi ho sakta

// 3. IF arr[0] == 0 hua to aage nhi gye, value distribute nhi hua, i.e arr[1...n-1] sab 0 hone chahiye
// 4. If arr[0] > 0 hua to x times arr[1] pe gya, so arr[1] i.e arr[i+1] se utne hi baar wapas aana bhi possible hona chahiye.. 

// So if arr[0] = x then arr[1] = -x , but suppose arr[1] pe y hai, iska matlab arr[1] aage wale elements ke sath kuch operation krke y value 
// achieve kiya hai, so arr[1] pe value (y - (-x)) --> y + x hongi

// Yha pe humne ensure kar liye ki 0 se 1 jaana aur aana, now see for other i kya wo aage jaake piche aa sakte hai based on the array values given


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    int n; cin >> n;

    vector<long long>arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    bool flag = true;

    for(int i=0;i<n-1;i++){

        if(arr[i] < 0){
            flag = false;
        }
        else if(arr[i] == 0){
            for(int j = i+1;j<n;j++){
                if(arr[j] != 0){
                    flag = false;
                    break;
                }
            }
            break;
        }
        else{
            if(i + 1 < n) arr[i+1] += arr[i];            
        }

    }

    // Total sum should be 0 .. arr[i+1] is storing the Total sum becz each indx me hum Prefix sum hi to kar rhe hai
    if(flag){
        if(arr[n-1] > 0 || arr[n-1] < 0) flag = false;
    }
    

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

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