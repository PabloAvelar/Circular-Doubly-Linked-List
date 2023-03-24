#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "listadoblecircular.h"
#define TIPO_DATO int

void menu(Lista lista){
    int op, pos;
    TIPO_DATO dato;
    typedef enum{
        SALIR,
        INSERTAR_INICIO, INSERTAR_FINAL, INSERTAR,
        ELIMINAR_INICIO, ELIMINAR_ULTIMO, ELIMINAR,
        RECUPERAR, BUSCAR,
        IMPRIMIR,       
        ANULAR
    };

    do{
        system("cls");
        printf("\tLista doblemente ligada circular con encabezado\n\n");
        (lista.ancla) ? cout<<"ancla: "<<lista.ancla->dato<<endl:cout<<"Ancla: null."<<endl;
        (lista.ultimo) ? cout<<"ultimo: "<<lista.ultimo->dato<<endl:cout<<"Ultimo: null."<<endl;

        cout<<"contador: "<<lista.contador<<endl;

        cout<<"1) Insertar al Inicio"<<endl;
        cout<<"2) Insertar al Final"<<endl;
        cout<<"3) Insertar"<<endl;
        cout<<"4) Eliminar Inicio"<<endl;
        cout<<"5) Eliminar Ultimo"<<endl;
        cout<<"6) Eliminar"<<endl;
        cout<<"7) Recuperar"<<endl;
        cout<<"8) Buscar"<<endl;
        cout<<"9) Imprimir"<<endl;
        cout<<"10) Anular"<<endl;
        cout<<"0) Salir"<<endl;
        fflush(stdin);
        cin>>op;

        switch (op){
        case INSERTAR_INICIO:
            cout<<"Dato: ";
            cin>>dato;
            lista.insertar(dato, 0);
            break;
        case INSERTAR_FINAL:
            cout<<"Dato: ";
            cin>>dato;
            lista.insertar(dato, lista.get_contador());
            break;
        case INSERTAR: ;
            cout<<"Dato: ";
            cin>>dato;
            cout<<"Posicion: ";
            cin>>pos;
            lista.insertar(dato, pos);
            break;

        case ELIMINAR_INICIO:
            lista.eliminar(0);
            break;

        case ELIMINAR_ULTIMO:
            lista.eliminar(lista.get_contador()-1);
            break;
        
        case ELIMINAR:
            cout<<"Posicion: ";
            cin>>pos;
            lista.eliminar(pos);
            break;

        case RECUPERAR:
            cout<<"Ingresa el indice del dato del nodo a recuperar: ";
            cin>>pos;
            cout<<"Nodo: ["<<lista.get_dato(pos)<<"]"<<endl;
            system("pause");
            break;

        case BUSCAR:
            cout<<"Ingresa el dato del nodo a buscar: ";
            cin>>dato;
            lista.buscar(dato);
            break;

        case IMPRIMIR:
            cout<<"Nodos: "<<endl;
            lista.imprimir();
            printf("\n");
            system("pause");
            break;

        case ANULAR:
            lista.anular();
            break;
        }
    } while (op!=SALIR);
    
}

#endif