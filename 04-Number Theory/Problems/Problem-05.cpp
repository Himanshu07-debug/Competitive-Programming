// We gave you an integer d and asked you to find the smallest positive integer a, such that a has 
// 1. at least 4 divisors;
// 2. difference between any two divisors of a is at least d

// d = 1 --> 6 [1,2,3,6]   ,,,, d = 2 ---> 15 [1,3,5,15]

// Constraint : 1 <= t <= 3000  ,,,, 1 <= d <= 10000

// LOGIC : 

// Hint 1 : Integer have exactly 4 divisors, if it is of form pq or p3 for some primes p and q . In the first case it have divisors 1, p, q ,pq
//          In the second case it have divisors 1 , p , p^2 , p^3 .

// Hint 2 : Instead of finding integer with at least 4 divisors, find integer with exactly 4 divisors. 

// Task 1 -> Numbers that have 4 divisors : Agar Number ke atleast 2 distinct prime factors hai p,q , p * q will have exactly 4 divisors
//           Agar 1 hi prime factor mila i.e p^k (k > 3) , then p^3 will have 4 divisors -> 1, p, p^2 , p^3

// Task 2 -> How to ensure the difference d ?
//           Phla 1 honga, hum next Prime factor 1 + d se nikalenge -> p , now agla p + d se .. Ensuring they are the smallest prime factors with 
//           difference >= d


// Agar p, q ke beech diff d ensure hai, pq se diff >=d gauranted honga, similarly p^3


#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int x;
    cin >> x;
    vector<int> p;

    // Leaving the range condition, INFINITE, as we dont know kha tak jayega ans
    for (int i = x + 1; ; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            p.push_back(i);
            break;
        }
    }
    for (int i = p.back() + x; ; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            p.push_back(i);
            break;
        }
    }
    cout << min(1ll * p[0] * p[1], 1ll * p[0] * p[0] * p[0]) << "\n";

    // NOTE -->  Here we have to guess the Number, so it is IMP that we handle both the cases .. p^3 bhi min. ho sakta hai yaa p*q bhi 
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}