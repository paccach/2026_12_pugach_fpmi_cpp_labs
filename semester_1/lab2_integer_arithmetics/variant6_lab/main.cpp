#include <iostream>
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

int main()
{
    using std::cout;
    using std::cin;
    int n;
    cout << "n = ";
    cin >> n;
    int k, p = 2;
    do
    {
        if (isPrime(p))
        {
            k = pow(2, p) - 1;
            if (k > n)
                break;
            else
                cout << k << " ";
        }
        p++;
    }
    while (true);
    return 0;
}
