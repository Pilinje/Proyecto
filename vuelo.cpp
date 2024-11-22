#include "vuelo.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Constructor por defecto
Vuelo::Vuelo() : duracion(0), precio(0), asientos_disponibles(0) {}

// Constructor parametrizado
Vuelo::Vuelo(const string& numVuelo, const string& nNombreVuelo, const string& nOrigen,
             const string& nDestino, const string& nFecha, double nDuracion,
             double nPrecio, int nAsientos)
    : numero_vuelo(numVuelo), nombre_vuelo(nNombreVuelo), origen(nOrigen),
      destino(nDestino), fecha(nFecha), duracion(nDuracion), 
      precio(nPrecio), asientos_disponibles(nAsientos) {}

// Destructor
Vuelo::~Vuelo() {}

// Métodos getter y setter para 'numero_vuelo'
string Vuelo::getNumeroVuelo() const { return numero_vuelo; }
void Vuelo::setNumeroVuelo(const string& numVuelo) { numero_vuelo = numVuelo; }

// Métodos getter y setter para 'nombre_vuelo'
string Vuelo::getNombreVuelo() const { return nombre_vuelo; }
void Vuelo::setNombreVuelo(const string& nNombreVuelo) { nombre_vuelo = nNombreVuelo; }

// Métodos getter y setter para 'origen'
string Vuelo::getOrigen() const { return origen; }
void Vuelo::setOrigen(const string& nOrigen) { origen = nOrigen; }

// Métodos getter y setter para 'destino'
string Vuelo::getDestino() const { return destino; }
void Vuelo::setDestino(const string& nDestino) { destino = nDestino; }

// Métodos getter y setter para 'fecha'
string Vuelo::getFecha() const { return fecha; }
void Vuelo::setFecha(const string& nFecha) { fecha = nFecha; }

// Métodos getter y setter para 'duracion'
double Vuelo::getDuracion() const { return duracion; }
void Vuelo::setDuracion(double nDuracion) {
    if (nDuracion > 0) {
        duracion = nDuracion;
    } else {
        throw invalid_argument("La duración debe ser positiva.");
    }
}

// Métodos getter y setter para 'precio'
double Vuelo::getPrecio() const { return precio; }
void Vuelo::setPrecio(double nPrecio) {
    if (nPrecio >= 0) {
        precio = nPrecio;
    } else {
        throw invalid_argument("El precio no puede ser negativo.");
    }
}

// Métodos getter y setter para 'asientos_disponibles'
int Vuelo::getAsientosDisponibles() const { return asientos_disponibles; }
void Vuelo::setAsientosDisponibles(int nAsientos) {
    if (nAsientos >= 0) {
        asientos_disponibles = nAsientos;
    } else {
        throw invalid_argument("El número de asientos no puede ser negativo.");
    }
}

// Métodos adicionales
void Vuelo::mostrarDetalles() const {
    cout << "Número de vuelo: " << numero_vuelo << endl
         << "Nombre del vuelo: " << nombre_vuelo << endl
         << "Origen: " << origen << endl
         << "Destino: " << destino << endl
         << "Fecha: " << fecha << endl
         << fixed << setprecision(2)
         << "Duración: " << duracion << " horas" << endl
         << "Precio: $" << precio << endl
         << "Asientos disponibles: " << asientos_disponibles << endl;
}

bool Vuelo::verificarDisponibilidad() const {
    return asientos_disponibles > 0;
}

void Vuelo::actualizarDisponibilidad(int asientosReservados) {
    if (asientosReservados <= 0) {
        throw invalid_argument("El número de asientos reservados debe ser positivo.");
    }
    if (asientosReservados > asientos_disponibles) {
        throw invalid_argument("No hay suficientes asientos disponibles.");
    }
    asientos_disponibles -= asientosReservados;
}
