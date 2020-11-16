#pragma region includes

#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;

#include "list.h"
#include "menus.h"
#include "datos.h"
#include "stock.h"
#include "carritoClientes.h"

#pragma endregion

int main()
{
    setlocale(LC_CTYPE, "Spanish");
    int opcion;            //para las opciones en general
    bool continuar = true; //bandera para los cambios entre bucles

    nodo<producto> *listaproductos = leerStock();     //la lista de productos
    nodo<cliente<producto>> *listaclientes = nullptr; //la lista de los clientes

    cliente<producto> cliente1; //donde guardar la info de los clientes
    producto aggproducto;       //donde guardar la info de un produto

    guardarStock(listaproductos);

    do
    {                          //repetir principal
        menuPrincipal(opcion); //llama a menu principal{viene de menus.h}

        switch (opcion)
        {
        case 1:                      //clientes
            datosClientes(cliente1); //guarda los datos iniciales del cliente{viene de datos.h}
            do
            { //repetir clientes
                menuClientes(opcion);
                switch (opcion)
                {
                case 1:
                    do
                    {
                        submenuCompras(opcion); //este te pregunta en que categoria quiere buscar {viene de menus.h}
                        switch (opcion)
                        {
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                            mostrarProducto(listaproductos, opcion); //muestra los productos en la lista{viene de datos.h}
                            agregarcarrito(cliente1, listaproductos, opcion);
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
                    continuar = true;
                    break;
                case 2:
                    do
                    {
                        modificarCarrito(opcion);
                        switch (opcion)
                        {
                        case 1:
                            eliminarItem(cliente1);
                            break;
                        }
                    } while (continuar);
                    continuar = true;
                    break;
                case 3:

                    continuar = false;
                    break;
                default:
                    system("cls");
                    cout << "\n\tOpcion no valida\n\n";
                    system("pause");
                    break;
                }
            } while (continuar);
            continuar = true;
            break;
        case 2: //admin
            if (datosAdmin() /*esta funcion verifica que se metan las credanciales correctas{viene de datos.h}*/)
            {
                do
                {                      //repetir admin
                    menuAdmin(opcion); //abre el menu del admin{viene de menus.h}
                    switch (opcion)
                    {
                    case 1:
                        //modificarClientes();
                        break;
                    case 2:
                        //modificarProductos();
                        break;
                    case 3:
                        system("cls");
                        cout << "\n\tUN GUSTO AYUDARTE\n\n";
                        system("pause");
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
            else
            {
                system("cls");
                cout << "\n\tLas credenciales no coinciden...\n\n";
                system("pause");
            }
            break;
        case 3: //salir
            system("cls");
            cout << "\n\tFUE UN GUSTO SERVIRTE\n\n";
            system("pause");
            continuar = false;
            break;
        default: //datos no validos
            system("cls");
            cout << "\n\tOpcion no valida\n\n";
            system("pause");
            break;
        }
    } while (continuar);

    return 0;
}