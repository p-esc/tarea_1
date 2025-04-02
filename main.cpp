#include <iostream>
#include <windows.h>

#include "Menu.h"
#include "Pregunta.h"
#include "Prueba.h"

using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int x;
    cout<<"¿Cuántas preguntas tendrá la prueba? \n";
    cin>> x;
    Prueba *p1 = new Prueba(x);
    Menu* menu = new Menu(p1);
    menu->mostrarMenu();




    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.