// Questions are of two types -> Direct and Indirect
// DIRECT -> It is said to use AND, OR, NOT ...
// IN-DIRECT -> Like in Q.s involves powers of 2 , it might relates to Bit Manipulation

// APPROACH --> 

// When solving a bitwise Problem, think in Bitwise .. Example -> 5 and 6 mat socho , Think 101 and 110


// ******************************************** NEGATION ****************************************************

// ~ x ==> - (x + 1)

// We know that ki 32 bit numbers ke liye int ki range -> [ -2^31 to 2^31 - 1 ].. HOW IN BIT ???

// Lets understand this with 4 bit -> Range -> [ -2^3 to 2^3 - 1 ]  => -8 to 7
// Remember first bit decides +ve and -ve ... 0 -> +ve and 1 -> -ve

// Positive No.s -> 0000 to 0111 ==> 0 to 7
// Negative No.s -> 1000 to 1111 ==> -8 to -15 

// NOTE -> All bit set is -1 ... Therefore -15 will be -1 ... -8 to -1 ...
// OBSERVE -> Range is same as INT for 32 bits

// Apan log 5 ko sirf 101 consider krte hai, but uske aage ke saare Zeroes 1 ho jaate hai in negation therefore OVERFLOW hota hai to -ve


// ********************************* OTHER OPERATION ****************************************************

// AND, OR, XOR ..................

// Left shift --> A << b ==> A * 2^b (Multipying by 2 b times)

// Right shift --> A >> b ==> A / 2^b (Dividing by 2 b times)


// ****************************** BIT MASKING ***************************************

// A bitmask is a sequence of N bits that encodes a SUBSET, where the element is taken if bit is set, and not taken if bit is unset
// Ex -> 10110  --> mean indexes 1,2,4 are taken, while 0,3 are not


// QUESTION --> Generating all subsets of the Array ... 

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

typedef long long ll;


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    ll n; cin >> n;

    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0; i < (1 << n) ;i++){  // UPTO 2^n - 1
        for(int j=0; j<n; j++){
            if(i & ( 1 << j )){                             /// Other -> (i >> j) & 1
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    
    



// QUESTION --> Find Complement of N but while finding Complement .. Consider only upto MSB,  Do not consider the leading zeroes 

// This means from N Complement ~N , apne ko samne ke 1 hatane padenge jo aage ke zeroes ke wajah se aaya

// Suppose N ki length x hai then 2^x - 1 will give all x bits set .. We can AND this with ~N


    ll y; cin >> y;

    int l = 0;
    while( y >> 1) l++;            // Finding length upto MSB

    cout << ((~y) & ((1 << l) - 1));



// GENERALLY, there are 2 types of Problem ================>>>

// 1. Bit Independent -> Can solve for each bit separately. The solution of bit x will not depend on the solution for bit y

// 2. Bit Dependent -> Cannot solve for each bit separately. All the bits are interconnected. (Addition -> Carry prev. bits ka)



    return 0;
}
