// You are given a string s, it is asked that by removing the non-adjacent letters from the string, can you get
// SORTED string, If yes , Outputs -> YES/NO
// Removal is allowed only once, take the sequence of k valid indexes and then remove them

// Example -> 0001101010  -> 0001110 -> 000111 [You can remove the last char]
// Example -> 0001100  ->   Impossible to get the sorted string


// LOGIC : 
// if there is a substring 11 before the substring 00 in our string, then from both of the substrings, 
// at least one character remains, so if the first occurrence of 11 is earlier than the last occurrence of 00, 
// there is no answer. Otherwise, the answer always exists.