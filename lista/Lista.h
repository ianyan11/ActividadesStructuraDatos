#include <iostream>
#include <string>

using namespace std;

#define MAX 100

template <class T>
class Lista {
private:
    T data[MAX];
    int size;
    void ins(T d);
public:
    Lista();
    void insert(T value);
    void erase();
    T getData(int pos);
    int getSize();
    void print();
    void operator+=(T d);
    void operator--();
};

template <class T>
Lista<T>::Lista() { 
    size = 0;
}
template <class T>
void Lista<T>::ins(T value) {
    if (size < MAX){
        data[size ++] = value;
    }
}

template <class T>
void Lista<T>::insert(T value) {
    ins(value);
}
template <class T>
void Lista<T>::operator+=(T value) {
    ins(value);
}
template <class T>
void Lista<T>::erase(){
    if(size > 0){
        size--;
        cout << "[" << size << "] - " << data[size]<<endl;
    }
    else{
        cout << "NO HAY ELEMENTOS" << endl;
    }
}
template <class T>
void Lista<T>::operator--(){
    erase();
}
template <class T>
T Lista<T>::getData(int pos){
    return data[pos];
}

template <class T>
int Lista<T>::getSize(){
    return size;
}

template <class T>
void Lista<T>::print(){
    for (int i=0; i<size; i++){
        cout << "[" << i << "] - " << data[i] << endl;
    }
}