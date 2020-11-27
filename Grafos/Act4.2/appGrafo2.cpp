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
 * \param vector<vector<int>> &listaAdj: Lista de Adjacencia
 */
void loadGraph(int n, int m, vector<vector<int>> &listaAdj)
{
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        listaAdj[a].push_back(b);
    }
}

bool directedDFSsecond(int root, vector<vector<int>> &listaAdj, vector<bool> &visited)
{
    if (visited[root])
    {
        return false;
    }
    visited[root] = true;
    for (int num : listaAdj[root])
    {
        bool result = directedDFSsecond(num, listaAdj, visited);
        if (result == false)
            return false;
    }
    return true;
}

/**
 * Regresa true si no se encuentra un ciclo en el grafo, llama directedDFSsecond ya que
 * de esta manera podemos encontrar un nodo separado del grafo.
 * Complejidad O(n + m) siendo n la cantidad de nodos y m la canntidad de arcos
 * \param vector<vector<int>> &listaAdj: Lista de Adjacencia
 * \param int n: # Vertices
 * \param int m: # Arcos
 */
bool directedDFS(int root, vector<vector<int>> &listaAdj, vector<bool> &visited)
{
    if (listaAdj[root].size() == 0)
    {
        return false;
    }
    visited[root] = true;
    for (int num : listaAdj[root])
    {
        bool result = directedDFSsecond(num, listaAdj, visited);
        if (result == false)
            return false;
    }
    return true;
}

/**
 * Diga si el Grafo Dirigido es un árbol o no.
 * Complejidad O(n + m) siendo n la cantidad de nodos y m la canntidad de arcos
 * \param vector<vector<int>> &listaAdj: Lista de Adjacencia
 * \param int n: # Vertices
 * \param int m: # Arcos
 */

bool isTree(vector<vector<int>> &listaAdj, int n, int m)
{
    queue<int> q;
    vector<int> indegree(n, 0);
    vector<bool> visited(n, false);
    vector<bool> visitedNow(n, false);

    if (listaAdj.size() == 1)
        return true;
    for (vector<int> lista : listaAdj)
    {
        for (int num : lista)
            indegree[num]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        for (int i = 0; i < visitedNow.size(); i++)
        {
            visitedNow[i] = false;
        }
        if (!directedDFS(q.front(), listaAdj, visitedNow))
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            visited[i] = visited[i] || visitedNow[i];
        }
        q.pop();
    }

    for (bool visit : visited)
    {
        if (visit == false)
        {
            return false;
        }
    }
    return true;
}
/**
 * Despliegue en orden topológico del grafo.
 * Complejidad O(n + m) siendo n la cantidad de nodos y m la canntidad de arcos
 * \param vector<vector<int>> &listaAdj: Lista de Adjacencia
 * \param int n: # Vertices
 * \param int m: # Arcos
 */
void topologicalSort(vector<vector<int>> &listaAdj, int n, int m)
{
    bool isPossible = true;
    queue<int> q;
    vector<int> order;
    vector<int> indegree(n, 0);
    for (vector<int> lista : listaAdj)
    {
        for (int num : lista)
            indegree[num]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int current = 0;
    while (!q.empty())
    {
        current = q.front();
        q.pop();
        order.push_back(current);
        for (int i = 0; i < listaAdj[current].size(); i++)
        {
            int neighbor = listaAdj[current][i];
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    if (order.size() != n)
    {
        cout << "NO tiene orden topologico" << endl;
        return;
    }

    for (int num : order)
        cout << num + 1 << " ";
    cout << endl;
}

/**
 * Diga si el Grafo Dirigido puede ser representado como Grafo bipartita.
 * Complejidad O(n + m) siendo n la cantidad de nodos y m la canntidad de arcos
 * \param vector<vector<int>> &listaAdj: Lista de Adjacencia
 * \param int n: # Vertices
 * \param int m: # Arcos
 */
bool bipartiteGraph(vector<vector<int>> &listaAdj, int n, int m)
{
    vector<int> color(n);
    queue<int> q;
    int notPainted = true;
    for (int node = 0; node < n; node++)
    {
        if (color[node])
        {
            continue;
        }
        color[node] = 1;

        for (int neighbor : listaAdj[node])
        {
            if (color[neighbor] != false)
            {
                color[node] = -color[neighbor];
                break;
            }
        }

        q.push(node);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor : listaAdj[current])
            {
                if (!color[neighbor])
                {
                    color[neighbor] = -color[current];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[current])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> listaAdj(n);
    loadGraph(n, m, listaAdj);
    topologicalSort(listaAdj, n, m);
    cout << (isTree(listaAdj, n, m) ? "true" : "false") << endl;
    cout << (bipartiteGraph(listaAdj, n, m) ? "true" : "false") << endl;
    return 0;
}
//test cases
/* 
5 4 0
1 2 0
1 5 0
5 4 0
4 1 0 
false
false
 
5 4 0
1 2 0
1 3 0
1 4 0
1 5 0 
true
true

6 5 0
1 2 0
1 3 0
4 1 0
4 5 0
6 5 0 
true
true

4 3 0
1 2 0
4 1 0
4 3 0
true
true

4 3 0
1 3 0
4 1 0
4 3 0
false 
false

4 4 0
1 2 0
2 3 0
4 1 0
4 3 0
false
true
*/
