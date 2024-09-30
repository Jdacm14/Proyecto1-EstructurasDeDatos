#include "SitioWeb.h"
#include <vector>

// Constructor

SitioWeb::SitioWeb(const std::string& _url, const std::string& _dominio, const std::string& _titulo) : url(_url), dominio(_dominio), titulo(_titulo), creacion(Clock::now()), tiempo(5){}

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

TimePoint SitioWeb::getCreacion() const
{
    return creacion;
}

int SitioWeb::getTiempo() const
{
    return tiempo;
}

void SitioWeb::setTiempo(int t)
{
    this->tiempo = t;
}

bool SitioWeb::haExpirado() const
{
    auto ahora = std::chrono::steady_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::minutes>(ahora - creacion);

    return duracion.count() >= this->tiempo;  // Retorna true si ha pasado el tiempo que se ha establecido  

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
    // Guardar la longitud y el contenido de la URL
    size_t urlSize = url.size();
    archivo.write(reinterpret_cast<const char*>(&urlSize), sizeof(urlSize));  // Guardar la longitud de la URL
    archivo.write(url.c_str(), urlSize);  // Guardar el contenido de la URL

    // Guardar la longitud y el contenido del dominio
    size_t dominioSize = dominio.size();
    archivo.write(reinterpret_cast<const char*>(&dominioSize), sizeof(dominioSize));  // Guardar la longitud del dominio
    archivo.write(dominio.c_str(), dominioSize);  // Guardar el contenido del dominio

    // Guardar la longitud y el contenido del t�tulo
    size_t tituloSize = titulo.size();
    archivo.write(reinterpret_cast<const char*>(&tituloSize), sizeof(tituloSize));  // Guardar la longitud del t�tulo
    archivo.write(titulo.c_str(), tituloSize);  // Guardar el contenido del t�tulo
}

void SitioWeb::cargarSitio(std::ifstream& archivo) {
    if (archivo.is_open()) {
        // Leer longitud de la URL y luego la URL
        size_t longitudUrl;
        archivo.read(reinterpret_cast<char*>(&longitudUrl), sizeof(longitudUrl));
       /* url.resize(longitudUrl);*/
        /*archivo.read(&url[0], longitudUrl);*/

        // Leer longitud del dominio y luego el dominio
        size_t longitudDominio;
        archivo.read(reinterpret_cast<char*>(&longitudDominio), sizeof(longitudDominio));
       /* dominio.resize(longitudDominio);*/
        /*archivo.read(&dominio[0], longitudDominio);*/

        // Leer longitud del t�tulo y luego el t�tulo
        size_t longitudTitulo;
        archivo.read(reinterpret_cast<char*>(&longitudTitulo), sizeof(longitudTitulo));
        /*titulo.resize(longitudTitulo);*/
        /*archivo.read(&titulo[0], longitudTitulo);*/
    }
    else {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
    }
}


// Mostrar informaci�n del sitio
void SitioWeb::mostrarInfo() const {
    std::cout << "URL: " << url << ", T�tulo: " << titulo << std::endl;
}
