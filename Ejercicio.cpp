#include <iostream>
#include <string.h>

using namespace std;

const int longitud = 20;

struct datos{
    char nombre[longitud + 1];
    int registro;
    float precio;
    float costo_unitario;
};

void leer(datos *, int);
void costo(datos *, int);
void desplegar();
void total();

int main()
{
    int n;
    cout << "\nCalcular el precio unitario y el total de la compra\n\n";

    cout << "Cuantos articulos desea comprar: ";
    cin >> n;
    datos registro[n];
    leer(registro, n);
    desplegar(registro, n);
}
void leer(datos *registro, int n)
{
    cout << "Ingrese los datos: ";
    for(int i = 0; i < n; i++){
    cout << "Ingrese el nombre de el articulo: ";
    getline(cin, registro[i].nombre, '\n')
    }
}
void desplegar(datos *registro, int n)
{

}