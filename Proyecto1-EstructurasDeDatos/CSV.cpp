#include "CSV.h"

bool CSV::cargarSitiosDesdeCSV(std::string& archivo)
{
    std::ifstream file(archivo);
    std::string linea;

    if (!file.is_open()) {
        std::cout << "No se pudo abrir el archivo: " << archivo << std::endl;
        return false;
    }

    while (getline(file, linea)) {
        std::stringstream ss(linea);
        std::string url, dominio, titulo;

        getline(ss, url, ',');      // Leer URL completo
        getline(ss, dominio, ',');  // Leer el dominio
        getline(ss, titulo, ',');   // Leer el título

        // Crear un objeto de la estructura SitioWeb y almacenar los datos
        SitioWeb sitio;
        sitio.urlCompleto = url;
        sitio.dominio = dominio;
        sitio.titulo = titulo;

        // Almacenar el sitio web en el vector
        sitiosWeb.push_back(sitio);
    }

    file.close();
    return true;
}

std::pair<std::string, std::string> CSV::buscarSitioPorURL(std::string& url)
{
    for (auto& sitio : sitiosWeb) {
        if (sitio.urlCompleto == url) {
            // Devolver URL completo y título como un par
            return std::make_pair(sitio.urlCompleto, sitio.titulo);
        }
    }

    // Si no se encuentra la URL, devolver un par con un mensaje de error
    return std::make_pair("", "404 - Not Found");
}
