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
    
    // Encabezado del método Problema 4
    void invertir();
};

// Desarrollo del método Problema 4
void ListaSimple::invertir() {
    Nodo* anterior = NULL;
    Nodo* actual = primero;
    Nodo* siguiente = NULL;
    while(actual != NULL) {
        siguiente = actual->siguiente;   // Guardar el siguiente nodo
        actual->siguiente = anterior;      // Invertir el enlace
        anterior = actual;                 // Avanzar "anterior"
        actual = siguiente;                // Avanzar "actual"
    }
    primero = anterior;  // Actualizar el primero al último nodo procesado
}

// Uso en el main (Problema 4)
int main() {
    ListaSimple lista;
    lista.insertarFinal(3);
    lista.insertarFinal(5);
    lista.insertarFinal(9);
    lista.insertarFinal(10);
    
    cout << "----- Problema 4 -----" << endl;
    cout << "Lista original: ";
    lista.mostrar();
    lista.invertir();
    cout << "Lista invertida: ";
    lista.mostrar();
    
    return 0;
}
