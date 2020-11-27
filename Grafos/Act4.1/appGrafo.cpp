#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
/**
 * Cargue los arcos del grafo y los almacene en una Matriz de Adjacencia y en una Lista de Adjacencia. 
 * Complejidad O(n)
 * \param int n: # Vertices
 * \param int m: # Arcos
 * \param  vector<vector<int>> &matAdj: Matriz de Adjacencia
 * \param vector<vector<int>> &listaAdj: Lista de Adjacencia
 */
void loadGraph(int n, int m, vector<vector<int>> &matAdj, vector<vector<int>> &listaAdj)
{
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        matAdj[a][b] = c;
        matAdj[b][a] = c;
        listaAdj[a].push_back(b);
        listaAdj[b].push_back(a);
    }
}
/**
 * Imprima el Recorrido de DFS (Profundidad) a partir de nodo inicial. 
 * Complejidad O(n + m) siendo n la cantidad de nodos y m la canntidad de arcos
 * \param vector<vector<int>> matAdj: Matriz de Adjacencia
 * \param int ni: Nodo Inicial 
 */
void DFS(vector<vector<int>> &matAdj, int ni)
{
    stack<int> pila;
    pila.push(--ni);
    int contadorVisitado = 0;
    int dato;
    vector<bool> status(matAdj.size(), false);

    while (!pila.empty() && contadorVisitado != matAdj.size())
    {
        dato = pila.top();
        pila.pop();

        if (!status[dato])
        {
            cout << dato + 1 << " ";
            status[dato] = true;
            contadorVisitado++;
            for (int j = matAdj.size() - 1; j >= 0; j--)
            {
                if (!status[j] && matAdj[dato][j]>0)
                {
                    pila.push(j);
                }
            }
        }
    }
    cout << endl;

}
/**
 * Imprima el Recorrido de BFS (Anchura) a partir de nodo inicial. Complejidad O(n + m) siendo n la cantidad de nodos y m la canntidad de arcos
 *
 * \param vector<vector<int>> &listaAdj: Lista de Adjacencia 
 * \param int ni: Nodo Inicial 
 */
void BFS(vector<vector<int>> &listAdj, int ni)
{
    ni--;
    queue<int> fila;
    int dato, contadorVisitado=0;
    vector<bool> status(listAdj.size(), false);
    fila.push(ni);
    status[ni] = true;
    while (!fila.empty() && contadorVisitado != listAdj.size())
    {
        dato = fila.front();
        fila.pop();
        status[dato] = true;
        cout << dato + 1 << " ";
        contadorVisitado++;
        for (int j = 0; j <listAdj[dato].size(); j++)
        {
            if (!status[listAdj[dato][j]])
            {
                fila.push(listAdj[dato][j]);
                status[listAdj[dato][j]] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> matrizAdj(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrizAdj[i][j] = false;

    vector<vector<int>> listaAdj(n);
    loadGraph(n, m, matrizAdj, listaAdj);
    DFS(matrizAdj, s);
    BFS(listaAdj, s);
    return 0;
}
