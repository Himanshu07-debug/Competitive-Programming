// The bear has a string s = s1 s2 ... s|s| (record |s| is the string's length), consisting of lowercase English letters. 
// The bear wants to count the number of such pairs of indices i, j (1 ≤ i ≤ j ≤ |s|), that string x(i, j) = s[i] s[i + 1]... s[j] contains at 
// least one string "bear" as a substring.

// String x(i, j) contains string "bear", if there is such index k (i  ≤  k  ≤  j - 3), that s[k] = b, s[k + 1] = e, s[k + 2] = a, s[k+ 3] = r.


// Input --> bearbtear
// O/P -> 6 [ (1, 4), (1, 5), (1, 6), (1, 7), (1, 8), (1, 9) ]

// Input --> bearaabearc
// O/P -> 20
// (1,  4), (1,  5), (1,  6), (1,  7), (1,  8), (1,  9), (1,  10), (1,  11), (2,  10), (2,  11), (3,  10), (3,  11), (4,  10), (4,  11), (5,  10), (5,  11), (6,  10), (6,  11),
//  (7,  10), (7,  11)


// LOGIC --------------->>>

