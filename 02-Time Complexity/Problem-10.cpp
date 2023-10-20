// A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

// MATRIX :    1    2   9   10  25
//             4    3   8   11  24
//             5    6   7   12  23
//             16   15  14  13  22
//             17   18  19  20  21

// Your task is to find out the number in row y and column x.

// Constraint : 1<= y,x <= 10^9


// LOGIC : In MATRIX questions, only observation can bring the ANSWER

// 2nd layer :  4 pe end hora,   3rd layer :  9 pe end hora,    4th layer -> 16 pe end hora

// i.e nth layer n^2 pe end honga

// Also odd indexed row se starting ho rhi hai, even wale pe end   ---->> Indexing from 1 is considered
// For COLUMN -> Even se staring , odd wale pe end 

// So agar hum given row,col se max(row,col) numbered layer bana de, to kaam ho jayenga

// Example :  r = 5, c = 2  , we will take max for layer assumption i.e 5th layer, 
//                            5 is odd so yha pe start hora hai, so (5-1) ka sqaure is 16, so starting 17 se hora hai row ka,
//                            so increment col number tk i.e c=2 so 16+2 i.e 18 is the ANS

// SIMILARLY you can do for Column,  Also handle the EDGE CASE when max is 1, (n-1) nhi kar sakte


// CODE SNIPPET ---> if(max(r,c) == r) then consider row wla logic
//                   else   EVEN wla logic

