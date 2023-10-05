#include<bits/stdc++.h>
using namespace std;

int main(){

    // max of 2 numbers
    int x = max(2,4);

    // Remember, in max, min function, both the number should be of same datatype

    // So if you have one number as int and another as long long
    int a = 5;
    long long b = 6;

    long long mx = max((long long)a,b);             // Same for min()

    // Max of 3 numbers

    long long c = 10;

    mx = max((long long)a,max(b,c));

    // Max of more than 3 numbers:

    long long d = 15;
    long long e = 12;
    long long z = a , g = b;

    mx = max( { b, c, d, e, g} );

    

    return 0;

}