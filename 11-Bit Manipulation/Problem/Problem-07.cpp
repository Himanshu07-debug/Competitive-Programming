// You are given an Array of size n. You can select an Integer K such that -> 
// X => arr[i_1] & arr[i_2] & ............. & arr[i_k] 
// Subtract this X from all selected K indexes..
// arr[i_1] = arr[i_1] - X
// ...
// arr[i_k] = arr[i_k] - X

// Find all possible value of K such that the entire array becomes 0 ?


// LOGIC ------------------------------------>>>

// X me 1 means saare selected k indexes ke wo bit position pe 1 hai ....
// By subtracting X, sabke wo bit position 0 ho jayenge becz humne pow(2,i) subtract kar diye ...........

// Lekin K ke konse value le sakte hai???
// Jaise 1 to hamesha hi le sakte hai becz 1 element liye aur usko subtract kar diye wahi element se 0 banane ke liye .. Waise hi aue konse element le sakte hai ??

