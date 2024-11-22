#ifndef SISTEMA_RESERVACION_HPP
#define SISTEMA_RESERVACION_HPP

#include <vector>
#include <string>
#include "usuario.hpp"
#include "vuelo.hpp"
#include "reservacion.hpp"

using namespace std;

class SistemaReservacion {
private:
    vector<Usuario> usuarios;        // Lista de usuarios registrados
    vector<Vuelo> vuelos;            // Lista de vuelos disponibles
    vector<Reservacion> reservaciones; // Lista de reservaciones activas

public:
    // Métodos para la gestión de usuarios
    void registrarUsuario(const string& nombre, const string& correo, const string& contraseña);

    // Métodos para la gestión de vuelos
    vector<Vuelo> buscarVuelos(const string& fecha, const string& origen, const string& destino, const string& filtro) const;

    // Métodos para la gestión de reservaciones
    void procesarReservacion(const Usuario& usuario, const Vuelo& vuelo, const string& asiento);
    void cancelarReservacion(const string& idReservacion);

    // Métodos para la persistencia de datos
    void guardarDatos() const;
    void cargarDatos();
};

#endif // SISTEMA_RESERVACION_HPP
