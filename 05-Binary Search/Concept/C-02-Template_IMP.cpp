
// *************************************** BINARY SEARCH ON ANSWERS ********************************************************


// PREDICATE Function is the condition on which we divide our array .. 
// For Eg: In last Index Qs => a[i] <= target             , In First Index Qs => a[i] >= target

// Predicate functions returns True and false values based on Our Condition for eacb element. 

// Binary Search works on the set of elements where the Predicate function applied on it as follows : 

// Set of Elements :  T T T ... T T F F ... F F F 

// Binary Search will move : l to mid when predicate is True  AND r to mid when predicate is False

// The Point where T and F are adjacent is called as Junction Point.. 

// The set of elements can be  F F F T T T based on your required goal


// ************************************** EXAMPLE ********************************************

// arr = 1 1 1 1 2 2 2 3 3 3 3 3 4 4 4  , target = 3

// Last Index ==>  Predicate Condition --->  a[i] <= Target .. 

// 1 1 1 1 2 2 2 3 3 3 3 3 4 4 4 
// T T T T T T T T T T T T F F F   --------------->> Last T is my Answer at the JUNCTION POINT

// First Index ==>  Predicate Condition --->  a[i] >= Target .. 

// 1 1 1 1 2 2 2 3 3 3 3 3 4 4 4 
// F F F F F F F T T T T T T T T  --------------->> First T is my Answer at the JUNCTION POINT

// NOTE : Your Answer will be either T or F of JUNCTION POINT, not other than that

// ************* REMEMBER ----------->>>>> 

// It is Recommended, not to change the Order, True ko left me hi rhne do, but agar nhi rkhna chahte then also no Issue, answer will not 
// change, T F ke jagah , ab F T ka JUNCTION POINT aayenga

// FIRST INDEX :  UPDATED PREDICATE function ===> a[i] < Target

// 1 1 1 1 2 2 2 3 3 3 3 3 4 4 4 
// T T T T T T T F F F F F F F F  --------------->> First F is my Answer at the JUNCTION POINT




// ********************************************** TEMPLATE *********************************************************


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

bool predicate(int m){

}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n =  6;

    int min = 0 , max = n - 1;  // This are the ranges

    int l = min-1, r = max+1;

    while (r-l > 1) {           // l < r - 1

        int m = (l + r) / 2;

        if (predicate(m))   l = m;
        else  r = m;

        // Shorter --> predicate(m) ? l = m : r = m;

    }

    // JUNCTION POINT : 
    cout << l << endl;               // L always points to Last True in T F junction
    cout << r << endl;               // R wlways points to First False in T F junction


    // In case of last occ. Ans is l
    // In case of first occ, Ans is r ( No matter aapne konsa T F or  F T ka junction lo )


    // ************************** CONVERTING T F  --> F T junction ************************************

    // predicate(m) ? r = m : l = m;

    return 0;

}


// POINTS TO NOTE ------>> 
// Never goes into an INFINITE LOOP 
// No Problem of taking ceil or Floor values
// RECOMMENDED -> To keep the T F junction ( NOT MANADATORY )

// ******************************** OUR TASK *************************************

// Observe the Question and Find the Predicate function such that the answer is always the LAST TRUE or the FIRST FALSE
// Simply, a function jo aapke answer ke search space me Ek junction pt. create kar paaye( Continous true's and then Continous False, Vice versa)


// ******************************** TIP ****************************************

// Wnenever there is Max-min Type of Question Such as Maximize the Minimum, or Minimize the Maximum ... BS on answer will help surely

// Question me Jo nikalne ko bola hai, Search Space ussi ki banti hai mostly i.e minimum time -> time ka Search Sapce , 
//                                                                               min. dist -> distance ka Search Sapce...


// For this -> Refer CP wali DSA notes book