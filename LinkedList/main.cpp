#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
    LinkedList<string> lista;
    cout<<"---Prueba funcion create----"<<endl;
    lista.addFirst("hola");
    lista.create("como",1);
    lista.create("estas?",20000);
    lista.create(",",1);
    lista.create("¿",-1000);
    lista.print();
    cout<<"----------------------------"<<endl;

    cout<<"----Prueba funcion read-----"<<endl;
    cout<<lista.read("como")<<endl;
    cout<<lista.read("perro")<<endl;
    cout<<"----------------------------"<<endl;

    cout<<"---Prueba funcion update----"<<endl;
    cout<<((lista.update("hola", "Juan"))?"true":"false")<<endl;
    cout<<((lista.update("Pedro","No"))?"true":"false")<<endl;
    lista.print();   
    cout<<"----------------------------"<<endl;
    
    cout<<"---Prueba funcion del----"<<endl;
    cout<<(lista.del("¿")?"true":"false")<<endl;
    cout<<(lista.del("saludos")?"true":"false")<<endl;
    lista.print();   
    cout<<"----------------------------"<<endl;

}