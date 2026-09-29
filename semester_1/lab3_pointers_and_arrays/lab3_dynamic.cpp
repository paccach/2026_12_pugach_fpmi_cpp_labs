#include <iostream>
#include <random>

using std::cin;
using std::cout;

void vivod(int &n, double *a)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << std::endl;
}

void alg(int n, double *arr)
{
    int N, j = n;
    cout << "введите N: ";
    cin >> N;
    while(N--)
    {
        int mini = 0;
        for (int i = 1; i < j; i++)
            if (arr[i] < arr[mini])
                mini = i;
        for (int i = mini; i < j - 1; i++)
            arr[i] = arr[i + 1];
        j--;
        arr[j] = 0.0;
    }
    return;
}

void vvod_0(int &n, double *&a)
{
    cout << "введите количество элементов: ";
    cin >> n;
    cout << "введите " << n << " элементов массива:\n";
    a = new double[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void vvod_1(int &n, double &l, double &r, double *&a)
{
    cout << "введите границы чисел для рандоиной генерации (l r через пробел): ";
    cin >> l >> r;
    std::mt19937 gen(12345);
    std::uniform_real_distribution<double> dist(l, r);
    cout << "введите количество элементов: ";
    cin >> n;
    cout << "сгенерированный массив:\n";
    a = new double[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = dist(gen);
        cout << a[i] << " ";
    }
    cout << std::endl;
}

int main() //variant 8
{
    setlocale(0, "");
    int sp, n;
    double *a = nullptr;
    cout << "выберите способ ввода (0 - ввести самому, 1 - рандомно заполнить): ";
    cin >> sp;
    if (sp == 0)
    {
        vvod_0(n, a);
    }
    else if (sp == 1)
    {
        double l, r;
        vvod_1(n, l, r, a);
    }
    alg(n, a);
    vivod(n, a);
    delete[] a;
    return 0;
}
