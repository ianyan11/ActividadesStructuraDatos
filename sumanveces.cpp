#include <iostream>

using namespace std;

int sumaIterativa(int arr[], int n)
{
    int acum=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
            acum += arr[i];
    }
    return acum;
}
int sumaRecursivo(int arr[], int n)
{
    if (n == 0)
        return 0;
    return sumaRecursivo(arr, n - 1) + ((arr[n-1] % 2 != 0) ? arr[n - 1] : 0);
}

int main()
{
    int n[5] = {1, 2, 3, 4,5};
    int a = 5;
    cout << sumaIterativa(n, a) << endl;
    cout << sumaRecursivo(n, a) << endl;
}