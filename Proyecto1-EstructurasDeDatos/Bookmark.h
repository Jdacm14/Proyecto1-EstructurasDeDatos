#pragma once
#include <string>
#include <vector>
#include <iostream>
#include<sstream>

class Bookmark {
private:
    std::string url;
    std::string title;
    std::vector<std::string> etiquetas;

public:
    Bookmark(const std::string, const std::string);
    void agregarEtiqueta(const std::string&);
    void mostrarEtiquetas();
    bool tieneEtiqueta(const std::string&);
    std::string getURL();
    std::string getTitle();
    std::string toString();
};










