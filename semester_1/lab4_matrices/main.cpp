#include <iostream>
#include <random>

std::mt19937 gen(45218965);

void allocateMatrix(int **&arr, int m, int n)
{
    arr = new int *[m];
    for(int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
}

void generateMatrix(int **arr, int m, int n)
{
    int x, y;
    std::cout << "Input borders:" << std::endl;
    std::cin >> x >> y;
    std::uniform_int_distribution<int> dist(x, y);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = dist(gen);
        }
    }
}

void inputMatrix(int **arr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> arr[i][j];
        }
    }
}

void outputMatrix(int **arr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int **arr, int m)
{
    for(int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void algorithm(int **arr, int m, int n)
{
    int *row = new int[m];
    int *col = new int[n];
    for(int i = 0; i < m; i++)
    {
        int mn = arr[i][0];
        for(int j = 1; j < n; j++)
        {
            if(arr[i][j] < mn)
            {
                mn = arr[i][j];
            }
        }
        row[i] = mn;
    }
    for(int i = 0; i < n; i++)
    {
        int mx = arr[0][i];
        for(int j = 1; j < m; j++)
        {
            if(arr[j][i] > mx)
            {
                mx = arr[j][i];
            }
        }
        col[i] = mx;
    }
    bool t = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == row[i] && arr[i][j] == col[j]){
                std::cout << "(" << i + 1 << "; " << j + 1 << "): " << arr[i][j] << std::endl;
                t = 0;
            }
        }
    }
    if(t) std::cout << "There is no answer";
}

int main() //variant 6
{
    int m, n;
    std::cout << "Input m and n:" << std::endl;
    std::cin >> m >> n;
    int **arr;
    allocateMatrix(arr, m, n);
    bool t;
    std::cout << "1 - input, 0 - generate" << std::endl;
    std::cin >> t;
    if(t)
    {
        std::cout << "Input matrix:" << std::endl;
        inputMatrix(arr, m, n);
    }
    else
    {
        generateMatrix(arr, m, n);
        outputMatrix(arr, m, n);
    }
    algorithm(arr, m, n);
    deleteMatrix(arr, m);
    return 0;
}
