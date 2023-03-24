#include "menu.h"
#include <iostream>
#define TIPO_DATO int

using namespace std;

int main(){
    Lista lista = Lista();
    lista.inicializa();

    menu(lista);

    lista.anular();

    return 0;
}