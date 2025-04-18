#include "Menu.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// constructor de la clase Menu que recibe un objeto Prueba
Menu::Menu(Prueba *miPrueba) {
    this->miPrueba = miPrueba;
}
// mostrar el menú de opciones y ejecutar la opción seleccionada
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
// agregar preguntas a la prueba hasta que se complete la cantidad definida
// se pregunta si es opción múltiple o verdadero/falso y se piden los datos correspondientes
void Menu::agregarPregunta() {
    do {
        int tipo;
        cout << "\nAgregando pregunta:\n";
        cout << "\nSeleccione tipo de pregunta\n(1) Opción Múltiple\n(2) Verdadero/Falso\n";
        cin >> tipo;
        cin.ignore();
        string enunciado;
        float tiempo;
        int nivel;
        cout << "Ingrese el enunciado: ";
        getline(cin, enunciado);
        cout << "Tiempo estimado en minutos: ";
        cin >> tiempo;
        do {
            cout << "Nivel de taxonomía:\n(1) Recordar    (2) Entender\n(3) Aplicar     (4) Analizar\n(5) Evaluar     (6) Crear\n";
            cin >> nivel;
            if (nivel < 1 || nivel > 6 ) {cout<<"No existe ese nivel taxonómico\n";}
        } while (nivel < 1 || nivel > 6 );
        if (tipo == 1) {
            vector<string> opciones;
            string opcion;
            char correcta;
            char alternativas[] = {'A', 'B', 'C', 'D'};
            cout << "Ingrese 4 alternativas:\n";
            cin.ignore();
            for (char alternativa: alternativas) {
                cout << alternativa << ")  ";
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
// actualizar una pregunta específica por su número y el tipo de dato a actualizar
// se pregunta si se quiere actualizar el enunciado, el tiempo estimado o el nivel taxonómico
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
// eliminar una pregunta específica por su número y recalcular los IDs de las preguntas restantes
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
        cout<<"\nSe han actualizado los números de las preguntas restantes\n";
    }
}
// buscar una pregunta específica por su número o por su nivel taxonómico
void Menu::buscarPregunta() {
    int valor, tipo;
    int nivel;
    cout<< "¿Por qué desea buscar?\n(1) Nivel taxonómico\n(2) N° de pregunta"<<endl;
    cin >> tipo;
    if (tipo == 1) {
        cout << "Nivel de taxonomía:\n(1) Recordar    (2) Entender\n(3) Aplicar     (4) Analizar\n(5) Evaluar     (6) Crear\n";
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

