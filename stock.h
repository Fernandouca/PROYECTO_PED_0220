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
    
    producto actual;
    ifstream input("stock.csv");
    string resultado, lineaActual;
    vector<string> registro;
    nodo<producto> *lista = nullptr;
    
    while (getline(input, lineaActual))
    {
        stringstream sCadena(lineaActual);
       
        while (getline(sCadena, resultado, ','))
        {
            registro.push_back(resultado);
        }
        
        actual.codigo = stoi(registro[0]);
        actual.nombre = registro[1];
        actual.modelo = registro[2];
        actual.precio = stof(registro[3]);
        actual.cantidad = stoi(registro[4]);
        
        agglista<producto>(&lista, actual);
        
        registro.clear();
    }
    
    input.close();
    return lista;
}

void guardarStock(nodo<producto> *lista)
{
    
    producto actual;
    string registro;
    ofstream output("stock.csv");
    
    while (lista)
    {
        actual = lista->dato;
        
        registro = to_string(actual.codigo) + "," + actual.nombre + "," + actual.modelo +
                   "," + to_string(actual.precio) + "," + to_string(actual.cantidad);

       
        output << registro << "\n";
        
        lista = lista->sig;
    }
}


