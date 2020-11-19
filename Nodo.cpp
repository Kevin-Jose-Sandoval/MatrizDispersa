#include <string>
#include <iostream>

using namespace std;

class Nodo{

public:
    // Punteros
    Nodo *arriba;
    Nodo *abajo;
    Nodo *siguiente;
    Nodo *anterior;

    // Datos
    int x;
    int y;
    string dato;

    // Constructor
    Nodo(int x, int y, string dato){
        this->arriba = NULL;
        this->abajo = NULL;
        this->siguiente = NULL;
        this->anterior = NULL;

        this->x = x;
        this->y = y;
        this->dato = dato;
    }

};
