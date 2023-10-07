#include<bits/stdc++.h>
// Increases Compile time, but has no effect on Run Time (Same as iostream)
// Does not work with Compilers other than GNU C++ 

using namespace std;
// Namespace is a Scope of the program that can store various useful functions and variables
// If not written , then use std :: (scope resolution operator)
// They are used to avoid conflicting names

// signed int => signed ( SAME )

int main(){

    // ***************************************  FAST IO  *******************************

    // It increases the execution time by taking fast Input and giving fast output, it saves your Run time, 
    // but there are some Drawbacks

    ios::sync_with_stdio(false);  // Removes sync between cout and printf

    // The effect of Above statement will that agar mai Printf aur cout use krta hu code me to Printf wale phle 
    // Print ho jaenge console before cout, even though printf wale niche likhe the cout se

    cout << 1 << '\n';
    printf("2\n");

    cin.tie(NULL);                // Removes sync between cout and cin

    // Effect of above statement : 
    cout << "Enter two values: ";
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;          // ---> Marker line
    cout << " Enter Third : ";
    int c ;
    cin >> c;
    cout << a + b + c << "\n";

    // Marker line me abhi endl hai, Starting me apko ""Enter two values: " statement nhi show honga, I/P kronge a,b
    // , immediately O/P aayenga cout ke sath, then you have to Input c ( Yha pe bhi cout statement "Enter Third : " 
    // nhi dikhenga), input ke baad dikhenga sum ek sath

    // But if you use "\n" in marker line , wo phle a, b ,c Input lenga and then Output dikhaenga all ka 
    // SEE THIS ALL IN CONSOLE BY RUNNING


    // ****************************** NOTE ********************************

    // "endl" forces the Input buffer to flush, therefore so far jo kuch bhi Output krna hai Input ka Kar denga,
    // When using fast IO, use "\n" rather than endl

    // WHEN TO NOT USE FAST IO -> While Debugging when you have to interact with the Output .. Becz fastio will so 
    //                             all outputs at the last after taking all Input
    // FAST IO should not be used in Interactive Problems




    // SEARCH -> user defined header files ( HOW )




    // Without namespace
    std::cout << 5 << std::endl;



    // Compile time vs Run time  --------------> 
 
    for(int i=0;i<10;i++){
        cout << i << " ";
    }
    cout << endl;

    // Compile time -> time taken to build (COMPILE) and start the output, preparing the exec file (Code to Byte code)
    // Run time -> Time taken by the FOR LOOP to run when the Output starts

    // REMEMBER -> Code --> Compilation time --> Run time 

    // C++ Documentation -> Devdocs.io

    return 0;

}

