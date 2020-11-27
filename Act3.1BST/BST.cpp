//Ian De La Garza González          A01283525

#include <iostream>

using namespace std;

#include "BST.h"

int main(){
	BST miArbol;
    miArbol.add(21);
	miArbol.add(13);
	miArbol.add(10);
	miArbol.add(18);
	miArbol.add(33);
    miArbol.add(25);
	miArbol.add(40);
	


    miArbol.visit(1);
    miArbol.visit(2);
    miArbol.visit(3);
    miArbol.visit(4);
    cout<< miArbol.height()<<endl;
    miArbol.ancestors(18);
    cout<<miArbol.whatlevelamI(25)<<endl;
	return 0;
}