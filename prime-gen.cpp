#include <iostream>
#include <vector>

using namespace std;

typedef uint64_t Number;

vector<Number> primes;


void generate(Number latestFound, Number maxCount)
{
    Number current = latestFound + 2;

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

    primes.push_back(3);

    generate(3, 1000000L); //1M
}


