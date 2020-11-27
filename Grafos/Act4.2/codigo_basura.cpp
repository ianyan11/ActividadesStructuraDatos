bool hasCycleDFS(vector<vector<int>> &listaAdj, int n)
{

    stack<int> pila;
    pila.push(1);
    vector<bool> status(n, false);
    vector<bool> rec(n, false);

    int contadorVisitado = 0;
    int dato;
    while (!pila.empty() && contadorVisitado != n)
    {
        dato = pila.top();
        pila.pop();

        if (!status[dato])
        {
            status[dato] = true;
            rec[dato] = true;
            contadorVisitado++;
            for (int j = listaAdj[dato].size() - 1; j >= 0; --j)
            {
                if (!status[listaAdj[dato][j]])
                {
                    if (rec[listaAdj[dato][j]])
                        return true;
                    else
                        pila.push(listaAdj[dato][j]);
                }
            }
        }
        rec[dato] = false;
    }
    return false;
}

void isConnected(vector<vector<int>> &listaAdj, int n, vector<bool> &vis)
{
    stack<int> pila;
    pila.push(0);
    vector<bool> status(n, false);
    int contadorVisitado = 0;
    int dato;
    for (int i = 0; i < n; i++)
    {
        if (!status[i])
        {
            while (!pila.empty())
            {
                dato = pila.top();
                pila.pop();
                vis[dato] = true;
                if (!status[dato])
                {
                    status[dato] = true;
                    contadorVisitado++;
                }
                for (int j = 0; j < listaAdj[dato].size(); ++j)
                {
                    if (!status[listaAdj[dato][j]])
                    {
                        pila.push(listaAdj[dato][j]);
                    }
                }
            }
        }
    }
}
bool isConnected(vector<vector<int>> &listaAdj, int n)
{
    vector<bool> vis1(n, false);
    vector<bool> vis2(n, false);
    isConnected(listaAdj, n, vis1);
    vector<vector<int>> invertListaAdj(n);
    for (int i = 0; i < n; i++)
    {
        for (int num : listaAdj[i])
        {
            invertListaAdj[num].push_back(i);
        }
    }
    printListAdj(listaAdj);
    for (int i : vis1)
    {
        cout << i << " ";
    }
    cout << endl;
    isConnected(invertListaAdj, n, vis2);
    printListAdj(invertListaAdj);
    for (int i : vis2)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (!vis1[i] && !vis2[i])
            return false;
    }
    return true;
}