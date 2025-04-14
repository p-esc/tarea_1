#include "Pregunta.h"
#include <iostream>
#include <algorithm>
// inicializar el contador de ID en 1
int Pregunta::contadorId = 1;
// constructor de la clase Pregunta
Pregunta::Pregunta(string enunciado, float tiempoEstimado, int nivelTaxonomia) {
    this->enunciado = enunciado;
    this->tiempoEstimado = tiempoEstimado;
    this->nivelTaxonomia = nivelTaxonomia;
    this->id = contadorId++;
}
// destructor de la clase Pregunta
Pregunta::~Pregunta() {}
// cambiar el enunciado de la pregunta por uno nuevo
void Pregunta::setEnunciado(string nuevoEnunciado) {
    this->enunciado = nuevoEnunciado;
}
// cambiar el ID de la pregunta por uno nuevo
void Pregunta::setId (int nuevoId) {
    this->id = nuevoId;
}
// obtener el nivel taxonómico de la pregunta en formato de palabra
string Pregunta::getNivelPalabra() const {
    string niveles[] = {"Recordar", "Entender", "Aplicar", "Analizar", "Evaluar", "Crear"};
    return niveles[this->nivelTaxonomia-1];
}
// obtener el nivel taxonómico de la pregunta en formato de número
int Pregunta::getNivel() {
    return this->nivelTaxonomia;
}
// cambiar el nivel taxonómico de la pregunta por uno nuevo (número)
void Pregunta::setNivel(int nivel) {
    if (nivel > 0 && nivel < 7 )
        this->nivelTaxonomia = nivel;
}
// obtener el tiempo estimado de la pregunta
float Pregunta::getTiempoEstimado() {
    return this->tiempoEstimado;
}
// cambiar el tiempo estimado de la pregunta por uno nuevo
void Pregunta::setTiempoEstimado(float nuevoTiempo) {
    this->tiempoEstimado = nuevoTiempo;
}
// ---------------------------------------------------------------
// Opcion Multiple
// constructor de la clase OpcionMultiple
OpcionMultiple::OpcionMultiple(string enunciado, float tiempoEstimado, int nivelTaxonomia, vector<string> alternativas, char correcta) : Pregunta(enunciado, tiempoEstimado,nivelTaxonomia) {
    this->alternativas = alternativas;
    this->correcta = correcta;
    this->nivelTaxonomia = nivelTaxonomia;
    this->enunciado = enunciado;
    this->tiempoEstimado = tiempoEstimado;
}
// obtener la respuesta correcta de la pregunta de opción múltiple
// (busca la letra en el array de alternativas)
string OpcionMultiple::getRespuestaCorrecta() const {
    char arr[] = {'a', 'b', 'c', 'd'};
    int x = distance(arr, find(arr, arr+3, this->correcta));
    return this->alternativas[x];
}
// mostrar la pregunta de opción múltiple
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
// constructor de la clase VerdaderoFalso
VerdaderoFalso::VerdaderoFalso(string enunciado, float tiempoEstimado, int nivelTaxonomia, string justificacion, bool respuestaCorrecta) : Pregunta(enunciado, tiempoEstimado, nivelTaxonomia) {
    this->enunciado = enunciado;
    this->tiempoEstimado = tiempoEstimado;
    this->nivelTaxonomia = nivelTaxonomia;
    this->justificacion = justificacion;
    this->respuestaCorrecta = respuestaCorrecta;
}
// obtener la respuesta correcta de la pregunta verdadero/falso en formato de palabra
string VerdaderoFalso::getRespuestaCorrecta() const{
    return this->respuestaCorrecta ? "Verdadero" : "Falso";
}
// mostrar la pregunta verdadero/falso
void VerdaderoFalso::mostrarPregunta() const {
    cout<<"Pregunta ("<<this->id<<")"<<endl;
    cout<<"Tiempo estimado: "<<this->tiempoEstimado<<" min"<<endl;
    cout<<"Nivel taxonómico: "<<this->getNivelPalabra()<<endl;
    cout<<this->enunciado<<endl;
    cout<< this->getRespuestaCorrecta()<<". "<< this->justificacion<<endl;
}
