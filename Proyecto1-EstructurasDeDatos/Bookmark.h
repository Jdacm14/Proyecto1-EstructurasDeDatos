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
    void agregarEtiqueta(std::string&);
    void mostrarEtiquetas();
    bool tieneEtiqueta(std::string&);
    std::string getURL();
    std::string getTitle();



    std::string toString();

};










