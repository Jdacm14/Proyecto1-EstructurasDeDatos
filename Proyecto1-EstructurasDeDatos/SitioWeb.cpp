#include "SitioWeb.h"

// Constructor
SitioWeb::SitioWeb(const std::string& _url, const std::string& _titulo) : url(_url), titulo(_titulo) {}

// Getters
std::string SitioWeb::getUrl() const {
    return url;
}

std::string SitioWeb::getTitulo() const {
    return titulo;
}

// Setters
void SitioWeb::setUrl(const std::string& _url) {
    url = _url;
}

void SitioWeb::setTitulo(const std::string& _titulo) {
    titulo = _titulo;
}

// Mostrar información del sitio
void SitioWeb::mostrarInfo() const {
    std::cout << "URL: " << url << ", Título: " << titulo << std::endl;
}
