#pragma once

#pragma region includes

#include <iostream>
#include <cstdlib>

using namespace std;

#include "list.h"

#pragma endregion

float mostrarGanancias(nodo<factura> *lista)
{
    float ganancia = 0;
    while (lista)
    {
        ganancia += lista->dato.total;
        lista = lista->sig;
    }
    return ganancia;
}

//+++PARA REEMBOLSOS+++//
void regresarAlStock(nodo<producto> **listaProductos, nodo<producto> *carrito)
{
    nodo<producto> *iterador = *listaProductos;
    while (iterador)
    {
        if (iterador->dato.codigo == carrito->dato.codigo)
        {
            iterador->dato.cantidad += carrito->dato.cantidad;
            return;
        }
        iterador = iterador->sig;
    }
}

void reembolso(nodo<producto> **listaProductos, nodo<factura> **listaFacrtuas)
{
    int codigo;
    nodo<producto> *carrito;
    system("cls");
    cout << "\n\tingrese el codigo de factura para efectuar el reembolso\n";
    cout << "\ncodigo: ";
    cin >> codigo;

    carrito = buscarint(*listaFacrtuas, codigo)->dato.carrito;

    while (carrito)
    {
        regresarAlStock(listaProductos, carrito);
        carrito = carrito->sig;
    }

    eliminarNodo(listaFacrtuas, codigo);
}

//++PARA AGREGAR AL STOCK+++//
int obtenerCodigo(nodo<producto> *lista, int min, int max)
{
    nodo<producto> *actual = buscarint(lista, min);
    int codigo;

    while ((actual) && (actual->sig->dato.codigo < max))
    {
        actual = actual->sig;
    }
    codigo = (actual->dato.codigo);

    return codigo;
}

producto skereee(nodo<producto> *listaProductos)
{
    producto agregar;
    unsigned short opcion;
    int min, max, codigo;
    system("cls");
    cout << "\n\tDe que categoria es el producto?\n";
    cout << "\n1.Monitores\t2.Tarjetas Graficas\t3.Procesadores";
    cout << "\n4.Cases\t\t5.Placas Base \t\t6.Fuentes de poder\n"
         << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        min = 1001;
        max = 1999;
        codigo = obtenerCodigo(listaProductos, min, max);
        break;
    case 2:
        min = 2001;
        max = 2999;
        codigo = obtenerCodigo(listaProductos, min, max);
        break;
    case 3:
        min = 3001;
        max = 3999;
        codigo = obtenerCodigo(listaProductos, min, max);
        break;
    case 4:
        min = 4001;
        max = 4999;
        codigo = obtenerCodigo(listaProductos, min, max);
        break;
    case 5:
        min = 5001;
        max = 5999;
        codigo = obtenerCodigo(listaProductos, min, max);
        break;
    case 6:
        min = 6001;
        max = 6999;
        codigo = obtenerCodigo(listaProductos, min, max);
        break;
    default:
        cout << "\nError\n";
        system("pause");
        break;
    }

    codigo = ++codigo;
    agregar.codigo = codigo;
    fflush(stdin);
    cout << "\nnombre del producto: ";
    getline(cin, agregar.nombre);
    cout << "\nmodelo del prducto: ";
    getline(cin, agregar.modelo);
    cout << "\nprecio del producto: ";
    cin >> agregar.precio;
    cout << "\ncantidad a ingresar: ";
    cin >> agregar.cantidad;

    return agregar;
}

void agregarInventario(nodo<producto> **listaProductos)
{
    int codigo, cantidad;
    nodo<producto> *modificador = *listaProductos;
    system("cls");
    cout << "\n\tintroduce el codigo de producto\n";
    cout << "\ncodigo: ";
    cin >> codigo;

    while (modificador->dato.codigo != codigo)
    {
        modificador = modificador->sig;
    }
    modificador->dato.mostrar();
    cout << "\n\ncuantos desea agregar al inventario: ";
    cin >> cantidad;

    modificador->dato.cantidad += cantidad;
}

void agregarAlStock(nodo<producto> **listaProductos)
{
    producto agregar;
    unsigned short opcion;

    system("cls");
    cout << "\n\tSELECCIONE UNA OPCION\n";
    cout << "\n1.Agregar un nuevo producto";
    cout << "\n2.Agregar al inventario";
    cout << "\nopcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        agregar = skereee(*listaProductos);
        agglista(listaProductos, agregar);
        break;
    case 2:
        agregarInventario(listaProductos);
        break;
    }
}

//+++PARA ELIMINAR DEL STOCK+++//
void eliminarDelStock(nodo<producto> **listaProductos)
{
    int codigo;

    cout << "\n\tIngrese el codigo del producto a eliminar\n";
    cout << "\ncodigo: ";
    cin >> codigo;

    if (eliminarNodo(listaProductos, codigo))
    {
        cout << "\n\nElproducto a sido eliminado\n\n";
        system("pause");
    }
}