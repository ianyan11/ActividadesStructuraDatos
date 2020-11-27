//Ian De La Garza González          A01283525
#include "NodeT.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class BST
{
public:
    BST();
    ~BST();
    void add(int data);
    bool search(int data);
    void remove(int data);
    void printPre();
    void printPost();
    void printIn();
    void printLevel();
    void visit(int num);
    int height();
    void ancestors(int data);
    int whatlevelamI(int data);
    int size();

private:
    /* data */
    NodeT *root;
    void preOrden(NodeT *r);
    void postOrden(NodeT *r);
    void inOrden(NodeT *r);
    void levelByLevel(queue<NodeT *> cola);
    void destruye(NodeT *r);
    int howManyChildren(NodeT *r);
    int succ(NodeT *r);
    int pred(NodeT *r);
    int count(NodeT *r);
    int height(NodeT *r);
};

BST::BST()
{
    root = nullptr;
}
//O(n)
BST::~BST()
{
    destruye(root);
}
//O(n)
void BST::destruye(NodeT *r)
{
    if (r != nullptr)
    {
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}
//O(n)
void BST::add(int data)
{
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr)
    {
        if (curr->getData() == data)
        {
            return;
        }
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if (father == nullptr)
    {
        root = new NodeT(data);
    }
    else
    {
        (father->getData() > data) ? father->setLeft(new NodeT(data)) : father->setRight(new NodeT(data));
    }
}
//O(n)
bool BST::search(int data)
{
    NodeT *curr = root;
    while (curr != nullptr)
    {
        if (curr->getData() == data)
            return true;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    return false;
}
//O(n)
void BST::preOrden(NodeT *r)
{
    if (r != nullptr)
    {
        cout << r->getData() << " ";
        preOrden(r->getLeft());
        preOrden(r->getRight());
    }
}
//O(n)
void BST::printPre()
{
    preOrden(root);
    cout << endl;
}
//O(n)
void BST::postOrden(NodeT *r)
{
    if (r != nullptr)
    {
        preOrden(r->getLeft());
        preOrden(r->getRight());
        cout << r->getData() << " ";
    }
}
//O(n)
void BST::printPost()
{
    postOrden(root);
    cout << endl;
}
//O(n)
void BST::inOrden(NodeT *r)
{
    if (r != nullptr)
    {
        inOrden(r->getLeft());
        cout << r->getData() << " ";
        inOrden(r->getRight());
    }
}
//O(n)
void BST::printIn()
{
    inOrden(root);
    cout << endl;
}

//O(n)
void BST::levelByLevel(queue<NodeT *> cola)
{
    queue<NodeT *> temp;
    if (cola.empty())
        return;

    while (!cola.empty())
    {
        NodeT *t = cola.front();
        cola.pop();
        cout << t->getData() << " ";
        if (t->getLeft() != nullptr)
            temp.push(t->getLeft());
        if (t->getRight() != nullptr)
            temp.push(t->getRight());
    }
    cola = temp;
    levelByLevel(cola);
}
//O(n)
void BST::printLevel()
{
    queue<NodeT *> cola;
    cola.push(root);
    levelByLevel(cola);
    cout << endl;

}

//O(1)
int BST::howManyChildren(NodeT *r)
{
    int cont = 0;
    if (r->getLeft() != nullptr)
    {
        cont++;
    }
    if (r->getRight() != nullptr)
    {
        cont++;
    }
    return cont;
}
//O(n)
int BST::succ(NodeT *r)
{
    NodeT *curr = r->getRight();
    while (curr->getLeft() != nullptr)
    {
        curr = curr->getLeft();
    }
    return curr->getData();
}
//O(n)
int BST::pred(NodeT *r)
{
    NodeT *curr = r->getLeft();
    while (curr->getRight() != nullptr)
    {
        curr = curr->getRight();
    }
    return curr->getData();
}

//O(n)
void BST::remove(int data)
{
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr && curr->getData() != data)
    {
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if (curr == nullptr)
    {
        return;
    }
    int cantHijos = howManyChildren(curr);
    switch (cantHijos)
    {
    case 0:
        if (father == nullptr)
        {
            root = nullptr;
        }
        else
        {
            if (father->getData() > data)
            {
                father->setLeft(nullptr);
            }
            else
            {
                father->setRight(nullptr);
            }
        }
        delete curr;
        break;
    case 1:
        if (father == nullptr)
        {
            root = (curr->getLeft() != nullptr) ? curr->getLeft() : curr->getRight();
        }
        else
        {
            if (father->getData() > data)
            { // quiero borrar al hijo izq del padre
                if (curr->getLeft() != nullptr)
                { // único hijo esta a la izq.
                    father->setLeft(curr->getLeft());
                }
                else
                { // único hijo esta a la der.
                    father->setLeft(curr->getRight());
                }
            }
            else
            { // quiero borrar al hijo der del padre
                if (curr->getLeft() != nullptr)
                { // único hijo esta a la izq.
                    father->setRight(curr->getLeft());
                }
                else
                { // único hijo esta a la der.
                    father->setRight(curr->getRight());
                }
            }
        }
        delete curr;
        break;
    case 2:
        int sucesor = succ(curr);
        remove(sucesor);
        curr->setData(sucesor);
        break;
    }
}
//O(n)
int BST::count(NodeT *r)
{
    if (r == nullptr)
    {
        return 0;
    }
    return 1 + count(r->getLeft()) + count(r->getRight());
}

//O(n)
int BST::size(){
	return count(root);
}
/*	
Desplegará cada uno de los datos almacenados en el BST dependiendo del parámetro en entrada:
1. Preorder
2. Inorder
3. Postorder
4. Level by level
Complejidad O(n)
*/
void BST::visit(int num)
{
    switch (num)
    {
    case 1:
        printPre();
        break;
    case 2:
        printIn();
        break;
    case 3:
        printPost();
        break;
    case 4:
        printLevel();
        break;
    default:
        break;
    }
}

int BST::height()
{
    return height(root);
}
//O(n)
int BST::height(NodeT *r)
{
    if (r == NULL)
        return 0;

    int lheight = height(r->getLeft());
    int rheight = height(r->getRight());
    return (lheight > rheight) ? lheight + 1 : rheight + 1;
}
//O(n)
void BST::ancestors(int data){
    NodeT *curr = root;
    stack <NodeT*> pila;
    while (curr != nullptr && curr->getData() != data)
    {
        pila.push(curr);
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if(curr->getData() == data){
        while(!pila.empty()){
            cout<<pila.top()->getData()<<" ";
            pila.pop();
        }
        cout<<endl;
    }
}
//O(n)
int BST::whatlevelamI(int data){
    NodeT *curr = root;
    while (curr != nullptr && curr->getData() != data)
    {
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if(curr==nullptr)
        return -1;

    return(height(root)-height(curr));
    
}