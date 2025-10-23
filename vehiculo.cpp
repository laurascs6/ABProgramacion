#include "Vehiculo.hpp"
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm> // para transformar texto a minúsculas


//  Función auxiliar: obtener el año actual del sistema
int obtenerAñoActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return (now->tm_year + 1900);
}

// ======================================================
//  Función auxiliar: comprobar si el combustible es válido
// ======================================================
bool Vehiculo::esCombustibleValido(const std::string& combustible) const {
    std::string c = combustible;
    // pasamos a minúsculas para comparar sin errores
    std::transform(c.begin(), c.end(), c.begin(), ::tolower);

    return (c == "gasolina" || c == "diesel" || c == "diésel" || 
            c == "híbrido" || c == "hibrido" || c == "eléctrico" || c == "electrico");
}

// ======================================================
//  Constructor por defecto
// ======================================================
Vehiculo::Vehiculo()
    : añoFabricacion(0), precio(0.0), kilometrajeInicial(0.0), capacidadCombustible(0.0),
      tipoCombustible("Gasolina") {} // por defecto gasolina

// ======================================================
//  Constructor con validaciones completas
// ======================================================
Vehiculo::Vehiculo(const std::string& matricula, const std::string& tipoVehiculo,
                   const std::string& marca, const std::string& modelo,
                   int añoFabricacion, double precio, const std::string& ultimaITV,
                   double kilometrajeInicial, double capacidadCombustible,
                   const std::string& etiquetaAmbiental,
                   const std::string& eficienciaEnergetica,
                   const std::string& tipoCombustible)
{
    int añoActual = obtenerAñoActual();

    this->matricula = matricula.empty() ? "DESCONOCIDA" : matricula;
    this->tipoVehiculo = tipoVehiculo.empty() ? "No especificado" : tipoVehiculo;
    this->marca = marca.empty() ? "Desconocida" : marca;
    this->modelo = modelo.empty() ? "Desconocido" : modelo;

    // Validar año
    if (añoFabricacion < 1886 || añoFabricacion > añoActual) {
        std::cerr << "[Aviso] Año de fabricación inválido. Se establece a 2000.\n";
        this->añoFabricacion = 2000;
    } else {
        this->añoFabricacion = añoFabricacion;
    }

    // Validar precio
    if (precio < 0) {
        std::cerr << "[Aviso] Precio negativo. Se establece a 0.\n";
        this->precio = 0.0;
    } else {
        this->precio = precio;
    }

    this->ultimaITV = ultimaITV.empty() ? "No registrada" : ultimaITV;

    // Validar kilometraje
    if (kilometrajeInicial < 0) {
        std::cerr << "[Aviso] Kilometraje negativo. Se establece a 0.\n";
        this->kilometrajeInicial = 0.0;
    } else {
        this->kilometrajeInicial = kilometrajeInicial;
    }

    // Validar capacidad combustible
    if (capacidadCombustible <= 0) {
        std::cerr << "[Aviso] Capacidad de combustible inválida. Se establece a 50L.\n";
        this->capacidadCombustible = 50.0;
    } else {
        this->capacidadCombustible = capacidadCombustible;
    }

    this->etiquetaAmbiental = etiquetaAmbiental.empty() ? "Desconocida" : etiquetaAmbiental;
    this->eficienciaEnergetica = eficienciaEnergetica.empty() ? "Sin datos" : eficienciaEnergetica;

    // Validar tipo de combustible
    if (!esCombustibleValido(tipoCombustible)) {
        std::cerr << "[Error] Tipo de combustible inválido o vacío. Se establece a 'Gasolina'.\n";
        this->tipoCombustible = "Gasolina";
    } else {
        this->tipoCombustible = tipoCombustible;
    }
}

// ======================================================
//  Getters
// ======================================================
std::string Vehiculo::getMatricula() const { return matricula; }
std::string Vehiculo::getTipoVehiculo() const { return tipoVehiculo; }
std::string Vehiculo::getMarca() const { return marca; }
std::string Vehiculo::getModelo() const { return modelo; }
int Vehiculo::getAñoFabricacion() const { return añoFabricacion; }
double Vehiculo::getPrecio() const { return precio; }
std::string Vehiculo::getUltimaITV() const { return ultimaITV; }
double Vehiculo::getKilometrajeInicial() const { return kilometrajeInicial; }
double Vehiculo::getCapacidadCombustible() const { return capacidadCombustible; }
std::string Vehiculo::getEtiquetaAmbiental() const { return etiquetaAmbiental; }
std::string Vehiculo::getEficienciaEnergetica() const { return eficienciaEnergetica; }
std::string Vehiculo::getTipoCombustible() const { return tipoCombustible; }

// ======================================================
//  Setters con validaciones
// ======================================================
void Vehiculo::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio < 0) {
        std::cerr << "[Aviso] No se puede asignar un precio negativo.\n";
        return;
    }
    precio = nuevoPrecio;
}

void Vehiculo::setUltimaITV(const std::string& nuevaFecha) {
    if (nuevaFecha.empty()) {
        std::cerr << "[Aviso] La fecha de ITV no puede estar vacía.\n";
        return;
    }
    ultimaITV = nuevaFecha;
}

void Vehiculo::setKilometrajeInicial(double nuevoKilometraje) {
    if (nuevoKilometraje < 0) {
        std::cerr << "[Aviso] El kilometraje no puede ser negativo.\n";
        return;
    }
    kilometrajeInicial = nuevoKilometraje;
}

void Vehiculo::setTipoCombustible(const std::string& nuevoTipo) {
    if (!esCombustibleValido(nuevoTipo)) {
        std::cerr << "[Error] El tipo de combustible debe ser Gasolina, Diésel, Híbrido o Eléctrico.\n";
        return;
    }
    tipoCombustible = nuevoTipo;
}

// ======================================================
//  Mostrar información del vehículo
// ======================================================
std::string Vehiculo::toString() const {
    std::ostringstream oss;
    oss << "Matrícula: " << matricula
        << " | Tipo: " << tipoVehiculo
        << " | Marca: " << marca
        << " | Modelo: " << modelo
        << " | Año: " << añoFabricacion
        << " | Precio: " << precio << " €"
        << " | Última ITV: " << ultimaITV
        << " | Km inicial: " << kilometrajeInicial
        << " | Capacidad combustible: " << capacidadCombustible << " L"
        << " | Etiqueta: " << etiquetaAmbiental
        << " | Eficiencia: " << eficienciaEnergetica
        << " | Combustible: " << tipoCombustible;
    return oss.str();
}
