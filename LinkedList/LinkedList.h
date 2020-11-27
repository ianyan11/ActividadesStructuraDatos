#include "Node.h"

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    int getSize();
    bool isEmpty();
    void deleteFirst();
    void deleteLast();
    int deleteAll();
    bool del(T key);
    void print();
    T set(T data, int pos);
    T get(int pos);
    bool change(int pos1, int pos2);
    void create(T data, int pos);
    int read(T key);
    bool update(T buscar, T remplazar);

private:
    Node<T> *head;
    int size;
};
template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    deleteAll();
}
//Comlejidad: O(1)
template <class T>
void LinkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    size++;
}
//Comlejidad: O(n)
template <class T>
void LinkedList<T>::addLast(T data)
{
    if (size == 0)
        addFirst(data);
    else
    {
        Node<T> *curr = head;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}
//Comlejidad: O(n)
template <class T>
bool LinkedList<T>::add(T data, int pos)
{
    if (pos > size)
    {
        return false;
    }
    if (pos == 0)
    {
        addFirst(data);
    }
    else if (pos == size)
    {
        addLast(data);
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}
//Complejidad: O(1)
template <class T>
int LinkedList<T>::getSize()
{
    return size;
}
//Complejidad: O(1)
template <class T>
bool LinkedList<T>::isEmpty()
{
    return head == nullptr;
}
//Complejidad: O(1)
template <class T>
void LinkedList<T>::deleteFirst()
{
    if (head != nullptr)
    {
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}
//Complejidad: O(n)
template <class T>
void LinkedList<T>::deleteLast()
{
    if (size <= 1)
    {
        deleteFirst();
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(nullptr);
        size--;
    }
}
//Complejidad: O(n)
template <class T>
bool LinkedList<T>::del(T key)
{
    Node<T> *curr = head;
    if (curr->getData() == key)
    {
        deleteFirst();
        return true;
    }

    while (curr->getNext() != nullptr)
    {
        if (curr->getNext()->getData() == key)
        {
            Node<T> *aux = curr->getNext();
            curr->setNext(aux->getNext());
            delete aux;
            size--;
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}

//Complejidad: O(n)
template <class T>
int LinkedList<T>::deleteAll()
{
    Node<T> *curr = head;
    while (head != nullptr)
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int sizeAux = size;
    size = 0;
    return sizeAux;
}

//Complejidad: O(n)
template <class T>
void LinkedList<T>::print()
{
    cout << "La LinkedList contiene:" << endl;
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        cout << curr->getData() << endl;
        curr = curr->getNext();
    }
}

//Complejidad:O(n)
template <class T>
T LinkedList<T>::get(int pos)
{
    Node<T> *curr = head;
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    return curr->getData();
}

//Complejidad: O(n)
template <class T>
T LinkedList<T>::set(T data, int pos)
{
    Node<T> *curr = head;
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

//Complejidad: O(n)
template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
    if (pos1 < 0 || pos1 > size || pos2 < 0 || pos2 > size)
        return false;

    Node<T> *curr1 = head;

    int posMen = (pos1 < pos2 ? pos1 : pos2);
    int posMay = (pos1 > pos2 ? pos1 : pos2);

    for (int i = 1; i <= posMen; i++)
    {
        curr1 = curr1->getNext();
    }
    Node<T> *curr2 = curr1;
    for (int i = 1; i <= (posMay - posMen); i++)
    {
        curr2 = curr2->getNext();
    }
    T dataAux = curr1->getData();
    curr1->setData(curr2->getData());
    curr2->setData(dataAux);
    return true;
}

//Complejidad: O(n)
template <class T>
void LinkedList<T>::create(T data, int pos)
{
    if (pos > size)
    {
        addLast(data);
    }
    if (pos <= 0)
    {
        addFirst(data);
    }
    else
    {
        add(data, pos);
    }
}

//Complejidad: O(n)
template <class T>
int LinkedList<T>::read(T key)
{
    Node<T> *curr = head;
    int count = 0;
    while (curr != nullptr)
    {
        if (curr->getData() == key)
        {
            return count;
        }
        count++;
        curr = curr->getNext();
    }
    return -1;
}

//Complejidad: O(n)
template <class T>
bool LinkedList<T>::update(T buscar, T remplazar)
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        if (curr->getData() == buscar)
        {
            curr->setData(remplazar);
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}
