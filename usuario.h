#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    string ID_Usuario;
    string correo;
    string contraseña;
    string kilometraje;

public:
    // Constructor y destructor
    Usuario();
    ~Usuario();

    // Métodos getter y setter para 'nombre'
    string getName() const;
    void setName(const string& nName);

    // Métodos getter y setter para 'ID_Usuario'
    string getID() const;
    void setID(const string& nID);

    // Métodos getter y setter para 'correo'
    string getCorreo() const;
    void setCorreo(const string& nCorreo);

    // Métodos getter y setter para 'contraseña'
    string getContraseña() const;
    void setContraseña(const string& nContraseña);

    // Métodos getter y setter para 'kilometraje'
    string getKilometraje() const;
    void setKilometraje(const string& nKilometraje);

    void actualizarKilometraje(double kilometros);
    bool iniciarSesion(const string& nCorreo, const string& nContraseña) const;
    void guardarDatos() const;
    void cargarDatos(const string& linea);  
};

#endif // USUARIO_HPP
