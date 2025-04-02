//
// Created by polae on 4/1/2025.
//

#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

Menu::Menu(Prueba *miPrueba) {
    this->miPrueba = miPrueba;
}

void Menu::mostrarMenu() {
    int opcion;
    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Agregar pregunta\n";
        cout << "2. Actualizar pregunta\n";
        cout << "3. Eliminar pregunta\n";
        cout << "4. Buscar pregunta\n";
        cout << "5. Mostrar prueba completa\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: this->agregarPregunta(); break;
            case 2: this->actualizarPregunta(); break;
            case 3: this->eliminarPregunta(); break;
            case 4: this->buscarPregunta(); break;
            case 5: miPrueba->mostrarPrueba(); break;
            case 6: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 6);
}

void Menu::agregarPregunta() {
    int tipo;
    cout << "Tipo de pregunta\n(1) Opción Múltiple\n(2) Verdadero/Falso):\n";
    cin >> tipo;
    cin.ignore();
    string enunciado;
    float tiempo;
    string nivel;
    cout << "Ingrese el enunciado: ";
    getline(cin, enunciado);
    cout << "Tiempo estimado en minutos: ";
    cin >> tiempo;
    cout << "Nivel de taxonomía:";
    cin >> nivel;

    if (tipo == 1) {
        vector<string> opciones;
        string opcion;
        char correcta;
        char alternativas[] = {'A', 'B', 'C', 'D'};
        cout << "Ingrese 4 alternativas:\n";
        cin.ignore();
        for (char alternativa : alternativas) {
            cout << "Alternativa " << alternativa << ". ";
            getline(cin, opcion);
            opciones.push_back(opcion);
        }
        cout << "Ingrese la letra de la alternativa correcta (A, B, C, D): ";
        cin >> correcta;
        miPrueba->agregarPregunta(new OpcionMultiple(enunciado, tiempo, nivel, opciones, correcta));
    }
    else if (tipo == 2) {
        bool correcta;
        string justificacion;
        cout << "¿Es verdadero (1) o falso (0)?: ";
        cin >>correcta;
        cout << "Ingrese la justificacion: ";
        cin.ignore();
        getline(cin, justificacion);
        miPrueba->agregarPregunta(new VerdaderoFalso(enunciado, tiempo, nivel, justificacion, correcta));
    }
}

void Menu::actualizarPregunta() {
    int id, tipo;
    cout << "Ingrese el número de la pregunta a actualizar: ";
    cin >> id;
    cout<< "¿Qué desea actualizar? \n(1) Enunciado\n(2) Tiempo estimado\n(3) Nivel Taxonómico:"<<endl;
    cin >> tipo;
    if (tipo == 1) {
        miPrueba->actualizarEnunciado(id);
    }
    else if (tipo == 2) {
        miPrueba->actualizarTiempo(id);
    }
    else if (tipo == 3){
        miPrueba->actualizarNivel(id);
    }
}

void Menu::eliminarPregunta() {
    int id;
    cout << "Ingrese el número de la pregunta a eliminar: ";
    cin >> id;
    miPrueba->borrarPregunta(id);
}

void Menu::buscarPregunta() {
    int valor, tipo;
    string nivel;
    cout<< "¿Por qué desea buscar? \n(1) Nivel taxonómico\n(2) N° de pregunta"<<endl;
    cin >> tipo;
    if (tipo == 1) {
        cout<<"¿Qué nivel quiere buscar?"<<endl;
        cin>>nivel;
        miPrueba->buscarNivel(nivel);
    }
    else {
        cout<<"¿Qué número de pregunta quiere buscar?"<<endl;
        cin>>valor;
        miPrueba->buscarItem(valor);
    }
}

