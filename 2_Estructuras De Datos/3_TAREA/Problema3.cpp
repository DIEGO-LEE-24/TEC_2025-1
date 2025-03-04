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
    
    // Encabezado del método Problema 3
    ListaSimple sumarListas(const ListaSimple &otra);
};

// Desarrollo del método Problema 3
ListaSimple ListaSimple::sumarListas(const ListaSimple &otra) {
    ListaSimple L3;  // Lista resultado
    Nodo* aux1 = primero;
    Nodo* aux2 = otra.primero;
    while(aux1 != NULL && aux2 != NULL) {
        int sumaNodo = aux1->dato + aux2->dato;
        L3.insertarFinal(sumaNodo);
        aux1 = aux1->siguiente;
        aux2 = aux2->siguiente;
    }
    return L3;
}

// Uso en el main (Problema 3)
int main() {
    ListaSimple L1, L2;
    // L1: 3 -> 5 -> 9 -> 10
    L1.insertarFinal(3);
    L1.insertarFinal(5);
    L1.insertarFinal(9);
    L1.insertarFinal(10);
    // L2: 12 -> 6 -> 4 -> 2
    L2.insertarFinal(12);
    L2.insertarFinal(6);
    L2.insertarFinal(4);
    L2.insertarFinal(2);
    
    ListaSimple L3 = L1.sumarListas(L2);
    cout << "----- Problema 3 -----" << endl;
    cout << "Lista resultante (L1 + L2): ";
    L3.mostrar();
    return 0;
}
