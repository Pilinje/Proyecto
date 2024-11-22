#include "sistema_reservacion.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <sstream>

// Registrar un nuevo usuario
void SistemaReservacion::registrarUsuario(const string& nombre, const string& correo, const string& contraseña) {
    string idUsuario = "USR" + to_string(usuarios.size() + 1);
    Usuario nuevoUsuario(idUsuario, nombre, correo, contraseña);
    usuarios.push_back(nuevoUsuario);
    cout << "Usuario registrado con éxito: " << nombre << endl;
}

// Buscar vuelos disponibles según criterios
vector<Vuelo> SistemaReservacion::buscarVuelos(const string& fecha, const string& origen, const string& destino, const string& filtro) const {
    vector<Vuelo> vuelosFiltrados;
    for (const Vuelo& vuelo : vuelos) {
        if (vuelo.getFecha() == fecha && vuelo.getOrigen() == origen && vuelo.getDestino() == destino) {
            vuelosFiltrados.push_back(vuelo);
        }
    }

    if (filtro == "precio") {
        sort(vuelosFiltrados.begin(), vuelosFiltrados.end(), [](const Vuelo& a, const Vuelo& b) {
            return a.getPrecio() < b.getPrecio();
        });
    } else if (filtro == "duracion") {
        sort(vuelosFiltrados.begin(), vuelosFiltrados.end(), [](const Vuelo& a, const Vuelo& b) {
            return a.getDuracion() < b.getDuracion();
        });
    }

    return vuelosFiltrados;
}

// Procesar la creación de una reservación
void SistemaReservacion::procesarReservacion(const Usuario& usuario, const Vuelo& vuelo, const string& asiento) {
    string idReservacion = "RES" + to_string(reservaciones.size() + 1);
    Reservacion nuevaReservacion(idReservacion, usuario.getID(), vuelo.getNumeroVuelo(), vuelo.getFecha(), asiento, vuelo.getPrecio());
    reservaciones.push_back(nuevaReservacion);

    Vuelo vueloActualizado = vuelo;
    vueloActualizado.actualizarDisponibilidad(1);

    cout << "Reservación creada exitosamente para el usuario: " << usuario.getName() << endl;
}

// Cancelar una reservación existente
void SistemaReservacion::cancelarReservacion(const string& idReservacion) {
    auto it = find_if(reservaciones.begin(), reservaciones.end(), [&](const Reservacion& reservacion) {
        return reservacion.getIdReservacion() == idReservacion;
    });

    if (it != reservaciones.end()) {
        it->cancelarReservacion(*find_if(vuelos.begin(), vuelos.end(), [&](const Vuelo& vuelo) {
            return vuelo.getNumeroVuelo() == it->getNumeroVuelo();
        }));

        reservaciones.erase(it);
        cout << "Reservación cancelada exitosamente." << endl;
    } else {
        throw runtime_error("No se encontró una reservación con el ID especificado.");
    }
}

// Guardar datos en archivos
void SistemaReservacion::guardarDatos() const {
    ofstream archivoUsuarios("usuarios.txt");
    for (const Usuario& usuario : usuarios) {
        archivoUsuarios << usuario.getID() << "," << usuario.getName() << "," << usuario.getCorreo() << "," << usuario.getKilometraje() << endl;
    }
    archivoUsuarios.close();

    ofstream archivoVuelos("vuelos.txt");
    for (const Vuelo& vuelo : vuelos) {
        archivoVuelos << vuelo.getNumeroVuelo() << "," << vuelo.getNombreVuelo() << "," << vuelo.getOrigen() << ","
                      << vuelo.getDestino() << "," << vuelo.getFecha() << "," << vuelo.getDuracion() << ","
                      << vuelo.getPrecio() << "," << vuelo.getAsientosDisponibles() << endl;
    }
    archivoVuelos.close();

    ofstream archivoReservaciones("reservaciones.txt");
    for (const Reservacion& reservacion : reservaciones) {
        archivoReservaciones << reservacion.getIdReservacion() << "," << reservacion.getIdUsuario() << ","
                             << reservacion.getNumeroVuelo() << "," << reservacion.getFechaReservacion() << ","
                             << reservacion.getAsiento() << "," << reservacion.getPrecioTotal() << endl;
    }
    archivoReservaciones.close();
}

// Cargar datos desde archivos
void SistemaReservacion::cargarDatos() {
    ifstream archivoUsuarios("usuarios.txt");
    string linea;
    while (getline(archivoUsuarios, linea)) {
        stringstream ss(linea);
        string id, nombre, correo, kilometraje;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, correo, ',');
        getline(ss, kilometraje, ',');
        usuarios.emplace_back(id, nombre, correo, "");  // Contraseña no almacenada
        usuarios.back().setKilometraje(kilometraje);
    }
    archivoUsuarios.close();

    ifstream archivoVuelos("vuelos.txt");
    while (getline(archivoVuelos, linea)) {
        stringstream ss(linea);
        string numero, nombre, origen, destino, fecha, duracion, precio, asientos;
        getline(ss, numero, ',');
        getline(ss, nombre, ',');
        getline(ss, origen, ',');
        getline(ss, destino, ',');
        getline(ss, fecha, ',');
        getline(ss, duracion, ',');
        getline(ss, precio, ',');
        getline(ss, asientos, ',');
        vuelos.emplace_back(numero, nombre, origen, destino, fecha, stod(duracion), stod(precio), stoi(asientos));
    }
    archivoVuelos.close();

    ifstream archivoReservaciones("reservaciones.txt");
    while (getline(archivoReservaciones, linea)) {
        stringstream ss(linea);
        string id, idUsuario, numVuelo, fecha, asiento, precio;
        getline(ss, id, ',');
        getline(ss, idUsuario, ',');
        getline(ss, numVuelo, ',');
        getline(ss, fecha, ',');
        getline(ss, asiento, ',');
        getline(ss, precio, ',');
        reservaciones.emplace_back(id, idUsuario, numVuelo, fecha, asiento, stod(precio));
    }
    archivoReservaciones.close();
}
