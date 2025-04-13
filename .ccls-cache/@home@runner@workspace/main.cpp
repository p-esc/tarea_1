#include <iostream>
#include "Menu.h"
#include "Pregunta.h"
#include "Prueba.h"

using namespace std;


int main() {
    int x;
    cout<<"¿Cuántas preguntas tendrá la prueba? ";
    cin>> x;
    Prueba *p1 = new Prueba(x);
    Menu* menu = new Menu(p1);
    menu->agregarPregunta();
    menu->mostrarMenu();

    
    return 0;
}
