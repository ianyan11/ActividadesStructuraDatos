//Ian De La Garza González a01283525
#include <vector>
#include <iostream>
using namespace std;
class priority_queue
{
public:
    priority_queue();
    void push(int dato);
    void pop();
    int top();
    bool empty();
    int size();
    void print();

private:
    vector<int> lista;
};

priority_queue::priority_queue()
{
    lista.push_back(-10101010);
}
//Complejidad O(1)
int priority_queue::size()
{
    return lista.size() - 1;
}

//Complejidad O(1)
bool priority_queue::empty()
{
    return lista.size() == 1;
}

//Complejidad O(1)
int priority_queue::top()
{
    return *(lista.begin() + 1);
}

//Complejidad O(log_2(n))
void priority_queue::push(int dato)
{
    int now = lista.size();
    lista.push_back(dato);
    int i = now / 2;
    while (lista[i] < lista[now] && i != 0)
    {
        int token = lista[now];
        lista[now] = lista[i];
        lista[i] = token;
        now = i;
        i = now / 2;
    }
}

//Complejidad O(log_2(n))
void priority_queue::pop()
{
    int i = 1, size = lista.size()-1;
    int token = lista[size];
    lista[size] = lista[1];
    lista[1] = token;
    lista.pop_back();
    while (lista[i] < lista[(2 * i >= size) ? i : 2 * i] || lista[i] < lista[(2 * i + 1 >= size) ? i : 2 * i + 1])
    {   
        int a = (2 * i >= size) ? i : 2 * i;
        int b = (2 * i + 1 >= size) ? i : 2 * i + 1;
        int pos = (lista[a] > lista[b]) ? a : b;
        token = lista[pos];
        lista[pos] = lista[i];
        lista[i] = token;
        i = pos;
    }
}
//Complejidad O(n)
void priority_queue::print()
{
    for (vector<int>::const_iterator i = lista.cbegin() + 1; i != lista.cend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}