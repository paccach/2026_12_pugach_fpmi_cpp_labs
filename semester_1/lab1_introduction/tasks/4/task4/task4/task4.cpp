#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int
        a1 = n / 100000,
        a2 = n / 10000 % 10,
        a3 = n / 1000 % 10,
        b1 = n % 10,
        b2 = n % 100 / 10,
        b3 = n % 1000 / 100;
    if (a1 + a2 + a3 == b1 + b2 + b3)
        cout << "yes";
    else
        cout << "no";
}
