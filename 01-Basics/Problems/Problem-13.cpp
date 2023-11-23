// Apko M * N sqaures ka rectangular grid diya hai .. Also, aoko unlimited no. of standard domino pieces 2 * 1 sqaures ke diye hai.. You are 
// allowed to rotate the pieces. Find the maximum no. of dominoes, which can be placed on board

// Constraint -> 1 <= M , N <= 16

// M = 2, N = 4  ---> 4


// LOGIC -------------->>

// 2 * 1 ka sqaure hai, 2 hai means no. of cases kam banege for diff values of M & N .. lets build the logic through cases ----->>

// M -> even and N -> even
// 2 length wla row pe rkhe to M/2 rows banege and each row me N pieces --> Therefore ans => N * M/2

// M -> odd and N -> even
// 2 length wla col me .. Total col -> N/2 .. N/2 cols me M pieces ---> ans => M * N/2

// Similar for M -> even and N -> odd

// M -> odd and N -> odd
// M-1 yaa N-1 even ho jayenga ==> Therefore (M-1)/2 * N 
// Now last M th row -> N/2

// Total ==> (M - 1)*N + N ==> M*N/2

// For all cases --> Answer is (M * N)/2

