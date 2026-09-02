#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, d;
    cin >> a >> b >> d;
    vector <int> pr;
    pr.push_back(a);
    int n = a;
    while ((n += d) <= b)
        pr.push_back(n);
    for (int i = 0; i < pr.size(); i++)
        if (pr[i] % 3 == 0)
            cout << pr[i] << " ";
}
