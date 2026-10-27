#include "mersen.h"

#include <cmath>

bool isPrime(int n)
{
    int col = 0;
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            col++;
    return col == 0;
}

std::vector <int> Mersens(int n)
{
    std::vector <int> mersens;
    int k, p = 2;
    do
    {
        if (isPrime(p))
        {
            k = static_cast <int> (std::pow(2, p) - 1);
            if (k > n)
                break;
            else
                mersens.push_back(k);
        }
        p++;
    } while (true);
    return mersens;
}