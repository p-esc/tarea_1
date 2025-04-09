//
// Created by polae on 4/1/2025.
//

#include "Prueba.h"
#include <iostream>
#include <vector>
using namespace std;

Prueba::Prueba(int cantPreguntas) {
    this->cantPreguntas= cantPreguntas;
}

Prueba::~Prueba() {};

void Prueba::agregarPregunta(Pregunta* pregunta) {
        this->preguntas.push_back(pregunta);
}

void Prueba::actualizarEnunciado(int num) {
    string nuevoEnunciado;
    cout<<"¿Cuál será el nuevo enunciado para la pregunta "<< num <<"?"<< endl;
    cin.ignore();
    getline(cin, nuevoEnunciado);
    preguntas[num-1]->setEnunciado(nuevoEnunciado);
}

void Prueba::actualizarNivel(int num) {
    int nuevoNivel;
    cout<<"¿Cuál es el nuevo nivel taxonómico para la pregunta "<< num <<"?"<< endl;
    cout<<"(1) Recordar\n(2) Entender\n(3) Aplicar\n(4) Analizar\n(5) Evaluar\n(6) Crear\n";
    cin>>nuevoNivel;
    preguntas[num-1]->setNivel(nuevoNivel);
}

void Prueba::actualizarTiempo(int num) {
    float nuevoTiempo;
    cout<<"¿Cuál es el nuevo tiempo estimado para la pregunta "<< num <<"?"<< endl;
    cin>>nuevoTiempo;
    preguntas[num-1]->setTiempoEstimado(nuevoTiempo);
    this->calcularTiempoTotal();
}

void Prueba::borrarPregunta(int numPregunta) {
    this->preguntas.erase(preguntas.begin() + numPregunta -1);
    this->recalcularId();
    this->calcularTiempoTotal();
}

void Prueba::buscarItem(int numPregunta) {
    cout<<"\n======= Pregunta N°"<<numPregunta<<" =======\n";
    preguntas[numPregunta-1]->mostrarPregunta();
    cout<<"\n============================================\n";
}

void Prueba::buscarNivel(int nivel) {
    cout<<"\n======= Preguntas de nivel taxonómico "<<nivel<<" =======\n";
    for (Pregunta* pregunta : preguntas) {
        if (pregunta->getNivel() == nivel)
            pregunta->mostrarPregunta();
    }
    cout<<"\n===========================================================\n";
}

void Prueba::recalcularId() {
    int nuevoId = 1;
    for (Pregunta* pregunta : preguntas) {
        pregunta->setId(nuevoId++);
    }
}

void Prueba::mostrarPrueba() {
    cout << "\n========= [ Mostrando la prueba completa ] ========="<<endl;
    for (Pregunta * pregunta : preguntas) {
        pregunta->mostrarPregunta();
        cout<<endl;
    }
    cout<<"Tiempo total de la prueba: "<<this->calcularTiempoTotal()<<" min\n";
    cout << "================= [ Fin prueba ] =================" << endl;
}

float Prueba::calcularTiempoTotal() {
    float tiempoTotal = 0;
    for (Pregunta * pregunta : preguntas) {
        tiempoTotal += pregunta->getTiempoEstimado();
    }
    return tiempoTotal;
}

int Prueba::getCantPreg() {
    return this->cantPreguntas;
}

int Prueba::getLargoVector() {
    return this->preguntas.size();
}