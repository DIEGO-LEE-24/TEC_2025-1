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
    
    // Encabezado: Inserta al inicio
    void insertarInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = primero;
        primero = nuevo;
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
    
    // Encabezado del método Problema 2
    void convertirParImpar(int num);
};

// Desarrollo del método Problema 2
void ListaSimple::convertirParImpar(int num) {
    // Primero, limpiar la lista (opcional)
    primero = NULL;
    
    // Particionar el número para insertarlo en la lista en el mismo orden
    // Usaremos insertarInicio para ello, ya que al extraer dígitos de derecha a izquierda,
    // insertar al inicio preserva el orden original.
    int copia = num;
    while(copia > 0) {
        int dig = copia % 10;
        insertarInicio(dig);
        copia /= 10;
    }
    
    // Recorrer la lista y aplicar: si es par, elevar al cuadrado; si es impar, al cubo.
    Nodo* aux = primero;
    while(aux != NULL) {
        int valor = aux->dato;
        if(valor % 2 == 0)
            aux->dato = valor * valor;       // par: valor^2
        else
            aux->dato = valor * valor * valor; // impar: valor^3
        aux = aux->siguiente;
    }
}

// Uso en el main (Problema 2)
int main() {
    ListaSimple lista;
    int num = 638901;
    cout << "----- Problema 2 -----" << endl;
    lista.convertirParImpar(num);
    cout << "Lista final (pares^2, impares^3): ";
    lista.mostrar();
    return 0;
}
