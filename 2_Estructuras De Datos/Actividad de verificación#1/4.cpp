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
    
    // Asignación de nptr
    nptr = &y;
    
    // Estado de la memoria después de la asignación de nptr
    cout << "\nEstado despues de nptr = &y:" << endl;
    cout << "1001 (y) -> " << y << endl;
    cout << "1002 (z) -> " << z << endl;
    cout << "1003 (nptr) -> " << nptr << " (Apunta a y)" << endl;
    cout << "1007 (mptr) -> Indeterminado" << endl;
    
    // Modificación de z mediante nptr
    z = *nptr;
    
    // Estado de la memoria después de la asignación z = *nptr
    cout << "\nEstado despues de z = *nptr:" << endl;
    cout << "1001 (y) -> " << y << endl;
    cout << "1002 (z) -> " << z << " (Ahora tiene el valor de y)" << endl;
    cout << "1003 (nptr) -> " << nptr << " (Apunta a y)" << endl;
    cout << "1007 (mptr) -> Indeterminado" << endl;
    
    // Modificación del valor de y a través de nptr
    *nptr = 7;
    
    // Estado de la memoria después de *nptr = 7
    cout << "\nEstado despues de *nptr = 7:" << endl;
    cout << "1001 (y) -> " << y << " (y modificado a 7)" << endl;
    cout << "1002 (z) -> " << z << " (z permanece igual)" << endl;
    cout << "1003 (nptr) -> " << nptr << " (Sigue apuntando a y)" << endl;
    cout << "1007 (mptr) -> Indeterminado" << endl;
    
    return 0;
}