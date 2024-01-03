// Consider a GRID problem --------->>

// There is a n*m Grid. You are at (0,0) and have to reach to (n-1,m-1) .. You can move right side or down side from each cell..

// Subproblems ??
// From (0,0) , if you move to ->
// (0,1) -> Iska Grid movement dimensions is reduced .. Yha se ab 0th col. pe nhi jaa sakte .. Allowed Grid -> (0,1) to (n-1, m-1)
// (1,0) -> Isme 1st row pe nhi jaa sakte ... Iska available grid movement size is reduced ... (1,0) -> (n-1, m-1)
// Solving a Subproblem is easy becz it covers smaller allowed space than the Bigger one...


// Why DP here ??
// If You are at (0,0) , aap (1,1) pe dono move se jaa sakte ho.. Agar ek move se phle hi (1,1) -> (n-1,m-1) path nikal chuka, why to calculate 
// it again for another move...
// Similarly there will be many Overlapping Subproblems



// ******************************** MAX / MIN **********************************************

// Find the max. sum path from (0,0) to (n-1,m-1)

// NOTION - 1 ----------->>

// dp[i][j] = min. sum path from (i,j) to (n-1, m-1)

// Transition == dp[i][j] = min( dp[i+1][j] , dp[i][j+1] ) + arr[i][j]

// Smallest Subproblem that cant be further reduced --> dp[n-1][m-1] = arr[n-1][m-1]

// Final Subproblem --> dp[0][0]



// NOTION - 2 ----------->>

// dp[i][j] = min. sum path from (0,0) to (i,j) 

// Transition == dp[i][j] = min( dp[i-1][j] , dp[i][j-1] ) + arr[i][j]

// Smallest Subproblem that cant be further reduced --> dp[0][0] = arr[0][0]

// Final Subproblem --> dp[n-1][m-1]



// NOTE --> Jo pt. Q.s me Specified consider krte ho state defination me , wohi Base case bnta hai .. Final (i,j) is the Final Subproblem
//          Notion - 1  ==> (n-1,m-1) is a Required pt. by Q.s .. BASE CASE
//          Notion - 2  ==> (0, 0) is a Required pt. by Q.s .. BASE CASE

// Also, different people might have different view/notion to the state defination, All are right until and unless your state is properly defined



// NOTE ---> If MAX SUM PATH is asked, usko bhi aaise hi solve kar skte ho....





// ******************************** NUMBER OF WAYS **********************************************

// Find the No. of ways of reaching to the (n-1,m-1) from (0,0)

// dp[i][j] = No. of path from (0,0) to (i,j) 

// Transition == dp[i][j] =  dp[i-1][j] + dp[i][j-1] 

// Smallest Subproblem that cant be further reduced --> dp[0][0] = 1

// Final Subproblem --> dp[n-1][m-1]





// ******************************** OBSTACLES IN GRID **********************************************

// Find the min. sum path when there are some obstacles cell in the Grid and path through the Obstacle is not allowed..

// State definition and Transition will remain the same...

// In grid, make dp[i][j] = INF if (i,j) is an Obstacle

// If max. sum path is asked, make dp[i][j] = -INF
// If no. of ways is asked, make dp[i][j] = 0




// **************************************** CHECK-POINTS **************************************************

// A grid with a Checkpoint(x,y) is given. Find the min. sum path from (0,0) to (n-1,m-1) mandatorily passing through given Checkpoint (x,y).

// Diagram photo is there in this folder only for this.. MUST SEE...

// If the min. sum path from (0,0) to (i,j) --> X  .. ( NOTION - 2 )
// If the min. sum path from (i,j) to (n-1,m-1) --> Y  .. ( NOTION - 1 )

// dp1[x][y] = min sum path from (0,0) to (i,j)
// dp2[x][y] = min sum path from (i,j) to (n-1,m-1)

// Final answer --> dp1[x][y] + dp2[x][y] - arr[x][y]

// If number of ways is asked here --->
// dp1[x][y] = No. of path from (0,0) to (i,j)
// dp2[x][y] = No. of path from (i,j) to (n-1,m-1)

// Final Answer --> dp1[x][y] * dp2[x][y]



// ************************************* MULTIPLE CHECKPOINTS ****************************************************

// Note -> See the Diagram photo in the folder

// REMEMBER, checkpoints ke beeck me ek relative ordering honi chahiye i.e Means single line to the destination pts. ko jhode to...
// Agar flow, thoda sa bhi backtrack hua upar yaa wapas left, Any Path will not Possible...

// (1,1) , (2,4) , (5,7)  --> Append (0,0) at first and (n-1,m-1) at last.. See line is continous
// (1,1) , (2,4) , (1,4) , (5,7) --> Not Valid checkpoints ... No path Possible .. Kyuki (2,4) and (1,4) kisi ko bhi lo phle, dusre ko lene me
//                                   zigzag ho jayega

// In this case, apko each 2 point ka one by one solve krna honga , let the answer be -->
// (0,0) -> (1,1) ==> x
// (1,1) -> (2,4) ==> y
// (2,4) -> (5,7) ==> z
// (5,7) -> (7,7) ==> a
// Number of ways --> x * y * z * a











