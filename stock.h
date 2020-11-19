#pragma once

#pragma region includes
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "list.h"

#pragma endregion

nodo<producto> *leerStock()
{
    //Declarando variables
    producto actual;
    ifstream input("stock.csv");
    string resultado, lineaActual;
    vector<string> registro;
    nodo<producto> *lista = nullptr;
    //Por cada registro/fila del archivo
    while (getline(input, lineaActual))
    {
        stringstream sCadena(lineaActual);
        //Por cada conjunto de caracteres separados por ,
        while (getline(sCadena, resultado, ','))
        {
            registro.push_back(resultado);
        }
        //Asignación y conversión de datos
        actual.codigo = stoi(registro[0]);
        actual.nombre = registro[1];
        actual.modelo = registro[2];
        actual.precio = stof(registro[3]);
        actual.cantidad = stoi(registro[4]);
        //Se agrega el producto a la lista;
        agglista<producto>(&lista, actual);
        //Se limpia el vector para incluir un nuevo registro
        registro.clear();
    }
    //Se cierra el archivo
    input.close();
    return lista;
}

void guardarStock(nodo<producto> *lista)
{
    //Declaración de variables
    producto actual;
    string registro;
    ofstream output("stock.csv");
    //Por cada nodo de la lista
    while (lista)
    {
        actual = lista->dato;
        //Se convierte el contenido del nodo a string
        registro = to_string(actual.codigo) + "," + actual.nombre + "," + actual.modelo +
                   "," + to_string(actual.precio) + "," + to_string(actual.cantidad);

        //Se guarda en el archivo
        output << registro << "\n";
        //Itera al siguiente nodo
        lista = lista->sig;
    }
}
