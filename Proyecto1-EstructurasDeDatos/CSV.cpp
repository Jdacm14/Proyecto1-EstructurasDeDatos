#include "CSV.h"

// Cargar sitios desde el archivo CSV
bool CSV::cargarSitiosDesdeCSV(const std::string& archivo) {
    std::ifstream file(archivo);
    std::string linea;

    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << archivo << std::endl;
        return false;
    }

    // Limpiar cualquier contenido anterior en el vector de sitios web
    if (!sitiosWeb.empty()) {
        sitiosWeb.clear();
    }

    // Leer cada l�nea del archivo CSV
    while (std::getline(file, linea)) {
        std::stringstream ss(linea);
        std::string url, titulo;

        // Leer la URL y el t�tulo separados por comas
        if (std::getline(ss, url, ',') && std::getline(ss, titulo, ',')) {
            // Crear un objeto SitioWeb y agregarlo al vector
            sitiosWeb.push_back(SitioWeb(url, titulo));
        }
        else {
            std::cerr << "Formato incorrecto en: " << linea << std::endl;
        }
    }

    file.close();
    return true;
}

// Buscar una URL en los sitios cargados
SitioWeb CSV::buscarSitioPorURL(const std::string& url) {
    for (const auto& sitio : sitiosWeb) {
        if (sitio.getUrl() == url) {
            return sitio;  // Devolver el objeto SitioWeb si la URL coincide
        }
    }

    // Si no se encuentra, devolver un sitio con mensaje "404 - Not Found"
    return SitioWeb(url, "404 - Not Found");
}
