#pragma once

#pragma region includes

#include <iostream>
#include <cstdlib>

using namespace std;

#include "list.h"

#pragma endregion


//+++MENUS PRINCIPALES+++//
void menuPrincipal(int &opcion){
    system("cls");
    cout<<"\n\tBIENVENIDO A NTN DIGITAL\n";
    cout<<"\nSeleccione una opcion:\n";
    cout<<"\n1.Cliente\t\t2.Administrador\t\t3.Salir";
    cout<<"\n\nopcion: ";
    cin>>opcion;
}

void menuClientes(int &opcion){
system("cls");

cout<<"\n\tQUE OPERACION DESEA REALIZAR\n";
cout<<"\n1.Agregar al carrito";
cout<<"\n2.Modificar carrito";
cout<<"\n3.Finalizar";
cout<<"\n\tOpcion: ";
cin>>opcion;
}

void menuAdmin(int &opcion){
    system("cls");

    cout<<"\n\tQUE OPERACION DESEA REALIZAR\n";
    cout<<"\n1.Modificar compras de clientes";
    cout<<"\n2.Modificar lista de productos";
    cout<<"\n3.Regresar";
    cout<<"\n\tOpcion: ";
    cin>>opcion;
}

//+++SUB MENUS+++//
void submenuCompras(int &opcion){
    system("cls");
    
    cout<<"\n\tEN QUE PRODUCTOS ESTA INTERESADO\n";
    cout<<"\n1.Monitores\t2.Tarjetas Graficas\t3.Procesadores";
    cout<<"\n4.Cases\t\t5.Placas Base \t\t6.Fuentes de poder";
    cout<<"\n7.Regresar";
    cout<<"\n\n\tOpcion: ";
    cin>>opcion;

} 

void modificarCarrito(int &opcion){
    system("cls");

    cout<<"\n\tQUE operacion desea Realizar?\n";
    cout<<"\n1.Eliminar un item del carrito";
    cout<<"\n2.Eliminar un producto del carrito";
    cout<<"\n3.Vaciar el carrito";
    cout<<"\n4.Regresar";
    cout<<"\n\tOpcion: ";
    cin>>opcion;
}
