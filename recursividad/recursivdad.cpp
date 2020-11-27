#include <iostream>

using namespace std;

long long fibonacciIterativo(int n) {
    long long suma=1;
    long long anterior = 1;
    for (int i = 2; i<n;i++) {
        suma=suma+anterior;
        anterior=suma-anterior;
    }
    return suma;
}
long long fibonacciRecursivo(int n) {

    return n<=2? 1: fibonacciRecursivo(n-1)+ fibonacciRecursivo(n-2);
}
#define NACEN 3.78
#define MUERE 2.34
int bacteriaIterativa(int n) {
    int bacterias=1;
    for (int i=0; i<n; i++) {
        bacterias += bacterias*(NACEN-MUERE);
    }
    return bacterias;
}
int bacteriaRecursiva(int n) {

    return n==0? 1: bacteriaRecursiva(n-1) * (1 + (NACEN-MUERE));
}

int potencialIterativa(int x, int y) {
    int sum=1;
    for (int i = 1; i <= y; i++)
    {
        sum*=x;
    }
    return sum;
}

int potenciaRecursiva(int x, int y) {
    if (y==0)
        return 1;
    return y==1? x : x*potenciaRecursiva(x, y-1);
}

int potenciaEficiente(int x, int y) {
    int sum=1;
    while (y > 0) {
        if (y%2 != 0) {
            sum*=x;
        }
        x*=x;
        y/=2;
    }
    return sum;
}
int main() {
    int n=10;
    cout<<fibonacciIterativo(n)<<endl;
    cout<<fibonacciRecursivo(n)<<endl;
    int dias=20;
    cout<<bacteriaIterativa(dias)<<endl;
    cout<<bacteriaRecursiva(dias)<<endl;
    int x=5, y=4;
    cout<<potencialIterativa(x, y)<<endl;
    cout<<potenciaRecursiva(x, y)<<endl;
    cout<<potenciaEficiente(x, y)<<endl;

}