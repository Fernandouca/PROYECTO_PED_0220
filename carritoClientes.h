#pragma once

#pragma region includes

#include <iostream>
#include <cstdlib>

using namespace std;

#include "list.h"

#pragma endregion

void agregarcarrito(cliente<producto> &clientes,nodo<producto> *&lista,int opcion){
       int cant, opcion2, aux;
    producto aux1;
    nodo<producto> *temp = new nodo<producto>();
    nodo<producto> *buscador = new nodo<producto>();

    cout<<"\n\tOpcion: ";
    cin>>opcion2;

    switch(opcion){
        case 1:
            aux = 1000 + opcion2;
            temp = buscarint(lista,aux);
            break;
        case 2:
            aux = 2000 + opcion2;
            temp = buscarint(lista,aux);
            break;
        case 3:
            aux = 3000 + opcion2;
            temp = buscarint(lista,aux);
            break;
        case 4:
            aux = 4000 + opcion2;
            temp = buscarint(lista,aux);
            break;
        case 5:
            aux = 5000 + opcion2;
            temp = buscarint(lista,aux);
            break;
        case 6:
            aux = 6000 + opcion2;
            temp = buscarint(lista,aux);
            break;
    }

    buscador = buscarint(clientes.carrito,temp->dato.codigo);

    system("cls");

    cout<<"\n\tPRODUCTO SELECCIONADO\n";
    cout<<"\nnombre: "<<temp->dato.nombre;
    cout<<"\nmodelo: "<<temp->dato.modelo;
    cout<<"\nprecio: $"<<temp->dato.precio;
    cout<<"\nEn stock: "<<temp->dato.cantidad;

    cout<<"\n\ncuantos desea agregar al carrito: ";
    cin>>cant;

    if((cant > temp->dato.cantidad) || (cant < 0)){
        system("cls");
        cout<<"\n\tNo se puede realizar la operacion\n\n";
        system("pause");
    }else{

        if(buscador == nullptr){
            aux1 = temp->dato;
            aux1.cantidad = 0;
            aux1.cantidad = cant;
            agglista(clientes.carrito,aux1);

        }else{
            if((buscador->dato.cantidad+cant)>temp->dato.cantidad){
                    system("cls");
                    cout<<"\n\tNo se puede realizar la operacion\n\n";
                    system("pause");
            }else{
                buscador->dato.cantidad += cant;
            }
        }


        system("cls");
        cout<<"\n\tSe agrego el producto a tu carrito\n\n";
        system("pause");
    }


}

void eliminarItem(cliente<producto> &clientes){
    int codigo;

    system("cls");
    cout<<"\n\testa es tu lista de productos: \n";
    mostrarLista(clientes.carrito);
    cout<<"Introduzca el codigo de el producto: ";
    cin>>codigo;
}