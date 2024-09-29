#include "HistorialNavegacion.h"
#include <iterator> 

// Constructor
HistorialNavegacion::HistorialNavegacion(int limite) : limiteEntradas(limite) {
    actual = historial.end();  // Inicialmente no hay ninguna página

}

//// Constructor copia
//HistorialNavegacion(HistorialNavegacion&& other) noexcept {
//    historial = std::move(other.historial);
//    actual = historial.begin();
//}
//
//// Operador de asignación por movimiento
//HistorialNavegacion& operator=(HistorialNavegacion&& other) noexcept {
//    if (this != &other) {
//        historial = std::move(other.historial);
//        actual = historial.begin();
//    }
//    return *this;
//}


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

    // Si es la primera página, asegúrate de que el iterador apunte al único elemento
    if (!historial.empty()) {
        actual = std::prev(historial.end());  // Actualizar el iterador actual al último elemento
    }
    // Limitar el tamaño del historial si excede el límite
    //while (historial.size() > static_cast<std::size_t>(limiteEntradas)) {
    //    historial.pop_front();  // Eliminar la página más antigua
    //}
}



// Obtener la página actual
SitioWeb& HistorialNavegacion::obtenerPaginaActual() {
    static SitioWeb sitioNulo("404 - Not Found", "Página no encontrada");  // Objeto estático para un sitio nulo
    if (historial.empty() || actual == historial.end()) {
        return sitioNulo;  // Devolver el sitio nulo si no hay páginas en el historial o el iterador es inválido
    }
  
    return *actual;
}


bool HistorialNavegacion::estaVacio()
{
    return historial.empty();
}

void HistorialNavegacion::setActualAlUltimo()
{
    if (!historial.empty()) {
        actual = std::prev(historial.end());  // Siempre apunta al último si no está vacío
    }
    else {
        actual = historial.end();  // Si está vacío, apunta al end()
    }
  
void HistorialNavegacion::setearActualAlPrincipio()
{
    actual = std::prev(historial.end());
}

void HistorialNavegacion::eliminarSitiosWeb()
{
    TimePoint ahora = Clock::now();

    auto duracionExpiracion = std::chrono::minutes(5);

    historial.erase(std::remove_if(historial.begin(), historial.end(), [&](const SitioWeb& sitio) {
        return(ahora - sitio.getCreacion()) >= duracionExpiracion;
    }), historial.end());
}

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

void HistorialNavegacion::guardarEnBinario(std::ofstream& archivo) const {
    // Guardar el tamaño del historial
    size_t historialSize = historial.size();
    std::cout << "Guardando historial de tamaño: " << historialSize << std::endl;
    archivo.write(reinterpret_cast<const char*>(&historialSize), sizeof(historialSize));

    // Guardar cada sitio web del historial
    for (const auto& sitio : historial) {
        std::cout << "Guardando sitio: " << sitio.getUrl() << ", " << sitio.getTitulo() << std::endl;
        sitio.guardarSitio(archivo);  // Usamos el método de SitioWeb para guardar
    }

    // Guardar el índice del iterador 'actual' manualmente
    if (historial.empty()) {
        int pos = -1;  // Si está vacío, ponemos un valor especial
        archivo.write(reinterpret_cast<const char*>(&pos), sizeof(pos));
        std::cout << "El historial está vacío, guardando posición del iterador: " << pos << std::endl;
    }
    else {
        // Recorrer manualmente la lista para encontrar la posición del iterador 'actual'
        int pos = 0;
        for (auto it = historial.begin(); it != historial.end(); ++it) {
            if (it == actual) {
                break;
            }
            ++pos;  // Contamos cuántos elementos hemos pasado
        }
        archivo.write(reinterpret_cast<const char*>(&pos), sizeof(pos));
        std::cout << "Guardando posición del iterador actual: " << pos << std::endl;
    }

    // Guardar el límite de entradas
    archivo.write(reinterpret_cast<const char*>(&limiteEntradas), sizeof(limiteEntradas));
    std::cout << "Guardando límite de entradas: " << limiteEntradas << std::endl;
}

void HistorialNavegacion::cargarDesdeBinario(std::ifstream& archivo) {
    // Leer el tamaño del historial
    size_t historialSize;
    archivo.read(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));
    std::cout << "Cargando historial de tamaño: " << historialSize << std::endl;

    // Limpiar el historial antes de cargar
    historial.clear();

    // Cargar cada sitio web en el historial
    for (size_t i = 0; i < historialSize; ++i) {
        SitioWeb sitio("", "");
        sitio.cargarSitio(archivo);
        historial.push_back(sitio);
        std::cout << "Cargando sitio: " << sitio.getUrl() << ", " << sitio.getTitulo() << std::endl;
    }

    // Colocar el iterador 'actual' al inicio del historial
    if (historial.empty()) {
        actual = historial.end();  // No hay páginas
        std::cout << "El historial está vacío. El iterador se ajusta a historial.end()." << std::endl;
    }
    else {
        actual = (historial.begin());  // El iterador apunta al inicio
        std::cout << "El iterador se ha colocado al inicio del historial." << std::endl;
    }

    // Leer el límite de entradas
    archivo.read(reinterpret_cast<char*>(&limiteEntradas), sizeof(limiteEntradas));
    std::cout << "Límite de entradas cargado: " << limiteEntradas << std::endl;
}
