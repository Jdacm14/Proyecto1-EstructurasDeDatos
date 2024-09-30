#include "SitioWeb.h"

// Constructor
SitioWeb::SitioWeb(const std::string& _url, const std::string& _titulo, const std::string& dom) : url(_url), titulo(_titulo), dominio(dom), creacion(Clock::now()), tiempo(5) {}

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

int SitioWeb::getTiempo() const
{
    return tiempo;
}

void SitioWeb::setTiempo(int t)
{
    this->tiempo = t;
}

void SitioWeb::setCreacion(TimePoint t)
{
    creacion = t;
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

void SitioWeb::setTitulo(const std::string& _titulo) {
    titulo = _titulo;
}

// Mostrar información del sitio
void SitioWeb::mostrarInfo() const {
    std::cout << "URL: " << url << ", Título: " << titulo << std::endl;
}

void SitioWeb::guardarArchivoSitioWeb(std::ofstream& out)
{
    size_t urlLength = url.length();
    out.write(reinterpret_cast<const char*>(&urlLength), sizeof(urlLength));
    out.write(url.c_str(), urlLength);

    size_t tituloLength = titulo.length();
    out.write(reinterpret_cast<const char*>(&tituloLength), sizeof(tituloLength));
    out.write(titulo.c_str(), tituloLength);

    size_t dominioLength = dominio.length();
    out.write(reinterpret_cast<const char*>(&dominioLength), sizeof(dominioLength));
    out.write(dominio.c_str(), dominioLength);


}

SitioWeb SitioWeb::cargarArchivoSitioWeb(std::ifstream& in)
{
    size_t urlT;
    size_t _titulo; 
    size_t _domT;

    in.read(reinterpret_cast<char*>(&urlT), sizeof(urlT));
    std::string url(urlT, ' ');
    in.read(&url[0], urlT);

    in.read(reinterpret_cast<char*>(&_titulo), sizeof(_titulo));
    std::string titulo(_titulo, ' ');
    in.read(&titulo[0], _titulo);

    in.read(reinterpret_cast<char*>(&_domT), sizeof(_domT));
    std::string dominio(_domT, ' ');
    in.read(&dominio[0], _domT);

    SitioWeb sitio(url, titulo, dominio);

    return sitio;

}

