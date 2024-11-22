#ifndef VUELO_HPP
#define VUELO_HPP

#include <string>
using namespace std;

class Vuelo {
private:
    string numero_vuelo;           // ID único del vuelo
    string nombre_vuelo;           // Nombre de la aerolínea o número de identificación
    string origen;                 // Ciudad de origen
    string destino;                // Ciudad de destino
    string fecha;                  // Fecha del vuelo
    double duracion;               // Duración del vuelo (en horas)
    double precio;                 // Precio base del vuelo
    int asientos_disponibles;      // Número de asientos libres

public:
    // Constructores y destructor
    Vuelo();
    Vuelo(const string& numVuelo, const string& nNombreVuelo, const string& nOrigen, 
          const string& nDestino, const string& nFecha, double nDuracion, double nPrecio, int nAsientos);
    ~Vuelo();

    // Métodos getter y setter para 'numero_vuelo'
    string getNumeroVuelo() const;
    void setNumeroVuelo(const string& numVuelo);

    // Métodos getter y setter para 'nombre_vuelo'
    string getNombreVuelo() const;
    void setNombreVuelo(const string& nNombreVuelo);

    // Métodos getter y setter para 'origen'
    string getOrigen() const;
    void setOrigen(const string& nOrigen);

    // Métodos getter y setter para 'destino'
    string getDestino() const;
    void setDestino(const string& nDestino);

    // Métodos getter y setter para 'fecha'
    string getFecha() const;
    void setFecha(const string& nFecha);

    // Métodos getter y setter para 'duracion'
    double getDuracion() const;
    void setDuracion(double nDuracion);

    // Métodos getter y setter para 'precio'
    double getPrecio() const;
    void setPrecio(double nPrecio);

    // Métodos getter y setter para 'asientos_disponibles'
    int getAsientosDisponibles() const;
    void setAsientosDisponibles(int nAsientos);

    // Métodos adicionales
    void mostrarDetalles() const;                 // Muestra los detalles del vuelo
    bool verificarDisponibilidad() const;         // Comprueba si hay asientos disponibles
    void actualizarDisponibilidad(int asientosReservados); // Actualiza los asientos disponibles tras una reserva
};

#endif // VUELO_HPP
