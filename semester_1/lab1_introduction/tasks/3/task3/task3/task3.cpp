#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 10 == n / 1000 && n % 100 / 10 == n / 100 % 10)
        cout << "yes";
    else
        cout << "no";
}
