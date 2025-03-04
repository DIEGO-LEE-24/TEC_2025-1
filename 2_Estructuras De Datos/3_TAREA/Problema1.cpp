#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int valor) : dato(valor), siguiente(NULL) {}
};

// Clase de Lista Simple
class ListaSimple {
public:
    Nodo* primero;
    ListaSimple() : primero(NULL) {}

    // Encabezado: Inserta un valor al final (para mantener el orden)
    void insertarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (primero == NULL)
            primero = nuevo;
        else {
            Nodo* aux = primero;
            while (aux->siguiente != NULL)
                aux = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }

    // Encabezado: Muestra la lista
    void mostrar() {
        Nodo* aux = primero;
        while (aux != NULL) {
            cout << aux->dato << " -> ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }
    
    // Encabezado del método Problema 1
    void procesarDosNumeros(int num1, int num2);

    // (Puedes agregar otros métodos básicos si es necesario)
};

// Desarrollo del método Problema 1
// Se particiona cada número en dos listas y luego se recorre cada lista
// para calcular la suma y la multiplicación según las reglas indicadas.
void ListaSimple::procesarDosNumeros(int num1, int num2) {
    // Crear dos listas para almacenar los dígitos de num1 y num2.
    ListaSimple L1, L2;
    int arreglo[20];  // arreglo auxiliar
    int count = 0;

    // Particionar num1 (para mantener el orden, se extraen dígitos y se insertan al final)
    int copia1 = num1;
    while(copia1 > 0) {
        arreglo[count++] = copia1 % 10;
        copia1 /= 10;
    }
    for (int i = count - 1; i >= 0; i--) {
        L1.insertarFinal(arreglo[i]);
    }

    // Particionar num2
    count = 0;
    int copia2 = num2;
    while(copia2 > 0) {
        arreglo[count++] = copia2 % 10;
        copia2 /= 10;
    }
    for (int i = count - 1; i >= 0; i--) {
        L2.insertarFinal(arreglo[i]);
    }

    // Variables para la suma y la multiplicación
    long long suma = 0;
    long long mult = 1;

    // Recorrer Lista1
    Nodo* aux1 = L1.primero;
    while(aux1 != NULL) {
        int valor = aux1->dato;
        if(valor % 2 == 0) {
            // Dígito par: elevar al cuadrado y sumar
            suma += valor * valor;
        } else {
            // Dígito impar: elevar al cubo y multiplicar
            mult *= valor * valor * valor;
        }
        aux1 = aux1->siguiente;
    }

    // Recorrer Lista2
    Nodo* aux2 = L2.primero;
    while(aux2 != NULL) {
        int valor = aux2->dato;
        if(valor % 2 != 0) {
            // Dígito impar: elevar al cubo y sumar
            suma += valor * valor * valor;
        } else {
            // Dígito par: elevar al cuadrado y multiplicar
            mult *= valor * valor;
        }
        aux2 = aux2->siguiente;
    }
    
    cout << "Suma = " << suma << endl;
    cout << "Mult = " << mult << endl;
}

// Uso en el main (Problema 1)
int main() {
    ListaSimple lista;
    int num1 = 6234;
    int num2 = 5890;
    cout << "----- Problema 1 -----" << endl;
    lista.procesarDosNumeros(num1, num2);
    return 0;
}
