#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

class Usuario {
private:
    string ID_Usuario;
    string nombre;
    string correo;
    string contraseña;
    string kilometraje;

public:
    // Constructores
    Usuario() : kilometraje("0") {}
    Usuario(const string& id, const string& nNombre, const string& nCorreo, const string& nContraseña)
        : ID_Usuario(id), nombre(nNombre), correo(nCorreo), contraseña(nContraseña), kilometraje("0") {}

    // Métodos getter y setter para 'nombre'
    string getName() const { return nombre; }
    void setName(const string& nName) { nombre = nName; }

    // Métodos getter y setter para 'ID_Usuario'
    string getID() const { return ID_Usuario; }
    void setID(const string& nID) { ID_Usuario = nID; }

    // Métodos getter y setter para 'correo'
    string getCorreo() const { return correo; }
    void setCorreo(const string& nCorreo) {
        if (nCorreo.find('@') != string::npos) {
            correo = nCorreo;
        } else {
            throw invalid_argument("Correo inválido.");
        }
    }

    // Métodos getter y setter para 'contraseña'
    string getContraseña() const { return contraseña; }
    void setContraseña(const string& nContraseña) { contraseña = nContraseña; }

    // Métodos getter y setter para 'kilometraje'
    string getKilometraje() const { return kilometraje; }
    void setKilometraje(const string& nKilometraje) {
        if (stod(nKilometraje) >= 0) {
            kilometraje = nKilometraje;
        } else {
            throw invalid_argument("El kilometraje no puede ser negativo.");
        }
    }

    // Métodos adicionales
    void actualizarKilometraje(double kilometros) {
        if (kilometros > 0) {
            kilometraje = to_string(stod(kilometraje) + kilometros);
        } else {
            throw invalid_argument("Los kilómetros deben ser positivos.");
        }
    }

    bool iniciarSesion(const string& nCorreo, const string& nContraseña) const {
        return correo == nCorreo && contraseña == nContraseña;
    }

    void guardarDatos() const {
        ofstream archivo("usuarios.txt", ios::app);
        if (archivo.is_open()) {
            archivo << ID_Usuario << "," << nombre << "," << correo << "," << contraseña << "," << kilometraje << endl;
            archivo.close();
        } else {
            cerr << "Error al abrir el archivo para guardar datos." << endl;
        }
    }

    void cargarDatos(const string& linea) {
        stringstream ss(linea);
        getline(ss, ID_Usuario, ',');
        getline(ss, nombre, ',');
        getline(ss, correo, ',');
        getline(ss, kilometraje, ',');
        getline(ss, contraseña, ','); // Para mantener el orden de los datos
    }
};
