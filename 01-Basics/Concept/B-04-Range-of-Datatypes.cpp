#include<bits/stdc++.h>
using namespace std;

int main(){

    // ************************************  INT ****************************************

    // Integer Max and Min value
    cout << INT_MAX << " " << INT_MIN << endl;

    // Int ranges from [ -2^31 , 2^31 )   
    // 2^31 is bit higher than 2 * 10^9
    // There are total 2 * 2^31 elements correctly.. 2^31 is excluded becz 0 is also considered as Positive.. 
    // So 2^31 negative elements & 2^31 positive elements 

    int x = INT_MAX;

    cout << x + 1 <<endl;   // OVERFLOW ( moving from INT_MAX TO INT_MIN )

    // In OUTPUT, you will see that a + 1 is giving -2^31 .. WHY ?? 
    // In C++, the datatype ranges flows in Circular way , max + 1 = min [ 0 -> MAX -> MIN -> 0 ]

    int a = 1 << 30; // 2^30
    int b =  1 << 30;

    cout << a + b << endl;    // OVERFLOW

    long long sum = a + b;

    cout << sum << endl;   
    // Why this is giving OVERFLOW ?
    // In C++, if you do any operation on elements of same datatype, the output will be also of that datatype, not
    // what you specified 



    // NOTE : long int is same as int in C++, not in JAVA


    // ************************************  LONG LONG INT ****************************************

    // long long Integer Max and Min value
    cout << LLONG_MAX << " " << LLONG_MIN << endl;

    // long long int -> [ -2^63 , 2^63 ) 
    // 2^63 is bit higher than 9 * 10^18


    // ************************************ UNSIGNED LONG LONG INT ****************************************

    // In this  datatype, there is no negative values.. 
    // All the long long range negative values is considered as positive and numbering starts from 0
    // RANGE -> [ 0, 2^64 )   ... 2^64 = 10^19

    unsigned long long d;

    // If you are not allowed to use -ve numbers, use this


    // ************************************ FLOAT / DOUBLE ****************************************

    // Float has a precision of 7 digits 
    // double has a precision of 15 digits
    // precision -> Itne digits tak values accurate rhngi, uske baad any random digit

    float f = 1234.234567892354;

    cout << f << endl;
    // This line will only outout 6 digits, even if you use double or long double = SAME CASE

    // WHY ? By default, for floating point numbers, precision is set to 6, you have to Set it to change

    cout << setprecision(10) << endl;
    cout << f << endl;

    // This will give precision to first 10 significant digits

    // But if you want precision to the elements after decimal point (.), so that after . , there is 10 elements 

    cout << fixed << setprecision(10) << endl;
    cout << f << endl;

    // You will see the random value digits after some starting digits as we discussed above 
    // using double will improve it much

    double fd = 1234.2345678923545466677;

    cout << fixed << setprecision(20) << endl;
    cout << fd << endl;



    // ************************************ LONG DOUBLE ****************************************

    // Long Double has a precision of 18 digits 

    long double fl = 1234.23456789235454645678901234567890;
    cout << fixed << setprecision(20) << endl;
    cout << fl << endl;

    // NOTE : In most Compiler, long double Output will be same as double Output becz long double do not
    //          gaurantee that it will have 18 digits, its precision will be long double >= double

    // REMEMBER : While Submiting, always use Long double becz this precision things vary from Compiler to Compiler.
    //            The online judges of Codechef, Codeforces, both have this precision diff in double and long double


    

    // ************************* IMP TIP WHILE USING FLOAT ****************************************

    // Never Print BIG float Numbers, becz it gets print in Scientific value and it is NEVER Accepted by any Judge
    // Convert it to int and then Print

    long double g = 12312345.678;
    float h = 123567689.09;

    // Inorder to see the scientific value output, just comment down setprecision() function
    cout << g << endl;
    cout << h << endl;
    cout << (int)g << " " << (int)h << endl;


    // ****************** OTHER CONCEPT :

    // While loop is used when you want to increment and decrement your iterator at certain conditions. By while,
    // It is Easy to do

    // " auto " keyword can be used only when you are giving the value in front of it
    // It is not used in an unitialized state

    auto j = 12;
    // auto j;   NOT ALLOWED

    // *************** REMEMBER WHILE USING VECTOR *******************

    // While using Vectors, if you are initializing its size during its declaration i.e arr(n) , then never use 
    // push_back to add, use arr[i] to update, becz push_back will add a new element at the n+1 index of the arr
    // For 0-based indexing vector, You can Input it directly by cin >> arr


    return 0;

}

