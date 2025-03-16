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
    
    // Asignación de punteros
    nptr = &y;
    mptr = &z;
    
    // Estado de la memoria después de la asignación de punteros
    cout << "\nEstado despues de la asignacion:" << endl;
    cout << "1001 (y) -> " << y << endl;
    cout << "1002 (z) -> " << z << endl;
    cout << "1003 (nptr) -> " << nptr << " (Apunta a y)" << endl;
    cout << "1007 (mptr) -> " << mptr << " (Apunta a z)" << endl;
    
    return 0;
}
