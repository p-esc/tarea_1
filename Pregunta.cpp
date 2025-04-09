//
// Created by polae on 4/1/2025.
//

#include "Pregunta.h"
#include <iostream>
#include <algorithm>

int Pregunta::contadorId = 1;

Pregunta::Pregunta(string enunciado, float tiempoEstimado, int nivelTaxonomia) {
    this->enunciado = enunciado;
    this->tiempoEstimado = tiempoEstimado;
    this->nivelTaxonomia = nivelTaxonomia;
    this->id = contadorId++;
}

Pregunta::~Pregunta() {}

void Pregunta::setEnunciado(string nuevoEnunciado) {
    this->enunciado = nuevoEnunciado;
}

void Pregunta::setId (int nuevoId) {
    this->id = nuevoId;
}

int Pregunta::getId() {
    return this->id;
}

string Pregunta::getNivelPalabra() const {
    string niveles[] = {"Recordar", "Entender", "Aplicar", "Analizar", "Evaluar", "Crear"};
    return niveles[this->nivelTaxonomia-1];
}

int Pregunta::getNivel() {
    return this->nivelTaxonomia;
}

void Pregunta::setNivel(int nivel) {
    if (nivel > 0 && nivel < 7 )
        this->nivelTaxonomia = nivel;
}

float Pregunta::getTiempoEstimado() {
    return this->tiempoEstimado;
}

void Pregunta::setTiempoEstimado(float nuevoTiempo) {
    this->tiempoEstimado = nuevoTiempo;
}


// ------------------------------------------
// Opcion Multiple
OpcionMultiple::OpcionMultiple(string enunciado, float tiempoEstimado, int nivelTaxonomia, vector<string> alternativas, char correcta) : Pregunta(enunciado, tiempoEstimado,nivelTaxonomia) {
    this->alternativas = alternativas;
    this->correcta = correcta;
    this->nivelTaxonomia = nivelTaxonomia;
    this->enunciado = enunciado;
    this->tiempoEstimado = tiempoEstimado;
}

string OpcionMultiple::getRespuestaCorrecta() const {
    char arr[] = {'a', 'b', 'c', 'd'};
    int x = distance(arr, find(arr, arr+3, this->correcta));
    return this->alternativas[x];
}

void OpcionMultiple::setAlternativas(vector<string> nuevasAlternativas) {
    if (nuevasAlternativas.size() == 4) {
        this->alternativas = nuevasAlternativas;
    }
}

void OpcionMultiple::setCorrecta() {
    char nuevaCorrecta;
    cout << "Ingrese la alternativa de la respuesta correcta: " << endl;
    cin >> nuevaCorrecta;
    this->correcta = tolower(nuevaCorrecta);
}

vector<string> OpcionMultiple::getAlternativas() {
    return this->alternativas;
}

void OpcionMultiple::mostrarPregunta() const {
    string arr[] = {"A", "B", "C", "D"};
    cout<<"Pregunta ("<<this->id<<")\n";
    cout<<"Tiempo estimado: "<<this->tiempoEstimado<<" min\n";
    cout<<"Nivel taxonómico: "<<this->getNivelPalabra()<<endl;
    cout<<this->enunciado<<endl;
    for (size_t i = 0; i < alternativas.size(); i++) {
        cout << arr[i] << ". " << alternativas[i] <<endl;
    }
    cout<<"Correcta: "<<this->getRespuestaCorrecta()<<endl;
}

// ---------------------------------------------------------------
// Verdadero o Falso
VerdaderoFalso::VerdaderoFalso(string enunciado, float tiempoEstimado, int nivelTaxonomia, string justificacion, bool respuestaCorrecta) : Pregunta(enunciado, tiempoEstimado, nivelTaxonomia) {
    this->enunciado = enunciado;
    this->tiempoEstimado = tiempoEstimado;
    this->nivelTaxonomia = nivelTaxonomia;
    this->justificacion = justificacion;
    this->respuestaCorrecta = respuestaCorrecta;
}

void VerdaderoFalso::setJustificacion(string nuevaJustificacion) {
    this->justificacion = nuevaJustificacion;
}

string VerdaderoFalso::getJustificacion() {
    return this->justificacion;
}

string VerdaderoFalso::getRespuestaCorrecta() const{
    return this->respuestaCorrecta ? "Verdadero" : "Falso";
}

void VerdaderoFalso::mostrarPregunta() const {
    cout<<"Pregunta ("<<this->id<<")"<<endl;
    cout<<"Tiempo estimado: "<<this->tiempoEstimado<<" min"<<endl;
    cout<<"Nivel taxonómico: "<<this->getNivelPalabra()<<endl;
    cout<<this->enunciado<<endl;
    cout<< this->getRespuestaCorrecta()<<". "<< this->justificacion<<endl;
}
