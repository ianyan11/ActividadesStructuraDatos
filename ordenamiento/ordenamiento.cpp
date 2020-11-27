//Ian De La Garza González a01283525
#include <iostream>
#include <vector>

using namespace std;

//Complejidad O(n^2)
void ordenaIntercambio(vector<int> &arr)
{
    int holder, count = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr.at(i) > arr.at(j))
            {
                holder = arr.at(i);
                arr.at(i) = arr.at(j);
                arr.at(j) = holder;
            }
            count++;
        }
    }
    cout << count << " ";
}

//Complejidad O(n^2)
void ordenaBurbuja(vector<int> &arr)
{
    int holder, count = 0;
    bool breaker = true;
    for (int i = 0; i < arr.size() - 1 && breaker; i++)
    {
        breaker = false;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr.at(j) > arr.at(j + 1))
            {
                holder = arr.at(j);
                arr.at(j) = arr.at(j + 1);
                arr.at(j + 1) = holder;
                breaker = true;
            }
            count++;
        }
    }
    cout << count << " ";
}

int merge(int inicio, int mitad, int fin, vector<int> &arr, vector<int> &temp)
{
    int i = inicio, j = mitad + 1, k = inicio;
    int count = 0;

    while ((i <= mitad) && (j <= fin))
    {
        count++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mitad)
        temp[k++] = arr[i++];
    while (j <= fin)
        temp[k++] = arr[j++];

    for (int a = inicio; a <= fin; a++)
    {
        arr[a] = temp[a];
    }
    return count;
}
//complejidad O(n log n)
int ordenaMerge(int inicio, int fin, vector<int> &arr, vector<int> &temp)
{
    int count = 0;
    if (inicio < fin)
    {
        int mitad = (inicio + fin) / 2;
        count += ordenaMerge(inicio, mitad, arr, temp);
        count += ordenaMerge(mitad + 1, fin, arr, temp);
        count += merge(inicio, mitad, fin, arr, temp);
    }

    return count;
}
void ordenaMerge(vector<int> &arr)
{
    vector<int> temp(arr.size());
    cout << ordenaMerge(0, arr.size() - 1, arr, temp) << " ";
}

//Complejidad O(n)
int busqSecuencial(vector<int> arr, int valor)
{
    int count = 0;
    bool breaker = true;
    for (int i = 0; i < arr.size() && breaker; i++)
    {
        count++;
        if (valor == arr[i])
        {
            cout << i << " ";
            cout << count << " ";
            return i;
        }
    }
    cout << -1 << " ";
    cout << count << " ";
    return -1;
}

//Complejidad O(log n)
int busqBinaria(vector<int> arr, int valor)
{
    int central, bajo, alto, valorCentral, n, count;
    bajo = 0, count = 0;
    n = arr.size();
    alto = n - 1;
    while (bajo <= alto)
    {
        count++;
        central = (bajo + alto) / 2;
        valorCentral = arr[central];
        if (valor == valorCentral)
        {
            cout << count << " ";
            return central;
        }
        else if (valor < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;
    }
    cout << count << " ";
    return -1;
}

int main(int argc, char const *argv[])
{
    int n = 0, x, q;

    //cantidad de entradas para el arreglo
    cin >> n;
    vector<int> arr1, arr2, arr3;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr1.push_back(x);
        arr2.push_back(x);
        arr3.push_back(x);
    }
    ordenaIntercambio(arr1);
    ordenaBurbuja(arr2);
    ordenaMerge(arr3);
    cout << endl;

    //cantidad de entradas para la busqueda
    cin >> q;
    int pos = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        busqSecuencial(arr1, x);
        busqBinaria(arr1, x);
        cout << endl;
    }
}
