#include "SitioWeb.h"

// Constructor
SitioWeb::SitioWeb(const std::string& _url, const std::string& _titulo) : url(_url), titulo(_titulo), creacion(Clock::now()) {}

// Getters
std::string SitioWeb::getUrl() const {
    return url;
}

std::string SitioWeb::getTitulo() const {
    return titulo;
}

TimePoint SitioWeb::getCreacion() const
{
    return creacion;
}

bool SitioWeb::haExpirado() const
{
    auto ahora = std::chrono::steady_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::minutes>(ahora - creacion);
    return duracion.count() >= 5;  // Retorna true si han pasado 5 minutos o más   
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
