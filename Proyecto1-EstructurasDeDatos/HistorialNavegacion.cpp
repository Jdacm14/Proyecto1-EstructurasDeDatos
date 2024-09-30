#include "HistorialNavegacion.h"

// Constructor
HistorialNavegacion::HistorialNavegacion(int limite) : limiteEntradas(limite) {
    actual = historial.end();  // Inicialmente no hay ninguna página

}

// Destructor
HistorialNavegacion::~HistorialNavegacion() {
    limpiarHistorial();
}

std::list<SitioWeb>::iterator HistorialNavegacion::Getactual()
{
    return actual;
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
    static SitioWeb sitioNulo("404 - Not Found", "Pagina no encontrada");  // Objeto estático para un sitio nulo
    if (historial.empty()  || actual == historial.end()) {
        return sitioNulo;  // Devolver el sitio nulo si no hay páginas en el historial
    }
    
    return *actual;
}

std::list<SitioWeb> HistorialNavegacion::getLista()
{
    return historial;
}


void HistorialNavegacion::setMinutosTodosSitios(int n)
{
    
    for (SitioWeb& sitio : historial) {
        sitio.setTiempo(n);
    }
}

void HistorialNavegacion::setearActualAlPrincipio()
{
    if (historial.size() >= 1) {
        actual = std::prev(historial.end());
    }
    else {
        actual = actual;
    }
}

// elimnina el sitio web, según tiempo
void HistorialNavegacion::eliminarSitiosWeb()
{
    historial.erase(std::remove_if(historial.begin(), historial.end(), [&](const SitioWeb& sitio) {
        return sitio.haExpirado();
    }), historial.end());

}

// setea la pagina actual
void HistorialNavegacion::setPaginaActual(int n)
{
    if (historial.empty()) {
        return;
    }
    if (n == 75) {
        actual = std::prev(actual);
    }
    else if(n==77){
        actual = std::next(actual);
    }
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

size_t HistorialNavegacion::getHistorialSize() {
    return historial.size();
}

std::list<std::pair<std::string, std::string>> HistorialNavegacion::obtenerHistorial() {
    std::list<std::pair<std::string, std::string>> historialLista; 
    std::set<std::pair<std::string, std::string>> agregadas;
    for (const auto& pagina : historial) {
        auto entrada = std::make_pair(pagina.getUrl(), pagina.getTitulo()); // Crea un par con titulo y utl
        if (agregadas.find(entrada) == agregadas.end()) {
            historialLista.emplace_back(entrada);
            agregadas.insert(entrada);
        }
    }
    return historialLista;
}

std::list<SitioWeb>& HistorialNavegacion::getHistorial() {
    return historial;
}