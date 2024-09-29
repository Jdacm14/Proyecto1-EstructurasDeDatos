#pragma once
#include <string>
#include <iostream>
#include <stdexcept>    // manejo de excepciones
#include <set> // para verificar duplicados
#include<fstream>

class SitioWeb {
private:
    std::string url;    // Atributo para la URL
    std::string dominio; // Atributo para el dominio
    std::string titulo; // Atributo para el t�tulo

public:
    // Constructor
    SitioWeb(const std::string& _url = "", const std::string& _dominio = "", const std::string& _titulo = "");

    // Getters
    std::string getUrl() const;
    std::string getDominio() const;
    std::string getTitulo() const;

    // Setters
    void setUrl(const std::string& _url);
    void setDominio(const std::string& _dominio);
    void setTitulo(const std::string& _titulo);

    // Guardar
    void guardarSitio(std::ofstream& archivo) const;

    //Cargar
    void cargarSitio(std::ifstream& archivo);

    // Mostrar informaci�n del sitio
    void mostrarInfo() const;
};
