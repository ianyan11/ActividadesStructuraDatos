#include <iostream>

using namespace std;

long long factorialIterativo(int n) {
    long long acum=1;
    for (int i=1; i<=n; i++) {
        acum *= i;
    }
    return acum;
}

long long factorialRecursivo(int n) {
    return n==0 ? 1 : n * factorialRecursivo(--n);
}


int main() {
    int n;
    cin>>n;
    cout<<factorialIterativo(n)<<endl;
    cout<<factorialRecursivo(n)<<endl;
}