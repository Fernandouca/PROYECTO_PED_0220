#pragma once

#pragma region includes

#include <iostream>
#include <cstdlib>

using namespace std;

#include "list.h"

#pragma endregion

void agregarProducto(factura *clientes, nodo<producto> *lista, unsigned short opcion)
{
    int cant, opcion2, aux;
    producto aux1;
    nodo<producto> *temp = new nodo<producto>();
    nodo<producto> *buscador = new nodo<producto>();

    cout << "\n\tOpcion: ";
    cin >> opcion2;

    switch (opcion)
    {
    case 1:
        aux = 1000 + opcion2;
        temp = buscarint(lista, aux);
        break;
    case 2:
        aux = 2000 + opcion2;
        temp = buscarint(lista, aux);
        break;
    case 3:
        aux = 3000 + opcion2;
        temp = buscarint(lista, aux);
        break;
    case 4:
        aux = 4000 + opcion2;
        temp = buscarint(lista, aux);
        break;
    case 5:
        aux = 5000 + opcion2;
        temp = buscarint(lista, aux);
        break;
    case 6:
        aux = 6000 + opcion2;
        temp = buscarint(lista, aux);
        break;
    }

    if (buscarint(lista, aux))
    {
        buscador = buscarint(clientes->carrito, temp->dato.codigo);

        system("cls");

        cout << "\n\tPRODUCTO SELECCIONADO\n";
        cout << "\nnombre: " << temp->dato.nombre;
        cout << "\nmodelo: " << temp->dato.modelo;
        cout << "\nprecio: $" << temp->dato.precio;
        cout << "\nEn stock: " << temp->dato.cantidad;

        cout << "\n\ncuantos desea agregar al carrito: ";
        cin >> cant;

        if ((cant > temp->dato.cantidad) || (cant < 0))
        {
            system("cls");
            cout << "\n\tNo se puede realizar la operacion\n\n";
            system("pause");
        }
        else
        {

            if (buscador == nullptr)
            {
                aux1 = temp->dato;
                aux1.cantidad = 0;
                aux1.cantidad = cant;
                agglista(&clientes->carrito, aux1);
                system("cls");
                cout << "\n\tSe agrego el producto a tu carrito\n\n";
                system("pause");
            }
            else
            {
                if ((buscador->dato.cantidad + cant) > temp->dato.cantidad)
                {
                    system("cls");
                    cout << "\n\tNo se puede realizar la operacion\n\n";
                    system("pause");
                }
                else
                {
                    buscador->dato.cantidad += cant;
                    system("cls");
                    cout << "\n\tSe agrego el producto a tu carrito\n\n";
                    system("pause");
                }
            }
        }
    }
    else
    {
        cout << "\nel producto no existe en el inventario\n";
        system("pause");
    }
}

void eliminarItems(factura *clientes)
{
    int codigo, cant;
    unsigned short opcion;

    system("cls");
    cout << "\n\testa es tu lista de productos: \n";
    mostrarLista(clientes->carrito);
    cout << "Introduzca el codigo de el producto: ";
    cin >> codigo;

    system("cls");

    if (buscarint(clientes->carrito, codigo))
    {

        nodo<producto> *productocarrito = buscarint(clientes->carrito, codigo);

        cout << "\n\tproducto seleccionado\n";
        productocarrito->dato.mostrar();
        cout << "\n\n";
        cout << "desea eliminar una cantidad especifica o todo el producto?";
        cout << "\n1.cantidad especifica\t2.todo el producto\nopcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "cuantos desea eliminar?";
            cin >> cant;
            if (cant == productocarrito->dato.cantidad)
            {
                eliminarNodo(&clientes->carrito, codigo);
                system("cls");
                cout << "\nse elimino correctamente\n\n";
            }
            else if (cant < productocarrito->dato.cantidad)
            {
                productocarrito->dato.cantidad -= cant;
                system("cls");
                cout << "\nse elimino correctamente\n";
            }
            else
            {
                system("cls");
                cout << "\n\tno tiene esa cantidad de elementos en su carrito\n\n";
            }
            break;
        case 2:
            eliminarNodo(&clientes->carrito, codigo);
            system("cls");
            cout << "\nse elimino correctamente\n\n";
            break;
        }
    }
    else
    {
        cout << "\n\tese producto no existe o no estaen su carrito de compras\n\n";
    }
    system("pause");
}

int obtenerUltimoCodigo(nodo<factura> *lista)
{
    if (!lista)
    {
        return 0;
    }
    else
    {
        while (lista->sig)
        {
            lista = lista->sig;
        }
        return (lista->dato.codigo);
    }
}

void restarExistencias(int codigoProducto, int cantidadProductos, nodo<producto> **listaProducto)
{
    nodo<producto> *iterador = *listaProducto;
    while (iterador)
    {
        if (iterador->dato.codigo == codigoProducto)
        {
            iterador->dato.cantidad -= cantidadProductos;
            return;
        }
        iterador = iterador->sig;
    }
}

float obtenerTotal(nodo<producto> *carrito)
{
    float total = 0;
    while (carrito)
    {
        total += carrito->dato.precio * carrito->dato.cantidad;
        carrito = carrito->sig;
    }
    return total;
}

void pagarFactura(factura *clienteActual, nodo<producto> **listaProductos, nodo<factura> **listaFacturas)
{
    float pago;
    bool pagar = true;
    clienteActual->total = obtenerTotal(clienteActual->carrito);

    int codigo = obtenerUltimoCodigo(*listaFacturas);
    clienteActual->codigo = ++codigo;
    //resta existencias del stock
    nodo<producto> *carrito = clienteActual->carrito;
    while (carrito)
    {
        restarExistencias(carrito->dato.codigo, carrito->dato.cantidad, listaProductos);
        carrito = carrito->sig;
    }

    do
    {
        system("cls");
        cout << "\n\tsu total a pagar es de: $" << clienteActual->total;
        cout << "\n\ty su codigo de factura es: " << clienteActual->codigo;
        cout << "\n\n";
        cout << "con cuanto desea pagar: ";
        cin >> pago;
        if (pago < clienteActual->total)
        {
            cout << "el dinero es insuficiente para realizar la transaccion\n";
        }
        else
        {
            pago -= clienteActual->total;
            cout << "transaccion completada\n";
            cout << "su cambio es de: $" << pago;
            cout << "\n";
            pagar = false;
        }
        system("pause");
    } while (pagar);
}