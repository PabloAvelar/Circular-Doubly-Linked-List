#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#define TIPO_DATO int
#include <iostream>

using namespace std;

class Nodo{
    public:
    TIPO_DATO dato;
    Nodo *siguiente;
    Nodo *anterior;
};

class Lista{
    public:
    Nodo *ancla;
    Nodo *ultimo;
    int contador;

    
    void inicializa();
    bool vacia();
    void insertar(TIPO_DATO dato, int pos);
    void eliminar(int pos);
    void imprimir();
    void anular();

    void buscar(TIPO_DATO dato);

    // Getters
    int get_contador();
    TIPO_DATO get_dato(int pos);
};

int Lista::get_contador(){
    return contador;
}

TIPO_DATO Lista::get_dato(int pos){
    //Búsqueda lineal
    Nodo *aux = ancla;

    for(int i=0; i<pos; i++)
        aux = aux->siguiente;
    
    return aux->dato;
}

void Lista::buscar(TIPO_DATO dato){
    //Búsqueda lineal
    Nodo *aux = ancla;
    int cont = 0;
    while(aux->dato != dato && cont<=contador){
        aux = aux->siguiente;
        cont++;
    }

    printf("%-10s | %-20s | %-10s |\n\n",
                "Anterior", "DATO ENCONTRADO", "Siguiente");
    printf("%-10i | %-20i | %-10i |\n\n",
                aux->anterior->dato, aux->dato, aux->siguiente->dato);

    printf("[%-10i] [%-20i] [%-10i]\n\n",
                cont-1, cont, cont+1);

    system("pause");
}

void Lista::inicializa(){
    ancla = nullptr;
    ultimo = nullptr;
    contador = 0;
}

bool Lista::vacia(){
    return ancla==nullptr;
}

void Lista::insertar(TIPO_DATO dato, int pos){
    //Inicializando un nuevo nodo
    Nodo *aux = new Nodo();
    aux->siguiente = aux;
    aux->anterior = aux;
    aux->dato = dato;

    if(pos > contador){ //Esto para que se agregue al final si se pasa
        pos = contador;
    }

    if(vacia()){ //Inserción en lista vacía
        ancla = aux;
        ultimo = aux;
    }else if(pos == 0 && !vacia()){ //Inserción al principio
        aux->siguiente = ancla;
        aux->anterior = ultimo;
        ancla = aux;
        aux->siguiente->anterior = aux;
        cout<<"PRIMERO"<<endl;
    }else{ //Inserción en otro lugar
        Nodo *ant = ancla;
        for(int i=0; i<pos-1; i++)
            ant = ant->siguiente;

        aux->siguiente = ant->siguiente;
        ant->siguiente->anterior = aux;
        ant->siguiente = aux;
        aux->anterior = ant;

    }

    //Para actualizar el campo "ultimo"
    if(ultimo->siguiente != ancla)
        ultimo = ancla->anterior;

    contador++;
}

void Lista::eliminar(int pos){
    if(!vacia()){
        Nodo *aux = ancla;
        
        if(pos > contador){     //Esto para que se elimine al final si se pasa
            pos = contador-1;
        }

        if(contador == 1){      //Eliminando cuando sólo hay un único nodo en la lista
            delete[] ancla;
            ancla = nullptr;
            ultimo = nullptr;
        }else if(pos == 0){
           ancla = aux->siguiente;
           aux->siguiente->anterior = ultimo; 
        }else{                  //Eliminar en cualquier posicion
            for(int i=0; i<pos; i++){
                if(aux->siguiente != nullptr){
                    aux = aux->siguiente;
                }
            }

            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;

            delete[] aux;

            //Para actualizar el campo "ultimo"
            if(ultimo->siguiente != ancla)
                ultimo = ancla->anterior;
        }

        contador--;
    }
}

void Lista::imprimir(){
    Nodo *aux = ancla;
    if(!vacia()){
        if(contador == 1){
            cout<<"[Dato: "<<aux->dato<<"] -> ";
        }else{
            for(int i=0; i<contador;i++){
                cout<<"[Dato: "<<aux->dato<<"] -> ";
                aux = aux->siguiente;
            }
        }
    }else{
        cout<<"ESTA VACIA"<<endl;
    }
}

void Lista::anular(){
    if(!vacia()){
        while(!vacia()){
            eliminar(contador-1);
        }
    }else{
        cout<<"ESTA VACIA"<<endl;
    }
}

#endif LISTA_H