// Yash and Jay - both are frnds. They buy cupcakes of the shop. In the shop, there are n types of cupcakes and each cupcake is infinitely available.
// arr[i] -> tastiness of each cupcake of type i. 
// Yash purchased exactly one cupcakes of each type. Jay will purchased a segment of cupcake. Jay will not purchase the whole cupcake..
// Whoever total tastiness is stictly greater than the other, he is Happy. Tell if whether Yash will be happy or not ???

// [7,4,−1]
// Yash => 7 + 4 -1 = 10
// Jay => segments [7],[4],[−1],[7,4] or [4,−1], their total tastinesses are 7,4,−1,11 and 3 respectively. 
// OUTPUT => NO ( Jay 11 > Yash 10) -> Yash will not Happy


// Constraint -> 2 <= n <= 10^5 ,,,  -10^9 <= arr[i] <= 10^9



// LOGIC ------------->>

// Jay ke liye max. Subarray sum nikal lete KADANE se .. 
// Also iss subarray ke size ka bhi track rakhte so that we can check j - i + 1 < N when max_sum == total_sum

// KADANE VARIATION with index of Subarray

// REMEMBER -> In KADANE, hamesha window ki size min. consider hoti hai i.e [0, 8] -> size = 1 ( 0  consider nhi hota bhale hi same sum hai)
//                                                                           [8, 0] -> size = 1 (last wla 0 not considered)
