#include <iostream>
using namespace std;

// Definición de un nodo para lista simplemente enlazada
struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(NULL) {}
};

// Clase ListaSimple
class ListaSimple {
public:
    Nodo* primero;
    
    ListaSimple() : primero(NULL) {}
    
    // Verifica si la lista está vacía
    bool listaVacia() {
        return (primero == NULL);
    }
    
    // Inserta un valor al final de la lista
    void insertarFinal(int v) {
        Nodo* nuevo = new Nodo(v);
        if (listaVacia()) {
            primero = nuevo;
        } else {
            Nodo* aux = primero;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }
    }
    
    // Muestra la lista recorriendo los nodos hasta NULL
    void mostrar() {
        Nodo* aux = primero;
        while (aux != NULL) {
            cout << aux->valor << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
    
    // Sobrecarga de mostrar: muestra hasta n nodos (para evitar bucles infinitos en listas circulares)
    void mostrar(int n) {
        Nodo* aux = primero;
        for (int i = 0; i < n && aux != NULL; i++) {
            cout << aux->valor << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
    
    // Devuelve el último nodo de la lista
    Nodo* getUltimo() {
        if (listaVacia()) return NULL;
        Nodo* aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        return aux;
    }
};

int main() {
    // 1) Crear dos listas simples, cada una con 6 valores
    ListaSimple L1, L2;
    
    // L1: 5, 6, 3, 12, 23, 56
    L1.insertarFinal(5);
    L1.insertarFinal(6);
    L1.insertarFinal(3);
    L1.insertarFinal(12);
    L1.insertarFinal(23);
    L1.insertarFinal(56);
    
    // L2: 8, 9, 2, 13, 32, 5
    L2.insertarFinal(8);
    L2.insertarFinal(9);
    L2.insertarFinal(2);
    L2.insertarFinal(13);
    L2.insertarFinal(32);
    L2.insertarFinal(5);
    
    cout << "[Estado Inicial]" << endl;
    cout << "L1: ";
    L1.mostrar();
    cout << "L2: ";
    L2.mostrar();
    cout << endl;
    
    // 2) Modificar punteros:
    //    - El último nodo de L1 apuntará al primero de L2
    //    - El último nodo de L2 apuntará, por ejemplo, al tercer nodo de L1 (valor 3)
    Nodo* ultimoL1 = L1.getUltimo(); // debería ser 56
    Nodo* ultimoL2 = L2.getUltimo(); // debería ser 5
    
    // El último de L1 apunta al primero de L2
    if (ultimoL1 != NULL && L2.primero != NULL) {
        ultimoL1->siguiente = L2.primero;
    }
    
    // El último de L2 (5) apuntará al tercer nodo de L1
    if (ultimoL2 != NULL 
        && L1.primero != NULL 
        && L1.primero->siguiente != NULL 
        && L1.primero->siguiente->siguiente != NULL) {
        ultimoL2->siguiente = L1.primero->siguiente->siguiente;
    }
    
    cout << "[Después de modificar punteros]" << endl;
    
    // 3) Mostrar L1 y L2
    cout << "L1 (mostrar 12 nodos): ";
    L1.mostrar(12);  // Se espera mostrar hasta 12 nodos
    cout << "L2 (mostrar 8 nodos): ";
    L2.mostrar(8);   // Se muestra una cantidad menor, según cómo se modifiquen los punteros
    
    return 0;
}
