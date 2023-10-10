// Given 4 numbers A, B, C and D . Print the last 2 digits from their Multiplication. ( A * B * C * D)

// Constraints : 2 <= A,B,C,D <= 10^9

#include<bits/stdc++.h>
using namespace std;

int main(){

    // Normal Multiplication was not Possible due to numbers constraint. 
    // So we used an arr[100] size to store the multiplication result and returns the last 2 numbers.
    // We got AC by doing this

    // But is this Required , We have to only concern about the last two digits.
    // Matlab hum sirf a,b,c,d ke last ke two numbers ko hi consider krke multiply kiye to ans mil jaenga

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    a = a%100;
    b = b%100;
    c = c%100;
    d = d%100;

    long long ans = a*b*c*d;

    ans = ans % 100;

    // Edge case - if last two characters are 00 to 09
    if(ans<10){
        cout << 0 << ans;
    }
    else{
        cout<<ans;
    }

    return 0;
}