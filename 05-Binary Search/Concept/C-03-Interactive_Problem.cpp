// ********************* WHAT ARE INTERACTIVE PROBLEMS ??? ***************************************************

// In Interactive Problems, you get answers for your queries. Output a query, and an Input will be given as the answer by the JUDGE

// For Example -> You Ouput 3, this your query, now Judge will give the value at index 3 for the array that is internally make my the 
//                Judge for the Test Case. Matlab apko nhi bnana hai Array, Judge ko query krna hai ki iss indx pe value kitni hai

// The important part of this question, You cant ask for the whole n values of the array.. There will be a limit to the number of queries you can
// make. Also Note the format of the queries and use it Properly. Format are Specified in Question...


// In 99% of the Interactive Problems, Binary Search is used , becz 
// Suppose, size of the array is N (1 <= N <= 10^5) ,  It is given that you can Atmost 100 queries.. 

// Atmost 100 queries means You can ask only for 100 values of the Array out of 10^5 .. log(10^5) --> Small and require less no. of queries



// ************************ REMEMBER *****************************************

// Remove fast IO and use endl while solving Interactive Problems.



// ******************************** TIME FOR QUESTION ********************************************


// Homer likes arrays a lot and he wants to play a game with you. 

// Homer has hidden from you a permutation a1,a2,…,an of integers 1 to n . You are asked to find any index k ( 1≤ k ≤ n ) which is a local minimum. 
// For an array a1,a2,…,an , an index i (1 ≤ i ≤ n ) is said to be a local minimum if ai < min{ ai−1, ai+1} , where a0 = an+1 = +INF. 

// An array is said to be a permutation of integers 1 to n , if it contains all integers from 1 to n exactly once.

// Initially, you are only given the value of n without any other information about this permutation. At each interactive step, you are allowed to 
// choose any i (1 ≤ i ≤ n ) and make a query with it. As a response, you will be given the value of ai . 

// You are asked to find any index k which is a local minimum after at most 100 queries.

// Constraint -> 1 <= N <= 10^5 , 1<= a[i] <= N

// INPUT : 
// 5
// 3
// 2
// 1
// 4
// 5

// OUTPUT :
// ? 1        
// ? 2
// ? 3
// ? 4
// ? 5
// ! 3

// Query with ? and Answer with !

// In the example, the first line contains an integer 5 indicating that the length of the array is n=5 . 
// The example makes five "?" queries, after which we conclude that the array is a = [3,2,1,4,5] and k = 3 is local minimum.







// THIS IS HOW AN INTERACTIVE PROBLEM LOOK LIKE. IN FIRST LINE ONLY, MOSTLY IT IS SPECIFIED THAT "THIS IS AN INTERACTIVE PROBLEM"...

// In Question, it is specified the format that how the queries are to be make and how we can Output the answer ( FORMAT )


// LOGIC --> Our Array can be Unsorted.. [1, 4, 3, 2, 5, 7, 6]

// GOAL --> Make a Predicate function so that Every Local minimum is our Junction Point.. Generate a Graph to Observe

// INF 1 4 3 2 5 7 6 INF

// PREDICATE FUNCTION  --> T if Decreasing ( a[m] < a[m-1] ), F if Increasing (a[m] > a[m-1])

// INF 1 4 3 2 5 7 6 INF 
//  F   T F T T F F T  F    ---> Local min. in every TF junction


#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// Interactive Problems, For query part, always do this

int n;

map<int,int> prev_values;   // Just like DP array , Optimizing, Agar same indx again query hui, Judge se nhi puchenge, Map ki value return kar denge

int query(int index){
    if(prev_values.find(index) != prev_values.end()){
        return prev_values[index];
    }

    if(index == 0 || index == n + 1)
        return INF;

    
    cout << "?" << index << endl;   // Asking Judge
    int value; cin >> value;        // Judge Answer stored in value

    return prev_values[index] = value;

}


int main() {

    // REMEMBER --> Remove fast IO

    int l = 0 , r = n + 1;

    while (r-l > 1) {       

        int m = (l + r) / 2;

        (query(m-1) > query(m)) ? l = m : r = m;

    }

    cout << l << endl;

    // Another way : (query(m+1) > query(m)) ? r = m : l = m;   .. ( FT JUNCTION )
    //               cout << r << endl;
    return 0;

}
