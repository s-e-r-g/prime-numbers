#include <iostream>
#include <vector>

using namespace std;

typedef uint64_t Number;

vector<Number> primes; //primes without 2

void generate(Number maxCount)
{
    if (maxCount == 0) return;

    cout << 2 << endl;
    maxCount--;

    if (maxCount == 0) return;
    
    Number current = 3;

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

    generate(1000000L); //1M
}


