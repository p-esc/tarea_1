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
        cout << "\n======================= MENU =======================\n";
        cout << "(1) Actualizar pregunta\n";
        cout << "(2) Eliminar pregunta\n";
        cout << "(3) Buscar pregunta\n";
        cout << "(4) Mostrar prueba completa\n";
        cout << "(5) Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------------\n";
        switch (opcion) {
            case 1: this->actualizarPregunta(); break;
            case 2: this->eliminarPregunta(); break;
            case 3: this->buscarPregunta(); break;
            case 4: miPrueba->mostrarPrueba(); break;
            case 5: cout << "Saliendo del programa\n"; break;
            default: cout << "No existe esa opción. Intente nuevamente.\n";
        }
    } while (opcion != 5);
}

void Menu::agregarPregunta() {
    do {
        int tipo;
        cout << "\nAgregando pregunta:\n";
        cout << "Seleccione tipo de pregunta\n(1) Opción Múltiple\n(2) Verdadero/Falso:\n";
        cin >> tipo;
        cin.ignore();
        string enunciado;
        float tiempo;
        int nivel;
        cout << "Ingrese el enunciado: ";
        getline(cin, enunciado);
        cout << "Tiempo estimado en minutos: ";
        cin >> tiempo;
        cout << "Nivel de taxonomía:\n(1) Recordar\n(2) Entender\n(3) Aplicar\n(4) Analizar\n(5) Evaluar\n(6) Crear\n";
        cin >> nivel;
        while (nivel < 1 || nivel > 6 ) {
            cout<<"Ingrese un número válido\n";
            cout<< "Nivel de taxonomía:\n(1) Recordar\n(2) Entender\n(3) Aplicar\n(4) Analizar\n(5) Evaluar\n(6) Crear\n";
            cin >> nivel;
        }
        if (tipo == 1) {
            vector<string> opciones;
            string opcion;
            char correcta;
            char alternativas[] = {'A', 'B', 'C', 'D'};
            cout << "Ingrese 4 alternativas:\n";
            cin.ignore();
            for (char alternativa: alternativas) {
                cout << "Alternativa " << alternativa << ". ";
                getline(cin, opcion);
                opciones.push_back(opcion);
            }
            cout << "Letra de la alternativa correcta: ";
            cin >> correcta;
            miPrueba->agregarPregunta(new OpcionMultiple(enunciado, tiempo, nivel, opciones, tolower(correcta)));
        } else if (tipo == 2) {
            bool correcta;
            string justificacion;
            cout << "¿Es verdadero (1) o falso (0)?: ";
            cin >> correcta;
            cin.ignore();
            cout << "Ingrese la justificacion: ";
            getline(cin, justificacion);
            miPrueba->agregarPregunta(new VerdaderoFalso(enunciado, tiempo, nivel, justificacion, correcta));
        }
    }while (miPrueba->getLargoVector() < miPrueba->getCantPreg());
}

void Menu::actualizarPregunta() {
    int id, tipo;
    cout << "Ingrese el número de la pregunta a actualizar: ";
    cin >> id;
    if (id < 1 || id > miPrueba->getLargoVector()){
        cout<<"No existe una pregunta con ese número\n";
    }
    else {
        cout<< "¿Qué desea actualizar? \n(1) Enunciado\n(2) Tiempo estimado\n(3) Nivel Taxonómico"<<endl;
        cin >> tipo;
        if (tipo < 1 || tipo > 3) {
            cout<<"No existe esa opción\n";
        }
        else {
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
    }
}

void Menu::eliminarPregunta() {
    int id;
    cout << "Ingrese el número de la pregunta a eliminar: ";
    cin >> id;
    if (id < 1 || id > miPrueba->getLargoVector()) {
        cout<<"No existe una pregunta con ese número\n";
    }
    else {
        miPrueba->borrarPregunta(id);
        cout<<"Se ha eliminado la pregunta "<< id;
        cout<<"\nSe han actualizado los números de las preguntas restantes";
    }
}

void Menu::buscarPregunta() {
    int valor, tipo;
    int nivel;
    cout<< "¿Por qué desea buscar?\n(1) Nivel taxonómico\n(2) N° de pregunta"<<endl;
    cin >> tipo;
    if (tipo == 1) {
        cout<<"¿Qué nivel quiere buscar?\n(1) Recordar\n(2) Entender\n(3) Aplicar\n(4) Analizar\n(5) Evaluar\n(6) Crear\n";
        cin>>nivel;
        if (nivel < 1 || nivel > 6) {
            cout<<"\nNo existe ese nivel taxonómico\n";
        }
        else miPrueba->buscarNivel(nivel);
    }
    else if (tipo == 2) {
        cout<<"¿Qué número de pregunta quiere buscar?"<<endl;
        cin>>valor;
        cin.ignore();
        if (valor < 1 || valor > miPrueba->getLargoVector()) {
            cout<<"No existe una pregunta con ese número\n";
        }
        else miPrueba->buscarItem(valor);
    }
    else cout<<"No existe esa opción\n";
}

