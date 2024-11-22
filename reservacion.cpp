#include "reservacion.hpp"
#include <iostream>
#include <stdexcept>

// Constructor por defecto
Reservacion::Reservacion() : precio_total(0.0) {}

// Constructor con parámetros
Reservacion::Reservacion(const string& idReservacion, const string& idUsuario, const string& numVuelo, 
                         const string& fecha, const string& asiento, double precio)
    : id_reservacion(idReservacion), id_usuario(idUsuario), numero_vuelo(numVuelo), 
      fecha_reservacion(fecha), asiento(asiento), precio_total(precio) {}

// Getters y setters
string Reservacion::getIdReservacion() const {
    return id_reservacion;
}

void Reservacion::setIdReservacion(const string& idReservacion) {
    id_reservacion = idReservacion;
}

string Reservacion::getIdUsuario() const {
    return id_usuario;
}

void Reservacion::setIdUsuario(const string& idUsuario) {
    id_usuario = idUsuario;
}

string Reservacion::getNumeroVuelo() const {
    return numero_vuelo;
}

void Reservacion::setNumeroVuelo(const string& numVuelo) {
    numero_vuelo = numVuelo;
}

string Reservacion::getFechaReservacion() const {
    return fecha_reservacion;
}

void Reservacion::setFechaReservacion(const string& fecha) {
    fecha_reservacion = fecha;
}

string Reservacion::getAsiento() const {
    return asiento;
}

void Reservacion::setAsiento(const string& asientoReservado) {
    asiento = asientoReservado;
}

double Reservacion::getPrecioTotal() const {
    return precio_total;
}

void Reservacion::setPrecioTotal(double precio) {
    precio_total = precio;
}

// Métodos adicionales
void Reservacion::crearReservacion(const Usuario& usuario, const Vuelo& vuelo, const string& asientoReservado) {
    id_usuario = usuario.getID();
    numero_vuelo = vuelo.getNumeroVuelo();
    fecha_reservacion = vuelo.getFecha();
    asiento = asientoReservado;
    precio_total = vuelo.getPrecio();  // Precio base del vuelo
    cout << "Reservación creada para el usuario: " << usuario.getName() << endl;
}

void Reservacion::cancelarReservacion(Vuelo& vuelo) {
    vuelo.actualizarDisponibilidad(-1);  // Incrementa la disponibilidad de asientos
    id_reservacion = "";
    id_usuario = "";
    numero_vuelo = "";
    fecha_reservacion = "";
    asiento = "";
    precio_total = 0.0;
    cout << "Reservación cancelada correctamente." << endl;
}

void Reservacion::aplicarDescuento(double porcentaje) {
    if (porcentaje > 0 && porcentaje <= 100) {
        precio_total *= (1 - porcentaje / 100);
    } else {
        throw invalid_argument("Porcentaje de descuento inválido.");
    }
}
