#pragma once

#pragma region includes

#include <iostream>
#include <cstdlib>

using namespace std;

#include "list.h"
#include "stock.h"
#include "datos.h"
#include "carritoClientes.h"
#include "funcionesadmin.h"
#pragma endregion

//+++SUB MENUS DE ADMIN+++//
void menuFacturas(nodo<producto> **listaProductos, nodo<factura> **listaFacturas)
{
    bool continuar = true;
    unsigned short opcion;
    do
    {
        system("cls");
        cout << "\n\tQUE OPERACION DESEA REALIZAR\n";
        cout << "\n1.Mostrar la lista de facturas";
        cout << "\n2.Hacer un reembolso";
        cout << "\n3.regresar";
        cout << "\nopcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            mostrarLista(*listaFacturas);
            system("pause");
            break;
        case 2:
            reembolso(listaProductos, listaFacturas);
            break;
        case 3:
            continuar = false;
            break;
        default:
            cout << "Opcion invalida! \nIngrese otra opcion.\n\n";
            system("pause");
            break;
        }
    } while (continuar);
}

void menuProductos(nodo<producto> **listaProductos)
{
    bool continuar = true;
    unsigned short opcion;
    producto agregar;

    do
    {
        system("cls");
        cout << "\n\tQUE OPERACION DESEA REALIZAR\n";
        cout << "\n1.Agregar un producto al stock";
        cout << "\n2.Eliminar un producto al stock";
        cout << "\n3.Regresar";
        cout << "\nopcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarAlStock(listaProductos);
            break;
        case 2:
            eliminarDelStock(listaProductos);
            break;
        case 3:
            continuar = false;
            break;
        default:
            cout << "Opcion invalida! \nIngrese otra opcion.";
            system("pause");
            break;
        }
    } while (continuar);
}

//+++SUB MENUS DE CLIENTE+++//
void agregarAlCarrito(nodo<producto> **listaProductos, factura *clienteActual)
{
    bool continuar = true;
    unsigned short opcion = 0;
    do
    {
        system("cls");
        cout << "\n\tEN QUE PRODUCTOS ESTA INTERESADO\n";
        cout << "\n1.Monitores\t2.Tarjetas Graficas\t3.Procesadores";
        cout << "\n4.Cases\t\t5.Placas Base \t\t6.Fuentes de poder";
        cout << "\n7.Regresar";
        cout << "\n\n\tOpcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            mostrarProducto(*listaProductos, opcion); //muestra los productos en la lista{viene de datos.h}
            agregarProducto(clienteActual, *listaProductos, opcion);
            break;
        case 7:
            continuar = false;
            break;
        default:
            system("cls");
            cout << "\n\tOpcion no valida\n\n";
            system("pause");
            break;
        }
    } while (continuar);
}

void modificarCarrito(factura *clienteActual)
{
    unsigned short opcion = 0;
    bool continuar = true;

    do
    {
        system("cls");
        cout << "\n\tQue operacion desea realizar?\n";
        cout << "\n1.Eliminar un item del carrito";
        cout << "\n2.Vaciar el carrito";
        cout << "\n3.Regresar";
        cout << "\n\tOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            eliminarItems(clienteActual);
            break;
        case 2:
            if (eliminarLista(&clienteActual->carrito))
            {
                system("cls");
                cout << "\n\tel carrito de compras esta vacio\n\n";
                system("pause");
            }
            break;
        case 3:
            continuar = false;
            break;
        default:
            cout << "Opcion invalida! \nIngrese otra opcion.\n";
            system("pause");
            break;
        }
    } while (continuar);
}

//+++SUB MENUS DEL PRINCIPAL+++//
void menuClientes(nodo<producto> **listaProductos, nodo<factura> **listaFacturas)
{
    bool continuar = true;
    unsigned short opcion = 0;
    factura clienteActual;
    datosClientes(clienteActual);
    do
    {
        system("cls");
        cout << "\n\tQUE OPERACION DESEA REALIZAR\n";
        cout << "\n1.Agregar al carrito";
        cout << "\n2.Modificar carrito";
        cout << "\n3.Finalizar";
        cout << "\n\tOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarAlCarrito(listaProductos, &clienteActual);
            break;
        case 2:
            if (clienteActual.carrito)
            {
                modificarCarrito(&clienteActual);
            }
            else
            {
                cout << "\nSu carrito esta vacio\n";
                system("pause");
            }
            break;
        case 3:
            if (clienteActual.carrito)
            {
                pagarFactura(&clienteActual, listaProductos, listaFacturas);
                agglista(listaFacturas, clienteActual);
            }
            else
            {
                cout << "Gracias por visitarnos." << endl;
                system("pause");
                continuar = false;
                break;
            }
        default:
            cout << "Opcion invalida! \nIngrese otra opcion.\n";
            system("pause");
            break;
        }
    } while (continuar);
}

void menuAdmin(nodo<producto> **listaProductos, nodo<factura> **listaFacturas)
{
    int opcion = 0;
    bool continuar = true;
    do
    {
        system("cls");

       cout << "\n\tQUE OPERACION DESEA REALIZAR\n";
        cout << "\n1.Reembolsar compras de clientes";
        cout << "\n2.Modificar lista de productos";
        cout << "\n3.Ver ganancias totales";
        cout << "\n4.Regresar";
        cout << "\n\tOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (listaFacturas == nullptr)
            {
                menuFacturas(listaProductos, listaFacturas);
            }
            else
            {
                cout << "No hay compras que reembolsar." << endl;
                system("pause");
                break;
            }

        case 2:
            menuProductos(listaProductos);
            break;
        case 3:
            system("cls");
            cout << "las ganancias de las ventas son: $" << mostrarGanancias(*listaFacturas) << endl;
            system("pause");
            break;
        case 4:
            continuar = false;
            break;
        }
    } while (continuar);
}

//+++MENU PRINCIPAL+++//
void menuPrincipal()
{
    bool continuar = true;
    unsigned short opcion = 0;
    nodo<producto> *listaProductos = leerStock();
    nodo<factura> *listaFacturas = nullptr;

    do
    {
        system("cls");
        cout << "\n\tBIENVENIDO A DIGITAL ZONE\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "\n1.Cliente\t\t2.Administrador\t\t3.Salir";
        cout << "\n\nopcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            menuClientes(&listaProductos, &listaFacturas);
            break;
        case 2:
            if (datosAdmin())
            {
                menuAdmin(&listaProductos, &listaFacturas);
            }
            else
            {
                cout << "las credenciales son incorrectas." << endl;
                system("pause");
            }
            break;
        case 3:
            continuar = false;
            cout << endl
                 << "Gracias por preferirnos!" << endl;
            break;
        default:
            break;
        }
    } while (continuar);

    guardarStock(listaProductos);
}
