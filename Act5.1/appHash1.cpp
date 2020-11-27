#include <iostream>
#include <vector>

using namespace std;
/*complejidad O(n^2) 
Complejidad O(n) para la cantidad de entradas y
Complejidad O(n) para el peor caso al insertar el numero 
Dando en total una complejidad de O(n*n)*/
void open(vector<int> &map, int n)
{
    int num, j;
    bool inserted = false;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        j = 0;
        if (map[num % n] == -1)
        {
            map[num % n] = num;
        }
        else
        {
            while (!inserted)
            {
                j++;
                if (map[(num + j) % n] == -1)
                {
                    map[(num + j) % n] = num;
                    inserted = true;
                }
            }
            inserted = false;
        }
    }
}

main()
{
    int count;
    cin >> count;
    vector<int> map(count, -1);

    open(map, count);
    for (int i = 0; i < count; i++)
    {
        cout << i
             << " - " << map[i] << endl;
    }
}

/*
5
100
200
543
123
4
*/