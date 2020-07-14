#include <iostream>
#include <string.h>
using namespace std;
const int longitud = 20;

//Se cambio el nombre de algunos campos por comodidad.
struct datos{
    char nombre[longitud + 1];
    int cantidad;
    float precio_unitario;
    float costo_articulo;
};
//Funciones que tienen el mismo argumento.
void leer(datos *, int);
void costo(datos *, int);
void desplegar(datos *, int);
float total(datos *, int);

int main()
{
    int n;
    float total_a_pagar;
    
    cout << "\nCalcular el precio unitario y el total de la compra\n\n";

    cout << "Cuantos articulos desea comprar: ";
    cin >> n;
    //Se limpia el teclado puesto que se va a leer una cadena string.
    cin.ignore(100, '\n');
    //Se crea el arreglo de tipo usando la estructutra "datos", ademas se llaman a todas las funciones.
    datos registro[n];
    leer(registro, n);
    costo(registro, n);
    desplegar(registro, n);
    total_a_pagar= total(registro, n);
    cout << "\n\nEl total de su compra es: " << total_a_pagar << endl;
    cout << "Gracias por su preferencia!" << endl;
}
//Funcion que lee los datos de los productos.
void leer(datos *registro, int n)
{
    string nombre;
    cout << "\nIngrese los datos\n";
    for(int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Nombre del producto-----------";
        getline(cin, nombre, '\n');
        strncpy(registro[i].nombre, nombre.c_str(), longitud);
        cout << "Cantidad----------------------";
        cin >> registro[i].cantidad;
        cout << "Precio unitario en dolares----";
        cin >> registro[i].precio_unitario;
        //Se vuelve a limpiar el teclado para ingresar una cadena en el nuevo ciclo del for.
        cin.ignore(100, '\n');
    }
}
//Funcion que calcula el costo de cada articulo.
void costo(datos *registro, int n)
{
    for(int i = 0; i < n; i++) 
        registro[i].costo_articulo = registro[i].cantidad * registro[i].precio_unitario;
}
//Funcion que despliega los datos.
void desplegar(datos *registro, int n)
{
    cout << "\n\nLos datos que han sido ingresados son\n";
    for(int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Nombre------------------------" << registro[i].nombre << endl;
        cout << "Cantidad----------------------" << registro[i].cantidad << endl;
        cout << "Precio unitario---------------" << registro[i].precio_unitario << " dolares" << endl;
        cout << "Costo total del articulo------" << registro[i].costo_articulo << " dolares" << endl;
    }
}
//Funcion que calcula el total a pagar.
float total(datos *registro, int n)
{
    float pago_total=0.0;
    for(int i = 0; i < n; i++)
        pago_total += registro[i].costo_articulo;

    return pago_total;
}