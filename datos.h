#pragma once

#pragma region includes

#include <iostream>
#include <cstdlib>

using namespace std;

#include "list.h"

#pragma endregion

void datosClientes(factura &cliente1)
{ //solorecolecta los datos de los clientes
    system("cls");
    fflush(stdin);

    cout << "\n\tHOLA, POR FAVOR COLOCA TUS DATOS\n";
    cout << "\nnombre de usuario: ";
    getline(cin, cliente1.nombre);
    cout << "\ndireccion: ";
    getline(cin, cliente1.direccion);
}

bool datosAdmin()
{ //agarra los datos que se ingresen y los compara
    string user1 = "admin", user2;
    string pass1 = "admin", pass2;

    system("cls");
    fflush(stdin);
    cout << "\n\tPOR FAVOR INGRESE SUS CREDENCIALES DE ADMINISTRADOR\n";
    cout << "\nUSER: ";
    getline(cin, user2);
    cout << "\nPASSWORD: ";
    getline(cin, pass2);
    //como es una funcion bool retorna un valor booleano {true or false}
    return ((user1 == user2) && (pass1 == pass2)) ? true : false; //esto simplifica una condicional para retornar un valor bool
}

void mostrarProducto(nodo<producto> *lista, int opcion)
{
    int cont = 1;
    nodo<producto> *actual = new nodo<producto>(); //un nuevo nodo donde especifico que la template T es un producto
    actual = lista;                                //pongo el nodo al principio de la lista

    system("cls");

    switch (opcion)
    {
    case 1:
        while ((actual != NULL) && (actual->dato.codigo >= 1001) && (actual->dato.codigo <= 1999))
        {                                  //verifica que no este fuera de la categoria ni al final de lista
            cout << "\n\tOpcion " << cont; //es solo para saber que producto es sin mostrar el codigo de producto
            cout << "\n\tNombre: " << actual->dato.nombre;
            cout << "\n\tModelo: " << actual->dato.modelo;
            cout << "\n\tPrecio: $" << actual->dato.precio;
            if (actual->dato.cantidad == 0)
            {
                cout << "\n\tEn stock: AGOTADO";
            }
            else
            {
                cout << "\n\tEn stock: " << actual->dato.cantidad;
            }
            cout << "\n\n";
            cont++;               //el seleccionador por asi decirlo avanza
            actual = actual->sig; //me muevo al siguiente nodo{osea producto}
        }
        break;
    case 2:
        actual = buscarint(lista, 2001); //aqui uso la funcion buscar que me retorna un nodo especifico de la lista para que actual este en ese nodo
        while ((actual != NULL) && (actual->dato.codigo >= 2001) && (actual->dato.codigo <= 2999))
        {
            cout << "\n\tOpcion " << cont;
            cout << "\n\tnombre: " << actual->dato.nombre;
            cout << "\n\tmodelo: " << actual->dato.modelo;
            cout << "\n\tprecio: $" << actual->dato.precio;
            if (actual->dato.cantidad == 0)
            {
                cout << "\n\tEn stock: AGOTADO";
            }
            else
            {
                cout << "\n\tEn stock: " << actual->dato.cantidad;
            }
            cout << "\n\n";
            cont++;
            actual = actual->sig;
        }
        break;
    case 3:
        actual = buscarint(lista, 3001);
        while ((actual != NULL) && (actual->dato.codigo >= 3001) && (actual->dato.codigo <= 3999))
        {
            cout << "\n\tOpcion " << cont;
            cout << "\n\tnombre: " << actual->dato.nombre;
            cout << "\n\tmodelo: " << actual->dato.modelo;
            cout << "\n\tprecio: $" << actual->dato.precio;
            if (actual->dato.cantidad == 0)
            {
                cout << "\n\tEn stock: AGOTADO";
            }
            else
            {
                cout << "\n\tEn stock: " << actual->dato.cantidad;
            }
            cout << "\n\n";
            cont++;
            actual = actual->sig;
        }
        break;
    case 4:
        actual = buscarint(lista, 4001);
        while ((actual != NULL) && (actual->dato.codigo >= 4001) && (actual->dato.codigo <= 4999))
        {
            cout << "\n\tOpcion " << cont;
            cout << "\n\tnombre: " << actual->dato.nombre;
            cout << "\n\tmodelo: " << actual->dato.modelo;
            cout << "\n\tprecio: $" << actual->dato.precio;
            if (actual->dato.cantidad == 0)
            {
                cout << "\n\tEn stock: AGOTADO";
            }
            else
            {
                cout << "\n\tEn stock: " << actual->dato.cantidad;
            }
            cout << "\n\n";
            cont++;
            actual = actual->sig;
        }
        break;
    case 5:
        actual = buscarint(lista, 5001);
        while ((actual != NULL) && (actual->dato.codigo >= 5001) && (actual->dato.codigo <= 5999))
        {
            cout << "\n\tOpcion " << cont;
            cout << "\n\tnombre: " << actual->dato.nombre;
            cout << "\n\tmodelo: " << actual->dato.modelo;
            cout << "\n\tprecio: $" << actual->dato.precio;
            if (actual->dato.cantidad == 0)
            {
                cout << "\n\tEn stock: AGOTADO";
            }
            else
            {
                cout << "\n\tEn stock: " << actual->dato.cantidad;
            }
            cout << "\n\n";
            cont++;
            actual = actual->sig;
        }
        break;
    case 6:
        actual = buscarint(lista, 6001);
        while ((actual != NULL) && (actual->dato.codigo >= 6001) && (actual->dato.codigo <= 6999))
        {
            cout << "\n\tOpcion " << cont;
            cout << "\n\tnombre: " << actual->dato.nombre;
            cout << "\n\tmodelo: " << actual->dato.modelo;
            cout << "\n\tprecio: $" << actual->dato.precio;
            if (actual->dato.cantidad == 0)
            {
                cout << "\n\tEn stock: AGOTADO";
            }
            else
            {
                cout << "\n\tEn stock: " << actual->dato.cantidad;
            }
            cout << "\n\n";
            cont++;
            actual = actual->sig;
        }
        break;
    }
}
