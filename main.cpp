#include <iostream>
#include <string>
#include "sis_reser.h"
#include "usuario.h"
#include "vuelo.h"
#include "reservacion.h"

using namespace std;

int main() {
    SistemaReservacion sistema;
    sistema.cargarDatos();  // Carga los datos desde los archivos al iniciar el sistema

    // Añadir un nuevo usuario
    string nombre, correo, contrasena;
    cout << "Registrar nuevo usuario\n";
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Correo: ";
    getline(cin, correo);
    cout << "Contraseña: ";
    getline(cin, contrasena);
    
    sistema.registrarUsuario(nombre, correo, contrasena);

    // Buscar vuelos
    string fecha, origen, destino, filtro;
    cout << "Buscar vuelos disponibles\n";
    cout << "Fecha (yyyy-mm-dd): ";
    getline(cin, fecha);
    cout << "Origen: ";
    getline(cin, origen);
    cout << "Destino: ";
    getline(cin, destino);
    cout << "Filtro (precio/duracion): ";
    getline(cin, filtro);

    vector<Vuelo> vuelosDisponibles = sistema.buscarVuelos(fecha, origen, destino, filtro);

    if (vuelosDisponibles.empty()) {
        cout << "No se encontraron vuelos disponibles con los criterios especificados." << endl;
        return 0;
    }

    // Mostrar detalles de vuelos encontrados
    cout << "\nVuelos encontrados:\n";
    for (size_t i = 0; i < vuelosDisponibles.size(); ++i) {
        const Vuelo& vuelo = vuelosDisponibles[i];
        cout << i + 1 << ". " << vuelo.getNombreVuelo() << " - " << vuelo.getFecha() << " | Precio: "
             << vuelo.getPrecio() << " | Duración: " << vuelo.getDuracion() << " horas\n";
    }

    // Elegir un vuelo
    int seleccion;
    cout << "Seleccione el número del vuelo a reservar: ";
    cin >> seleccion;
    if (seleccion < 1 || seleccion > vuelosDisponibles.size()) {
        cout << "Selección inválida. Terminando programa." << endl;
        return 0;
    }
    Vuelo vueloSeleccionado = vuelosDisponibles[seleccion - 1];

    // Mostrar detalles del vuelo seleccionado
    cout << "\nDetalles del vuelo seleccionado:\n";
    cout << "Vuelo: " << vueloSeleccionado.getNombreVuelo() << " - " << vueloSeleccionado.getFecha() << "\n";
    cout << "Origen: " << vueloSeleccionado.getOrigen() << " | Destino: " << vueloSeleccionado.getDestino() << "\n";
    cout << "Precio: " << vueloSeleccionado.getPrecio() << " | Duración: " << vueloSeleccionado.getDuracion() << " horas\n";

    // Verificar kilómetros acumulados del usuario y aplicar descuento si corresponde
    double kmAcumulados;
    cout << "Kilómetros acumulados: ";
    cin >> kmAcumulados;
    double precioFinal = vueloSeleccionado.getPrecio();
    if (kmAcumulados > 50000) {
        precioFinal = precioFinal * 0.60;  // Aplica un 40% de descuento
        cout << "¡Descuento del 40% aplicado! Nuevo precio: " << precioFinal << endl;
    }

    // Colocar al pasajero en lista de espera (opcional)
    char opcionEspera;
    cout << "¿Colocar en lista de espera? (S/N): ";
    cin >> opcionEspera;
    bool enListaEspera = (opcionEspera == 'S' || opcionEspera == 's');
    if (enListaEspera) {
        cout << "El pasajero ha sido colocado en lista de espera." << endl;
    }

    // Crear la reservación
    string asiento;
    cout << "Número de asiento: ";
    cin >> asiento;
    sistema.procesarReservacion(sistema.buscarVuelos(fecha, origen, destino, filtro)[seleccion - 1], vueloSeleccionado, asiento);

    // Mostrar mensaje de éxito
    cout << "Reservación realizada con éxito.\n";

    // Cancelar una reservación (opcional)
    string cancelar;
    cout << "¿Deseas cancelar alguna reservación? (S/N): ";
    cin >> cancelar;
    if (cancelar == "S" || cancelar == "s") {
        string idReservacion;
        cout << "Introduce el ID de la reservación a cancelar: ";
        cin >> idReservacion;
        try {
            sistema.cancelarReservacion(idReservacion);
        } catch (const runtime_error& e) {
            cout << "Error al cancelar la reservación: " << e.what() << endl;
        }
    }

    // Guardar los datos modificados en los archivos
    sistema.guardarDatos();

    return 0;
}
