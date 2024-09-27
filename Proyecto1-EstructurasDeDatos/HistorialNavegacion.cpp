#include "HistorialNavegacion.h"
#include <stdexcept>

// Constructor
HistorialNavegacion::HistorialNavegacion(int limite) : limiteEntradas(limite) {
    actual = historial.end();  // Inicialmente no hay ninguna p�gina
}

// Destructor
HistorialNavegacion::~HistorialNavegacion() {
    limpiarHistorial();
}

// Agregar una p�gina al historial
void HistorialNavegacion::agregarPagina(const SitioWeb& sitio) {
    // Agregar la nueva p�gina al final
    historial.push_back(sitio);
    actual = std::prev(historial.end());  // Actualizar el iterador actual al �ltimo elemento

    // Limitar el tama�o del historial si excede el l�mite
    //while (historial.size() > static_cast<std::size_t>(limiteEntradas)) {
    //    historial.pop_front();  // Eliminar la p�gina m�s antigua
    //}
}


// Obtener la p�gina actual
SitioWeb HistorialNavegacion::obtenerPaginaActual() {
    if (historial.empty()) {
        return SitioWeb("", "");
    }
    return *actual;
}

// Verificar si se puede retroceder
bool HistorialNavegacion::puedeRetroceder() {
    return actual != historial.begin();
}

// Verificar si se puede avanzar
bool HistorialNavegacion::puedeAvanzar() {
    return actual != historial.end() && std::next(actual) != historial.end();
}

// Retroceder una p�gina
void HistorialNavegacion::atras() {
    if (puedeRetroceder()) {
        --actual;
    }
    else {
        throw std::out_of_range("No se puede retroceder m�s.");
    }
}

// Avanzar una p�gina
void HistorialNavegacion::adelante() {
    if (puedeAvanzar()) {
        ++actual;
    }
    else {
        throw std::out_of_range("No se puede avanzar m�s.");
    }
}

// Limpiar el historial
void HistorialNavegacion::limpiarHistorial() {
    historial.clear();
    actual = historial.end();
}

// Establecer el l�mite de entradas del historial
void HistorialNavegacion::establecerLimite(int limite) {
    limiteEntradas = limite;
}
