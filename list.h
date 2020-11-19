#pragma once //este es para que las cabeceras no creen archivos .exe

#pragma region inlcudes

#include <iostream>
#include <cstdlib>

#pragma endregion

#pragma region estructuras

template <typename T> //esto es una template sirve para generalizar una estructura, funcion o clases
struct nodo
{
    T dato;
    nodo<T> *sig;
    nodo() : sig(nullptr) {}
    nodo(T Datoagregado) : dato(Datoagregado) {} //este es un constructor, de esta forma es mas facil meter los datos a la estructura
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
    nodo<T> *Datoagregado = new nodo<T>(aggdato); //gracias al constructor se mete el tipo de dato en el parentesis del nuevo nodo

    nodo<T> *aux1 = *lista; //el auxiliar 1 apunta donde apunta la lista(si esta vacia es hacia null)
    nodo<T> *aux2;          //este ayuda a ordenar mas tarde

    while ((aux1 != nullptr) && (aux1->dato.codigo < aggdato.codigo))
    { //comprueba que A).la lista no este vacia y B). que en la lista de codigos no podas meter un producto en la categoria que no es
        //entonces como la lista no esta vacia ni el codigo del producto que quiero agregar es mayor al que esta atras
        aux2 = aux1;      //el auxiliar 2 apunta a donde apunta el auxiliar 1
        aux1 = aux1->sig; //y el auxiliar 1 avanza una posicion
    }
    //si tengo una lista vacia y quiero meter 1 va al if
    //si tengo una lista de {1,2,5,9} y quiero meter 7 pasa por 1 ,2, 5 y cuando ve que 9 es mayor se detiene entonces pasa al else
    if (*lista == aux1)
    {
        *lista = Datoagregado; //aqui lista que apuntaba a null ahora apunta a el nuevo nodo
    }
    else
    {
        aux2->sig = Datoagregado; //como auxiliar 2 es una posicion atras de auxiliar 1 introduce el nodo atras del auxiliar 1
    }
    Datoagregado->sig = aux1; //para ambos casos de hace que el nodo agregado apunte hacia el que tiene en frente
}

template <typename T>
void mostrarLista(nodo<T> *lista)
{
    nodo<T> *actual = new nodo<T>(); //crea un nuevo nodo
    actual = lista;                  //apunta donde apunta el inicio de la lista

    while (actual != nullptr)
    {
        actual->dato.mostrar();
        cout << "\n\n";
        actual = actual->sig; //avanza una posicion
    }
}

template <typename T>
nodo<T> *buscarint(nodo<T> *lista, int buscador)
{
    bool cont = false;             //la bandera para verificar
    nodo<T> *actual = lista;       //el nodo para buscar
    nodo<T> *aux1 = new nodo<T>(); //el nodo que me ayuda despues

    while ((actual != nullptr) && (actual->dato.codigo <= buscador))
    { //comprueba que no este en el final de la lista y que el paramentro de busqueda no se vaya adelante de un valor mayor al qu busco
        if (actual->dato.codigo == buscador)
        {                //compara si los datos coinciden
            cont = true; //si lo hacen mi bandera cambia
        }
        aux1 = actual;        //aqui hago qe mi auxiliar mantenga el dato que se comparo
        actual = actual->sig; //y aqui hago que el nodo de busqueda avance una posicion
    }
    if (cont) //si la bandera cambio
    {
        return aux1; //devuelve el nodo que si coincide
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
bool eliminarNodo(nodo<T> **lista, int buscador)
{
    if (*lista)
    {
        nodo<T> *iterador = *lista;

        if (iterador->dato.codigo == buscador)
        {
            *lista = iterador->sig;
            delete iterador;
            return true;
        }
        while (iterador->sig)
        {
            if (iterador->sig->dato.codigo == buscador)
            {
                nodo<T> *nodoABorrar = iterador->sig;
                iterador->sig = iterador->sig->sig;
                delete nodoABorrar;
                return true;
            }
        }
        if (iterador->dato.codigo == buscador)
        {
            nodo<T> *nodoABorrar = iterador;
            iterador = nullptr;
            delete nodoABorrar;
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
    while (lista)
    {
        nodo<T> *aux = *lista;
        *lista = aux->sig;
        delete aux;
    }
    if (!lista)
    {
        return true;
    }
};
