// What's the minimum number of days needed for a ship, starting at (x1, y1), to reach coordinates (x2, y2) based on a 
// periodic wind forecast (U, D, L, R) of length n? The ship moves one unit up, down, left, or right according to the wind, and can stays 
// in its place only. The wind direction repeats every n days.
// The ship can also make its move alongwith wind moves when it aims to move i.e In order to move Diagonally, when Wind is blowing L, it goes
// U, the ship will move ( x-1, y+1 ) .. If ship move U and wind is also moving U at that time, then it doubles (x, y + 2)

// x1 = 0, y1 = 0
// x2 = 4, y2 = 6
// n = 3
// str = "UUU"
// OUTPUT -> 5 ( (0,0) → (1,1) → (2,2) → (3,3) → (4,4) → (4,6) )

// x1 = 0, y1 = 0
// x2 = 0, y2 = 1
// n = 1
// str = "L"
// OUTPUT -> -1

// 1 <= n <= 10^5  , 0 <= x,y <= 10^9


// LOGIC ---> 


// We have to minimize the number of Days...
// Search Space -> on the days
// If I can reach in x days, I can reach in x+1 days also
// F F F F F F T T T T T T T


// In Binary Search, the Question Always gets Clear, Its hard to write the Predicate Function --->

// PREDICATE FUNCTION LOGIC --->

// Our Ship can make its moves only with winds moves, not alone... 
// So, If m operations are done by wind to move the ship in x no. of days, then the no. of Operation done by ship should be <= m ...

// This will be Our Main Idea ...
// Checking ship can reach to the destination in x no. of days ????
// 1. Let our starting pt. is x1,y1...
// 2. Now, we reach to some pt. x', y' by the wind contribution in x no. of days....
// 3. Now, x', y' --> x2, y2  .. jaane me Ship ko kitna move krna pada i.e abs(x2 - x') + abs(y2 - y') .. Calculate..
// 4. Now, if Number of moves made by ship <= x ... Then VALID, otherwise x no. of days is not valid to reach destination


// Question me bola hai Wind and Ship sath me chal rhe hai... We are Calculating it one after the other, Does this affect ???
// NO ... 
// REMEMBER, in Grids, we only concerns about the number of upper, lower, left, right moves .. 
// Koi bhi 2 moves milake usko digonal move bna sakte hai ... But even after doing this, If You will calculate.. The number of U,L,D,R moves 
// remain same for src to Destination... No matter whatever Path you take

// --> Iss Question me agar ship ka move <= x hua to It can be considered that ship ka moves wind ke sath kisi dinn hue x days me
// No. of Ships move = M, so x me se koi bhi M dinn ship ne move kiya honga alongwith wind..








