// Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

// AAAACACBA  ---->> AACABACAA

// Constraint : 1 <= n <= 10^6

// LOGIC : Apko sirf bola hai reorder kro, matlab aap koi bhi possible palindrome bana sakte ho, so Apne ko sirf yeah find krna hai ki
//         given string se palindorme ban sakta hai kya, If YES, then will print any

// Given string is Paliondrome or NOT ?? 
// agar sabki frequency nikal liye to bta sakte hai ki given characters se palindrome banega kya, for EVEN n , we want all cnt as even,
// and for ODD n, ek odd cnt bhi chalega


#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1;

string reorderToPalindrome(string s) {
    int n = s.size();
    unordered_map<char, int> charCount;

    for (int i = 0; i < n; i++) {
        charCount[s[i]]++;
    }

    int odd = 0;
    for (const auto &entry : charCount) {
        if (entry.second % 2 != 0) {
            odd++;
            s[n / 2] = entry.first;   // odd wla placed at center
            charCount[entry.first]--;
            // if (charCount[entry.first] == 0)  --->> hum yeah nhi kar sakte idhar, kyuki hum MAP me hi traverse kar rhe hai, changing it will 
            //                                         give error
        }
    }

    // string me ek se more than 1 odd characters hai
    if (odd > 1) {
        return "NO SOLUTION";
    } else {

        // EDGE CASE -> To remove the odd character with cnt = 1, jo ab 0 ho gya becz usko middle me fill kar diye already.. Remove IT
        for (char c : s) {
            if (charCount.find(c) != charCount.end() && charCount[c] == 0) {
                charCount.erase(c);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            auto it = charCount.begin();
            s[i] = s[n - i - 1] = it->first;
            charCount[it->first] -= 2;
            if (charCount[it->first] == 0) {
                charCount.erase(it);
            }
        }

        return s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string palindrome = reorderToPalindrome(s);
    cout << palindrome << endl;

    return 0;
}


