#include <iostream>
#include <random>

using std::cin;
using std::cout;

void alg(int arr[], int n)
{
    int a, b;
    cout << "введите a и b:\n";
    if (!(cin >> a >> b) || a > b || a > n || b > n)
    {
        cout << "error";
        return;
    }

    ///
    int res[n];
    for (int i = 0; i < n; i++)
    {
        if (i < a || i > b)

    }
    ///

    return;
}

int main() //variant 6
{
    setlocale(0, "");
    int sp;
    cout << "выберите способ ввода (0 - ввести самому, 1 - рандомно заполнить): ";
    cin >> sp;
    if (sp == 0)
    {
        int n;
        cout << "введите количество элементов: ";
        cin >> n;
        int a[n];
        cout << "введите " << n << " элементов массива:\n";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        alg(a, n);
    }
    else if (sp == 1)
    {
        int l, r, n;
        cout << "введите границы чисел для рандоиной генерации (l r через пробел): ";
        cin >> l >> r;
        std::mt19937 gen(12345);
        std::uniform_int_distribution<int> dist(l, r);
        cout << "введите количество элементов: ";
        cin >> n;
        int a[n];
        cout << "сгенерированный массив:\n";
        for (int i = 0; i < n; i++)
        {
            a[i] = dist(gen);
            cout << a[i] << " ";
        }
        alg(a, n);
    }
    return 0;
}
