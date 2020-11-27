#include <iostream>
#include <vector>

using namespace std;
/*complejidad O(n) 
Complejidad O(n) para la cantidad de entradas y
Complejidad O(1) para el peor caso al insertar el numero 
Dando en total una complejidad de O(n*1)*/
void chain(vector<vector<int>> &map, int n)
{
    int num, j;
    bool inserted = false;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        map[num % n].push_back(num);
        
    }
}

main()
{
    int count;
    cin >> count;
    vector<vector<int>> map(count);

    chain(map, count);
    for (int i = 0; i < map.size(); i++)
    {
        cout << i << " - ";
        for (int j : map[i])
        {
            cout << j << " ";
        }
        cout << endl;
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