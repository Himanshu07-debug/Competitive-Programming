// Find 3 different positive integers x , y , and z such that exactly one of them is good and the other 2 are nearly good, and x + y = z .

// The integer is good if it is divisible by A * B
// Otherwise, the integer is nearly good, if it is divisible by A

// 1 <= A, B <= 10^6

// LOGIC -->

// If B = 1, solution do not exist becz A + 2A = 3A .. All numbers are divisible A * B .. No nearly good numbers

// A + A*B = A*(1 + B)    OR  A + (B - 1)*A = A*B

// This will give us the valid solutions, A*B is good, rest others are Not good


#include <bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;

    while (q--) {
        int a, b; cin >> a >> b;
        if (b == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a << ' ' << a * 1ll * b << ' ' << a * (long long)(b + 1) << endl;
        }
    }
}

