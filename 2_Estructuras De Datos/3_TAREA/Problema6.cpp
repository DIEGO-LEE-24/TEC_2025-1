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
        if (listaVacia())
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
    
    // Encabezado del método Problema 6
    bool buscarEnPos(int valor, int pos);
};

// Desarrollo del método Problema 6
bool ListaSimple::buscarEnPos(int valor, int pos) {
    if(pos < 1)
        return false;
    Nodo* aux = primero;
    int contador = 1;
    while(aux != NULL) {
        if(contador == pos)
            return (aux->dato == valor);
        aux = aux->siguiente;
        contador++;
    }
    return false;
}

// Uso en el main (Problema 6)
int main() {
    ListaSimple lista;
    // Crear la lista: 3 -> 4 -> 5 -> 6 -> 7 -> 1 -> 2 -> 13 -> 0 -> NULL
    lista.insertarFinal(3);
    lista.insertarFinal(4);
    lista.insertarFinal(5);
    lista.insertarFinal(6);
    lista.insertarFinal(7);
    lista.insertarFinal(1);
    lista.insertarFinal(2);
    lista.insertarFinal(13);
    lista.insertarFinal(0);
    
    cout << "----- Problema 6 -----" << endl;
    cout << "Buscar 7 en pos 3: " << (lista.buscarEnPos(7, 3) ? "True" : "False") << endl; // Debe ser False (posición 3 tiene 5)
    cout << "Buscar 1 en pos 6: " << (lista.buscarEnPos(1, 6) ? "True" : "False") << endl; // Debe ser True (posición 6 tiene 1)
    
    return 0;
}
