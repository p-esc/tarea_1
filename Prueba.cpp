#include "Prueba.h"
#include <iostream>
#include <vector>
using namespace std;

// Constructor para inicializar la prueba con una cantidad específica de preguntas
Prueba::Prueba(int cantPreguntas) {
    this->cantPreguntas=cantPreguntas;
}
// Destructor de la clase Prueba
Prueba::~Prueba() {};
// Método para agregar una pregunta a la prueba
void Prueba::agregarPregunta(Pregunta* pregunta) {
        this->preguntas.push_back(pregunta);
}
// Actualizar el enunciado de una pregunta por su número
void Prueba::actualizarEnunciado(int num) {
    string nuevoEnunciado;
    cout<<"¿Cuál será el nuevo enunciado para la pregunta "<< num <<"?"<< endl;
    cin.ignore();
    getline(cin, nuevoEnunciado);
    preguntas[num-1]->setEnunciado(nuevoEnunciado);
}
// Actualizar el nivel taxonómico de una pregunta por su número
void Prueba::actualizarNivel(int num) {
    int nuevoNivel;
    cout<<"¿Cuál es el nuevo nivel taxonómico para la pregunta "<< num <<"?"<< endl;
    cout << "Nivel de taxonomía:\n(1) Recordar    (2) Entender\n(3) Aplicar     (4) Analizar\n(5) Evaluar     (6) Crear\n";
    cin>>nuevoNivel;
    preguntas[num-1]->setNivel(nuevoNivel);
}
// Actualizar el tiempo estimado de una pregunta por su número
void Prueba::actualizarTiempo(int num) {
    float nuevoTiempo;
    cout<<"¿Cuál es el nuevo tiempo estimado para la pregunta "<< num <<"?"<< endl;
    cin>>nuevoTiempo;
    preguntas[num-1]->setTiempoEstimado(nuevoTiempo);
    this->calcularTiempoTotal();
}
// Borrar una pregunta específica por su número
void Prueba::borrarPregunta(int numPregunta) {
    this->preguntas.erase(preguntas.begin() + numPregunta -1);
    this->recalcularId();
}
// Recalcular los IDs de las preguntas después de eliminar una pregunta
void Prueba::recalcularId() {
    int nuevoId = 1;
    for (Pregunta* pregunta : preguntas) {
        pregunta->setId(nuevoId++);
    }
}
// Buscar una pregunta específica en la prueba por su número
void Prueba::buscarItem(int numPregunta) {
    cout<<"\n=================== Pregunta N°"<<numPregunta<<" ===================\n";
    preguntas[numPregunta-1]->mostrarPregunta();
    cout<<endl;
    cout<<"====================================================\n";
}
// Buscar todas las preguntas de un nivel taxonómico específico en la prueba
void Prueba::buscarNivel(int nivel) {
    cout<<"\n========= Preguntas de nivel taxonómico "<< nivel <<" =========\n";
    for (Pregunta* pregunta : preguntas) {
        if (pregunta->getNivel() == nivel) {
            pregunta->mostrarPregunta();
            cout<<endl;
        }
    }
    cout<<"====================================================\n";
}
// Mostrar todas las preguntas de la prueba y el tiempo total
void Prueba::mostrarPrueba() {
    cout << "\n========= [ Mostrando la prueba completa ] ========="<<endl;
    for (Pregunta * pregunta : preguntas) {
        pregunta->mostrarPregunta();
        cout<<endl;
    }
    cout<<"Tiempo total de la prueba: "<<this->calcularTiempoTotal()<<" min\n";
    cout << "================= [ Fin prueba ] ===================" << endl;
}
// Calcular el tiempo total de la prueba sumando los tiempos de todas las preguntas
float Prueba::calcularTiempoTotal() {
    float tiempoTotal = 0;
    for (Pregunta * pregunta : preguntas) {
        tiempoTotal += pregunta->getTiempoEstimado();
    }
    return tiempoTotal;
}
// Obtener la cantidad de preguntas definida para la prueba
int Prueba::getCantPreg() {
    return this->cantPreguntas;
}
// Obtener la cantidad de preguntas actuales en la prueba
int Prueba::getLargoVector() {
    return this->preguntas.size();
}