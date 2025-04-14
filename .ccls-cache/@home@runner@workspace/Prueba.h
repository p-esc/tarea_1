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
    void agregarPregunta(Pregunta* pregunta);
    void actualizarEnunciado(int num);
    void actualizarNivel(int num);
    void actualizarTiempo(int num);
    void borrarPregunta(int numPregunta);
    void recalcularId();
    void buscarItem(int numPregunta);
    void buscarNivel(int nivel);
    float calcularTiempoTotal();
    void mostrarPrueba();
    int getCantPreg();
    int getLargoVector();
};


#endif //PRUEBA_H
