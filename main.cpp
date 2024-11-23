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

int main()
{
    // Variables de entrada
    int menu;               
    string nombre;          
    string cedula;          
    int asiento;            
    string clase_silla;      
    string posicion_silla;   
    int total_sillas = 50;   
    int sillas_ejecutivas = 8;   
    int sillas_ocupadas = 0;   
    float precio;          
    float ventas_totales = 0;   
    float promedio_ventas = 0;  
    
    // Variables de salida
    float porcentaje_ocupacion;
    
     // Almacenar reservas
    string reservas_nombres[total_sillas] = {};  
    string reservas_cedulas[total_sillas] = {};  
    bool silla_ocupada[total_sillas] = {false};

    do
    {
        cout << "1. Asignar una silla a un pasajero" << endl;
        cout << "2. Consultar una reserva" << endl;
        cout << "3. Eliminar reserva" << endl;
        cout << "4. Buscar pasajero" << endl;
        cout << "5. Calcular el porcentaje de ocupación del avión." << endl;
        cout << "6. Consultar el valor total de ventas por concepto de sillas ocupadas en el avión." << endl;
        cout << "7. Consultar el valor promedio de venta por concepto de sillas ocupadas / pasajero en el avión." << endl;
        cout << "8. Salir" << endl;
        cout << "Digite la opción que desee saber: ";
        cin >> menu;

        switch (menu) 
        {
            case 1:
                cout << "Ingrese el nombre del pasajero: ";
                cin >> nombre;
                cout << "Ingrese la cédula del pasajero: ";
                cin >> cedula;

                // Validación cédula
                while (cedula.length() != 10) {
                    cout << "La cédula debe tener exactamente 10 dígitos. Intente de nuevo." << endl;
                    // Volver a pedir la cédula
                    cout << "Ingrese la cédula del pasajero (debe tener 10 dígitos): ";
                    cin >> cedula;
                }

    // Validación clase de silla
    cout << "Ingrese la clase de silla (Ejecutiva/Economica): ";
    cin >> clase_silla;
    while (clase_silla != "Ejecutiva" && clase_silla != "Economica") {
        cout << "Clase de silla inválida. Ingrese 'Ejecutiva' o 'Economica': ";
        cin >> clase_silla;
    }

    // Validación posición de la silla
    cout << "Ingrese la posición de la silla (Ventana/Pasillo/Centro): ";
    cin >> posicion_silla;
    while (posicion_silla != "Ventana" && posicion_silla != "Pasillo" && posicion_silla != "Centro") {
        cout << "Posición inválida. Ingrese 'Ventana', 'Pasillo' o 'Centro': ";
        cin >> posicion_silla;
    }

    // Asignación
    for (int i = 0; i < total_sillas; ++i) {
        if (!silla_ocupada[i] && 
            ((clase_silla == "Ejecutiva" && i < sillas_ejecutivas) || 
            (clase_silla == "Economica" && i >= sillas_ejecutivas))) {
            asiento = i + 1;
            silla_ocupada[i] = true;
            reservas_nombres[i] = nombre;
            reservas_cedulas[i] = cedula;
            sillas_ocupadas++;
            break;
        }
    }

    cout << "Silla asignada a " << nombre << " en el asiento " << asiento << " (" << clase_silla << ", " << posicion_silla << ")" << endl;
    break;
                
            case 2:
                cout << "Ingrese el número de asiento a consultar: ";
    cin >> asiento;

    // Validación número de asiento
    while (asiento < 1 || asiento > total_sillas) {
        cout << "Número de asiento inválido. Ingrese un número entre 1 y " << total_sillas << ": ";
        cin >> asiento;
    }

    if (silla_ocupada[asiento - 1]) {
        cout << "Reserva para " << reservas_nombres[asiento - 1] << " (Cédula: " << reservas_cedulas[asiento - 1] << ") en el asiento " << asiento << endl;
    } else {
        cout << "El asiento " << asiento << " está libre." << endl;
    }
    break;

case 3:
    cout << "Ingrese el número de asiento a eliminar: ";
    cin >> asiento;

    // Validación número de asiento
    while (asiento < 1 || asiento > total_sillas) {
        cout << "Número de asiento inválido. Ingrese un número entre 1 y " << total_sillas << ": ";
        cin >> asiento;
    }

    if (silla_ocupada[asiento - 1]) {
        silla_ocupada[asiento - 1] = false;
        sillas_ocupadas--;
        cout << "Reserva eliminada para el asiento " << asiento << endl;
    } else {
        cout << "El asiento " << asiento << " no tiene una reserva activa." << endl;
    }
    break;

            case 4:
                cout << "Ingrese la cédula del pasajero a buscar: ";
                cin >> cedula;
                for (int i = 0; i < total_sillas; ++i) {
                    if (reservas_cedulas[i] == cedula) {
                        cout << "Pasajero " << reservas_nombres[i] << " encontrado en el asiento " << (i + 1) << endl;
                        break;
                    }
                }
                break;

           case 5:
                porcentaje_ocupacion = (float)sillas_ocupadas / total_sillas * 100;
                cout << "El porcentaje de ocupación del avión es: " << porcentaje_ocupacion << "%" << endl;
                break;

            case 6:
                cout << "El valor total de ventas es: $" << ventas_totales << endl;
                break;

           case 7:
                if (sillas_ocupadas > 0) {
                    promedio_ventas = ventas_totales / sillas_ocupadas;
                } else 
                {
                    promedio_ventas = 0;
                }
                cout << "El valor promedio de venta por pasajero es: $" << promedio_ventas << endl;
                break;
                
            case 8:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Operación no válida." << endl;
                break;
        }
    } 
    while (menu != 8);

}