#include <iostream>
#include <random>

using std::cin;
using std::cout;

void vivod(int &n, int *a)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << std::endl;
}

void alg(int n, int *arr)
{
    int a, b;
    cout << "введите a и b:\n";
    cin >> a >> b;
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < a || arr[i] > b)
        {
            int x = arr[i];
            for (int k = i; k > j; k--)
                arr[k] = arr[k - 1];
            arr[j] = x;
            j++;
        }
    }
    return;
}

void vvod_0(int &n, int *a)
{
    cout << "введите количество элементов: ";
    cin >> n;
    cout << "введите " << n << " элементов массива:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void vvod_1(int &n, int &l, int &r, int *a)
{
    cout << "введите границы чисел для рандоиной генерации (l r через пробел): ";
    cin >> l >> r;
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(l, r);
    cout << "введите количество элементов: ";
    cin >> n;
    cout << "сгенерированный массив:\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = dist(gen);
        cout << a[i] << " ";
    }
    cout << std::endl;
}

int main() //variant 6
{
    setlocale(0, "");
    int sp, n, a[10000];
    cout << "выберите способ ввода (0 - ввести самому, 1 - рандомно заполнить): ";
    cin >> sp;
    if (sp == 0)
    {
        vvod_0(n, a);
    }
    else if (sp == 1)
    {
        int l, r;
        vvod_1(n, l, r, a);
    }
    alg(n, a);
    vivod(n, a);
    return 0;
}
