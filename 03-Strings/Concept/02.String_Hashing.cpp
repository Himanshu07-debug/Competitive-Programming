// Humne String Hashing DSA book me dekhe hai.. We take a Prime value X and uske diff-diff powers se string ke characters ko multiply krte hai..
// This helps to reduce COLLISIONS ... 

// NOTE -> Agar each position pe X ke diff powers se nhi krnge to abc and cba same HASH value denge kyuki similar characters hai dono me ...


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

long long get_hash(string s){

    long long h = 0;

    for(char c : s){

        h = (h * 31 + (c - 'a' + 1)) % MOD;

    }

    return h;
}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    cout << get_hash("abc") << endl;                       

    // Comparison --> 
    cout << (get_hash("dbc") == get_hash("dbc")) << endl;  

    // Both line above take O(n) time ...


    // Here also Collision can occur becz we are finding HASH value by taking MODULO ( CYCLE ) ..
    // Probability of Collisions ---->> 1 / MOD ==> 1 / 10^9

    // How we can more OPTIMIZE IT ??? 
    // REMEMBER -> We cant optimize the MOD value as it is the max. that we can take .. 

    // 1. Use DOUBLE HASHING --> 
    // MOD Se bhi hash value nikalo and Another Prime no. 98245.. (GOOGLE) se bhi hash nikalo.. Now if agar both hashes match hue, them CORRECT
    // Probability of Collisions now become ---->> 1 / (MOD * MOD) ==> 1 / 10^18


    // 2. Prefix Hashes

    // ******************************* PREFIX HASHES *****************************************************


    // For String =======>> " abcd " 

    // PREFIX ARRAY -->  [ a , pow(31,1)*a + b , pow(31,2)*a + pow(31,1)*b + c , pow(31,3)*a + pow(31,2)*b + pow(31,1)*c + d  ]

    // Hash value of s[i,j] => ( prefix[j] - [ prefix[i-1] * pow(31, j - i) ] ) 


    // "cd" ki hash value from "abcd" ----------------------> 
    // ( pow(31,3)*a + pow(31,2)*b + pow(31,1)*c + d ) - [ (pow(31,1)*a + b) * pow(31,2) ] ==> pow(31,1)*c + d



    // WHY MULTIPLICATION WITH pow(31, j - i) to the prefix[i-1] ??
    // Same like Left shift .. abcd se ab subtract krna hai to phle ab ko uske place pe laana honga i.e abcd - ab__ => cd .. 
    // "ab" ko 2 baar left shift kiye i.e multiplication with 31^2

    // abcd - ab will give wrong O/P ... Same like 989 - 9 = 980 but we want 989 - 900 = 89



    // Contribution in prefix -> Leftmost 1 > leftmost 2 > leftmost 3

    // PROBLEM ------------------------------>>>>

    // Suppose agar Q queries di hai and apko Strings ke substring compare krna hai i.e s1[i1...j1] == s2[i2...j2] , THEN --> 
    // NAIVE se kiye to O(N * Q) 
    // By Prefix Hash , it will take O(N + Q)


    // RABIN KARP (Pattern Matching) ----------------------------->>>

    // String S & t given.. Find where t occurs in S .. 
    
    // Rabin karp => Sliding window + Prefix Array (String wla)

    // We have done in DSA book in a very nice way .. Only take d = 31 there..
    // NOTICE -> In book, we are not multiplying by powers, we are taking d^(m-1) .. This is also a Good WAY and also easy to understand

    // Why we are checking for Spurious hits ??
    // As its modulo, ho skta hai kisi string ka same hash value aaye lekin wo pattern t ke equal na ho.. Therefore it is important to check


    
    // ************************************ TIP ******************************************

    // Whwnwver you have to compare lots of strings, use STRING HASHING

    // If bhut saare test cases pass ho gye and error big length strings me aa rha hai, then hashing me collision aane se ho sakta hai Error

    // NOTE ---> 
    // If String Contains only lowercase letters         --> p = 31
    // If String Contains mix of uppercase and lowercase --> p = 53

    // In DOUBLE HASHING --> 
    // lowercase letters -> p1 = 29 and p2 = 31
    //  mix              -> p1 = 53 and p2 = 127
    // MOD-1 = 1e9 + 7  ... MOD-2 = 1e9 + 9

    
    return 0;
}