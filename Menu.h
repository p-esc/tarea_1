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
    // Create
    Menu(Prueba* miPrueba);
    ~Menu();
    void agregarPregunta();
    // Retrieve
    void buscarPregunta();
    void mostrarMenu();
    // Update
    void actualizarPregunta();
    // Delete
    void eliminarPregunta();
};

#endif //MENU_H
