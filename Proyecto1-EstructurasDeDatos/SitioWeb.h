#pragma once
#include <string>
#include <iostream>
#include<chrono>    //para el temporalizador de los sitios
#include <stdexcept>    // manejo de excepciones
#include <set> // para verificar duplicados
#include<thread>
#include<memory>

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;

class SitioWeb {
private:
    std::string url;    // Atributo para la URL
    std::string titulo; // Atributo para el título
    TimePoint creacion;
    int tiempo;
public:
    // Constructor
    SitioWeb(const std::string& _url = "", const std::string& _titulo = "");

    // Getters
    std::string getUrl() const;
    std::string getTitulo() const;
    TimePoint getCreacion() const;
    int getTiempo() const;
    void setTiempo(int);

    bool haExpirado() const;

    // Setters
    void setUrl(const std::string& _url);
    void setTitulo(const std::string& _titulo);

    // Mostrar información del sitio
    void mostrarInfo() const;
};
