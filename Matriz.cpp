#include <string>
#include <iostream>
#include "Nodo.cpp"

using namespace std;

class Matriz{


public:
    // Raíz
    Nodo *root;

    // Constructor
    Matriz(){
        this->root = new Nodo(-1, -1, "Root");
    }

    // Busca el nodo en Y, si existe retorna el nodo sino NULL
    Nodo* buscarFila(int y){
        Nodo* temp = this->root;

        while (temp != NULL) {
            if (temp->y == y) {
                return temp;
            }
            temp = temp->abajo;
        }
        return NULL;
    }

    // Busca el nodo en X, si existe retorna el nodo sino NULL
    Nodo* buscarColumna(int x){
        Nodo* temp = this->root;

        while (temp != NULL) {
            if (temp->x == x) {
                return temp;
            }
            temp = temp->siguiente;
        }
        return NULL;
    }

    // Insertar ordenado en columnas
    Nodo* insertarOrdenadoColumna(Nodo* nuevo, Nodo* cabeza_col){
        Nodo* temp = cabeza_col;
        bool bandera = false;

        while (true) {
            if (temp->x == nuevo->x) {
                // Si la posición es la misma se sobreescribe
                temp->y = nuevo->y;
                temp->dato = nuevo->dato;
                return temp;
            }
            else if (temp->x > nuevo->x) {
                // Insertar antes del temp
                bandera = true;
                break;
            }
            else if (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            else {
                // Insertar nuevo despues de temp
                // bandera = false
                break;
            }

        } // Termina while

        if (bandera) {
            // Insertar antes del temporal
            nuevo->siguiente = temp;
            temp->anterior->siguiente = nuevo;
            nuevo->anterior = temp->anterior;
            temp->anterior = nuevo;
        }
        else {
            temp->siguiente = nuevo;
            nuevo->anterior = temp;
        }
        return nuevo;

    }

    // Insertar ordenado en filas
    Nodo* insertarOrdenadoFila(Nodo* nuevo, Nodo* cabeza_Fila){
        Nodo* temp = cabeza_Fila;
        bool bandera = false;

        while (true) {
            if (temp->y == nuevo->y) {
                // Si la posición es la misma se sobreescribe
                temp->x = nuevo->x;
                temp->dato = nuevo->dato;
                return temp;
            }
            else if (temp->y > nuevo->y) {
                // Insertar antes del temp
                bandera = true;
                break;
            }
            else if (temp->abajo != NULL) {
                temp = temp->abajo;
            }
            else {
                // Insertar nuevo despues de temp
                // bandera = false
                break;
            }

        } // Termina while

        if (bandera) {
            // Insertar antes del temporal
            nuevo->abajo = temp;
            temp->arriba->abajo= nuevo;
            nuevo->arriba = temp->arriba;
            temp->arriba = nuevo;
        }
        else {
            temp->abajo = nuevo;
            nuevo->arriba = temp;
        }
        return nuevo;

    }

    // Crear columna
    Nodo * crearColumna(int x){
        Nodo* cabezaColumna;
        Nodo* columna;

        cabezaColumna = this->root;
        columna = this->insertarOrdenadoColumna(new Nodo(x, -1, "COL"), cabezaColumna);
        return columna;
    }

    // Crear fila
    Nodo * crearFila(int y){
        Nodo* cabezaFila;
        Nodo* fila;

        cabezaFila = this->root;
        fila = this->insertarOrdenadoFila(new Nodo(-1, y, "FIL"), cabezaFila);
        return fila;
    }

    // Inserción general
    void insertar(int x, int y, string dato){
        Nodo* nuevo = new Nodo(x, y, dato);
        Nodo* nodoColumna = this->buscarColumna(x);
        Nodo* nodoFila = this->buscarFila(y);

        // CASO 1: Columna no existe y fila no existe
        if (nodoColumna == NULL && nodoFila == NULL) {
            cout<<"Caso 1"<<endl;
            // Crear columna
            nodoColumna = this->crearColumna(x);
            // Crear fila
            nodoFila = this->crearFila(y);
            // Insertamos de forma ordenada en columna
            nuevo = this->insertarOrdenadoColumna(nuevo, nodoFila);
            // Insertamos de forma ordenada en fila
            nuevo = this->insertarOrdenadoFila(nuevo, nodoColumna);
            return;
        }
        // CASO 2: Columna no existe y fila si existe
        else if (nodoColumna == NULL && nodoFila != NULL) {
            cout<<"Caso 2"<<endl;
            // Crear columna
            nodoColumna = this->crearColumna(x);
            // Insertamos de forma ordenada en columna
            nuevo = this->insertarOrdenadoColumna(nuevo, nodoFila);
            // Insertamos de forma ordenada en fila
            nuevo = this->insertarOrdenadoFila(nuevo, nodoColumna);
            return;
        }
        // CASO 3: Columna existe y fila no existe
        else if (nodoColumna != NULL && nodoFila == NULL) {
            cout<<"Caso 3"<<endl;
            // Crear fila
            nodoFila = this->crearFila(y);
            // Insertamos de forma ordenada en columna
            nuevo = this->insertarOrdenadoColumna(nuevo, nodoFila);
            // Insertamos de forma ordenada en fila
            nuevo = this->insertarOrdenadoFila(nuevo, nodoColumna);
            return;
        }
        // CASO 4: Columna y fila existen
        else if (nodoColumna != NULL && nodoFila != NULL) {
            cout<<"Caso 4"<<endl;
            // Insertamos de forma ordenada en columna
            nuevo = this->insertarOrdenadoColumna(nuevo, nodoFila);
            // Insertamos de forma ordenada en fila
            nuevo = this->insertarOrdenadoFila(nuevo, nodoColumna);
        }
    }

    // mostrar cabecera filas
    void mostrarCabeceraFilas(){
        Nodo* temp = this->root;
        while (temp != NULL) {
            cout<<temp->x<<endl;
            temp = temp->siguiente;
        }
    }

    // mostrar cabecera columnas
    void mostrarCabeceraColumnas(){
        Nodo* temp = this->root;
        while (temp != NULL) {
            cout<<temp->y<<endl;
            temp = temp->abajo;
        }
    }

    // mostrar contenido de la matriz
    void mostrarContenidoMatriz(){
        Nodo* temp = this->root;
        // Recorriendo desde la raíz hacia abajo
        while (temp != NULL) {
            cout<<"Columna: "<<temp->y<<endl;
            Nodo* aux = temp;
            // Recorriendo desde la columna n hacia abajo
            while (aux->siguiente != NULL) {
                cout<<aux->siguiente->dato<<endl;
                aux = aux->siguiente;
            }
            temp = temp->abajo;
        }
    }


};
