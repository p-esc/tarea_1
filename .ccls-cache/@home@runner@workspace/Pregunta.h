//
// Created by polae on 4/1/2025.
//

#ifndef PREGUNTA_H
#define PREGUNTA_H
#include <string>
#include <vector>
using namespace std;


// Clase base preguntas
class Pregunta {
protected:
    string enunciado;
    float tiempoEstimado;
    int nivelTaxonomia;
    static int contadorId;
    int id;
public:
    Pregunta(string enunciado, float tiempoEstimado, int nivelTaxonomia);
    virtual ~Pregunta();
    // setters y getters
    int getId();
    void setId(int nuevoId);
    string getNivelPalabra() const;
    int getNivel();
    void setNivel(int nivel);
    float getTiempoEstimado();
    void setTiempoEstimado(float nuevoTiempo);
    void setEnunciado(string nuevoEnunciado);
    // métodos virtuales
    virtual string getRespuestaCorrecta() const = 0;
    virtual void mostrarPregunta() const = 0;
};


// Preguntas de opción multiple
class OpcionMultiple: public Pregunta {
private:
    vector<string> alternativas;
    char correcta;
public:
    // constructor
    OpcionMultiple(string enunciado, float tiempoEstimado, int nivelTaxonomia, vector<string> alternativas, char correcta);
    // setters y getters
    string getRespuestaCorrecta() const override;
    void setAlternativas(vector<string> nuevasAlternativas);
    void setCorrecta();
    vector<string> getAlternativas();
    // mostrar
    void mostrarPregunta() const override;
};


// Preguntas de Verdadero o Falso
class VerdaderoFalso: public Pregunta {
private:
    string justificacion;
    bool respuestaCorrecta;
public:
    VerdaderoFalso(string enunciado, float tiempoEstimado, int nivelTaxonomia, string justificacion, bool respuestaCorrecta);
    void setJustificacion(string nuevaJustificacion);
    string getJustificacion();
    string getRespuestaCorrecta() const override;
    void mostrarPregunta() const override;
};


#endif //PREGUNTA_H
