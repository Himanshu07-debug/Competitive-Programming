// Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

// txt = forxxorfxdofr  .. pat = for   ----> 3
// txt = aabaabaa  ... pat = aaba      ----> 4

// Constraint -> 1 <= pat <= txt <= 10^5


// LOGIC -> 

// Yha pe Size is fixed and it is required to be contigous --> SLIDING WINDOW
// Cnt[26] OR cnt[256] ke 2 array banalo, ek Pattern ka aur Ek for current Window.. 
// The important thing to note is, time complexity to compare two count arrays is O(1) as the number of elements in them are 
// fixed (independent of pattern and text sizes )


// But If we use vector, we can compare them in if statement like Strings.. So we will use it...

#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1;

int main(){

    int n; cin >> n;

    string txt, pat;

    cin >> txt >> pat;

    int k = pat.size();

    vector<int> arr(26), brr(26);

    for(int i=0;i<pat.size();i++){
        arr[pat[i]-'a']++;
    }

    for(int i=0;i<k-1;i++){
        brr[txt[i]-'a']++;
    }

    long long ans = 0;

    for(int i=k-1;i<txt.size();i++){
	    brr[txt[i]-'a']++;
        if(arr == brr) ans++;
        brr[txt[i-k+1]]--;
	}

    cout << ans << endl;


}

// *************************** VARIATION OF THIS QUESTION **********************************

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").


// Permutation is also same as Anagram.. Order of characters can be anythings but they must be contigous of the size of window