#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void leeListAdj(vector<vector <int> > &listAdj, int m){
	int a, b;
	for (int i=1; i<=m; i++){
		cin >> a >> b;
		listAdj[a-1].push_back(b-1);
		listAdj[b-1].push_back(a-1);
	}
}

void printListAdj(vector<vector<int> > &listAdj){
	for (int i=0; i<listAdj.size(); i++){
		cout << (i+1)<< " ";
		for (int j=0; j< listAdj[i].size(); j++){
			cout << " - " << (listAdj[i][j]+1);
		}
		cout << endl;
	}
}

void DFS(vector<vector<int> > &listAdj){
    stack<int> pila;
    pila.push(0);
    vector<bool> status(listAdj.size(), false);
    int contadorVisitado = 0;
    int dato;
    while (!pila.empty() && contadorVisitado != listAdj.size())
    {
        dato = pila.top();
        pila.pop();

        if (!status[dato])
        {
            cout << dato+1 << " ";
            status[dato] = true;
            contadorVisitado++;
            for (int j = listAdj[dato].size() - 1; j >= 0; --j)
            {
                if (!status[listAdj[dato][j]])
                {
                    pila.push(listAdj[dato][j]);
                }
            }
        }
    }
    cout << endl;
}

int main(){
// n = cantidad de nodos
// m = cantidad de arcos
	int n, m;
	cin >> n >> m;
	vector<vector <int> > listAdj(n);
	leeListAdj(listAdj, m);
	printListAdj(listAdj);
	DFS(listAdj);
}

/*
Datos del Grafo1 solo falta agregar el nodo de arranque
7 11
1 2
1 3
1 4
2 3  
2 5
3 4
3 5
4 5
4 6
5 7
6 7

Datos del Grafo2 solo falta agregar el nodo de arranque
7 6
1 2
2 3  
2 5
3 4
4 6
5 7
*/