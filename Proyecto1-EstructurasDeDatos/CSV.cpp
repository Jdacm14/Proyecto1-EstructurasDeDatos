#include "CSV.h"

// Cargar sitios desde el archivo CSV
bool CSV::cargarSitiosDesdeCSV(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        return false;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream ss(linea);
        std::string url, dominio, titulo;

        // Supongamos que los valores están separados por comas
        std::getline(ss, url, ',');
        std::getline(ss, dominio, ',');
        std::getline(ss, titulo, ',');

        // Crear un nuevo objeto SitioWeb dinámicamente
        SitioWeb* nuevoSitio = new SitioWeb(url, dominio, titulo);

        // Agregar el puntero al vector
        sitiosWeb.push_back(nuevoSitio);
    }

    file.close();
    return true;
}

// Buscar una URL en los sitios cargados
SitioWeb* CSV::buscarSitioPorURL(const std::string& url) {
    for (const auto& sitio : sitiosWeb) {
        if (sitio->getUrl() == url) {
            return sitio;
        }
    }

    // Crear un sitio "404 - Not Found" estático
    static SitioWeb sitioNoEncontrado(url, "404 - Not Found");
    return &sitioNoEncontrado;
}
