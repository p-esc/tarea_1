#ifndef MENU_H
#define MENU_H
#include "Prueba.h"

class Menu {
private:
    Prueba* miPrueba;
public:
    Menu(Prueba* miPrueba);
    ~Menu();
    void agregarPregunta();
    void buscarPregunta();
    void actualizarPregunta();
    void eliminarPregunta();
    void mostrarMenu();
};

#endif //MENU_H
