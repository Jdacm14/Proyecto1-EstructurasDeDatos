#include "SitioWeb.h"

// Constructor
SitioWeb::SitioWeb(const std::string& _url,const std::string& _dominio, const std::string& _titulo) : url(_url),dominio(_dominio), titulo(_titulo) {}

// Getters
std::string SitioWeb::getUrl() const {
    return url;
}

std::string SitioWeb::getDominio() const
{
    return dominio;
}

std::string SitioWeb::getTitulo() const {
    return titulo;
}

// Setters
void SitioWeb::setUrl(const std::string& _url) {
    url = _url;
}

void SitioWeb::setDominio(const std::string& _dominio)
{
    dominio = _dominio;
}

void SitioWeb::setTitulo(const std::string& _titulo) {
    titulo = _titulo;
}

void SitioWeb::guardarSitio(std::ofstream& archivo) const {
    if (!archivo.is_open()) {
        throw std::runtime_error("No se puede escribir en el archivo binario.");
    }

    size_t urlSize = url.size();
    size_t dominioSize = dominio.size();
    size_t tituloSize = titulo.size();

    archivo.write(reinterpret_cast<const char*>(&urlSize), sizeof(urlSize));
    archivo.write(url.c_str(), urlSize);

    archivo.write(reinterpret_cast<const char*>(&dominioSize), sizeof(dominioSize));
    archivo.write(dominio.c_str(), dominioSize);

    archivo.write(reinterpret_cast<const char*>(&tituloSize), sizeof(tituloSize));
    archivo.write(titulo.c_str(), tituloSize);

    if (archivo.fail()) {
        throw std::runtime_error("Error al escribir en el archivo binario.");
    }
}

void SitioWeb::cargarSitio(std::ifstream& archivo) {
    if (!archivo.is_open()) {
        throw std::runtime_error("No se puede leer del archivo binario.");
    }

    size_t urlSize, dominioSize, tituloSize;

    archivo.read(reinterpret_cast<char*>(&urlSize), sizeof(urlSize));
    if (archivo.fail()) throw std::runtime_error("Error al leer tamaño de URL.");

    url.resize(urlSize);
    archivo.read(&url[0], urlSize);
    if (archivo.fail()) throw std::runtime_error("Error al leer URL.");

    archivo.read(reinterpret_cast<char*>(&dominioSize), sizeof(dominioSize));
    if (archivo.fail()) throw std::runtime_error("Error al leer tamaño de dominio.");

    dominio.resize(dominioSize);
    archivo.read(&dominio[0], dominioSize);
    if (archivo.fail()) throw std::runtime_error("Error al leer dominio.");

    archivo.read(reinterpret_cast<char*>(&tituloSize), sizeof(tituloSize));
    if (archivo.fail()) throw std::runtime_error("Error al leer tamaño de título.");

    titulo.resize(tituloSize);
    archivo.read(&titulo[0], tituloSize);
    if (archivo.fail()) throw std::runtime_error("Error al leer título.");
}


// Mostrar información del sitio
void SitioWeb::mostrarInfo() const {
    std::cout << "URL: " << url << ", Título: " << titulo << std::endl;
}
