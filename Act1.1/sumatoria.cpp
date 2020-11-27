#include <iostream>

using namespace std;

//Complejidad O(n)
//Se obtiene la sumatoria de 1 a 'n' de manera iterativa.
long long sumaIterativa(long long n){
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

//Complejidad O(n)
//Se obtiene la sumatoria de 1 a 'n' de manera recursiva.
long long sumaRecursiva(long long n){
    return n == 1 ? (long long)1 : sumaRecursiva(n - 1) + n;
}

//Complejidad O(1)
//Se obtiene la sumatoria de 1 a 'n' de manera directa.
long long sumaDirecta(long long n){
    return n % 2 == 0 ? (n + 1) * (n / 2) : (n + 1) * (n / 2) + (n / 2 + (long long)1);
}

int main(){
    int k = 0, n = 0;
    cin >> k; //cantidad de entradas

    for (int i = 0; i < k; i++){
        //Recibir numero para obtener su sumatoria
        cin >> n;

        //llamada a los metodos
        cout << sumaIterativa(n) << " " << sumaRecursiva(n) << " " << sumaDirecta(n) << endl;
    }
}