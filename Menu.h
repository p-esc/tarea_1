//
// Created by polae on 4/1/2025.
//

#ifndef MENU_H
#define MENU_H
#include "Prueba.h"

class Menu {
private:
    Prueba* miPrueba;

public:
    Menu(Prueba* miPrueba);
    void mostrarMenu();
    void agregarPregunta();
    void actualizarPregunta();
    void eliminarPregunta();
    void buscarPregunta();
};


#endif //MENU_H
