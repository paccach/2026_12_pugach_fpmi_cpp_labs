#include "mersen.h"

#include <iostream>

using std::cout;
using std::cin;

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    std::vector <int> mersens = Mersens(n);
    for (size_t i = 0; i < mersens.size(); i++)
        cout << mersens[i] << " ";
    return 0;
}