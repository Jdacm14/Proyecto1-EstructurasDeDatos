#pragma once
#include <string>
#include <iostream>

class SitioWeb {
private:
    std::string url;    // Atributo para la URL
    std::string titulo; // Atributo para el título

public:
    // Constructor
    SitioWeb(const std::string& _url = "", const std::string& _titulo = "");

    // Getters
    std::string getUrl() const;
    std::string getTitulo() const;

    // Setters
    void setUrl(const std::string& _url);
    void setTitulo(const std::string& _titulo);

    // Mostrar información del sitio
    void mostrarInfo() const;
};
