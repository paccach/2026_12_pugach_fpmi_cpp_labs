#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int kol = 0;
    for (int i = 1; i < n; i++)
    {
        if (i == 1)
            cout << "  ";
        else
            cout << "   ";
        kol += 3;
    }
    for (int i = 1; i <= k; i++)
    {
        if (kol >= 20)
        {
            kol = 0;
            cout << endl;
        }
        if (kol != 0)
            cout << " ";
        if (i / 10 == 0)
            cout << " ";
        cout << i;
        kol += 3;
    }
    return 0;
}