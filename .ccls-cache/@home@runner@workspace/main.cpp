// Pola Escobar
// Sofía Sepúlveda
// 1/4/2025

#include <iostream>
#include "Menu.h"
#include "Pregunta.h"
#include "Prueba.h"

using namespace std;

int main() {
    // se crea una nueva prueba con x preguntas y un menú con la prueba
    int x;
    cout<<"¿Cuántas preguntas tendrá la prueba? ";
    cin>> x;
    Prueba *p1 = new Prueba(x);
    Menu* menu = new Menu(p1);
    // se agregan las x preguntas a la prueba
    menu->agregarPregunta();
    // se muestra el menú
    menu->mostrarMenu();    
    return 0;
}
