#include <iostream>
#include "Matriz.cpp"

using namespace std;

int main()
{
    Matriz* matriz = new Matriz();

    matriz->insertar(1,5,"(1,5)");
    matriz->insertar(2,2,"(2,2)");
    matriz->insertar(3,2,"(3,2)");
    matriz->insertar(2,3,"(2,3)");
    matriz->insertar(4,3,"(4,3)");
    matriz->insertar(5,1,"(5,1)");
    matriz->insertar(1,1,"(1,1)");
    matriz->insertar(5,4,"(5,4)");
    matriz->insertar(6,1,"(6,1)");

    cout<<"----- CABECERAS FILAS -----"<<endl;
    matriz->mostrarCabeceraFilas();
    cout<<"----- CABECERAS COLUMNAS -----"<<endl;
    matriz->mostrarCabeceraColumnas();
    cout<<"----- CONTENIDO MATRIZ -----"<<endl;
    matriz->mostrarContenidoMatriz();

    return 0;
}
