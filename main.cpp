#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "Pregunta.h"
#include "Prueba.h"

using namespace std;


int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int x;
    cout<<"¿Cuántas preguntas tendrá la prueba? \n";
    cin>> x;
    Prueba *p1 = new Prueba(x);
    Menu* menu = new Menu(p1);
    menu->agregarPregunta();
    menu->mostrarMenu();

    return 0;
}
