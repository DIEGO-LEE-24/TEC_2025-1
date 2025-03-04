#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int valor): dato(valor), siguiente(NULL) {}
};

class ListaSimple {
public:
    Nodo* primero;
    ListaSimple(): primero(NULL) {}

    bool listaVacia() {
        return (primero == NULL);
    }
    
    // Encabezado: Inserta al final
    void insertarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if(listaVacia())
            primero = nuevo;
        else {
            Nodo* aux = primero;
            while(aux->siguiente != NULL)
                aux = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
    
    // Encabezado: Muestra la lista
    void mostrar() {
        Nodo* aux = primero;
        while(aux != NULL) {
            cout << aux->dato << " -> ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }
    
    // Encabezado del método Problema 5
    bool buscar(int valor);
};

// Desarrollo del método Problema 5
bool ListaSimple::buscar(int valor) {
    Nodo* aux = primero;
    while(aux != NULL) {
        if(aux->dato == valor)
            return true;
        aux = aux->siguiente;
    }
    return false;
}

// Uso en el main (Problema 5)
int main() {
    ListaSimple lista;
    lista.insertarFinal(3);
    lista.insertarFinal(4);
    lista.insertarFinal(5);
    lista.insertarFinal(6);
    lista.insertarFinal(7);
    lista.insertarFinal(1);
    lista.insertarFinal(2);
    lista.insertarFinal(13);
    lista.insertarFinal(0);
    
    cout << "----- Problema 5 -----" << endl;
    cout << "Buscar 9: " << (lista.buscar(9) ? "True" : "False") << endl; // Debe imprimir False
    cout << "Buscar 1: " << (lista.buscar(1) ? "True" : "False") << endl; // Debe imprimir True
    
    return 0;
}
