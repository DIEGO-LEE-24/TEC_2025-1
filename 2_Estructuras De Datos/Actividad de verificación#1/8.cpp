#include <iostream>

using namespace std;

int main() {
    int y = 5;
    int z = 3;
    int *nptr;
    int *mptr;
    
    // Estado de la memoria antes de la asignación de punteros
    cout << "\nEstado inicial de la memoria:" << endl;
    cout << "1001 (y) -> " << y << endl;
    cout << "1002 (z) -> " << z << endl;
    cout << "1003 (nptr) -> Indeterminado" << endl;
    cout << "1007 (mptr) -> Indeterminado" << endl;
    
    // Asignación de nptr a y
    nptr = &y;
    cout << "\nDespues de nptr = &y:" << endl;
    cout << "1001 (y) -> " << y << endl;
    cout << "1002 (z) -> " << z << endl;
    cout << "1003 (nptr) -> " << nptr << " (Apunta a y)" << endl;
    cout << "1007 (mptr) -> Indeterminado" << endl;
    
    // Modificación de z mediante nptr
    z = *nptr;
    cout << "\nDespues de z = *nptr:" << endl;
    cout << "1001 (y) -> " << y << endl;
    cout << "1002 (z) -> " << z << " (Ahora tiene el valor de y)" << endl;
    cout << "1003 (nptr) -> " << nptr << " (Apunta a y)" << endl;
    cout << "1007 (mptr) -> Indeterminado" << endl;
    
    // Modificación del valor de y a través de nptr
    *nptr = 7;
    cout << "\nDespues de *nptr = 7:" << endl;
    cout << "1001 (y) -> " << y << " (y modificado a 7)" << endl;
    cout << "1002 (z) -> " << z << " (z sigue con 5)" << endl;
    cout << "1003 (nptr) -> " << nptr << " (Sigue apuntando a y)" << endl;
    cout << "1007 (mptr) -> Indeterminado" << endl;
    
    // Asignación de mptr a nptr
    mptr = nptr;
    cout << "\nDespues de mptr = nptr:" << endl;
    cout << "1001 (y) -> " << y << " (y sigue en 7)" << endl;
    cout << "1002 (z) -> " << z << " (z sigue en 5)" << endl;
    cout << "1003 (nptr) -> " << nptr << " (Apunta a y)" << endl;
    cout << "1007 (mptr) -> " << mptr << " (Ahora también apunta a y)" << endl;
    
    // Modificación de y a través de nptr sumando 1
    y = (*nptr) + 1;
    cout << "\nDespues de y = (*nptr) + 1:" << endl;
    cout << "1001 (y) -> " << y << " (y ahora es 10)" << endl;
    cout << "1002 (z) -> " << z << " (z sigue en 5)" << endl;
    cout << "1003 (nptr) -> " << nptr << " (Sigue apuntando a y)" << endl;
    cout << "1007 (mptr) -> " << mptr << " (Sigue apuntando a y)" << endl;
    
    return 0;
}