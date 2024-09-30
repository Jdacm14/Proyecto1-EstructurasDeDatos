#pragma once
#include <string>
#include <vector>
#include <iostream>
#include<sstream>
#include<fstream>

class Bookmark {
private:
    std::string url;
    std::string title;
    std::vector<std::string> etiquetas;

public:
    Bookmark(const std::string&, const std::string&);
    void agregarEtiqueta(std::string&);
    void mostrarEtiquetas();
    bool tieneEtiqueta(std::string&);
    std::string getURL();
    std::string getTitle();

    //Guardar
    void guardarEnBinario(std::ofstream& archivo) const;

    //Cargar
    void cargarDesdeBinario(std::ifstream& archivo);


    std::string toString();

};










