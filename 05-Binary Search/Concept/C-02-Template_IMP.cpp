
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

// 1. Wnenever there is Max-min Type of Question Such as Maximize the Minimum, or Minimize the Maximum ... BS on answer will help surely

// 2. Question me Jo nikalne ko bola hai, Search Space ussi ki banti hai mostly i.e minimum time -> time ka Search Sapce , 
//                                                                                  min. dist -> distance ka Search Sapce...

// 3. Always Ask Yourself the Question, If x is possible , Can x - 1 is possible ? OR if x is possible, can x + 1 is possible ?

// 4. In BS Problems, Don't think too much.. Agar Problem max/min value pucha hai jo koi condition ko satisfy kar rha ho.. Use BS...
//    Implementation -> (a) Search Space where your answer can lie  
//                      (b) In the Predicate, write the logic for the condition specified in Problem, if condition satisfy, return true, or false
//                      (c) Decide on true/false , which half of the search space can be neglected .. (Pt. 3)


// 5. Our job is to only write the proper Predicate function so that any value given to func can be determined that it satisfies the condition or 
//    not.. And thoda sa movement dekhlo true hone pe kha jaana hai... Do not think much that BS min/max satisfying pt. ka answer kaise denga..
//    Aap sirf Predicate likh do and BS pe leave krdo all Job... This is becz ->
//    BS helps in finding the maximum/minimum satisfying value in your answer search space where the condition given in particular Q. satisfies..
//    Threshold pt. / Junction pt.   

// For this -> Refer CP wali DSA notes book