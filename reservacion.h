#ifndef RESERVACION_HPP
#define RESERVACION_HPP

#include <string>
#include "usuario.hpp"
#include "vuelo.hpp"

using namespace std;

class Reservacion {
private:
    string id_reservacion;
    string id_usuario;
    string numero_vuelo;
    string fecha_reservacion;
    string asiento;
    double precio_total;

public:
    // Constructores
    Reservacion();
    Reservacion(const string& idReservacion, const string& idUsuario, const string& numVuelo, 
                const string& fecha, const string& asiento, double precio);

    // Métodos getter y setter
    string getIdReservacion() const;
    void setIdReservacion(const string& idReservacion);

    string getIdUsuario() const;
    void setIdUsuario(const string& idUsuario);

    string getNumeroVuelo() const;
    void setNumeroVuelo(const string& numVuelo);

    string getFechaReservacion() const;
    void setFechaReservacion(const string& fecha);

    string getAsiento() const;
    void setAsiento(const string& asiento);

    double getPrecioTotal() const;
    void setPrecioTotal(double precio);

    // Métodos adicionales
    void crearReservacion(const Usuario& usuario, const Vuelo& vuelo, const string& asientoReservado);
    void cancelarReservacion(Vuelo& vuelo);
    void aplicarDescuento(double porcentaje);
};

#endif // RESERVACION_HPP
