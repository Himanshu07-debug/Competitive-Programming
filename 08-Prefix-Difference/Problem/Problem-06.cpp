// A message is a sequence of n integers a1, a2, ..., an. Encryption uses a key which is a sequence of m integers b1, b2, ..., bm (m  ≤  n). 
// All numbers from the message and from the key belong to the interval from 0 to c - 1, inclusive, and all the calculations are performed modulo c.

// Encryption is performed in n - m + 1 steps. On the first step we add to each number a1, a2, ..., am a corresponding number b1, b2, ..., bm. 
// On the second step we add to each number a2, a3, ..., am + 1 (changed on the previous step) a corresponding number b1, b2, ..., bm. 
// And so on: on step number i we add to each number ai, ai + 1, ..., ai + m - 1 a corresponding number b1, b2, ..., bm. The result of the encryption 
// is the sequence a1, a2, ..., an after n - m + 1 steps.


// n = 4 , m = 3 , c = 2 
// 1 1 1 1
// 1 1 1
// OUTPUT -> 0  1  1  0


// LOGIC -->

// One thing is Very Clear ki Sliding Window Jaisa dikh rha hai but Sliding Window nhi laga sakte... Koi bhi Past window result ko use nhi kar
// naye window... firse Window Generate krni Padegi....


// Here, we are concerned with SUM ... Agar mai har indexes pe dekhlu window ka kaunsa element kitna contribute kar rha hai, I can find the value
// at that index ... Sum % c

// This is sliding window... b1 msg array to first element se n-m+1 index tak ke hi elements ke sum me Contribute krnga ...
// b2 -> second index se n - m + 2  
// b3 -> third index se n - m + 3


// This all contribution have range... We can Use Difference Array to Do this


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, m ,c;
    cin >> n >> m >> c;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin >> arr[i];

    vector<int> brr(m+1);

    vector<long long> diff(n+2,0);

    for(int i=1;i<=m;i++){
        cin >> brr[i];

        diff[i]+=brr[i];
        diff[n-m+i+1] -= brr[i];
    }

    long long sum = 0;

    for(int i=1;i<=n;i++){
        diff[i] += diff[i-1];

        long long res = ((sum%c) + (arr[i]%c))%c;
        cout << res << " ";
    }

    cout << endl;
    
    
    return 0;
}