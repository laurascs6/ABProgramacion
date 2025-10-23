#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <string>

class Vehiculo {
private:
    std::string matricula;
    std::string tipoVehiculo;
    std::string marca;
    std::string modelo;
    int añoFabricacion;
    double precio;
    std::string ultimaITV;
    double kilometrajeInicial;
    double capacidadCombustible;
    std::string etiquetaAmbiental;
    std::string eficienciaEnergetica;
    std::string tipoCombustible;

    // Función auxiliar para validar tipo de combustible
    bool esCombustibleValido(const std::string& combustible) const;

public:
    // Constructores
    Vehiculo();
    Vehiculo(const std::string& matricula, const std::string& tipoVehiculo,
             const std::string& marca, const std::string& modelo,
             int añoFabricacion, double precio, const std::string& ultimaITV,
             double kilometrajeInicial, double capacidadCombustible,
             const std::string& etiquetaAmbiental,
             const std::string& eficienciaEnergetica,
             const std::string& tipoCombustible);

    // Getters
    std::string getMatricula() const;
    std::string getTipoVehiculo() const;
    std::string getMarca() const;
    std::string getModelo() const;
    int getAñoFabricacion() const;
    double getPrecio() const;
    std::string getUltimaITV() const;
    double getKilometrajeInicial() const;
    double getCapacidadCombustible() const;
    std::string getEtiquetaAmbiental() const;
    std::string getEficienciaEnergetica() const;
    std::string getTipoCombustible() const;

    // Setters con validación
    void setPrecio(double nuevoPrecio);
    void setUltimaITV(const std::string& nuevaFecha);
    void setKilometrajeInicial(double nuevoKilometraje);
    void setTipoCombustible(const std::string& nuevoTipo);

    // Mostrar información
    std::string toString() const;
};

#endif
