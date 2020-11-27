int main()
{
    int k = 0, n = 0;
    //cantidad de entradas
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        //llamar metodos
        cout << sumaIterativa(n) << " " << sumaRecursiva(n) << " " << sumaDirecta(n) << endl;
    }
}