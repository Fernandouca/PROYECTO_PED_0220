#pragma once 

#pragma region inlcudes

#include <iostream>
#include <cstdlib>

#pragma endregion

#pragma region estructuras

template <typename T> 
struct nodo
{
    T dato;
    nodo<T> *sig;
    nodo() : sig(nullptr) {}
    nodo(T Datoagregado) : dato(Datoagregado) {} 
};

struct producto
{
    int codigo;
    string nombre;
    string modelo;
    float precio;
    int cantidad;

    void mostrar()
    {
        cout << "\ncodigo: " << this->codigo;
        cout << "\nnombre: " << this->nombre;
        cout << "\nmodelo: " << this->modelo;
        cout << "\nprecio: " << this->precio;
        cout << "\ncantidad: " << this->cantidad;
    }
};
struct factura
{
    int codigo;
    string nombre;
    string direccion;
    float total;
    nodo<producto> *carrito = nullptr;

    void mostrar()
    {
        cout << "\ncodigo: " << this->codigo;
        cout << "\nnombre: " << this->nombre;
        cout << "\ndireccion: " << this->direccion;
        cout << "\ntotal: $" << this->total;
    }
};

#pragma endregion

template <typename T>
void agglista(nodo<T> **lista, T aggdato)
{
    nodo<T> *Datoagregado = new nodo<T>(aggdato); 

    nodo<T> *aux1 = *lista; 
    nodo<T> *aux2;          

    while ((aux1 != nullptr) && (aux1->dato.codigo < aggdato.codigo))
    { 
        
        aux2 = aux1;      
        aux1 = aux1->sig; 
    }
    
    
    if (*lista == aux1)
    {
        *lista = Datoagregado; 
    }
    else
    {
        aux2->sig = Datoagregado; 
    }
    Datoagregado->sig = aux1; 
}

template <typename T>
void mostrarLista(nodo<T> *lista)
{
    nodo<T> *actual = new nodo<T>(); 
    actual = lista;                  

    while (actual != nullptr)
    {
        actual->dato.mostrar();
        cout << "\n\n";
        actual = actual->sig; 
    }
}

template <typename T>
nodo<T> *buscarint(nodo<T> *lista, int buscador)
{
    bool cont = false;             
    nodo<T> *actual = lista;       
    nodo<T> *aux1 = new nodo<T>();

    while ((actual != nullptr) && (actual->dato.codigo <= buscador))
    { 
        if (actual->dato.codigo == buscador)
        {                
            cont = true; 
        }
        aux1 = actual;        
        actual = actual->sig; 
    }
    if (cont) 
    {
        return aux1;
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
bool eliminarNodo(nodo<T> **lista, int buscador)
{
    if (lista)
    {
        nodo<T> *aux1 = *lista;
        nodo<T> *aux2 = nullptr;

        while ((aux1) && (aux1->dato.codigo != buscador))
        {
            aux2 = aux1;
            aux1 = aux1->sig;
        }
        if (!aux1)
        {
            return false;
        }
        else if (!aux2)
        {
            *lista = aux1->sig;
            delete aux1;
            return true;
        }
        else
        {
            aux2->sig = aux1->sig;
            delete aux1;
            return true;
        }
    }
    else
    {
        return false;
    }
}

template <typename T>
bool eliminarLista(nodo<T> **lista)
{
    while (*lista)
    {
        nodo<T> *aux = *lista;
        *lista = aux->sig;
        delete aux;
    }
    if (!(*lista))
    {
        return true;
    }
}
