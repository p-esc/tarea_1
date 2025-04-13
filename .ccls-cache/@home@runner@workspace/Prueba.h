//
// Created by polae on 4/1/2025.
//

#ifndef PRUEBA_H
#define PRUEBA_H
#include <vector>

#include "Pregunta.h"
using namespace std;


class Prueba {
private:
    int cantPreguntas;
    vector<Pregunta*> preguntas;
public:
    Prueba(int cantPreguntas);
    ~Prueba();
    // Create
    void agregarPregunta(Pregunta* pregunta);
    // Update
    void actualizarEnunciado(int num);
    void actualizarNivel(int num);
    void actualizarTiempo(int num);
    // Delete
    void borrarPregunta(int numPregunta);
    void recalcularId();
    // Retreive
    void buscarItem(int numPregunta);
    void buscarNivel(int nivel);
    float calcularTiempoTotal();
    void mostrarPrueba();
    int getCantPreg();
    int getLargoVector();
};


#endif //PRUEBA_H
