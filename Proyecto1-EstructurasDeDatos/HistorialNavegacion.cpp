#include "HistorialNavegacion.h"
#include <iterator> 

// Constructor
HistorialNavegacion::HistorialNavegacion(int limite) : limiteEntradas(limite) {
    historial = new std::list<SitioWeb*>();  // Crear din�micamente la lista de sitios web
    actual = historial->end();  // Inicialmente, no hay p�ginas, as� que 'actual' apunta a 'end()'
}

//// Constructor copia
//HistorialNavegacion(HistorialNavegacion&& other) noexcept {
//    historial = std::move(other.historial);
//    actual = historial.begin();
//}
//
//// Operador de asignaci�n por movimiento
//HistorialNavegacion& operator=(HistorialNavegacion&& other) noexcept {
//    if (this != &other) {
//        historial = std::move(other.historial);
//        actual = historial.begin();
//    }
//    return *this;
//}


// Destructor
HistorialNavegacion::~HistorialNavegacion() {
    
      for (auto sitio : *historial) {
          delete sitio;  // Liberar la memoria de cada sitio web
      }
      delete historial;  // Liberar el contenedor de la lista
   
}

// Agregar una página al historial
void HistorialNavegacion::agregarPagina(SitioWeb* sitio) {
    if (historial->size() >= limiteEntradas) {
        delete historial->front();  // Liberar memoria del primer elemento si alcanzamos el límite
        historial->pop_front();  // Eliminar el primer elemento
    }
    historial->push_back(sitio);  // Agregar la nueva página
    actual = --historial->end();  // Apuntar el iterador al último elemento
}



// Obtener la página actual

SitioWeb* HistorialNavegacion::obtenerPaginaActual() {
    SitioWeb* sitio = new SitioWeb(" ", " ", " ");
    if (historial->empty() || actual == historial->end()) {
        return sitio;  // Si el historial está vacío o el iterador es inválido, devolver nullptr

//SitioWeb& HistorialNavegacion::obtenerPaginaActual() {
    //static SitioWeb sitioNulo("404 - Not Found", "Pagina no encontrada");  // Objeto estático para un sitio nulo
    //if (historial.empty()  || actual == historial.end()) {
        //return sitioNulo;  // Devolver el sitio nulo si no hay páginas en el historial

    }
    return *actual;  // Devolver el sitio web actual
}

std::list<SitioWeb*>* HistorialNavegacion::getHistorialList() const
{
    return historial;
}


size_t HistorialNavegacion::getHistorialSize() const
{
    return historial->size(); 
}


bool HistorialNavegacion::estaVacio()
{
    return historial->empty();

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

void HistorialNavegacion::setActualAlUltimo()
{
    if (!historial->empty()) {
        actual = std::prev(historial->end());  // Siempre apunta al �ltimo si no est� vac�o
    }
    else {
        actual = historial->end();  // Si est� vac�o, apunta al end()
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

void HistorialNavegacion::eliminarSitiosWeb()
{
    historial.erase(std::remove_if(historial.begin(), historial.end(), [&](const SitioWeb& sitio) {
        return sitio.haExpirado();
    }), historial.end());
}

void HistorialNavegacion::setPaginaActual(int n)
{
    if (historial->empty()) {
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
    return actual != historial->begin();
}

// Verificar si se puede avanzar
bool HistorialNavegacion::puedeAvanzar() {
    return actual != historial->end() && std::next(actual) != historial->end();
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
    historial->clear();
    actual = historial->end();
}

// Establecer el l�mite de entradas del historial
void HistorialNavegacion::establecerLimite(int limite) {
    limiteEntradas = limite;
}

size_t HistorialNavegacion::getHistorialSize() {
    return historial->size();
}

//std::list<std::pair<std::string, std::string>> HistorialNavegacion::obtenerHistorial() {
//    std::list<std::pair<std::string, std::string>> historialLista; 
//    std::set<std::pair<std::string, std::string>> agregadas;
//    for (const auto& pagina : historial) {
//        auto entrada = std::make_pair(pagina.getTitulo(), pagina.getUrl()); // Crea un par con titulo y utl
//        if (agregadas.find(entrada) == agregadas.end()) {
//            historialLista.emplace_back(entrada);
//            agregadas.insert(entrada);
//        }
//    }
//    return historialLista;
//}

void HistorialNavegacion::guardarEnBinario(const std::string& nombreArchivo) const{
    std::ofstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar el historial." << std::endl;
        return;
    }

    // Escribir el n�mero de sitios en el historial
    size_t numSitios = historial->size();
    archivo.write(reinterpret_cast<const char*>(&numSitios), sizeof(numSitios));

    // Recorrer la lista de sitios web y guardar solo las URLs
    for (const auto& sitio : *historial) {
        std::string url = sitio->getUrl();  // Obtener la URL del sitio web
        size_t longitudUrl = url.size();  // Obtener la longitud de la URL

        // Escribir la longitud de la URL
        archivo.write(reinterpret_cast<const char*>(&longitudUrl), sizeof(longitudUrl));

        // Escribir la URL
        archivo.write(url.c_str(), longitudUrl);
    }

    archivo.close();
}

void HistorialNavegacion::cargarDesdeBinario(const std::string& nombreArchivo) {
    CSV csv;

    // Cargar los sitios desde el archivo CSV
    if (!csv.cargarSitiosDesdeCSV("sitiosWeb.csv")) {  // M�todo que carga sitios desde un archivo CSV
        std::cerr << "Error al cargar los sitios web desde el archivo CSV." << std::endl;
        return;
    }

    std::ifstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para cargar el historial." << std::endl;
        return;
    }

    // Limpiar el historial actual para cargar los nuevos datos
    for (auto sitio : *historial) {
        delete sitio;  // Liberar la memoria de los sitios almacenados
    }
    historial->clear();  // Limpiar la lista

    // Leer el n�mero de sitios en el historial
    size_t numSitios;
    archivo.read(reinterpret_cast<char*>(&numSitios), sizeof(numSitios));

    // Recorrer el archivo para leer cada sitio web
    for (size_t i = 0; i < numSitios; ++i) {
        // Leer la longitud de la URL
        size_t longitudUrl;
        archivo.read(reinterpret_cast<char*>(&longitudUrl), sizeof(longitudUrl));

        // Leer la URL
        std::string url(longitudUrl, ' ');
        archivo.read(&url[0], longitudUrl);

        // Buscar el sitio web en la lista de sitios utilizando la clase CSV
        SitioWeb* sitioEncontrado = csv.buscarSitioPorURL(url);  // M�todo que busca el sitio por su URL

        if (sitioEncontrado != nullptr) {
            // Si se encuentra el sitio, lo a�adimos al historial
            historial->push_back(sitioEncontrado);
            actual = historial->begin();
        }
        else {
            std::cerr << "Error: No se encontr� un sitio web para la URL: " << url << std::endl;
        }
    }

    archivo.close();
}


std::list<SitioWeb>& HistorialNavegacion::getHistorial() {
    return historial;
}

