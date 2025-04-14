#ifndef PREGUNTA_H
#define PREGUNTA_H
#include <string>
#include <vector>
using namespace std;

// Clase base pregunta
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
    void setId(int nuevoId);
    string getNivelPalabra() const;
    int getNivel();
    void setNivel(int nivel);
    float getTiempoEstimado();
    void setTiempoEstimado(float nuevoTiempo);
    void setEnunciado(string nuevoEnunciado);
    virtual string getRespuestaCorrecta() const = 0;
    virtual void mostrarPregunta() const = 0;
};
// Preguntas de opción multiple
class OpcionMultiple: public Pregunta {
private:
    vector<string> alternativas;
    char correcta;
public:
    OpcionMultiple(string enunciado, float tiempoEstimado, int nivelTaxonomia, vector<string> alternativas, char correcta);
    string getRespuestaCorrecta() const override;
    void mostrarPregunta() const override;
};
// Preguntas de Verdadero o Falso
class VerdaderoFalso: public Pregunta {
private:
    string justificacion;
    bool respuestaCorrecta;
public:
    VerdaderoFalso(string enunciado, float tiempoEstimado, int nivelTaxonomia, string justificacion, bool respuestaCorrecta);
    string getRespuestaCorrecta() const override;
    void mostrarPregunta() const override;
};

#endif //PREGUNTA_H
