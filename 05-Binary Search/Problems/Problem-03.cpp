// Given an Array of Worloads, split it among K workers, Such that the maximum work that any Worker has to do is minimized

// Eg -> K = 3 , A = [10,5,20,50,25,45,15]  ===> 75

// Possible allocation of work -> 
// [10,5,20] [50,25] [45,15] -> max(35, 75, 60) => 75
// [10,5] [20,50,25] [45,15] -> max(15, 95, 60) => 95

// Similarly Aur allocate krke dekhlo, Best Combo jisme max. minimum aayenga -> Wo 75 wla hi honga


// LOGIC ---> 

// Aapke pass K buckets hai, unko allocate krna hai elements in such that the maximum sum of a bucket is min.

// This is a Typical Binary Search Problem .....
// Book Allocation, Task Allocation by Task Scheduler, etc



