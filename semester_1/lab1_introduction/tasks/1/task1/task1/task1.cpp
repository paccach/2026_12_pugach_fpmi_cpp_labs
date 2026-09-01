#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i * i <= min(n, m); i++)
        if (n % i == 0 && m % i == 0)
            cout << i << " ";
}
