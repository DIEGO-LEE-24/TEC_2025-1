#include <iostream>
#include <unordered_set>
using namespace std;

// Definición de un nodo para lista simplemente enlazada
struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

// Clase ListaSimple
class ListaSimple {
public:
    Nodo* primero;
    
    ListaSimple() : primero(nullptr) {}

    // Destructor que libera la memoria de los nodos, evitando doble eliminación
    ~ListaSimple() {
        // Conjunto estático para llevar registro de los nodos ya liberados
        static unordered_set<Nodo*> nodosLiberados;
        Nodo* actual = primero;
        while (actual != nullptr && nodosLiberados.find(actual) == nodosLiberados.end()) {
            nodosLiberados.insert(actual);
            Nodo* temp = actual->siguiente;
            delete actual;
            actual = temp;
        }
    }
    
    // Verifica si la lista está vacía
    bool listaVacia() const {
        return (primero == nullptr);
    }
    
    // Inserta un valor al final de la lista
    void insertarFinal(int v) {
        Nodo* nuevo = new Nodo(v);
        if (listaVacia()) {
            primero = nuevo;
        } else {
            Nodo* aux = primero;
            while (aux->siguiente != nullptr) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }
    }
    
    // Muestra la lista recorriendo los nodos hasta nullptr
    void mostrar() const {
        Nodo* aux = primero;
        while (aux != nullptr) {
            cout << aux->valor << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
    
    // Sobrecarga de mostrar: muestra hasta n nodos (para evitar bucles infinitos en listas circulares)
    void mostrar(int n) const {
        Nodo* aux = primero;
        for (int i = 0; i < n && aux != nullptr; i++) {
            cout << aux->valor << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
    
    // Devuelve el último nodo de la lista
    Nodo* getUltimo() const {
        if (listaVacia()) return nullptr;
        Nodo* aux = primero;
        while (aux->siguiente != nullptr) {
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
    Nodo* ultimoL1 = L1.getUltimo(); // Se espera que sea el nodo con valor 56
    Nodo* ultimoL2 = L2.getUltimo(); // Se espera que sea el nodo con valor 5
    
    // Validar y modificar punteros
    if (ultimoL1 != nullptr && L2.primero != nullptr) {
        ultimoL1->siguiente = L2.primero;
    } else {
        cerr << "Error: No se puede modificar L1, alguno de los nodos es nulo." << endl;
    }
    
    if (ultimoL2 != nullptr 
        && L1.primero != nullptr 
        && L1.primero->siguiente != nullptr 
        && L1.primero->siguiente->siguiente != nullptr) {
        ultimoL2->siguiente = L1.primero->siguiente->siguiente;
    } else {
        cerr << "Error: No se puede modificar L2, alguno de los nodos requeridos es nulo." << endl;
    }
    
    cout << "[Después de modificar punteros]" << endl;
    cout << "L1 (mostrar 12 nodos): ";
    L1.mostrar(12);  // Se espera mostrar hasta 12 nodos
    cout << "L2 (mostrar 8 nodos): ";
    L2.mostrar(8);   // Se muestra una cantidad menor, según cómo se modifiquen los punteros
    
    return 0;
}
