// Duff is a Weight Lifter. That's why in each step, she can only lift and throw away a sequence of weights 2^a1, ..., 2^ak if and only if there 
// exists a non-negative integer x such that 2^a1 + 2^a2 + ... + 2^ak  =  2^x, i. e. the sum of those numbers is a power of two.
// Help her minimize the number of steps.

// She have a sequence of weights. Weight of i-th of them is 2^w[i] pounds.

// 1 1 2 3 3  --> 2 ( First 4 no.s => 2 + 2 + 4 + 8 => 16  in 1 step AND last 3 i.e 2^3 => 8 in second step )
// NOTE -> Total sum 2 ke powers ka 24 aa rha tha i.e not Power of 2 isliye Pura array remove nhi kar sakte ek step me


// 0 1 2 3  ---> 4 ( Each step me ek-ek number )

// Constraint ->  1 <= n <= 10^6 .. 0 <= w[i] <= 1e6


// LOGIC ----------------------------------->>>>

// Sequence of no.s lena hai i.e subset, Contigous no.s nhi lena hai ( SUBARRAY )

// OBSERVATION ========================================================================> 

// If You will sum the whole 2^arr[i] of array , the no. of bits in the Total sum will be the answer ..

// NOTE --------------------->>>
// Kyuki humne Total sum 2 ke powers ko add krke banaye hai, To agar bit SET aa rha hai Total sum me to wo ->
// Yaa to sequence of powers of 2 se bna honga OR single power of 2 se bna honga


// Example ->  [1, 1, 2, 3, 3]  -> 10 + 10 + 100 + 1000 + 1000  ===> 11000  -> 2^4 and 2^3 ans are possible 


// CATCH in this Question ------------------->>>

// Here 0 <= w[i] <= 1e6  ---> so 2^(1e6) ==>  10^6 bits possible hai 
// (jaise hum 2^31 me 31 bits ka array banate the, yha pe 10^6 possible hai)


// 10^6 + 18 ka banaenge becz 10^6 carry Possible hai last element se so log(10^6) baar aur aage jayega carry ke wajah se ...


// NOTE this formula ---------------->>
// If cnt of 2^x is y , THEN -->
// Apne position bit pe -> (y%2) * 2^x  AND carry to next bit --> (y/2) * 2^(x+1)



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n; cin >> n;

    vector<long long> arr(1000020, 0);

    for(int i=0;i<n;i++){
        int x; cin >> x;

        arr[x]++;
    }

    long long cnt = 0;

    for(int i=0;i<1000020;i++){

        arr[i+1] += arr[i]/2;

        cnt += (arr[i]&1);

    }

    cout << cnt << endl;
    
        
    return 0;
}