#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>   // Para atof
#include <cmath>     // Para pow()
using namespace std;


// Nodo para representar cada token de la expresión (número, operador o paréntesis)
struct NodoToken {
    string token;
    NodoToken* siguiente;
};

NodoToken* crearNodoToken(const string &tok) {
    NodoToken* nuevo = new NodoToken;
    nuevo->token = tok;
    nuevo->siguiente = nullptr;
    return nuevo;
}

void insertarToken(NodoToken*& lista, const string &tok) {
    NodoToken* nuevo = crearNodoToken(tok);
    if(lista == nullptr)
        lista = nuevo;
    else {
        NodoToken* temp = lista;
        while(temp->siguiente != nullptr)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
}


// Cola estática de expresiones (arreglo de 5 elementos)
// Cada elemento es una estructura que contiene la referencia al inicio de la lista de tokens.

struct Expresion {
    NodoToken* inicio;
};


// Pila dinámica para operadores (implementada con lista enlazada)

struct NodoOp {
    string op;
    NodoOp* siguiente;
};

class PilaOper {
private:
    NodoOp* cima;
public:
    PilaOper() : cima(nullptr) {}

    bool vacia() { return cima == nullptr; }

    void apilar(const string &op) {
        NodoOp* nuevo = new NodoOp;
        nuevo->op = op;
        nuevo->siguiente = cima;
        cima = nuevo;
    }

    string desapilar() {
        if(vacia()) return "";
        string op = cima->op;
        NodoOp* temp = cima;
        cima = cima->siguiente;
        delete temp;
        return op;
    }

    string cimaOp() {
        return vacia() ? "" : cima->op;
    }
};


// Pila dinámica para números (para evaluar la expresión posfija)

struct NodoNum {
    double valor;
    NodoNum* siguiente;
};

class PilaNum {
private:
    NodoNum* cima;
public:
    PilaNum() : cima(nullptr) {}

    bool vacia() { return cima == nullptr; }

    void apilar(double valor) {
        NodoNum* nuevo = new NodoNum;
        nuevo->valor = valor;
        nuevo->siguiente = cima;
        cima = nuevo;
    }

    double desapilar() {
        if(vacia()) return 0;
        double valor = cima->valor;
        NodoNum* temp = cima;
        cima = cima->siguiente;
        delete temp;
        return valor;
    }
};


// Funciones de prioridad para operadores
// Según la tabla vista en clase:
//   ^: prioridad dentro=3, fuera=4
//   *,/ : prioridad dentro=2, fuera=2
//   +,- : prioridad dentro=1, fuera=1
//   ( : prioridad dentro=0, fuera=5

int prioridadDentro(const string &op) {
    if(op == "^") return 3;
    if(op == "*" || op == "/") return 2;
    if(op == "+" || op == "-") return 1;
    if(op == "(") return 0;
    return -1;
}

int prioridadFuera(const string &op) {
    if(op == "^") return 4;
    if(op == "*" || op == "/") return 2;
    if(op == "+" || op == "-") return 1;
    if(op == "(") return 5;
    return -1;
}

// Función que determina si un token es un operador
bool esOperador(const string &tok) {
    return (tok == "+" || tok == "-" || tok == "*" || tok == "/" || tok == "^");
}


// Función que determina si un token es un número
bool esNumero(const string &tok) {
    return (!tok.empty() && isdigit(tok[0]));  // Suponemos que si inicia con dígito, es número
}


// Función para convertir la expresión infija a posfija
// Se utiliza una pila de operadores y se genera una lista enlazada de salida.

NodoToken* convertirInfijoAPosfijo(NodoToken* infijo) {
    PilaOper pila;
    NodoToken* posfijo = nullptr;
    NodoToken* ptr = infijo;
    
    while(ptr != nullptr) {
        string tok = ptr->token;
        
        if(esNumero(tok)) {
            insertarToken(posfijo, tok);
        }
        else if(tok == "(") {
            pila.apilar(tok);
        }
        else if(tok == ")") {
            while(!pila.vacia() && pila.cimaOp() != "(") {
                insertarToken(posfijo, pila.desapilar());
            }
            // Sacar el "(" de la pila (no se agrega a posfijo)
            if(!pila.vacia())
                pila.desapilar();
        }
        else if(esOperador(tok)) {
            while(!pila.vacia() && (prioridadDentro(pila.cimaOp()) >= prioridadFuera(tok))) {
                insertarToken(posfijo, pila.desapilar());
            }
            pila.apilar(tok);
        }
        
        ptr = ptr->siguiente;
    }
    
    // Vaciar la pila de operadores
    while(!pila.vacia()) {
        insertarToken(posfijo, pila.desapilar());
    }
    
    return posfijo;
}


// Función para evaluar la expresión posfija
double evaluarPosfijo(NodoToken* posfijo) {
    PilaNum pila;
    NodoToken* ptr = posfijo;
    
    while(ptr != nullptr) {
        string tok = ptr->token;
        if(esNumero(tok)) {
            double num = atof(tok.c_str());
            pila.apilar(num);
        } else if(esOperador(tok)) {
            double num2 = pila.desapilar();
            double num1 = pila.desapilar();
            double res = 0;
            if(tok == "+") res = num1 + num2;
            else if(tok == "-") res = num1 - num2;
            else if(tok == "*") res = num1 * num2;
            else if(tok == "/") res = num1 / num2;
            else if(tok == "^") res = pow(num1, num2);
            pila.apilar(res);
        }
        ptr = ptr->siguiente;
    }
    return pila.desapilar();
}


// Función para imprimir una lista enlazada de tokens (la expresión)
void imprimirExpresion(NodoToken* lista) {
    NodoToken* ptr = lista;
    while(ptr != nullptr) {
        cout << ptr->token;
        ptr = ptr->siguiente;
    }
    cout << endl;
}


// Función para liberar memoria de una lista enlazada
void liberarLista(NodoToken* lista) {
    while(lista != nullptr) {
        NodoToken* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
}


// Función para leer un archivo y construir la lista de tokens
// Se asume que cada línea del archivo contiene un token
NodoToken* leerArchivo(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return nullptr;
    }
    NodoToken* lista = nullptr;
    string linea;
    while(getline(archivo, linea)) {
        if(!linea.empty()) {
            insertarToken(lista, linea);
        }
    }
    archivo.close();
    return lista;
}


// Función principal
int main() {
    const int TAM_COLA = 5;
    // Cola estática: arreglo de 5 expresiones
    Expresion cola[TAM_COLA];
    const char* nombres[TAM_COLA] = {"Arch1.txt", "Arch2.txt", "Arch3.txt", "Arch4.txt", "Arch5.txt"};
    
    // Lectura de archivos y carga en la cola
    for(int i = 0; i < TAM_COLA; i++) {
        cola[i].inicio = leerArchivo(nombres[i]);
        if(cola[i].inicio == nullptr) {
            cout << "Error leyendo el archivo " << nombres[i] << endl;
        }
    }
    
    // Procesar cada expresión en la cola (en orden)
    for(int i = 0; i < TAM_COLA; i++) {
        cout << "--------------------------------------------------" << endl;
        cout << "Expresión original (Archivo " << nombres[i] << "): ";
        imprimirExpresion(cola[i].inicio);
        
        // Convertir a posfijo
        NodoToken* posfijo = convertirInfijoAPosfijo(cola[i].inicio);
        cout << "Expresión en posfijo: ";
        imprimirExpresion(posfijo);
        
        // Evaluar la expresión posfijo
        double resultado = evaluarPosfijo(posfijo);
        cout << "Resultado de la evaluación: " << resultado << endl;
        
        // Liberar memoria de las listas
        liberarLista(cola[i].inicio);
        liberarLista(posfijo);
    }
    
    return 0;
}
