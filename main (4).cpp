#include <iostream>
#include <string>
using namespace std;

// Estructura del Pasajero
struct Pasajero {
    string nombre;
    string cedula;
};

// Estructura de la Silla
struct Silla {
    int numero;
    string clase;
    string posicion;
    bool ocupada = false;
    Pasajero pasajero; // Se usa la estructura Pasajero
};

// Estructura del Avion
struct Avion {
    int total_sillas = 50;
    int sillas_ejecutivas = 8;
    Silla sillas[50]; // Array de 50 sillas
    int sillas_ocupadas = 0;
};

// Estructura de Ventas
struct Ventas {
    float total_ventas = 0;
    float promedio_ventas = 0;
};

// Inicializar las sillas del avión
void inicializarSillas(Avion &avion) {
    for (int i = 0; i < avion.total_sillas; ++i) {
        avion.sillas[i].numero = i + 1;
        if (i < avion.sillas_ejecutivas) {
            avion.sillas[i].clase = "Ejecutiva";
            avion.sillas[i].posicion = (i % 2 == 0) ? "Ventana" : "Pasillo"; // Alternar ventana/pasillo
        } else {
            avion.sillas[i].clase = "Economica";
            if ((i - avion.sillas_ejecutivas) % 3 == 0)
                avion.sillas[i].posicion = "Ventana";
            else if ((i - avion.sillas_ejecutivas) % 3 == 1)
                avion.sillas[i].posicion = "Centro";
            else
                avion.sillas[i].posicion = "Pasillo";
        }
    }
}

// Función para asignar una silla
int asignarSilla(Avion &avion, Pasajero pasajero, string clase, string posicion) {
    for (int i = 0; i < avion.total_sillas; ++i) {
        if (!avion.sillas[i].ocupada && avion.sillas[i].clase == clase && avion.sillas[i].posicion == posicion) {
            avion.sillas[i].ocupada = true;
            avion.sillas[i].pasajero = pasajero;
            avion.sillas_ocupadas++;
            cout << "Silla asignada a " << pasajero.nombre << " en el asiento " << avion.sillas[i].numero 
                 << " (" << clase << ", " << posicion << ")" << endl;
            return avion.sillas[i].numero;
        }
    }
    return -1; // No se encontró una silla disponible
}


int main() {
    Avion avion;
    Ventas ventas;
    int menu;
    Pasajero pasajero;
    string clase, posicion, cedula;
    int asiento;

    // Inicializar las sillas del avión
    inicializarSillas(avion);

    do {
        cout << "\n1. Asignar una silla a un pasajero" << endl;
        cout << "2. Consultar una reserva" << endl;
        cout << "3. Eliminar reserva" << endl;
        cout << "4. Buscar pasajero por cédula" << endl;
        cout << "5. Calcular el porcentaje de ocupación del avión." << endl;
        cout << "6. Consultar el valor total de ventas." << endl;
        cout << "7. Consultar el valor promedio de ventas por pasajero." << endl;
        cout << "8. Salir" << endl;
        cout << "Digite la opción que desee: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Ingrese el nombre del pasajero: ";
                cin.ignore(); // Limpiar el buffer
                getline(cin, pasajero.nombre);
                cout << "Ingrese la cédula del pasajero: ";
                getline(cin, pasajero.cedula);
                cout << "Ingrese la clase de silla (Ejecutiva/Economica): ";
                cin >> clase;
                cout << "Ingrese la posición de la silla (Ventana/Pasillo/Centro): ";
                cin >> posicion;
                asiento = asignarSilla(avion, pasajero, clase, posicion);
                if (asiento != -1) {
                    // Simular el precio basado en la clase
                    float precio = (clase == "Ejecutiva") ? 200.0 : 100.0;
                    ventas.total_ventas += precio;
                } else {
                    cout << "No hay sillas disponibles en la clase " << clase << " con posición " << posicion << endl;
                }
                break;

            case 2:
                cout << "Ingrese el número de asiento a consultar: ";
                cin >> asiento;
                break;

            case 3:
                cout << "Ingrese el número de asiento a eliminar: ";
                cin >> asiento;
                break;

            case 4:
                cout << "Ingrese la cédula del pasajero a buscar: ";
                cin >> cedula;
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida, por favor intente de nuevo." << endl;
        }

    } while (menu != 8);

    return 0;
}
