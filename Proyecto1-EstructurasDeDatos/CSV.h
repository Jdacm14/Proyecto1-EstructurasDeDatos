#pragma once
#include <fstream>
#include "SitioWeb.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class CSV {
private:
    // Vector para almacenar objetos SitioWeb
    std::vector<SitioWeb*> sitiosWeb;

public:
    // Cargar sitios desde el archivo CSV
    bool cargarSitiosDesdeCSV(const std::string& archivo);

    // Buscar una URL en los sitios cargados
    SitioWeb* buscarSitioPorURL(const std::string& url);
};

