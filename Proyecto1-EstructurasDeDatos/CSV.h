#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Definir una estructura para almacenar los datos del sitio web
struct SitioWeb {
    std::string urlCompleto;
    std::string dominio;
    std::string titulo;
};

class CSV {
private:
    // Vector para almacenar objetos SitioWeb
    std::vector<SitioWeb> sitiosWeb;

public:
    // Cargar sitios desde el archivo CSV
    bool cargarSitiosDesdeCSV(std::string& archivo);
    // Buscar una URL en los sitios cargados
    std::pair<std::string, std::string> buscarSitioPorURL(std::string & url);
     
};

