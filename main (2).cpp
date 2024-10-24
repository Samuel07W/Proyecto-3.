#include <iostream>
#include <string>
using namespace std;

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
                cout << "Ingrese la clase de silla (Ejecutiva/Economica): ";
                cin >> clase_silla;
                cout << "Ingrese la posición de la silla (Ventana/Pasillo/Centro): ";
                cin >> posicion_silla;

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
                cout << "Resultado: " << endl;
                break;

            case 3:
                cout << "Resultado: " << endl;
                break;

            case 4:
                cout << "Resultado: " << endl;
                        break;

            case 5:
                cout << "Resultado: " << endl;
                break;

            case 6:
                cout << "Resultado: " << endl;
                break;

            case 7:
                cout << "Resultado: " << endl;
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
