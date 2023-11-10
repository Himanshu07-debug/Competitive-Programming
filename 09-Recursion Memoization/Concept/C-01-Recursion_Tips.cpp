// ******************* UNDERSTANDING DIVIDE AND CONQUER **************************************

// Suppose You are Given a Big Problem which very Hard to solve.. You divide that Problem into smaller Subproblems...
// Assume that ki Yeah Smaller Subproblems are also not to much small so that you can solve them trivially... So You Again Divide it...
// Similarly, You divide again and again Until and unless you come to a point where You can Solve the Subproblem Trivially ....
// Now you use this answers from the Smaller Subproblem to solve the Bigger Subproblem answer...

// THIS IS ONLY RECURSION ............................................

// ************************************** MIND-SET BUILDING ***************************************

// 1. Breaking a Problem into a Smaller Subproblems..
// 2. How to get answer for Bigger problem from the Smaller Subproblems [ Establising Relationship ]
// 3. What is the Smallest subproblem which is trivial to solve.. [ BASE CASE ]
// 4. What is the Biggest Subproblem


// EASIEST WAY TO DO THIS ---->
// Draw kro Recursion Tree and 
// OBSERVE --> Which value/indx we are calling while moving to diff. child sides
//         --> How I am Merging the Child nodes
//         --> Where I am Stopping



// ***************************************** TIME COMPLEXITY *********************************

// Refer DSA BOOK
// TRICK -> If child > 1, then TIME --> [ child ^ (height) ]



// ***************************************** DEBUGGING THE RECURSION CODE ***************************************

// ==> Cout all function parameters in new lines .. Observe them.. Where the values are getting wrong
// ==> Also find the smallest Test case where the Code Can fail 

