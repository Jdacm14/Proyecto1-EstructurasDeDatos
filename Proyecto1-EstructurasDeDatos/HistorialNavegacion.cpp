#include "HistorialNavegacion.h"
#include <stdexcept>


// Constructor
HistorialNavegacion::HistorialNavegacion(int limite) : limiteEntradas(limite) {
    actual = historial.end();  // Inicialmente no hay ninguna página

}

// Destructor
HistorialNavegacion::~HistorialNavegacion() {
    limpiarHistorial();
}

// Agregar una página al historial
void HistorialNavegacion::agregarPagina(const SitioWeb& sitio) {
    // Agregar la nueva página al final
    historial.push_back(sitio);
    actual = std::prev(historial.end());  // Actualizar el iterador actual al último elemento

    // Limitar el tamaño del historial si excede el límite
    //while (historial.size() > static_cast<std::size_t>(limiteEntradas)) {
    //    historial.pop_front();  // Eliminar la página más antigua
    //}
}



// Obtener la página actual
SitioWeb& HistorialNavegacion::obtenerPaginaActual() {
    static SitioWeb sitioNulo("404 - Not Found", "Página no encontrada");  // Objeto estático para un sitio nulo
    if (historial.empty()) {
        return sitioNulo;  // Devolver el sitio nulo si no hay páginas en el historial
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

// Retroceder una página
void HistorialNavegacion::atras() {
    if (puedeRetroceder()) {
        --actual;
    }
    else {
        throw std::out_of_range("No se puede retroceder más.");
    }
}

// Avanzar una página
void HistorialNavegacion::adelante() {
    if (puedeAvanzar()) {
        ++actual;
    }
    else {
        throw std::out_of_range("No se puede avanzar más.");
    }
}

// Limpiar el historial
void HistorialNavegacion::limpiarHistorial() {
    historial.clear();
    actual = historial.end();
}

// Establecer el límite de entradas del historial
void HistorialNavegacion::establecerLimite(int limite) {
    limiteEntradas = limite;
}
