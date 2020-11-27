#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

void busquedaSequencial(string n)
{
    int count = 0, i = 0;
    bool debug = false;
    do
    {
        if (n.size() > i + 1)
            debug = n.at(i + 1) == n.at(i);
        else
            debug = false;
        count++;
        i += 2;
    } while (debug);
    if(i>n.size()&& n.size()%2==1)
        count--;
    char a = n.at(i - 2);
    cout << a << " " << count << " ";
}
void busquedaBinaria(string n)
{
    int count = 0;
    double mitad = n.size() / 2;
    int pos = mitad;
    bool cond = true;
    do
    {
        if(pos - 1<0 || pos+1>=n.size()){
            cond = false;
        }else if (((n.at(pos) == n.at(pos - 1)) && pos%2==1)||((n.at(pos) == n.at(pos + 1)) && pos%2==0))
        {
            mitad = (mitad / 2 == 0) ?  1 : ceil(mitad / 2);
            if(((n.at(pos) == n.at(pos + 1)) && pos%2==0) && mitad==1)
                count--;
            pos = pos + mitad;
            count++;
        }
        else if (((n.at(pos) == n.at(pos + 1)) && pos%2==1)||((n.at(pos) == n.at(pos - 1)) && pos%2==0))
        {
            mitad = mitad / 2;
            if(((n.at(pos) == n.at(pos - 1)) && pos%2==0) && mitad==1)
                count--;
            pos = pos - mitad;
            count++;
        }
        else{
            cond = false;
            count++;

        }
    } while (cond);
    cout << n.at(pos) << " " << count << endl;
}

int main()
{
    int k = 0;
    string n = "CXXYYZZAA";
    //cantidad de entradas
    cin >> k;
    for (int i = 0; i < k; i++)
    {
    cin >> n;
    //llamar metodos
        busquedaSequencial(n);
        busquedaBinaria(n);
    }
}