#include <iostream>
#include <vector>

using namespace std;

typedef uint64_t Number;

vector<Number> primes; //primes without 1 and 2


void generate(Number latestFound, Number maxCount)
{
    if (maxCount == 0) return;
    
    if (latestFound == 0)
    {
        cout << 1 << endl;
        latestFound = 1;
        maxCount--;
    }
    
    if (maxCount == 0) return;
    
    if (latestFound == 1)
    {
        cout << 2 << endl;
        latestFound = 2;
        maxCount--;
    }
    
    if (maxCount == 0) return;
    
    Number current = (latestFound % 2) ? (latestFound + 2) : (latestFound + 1);

    while (maxCount)
    {
        Number maxDivisor = (current / 2) - 1;

        bool isPrime = true;

        for (size_t i = 0; i < primes.size(); ++i)
        {
            Number divisor = primes[i];

            if (divisor > maxDivisor) break;

            if (current % divisor == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            cout << current << endl;

             --maxCount;

            primes.push_back(current);
        }

        current += 2; // skip even numbers
    }
}




int main()
{
    primes.reserve(10000000L); //10M

    generate(0, 1000000L); //1M
}


