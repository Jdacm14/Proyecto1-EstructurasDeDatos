#pragma once
#include <list>
#include <iterator> 
#include "SitioWeb.h"


class HistorialNavegacion {
private:
    std::list<SitioWeb> historial;  // Usamos std::list para manejar los sitios web
    std::list<SitioWeb>::iterator actual;  // Iterador para la página actual
    int limiteEntradas;  // Límite de entradas en el historial

public:
    HistorialNavegacion(int limite = 10);  // Constructor
    ~HistorialNavegacion();  // Destructor

    // Métodos
    void agregarPagina(const SitioWeb& sitio);
    SitioWeb& obtenerPaginaActual();

    bool estaVacio();
    void setActualAlUltimo();
    void setPaginaActual(int);
    bool puedeRetroceder();
    bool puedeAvanzar();
    void atras();
    void adelante();
    void limpiarHistorial();
    void establecerLimite(int limite);
    size_t getHistorialSize();
    std::list<std::pair<std::string, std::string>> obtenerHistorial();

    //Guardar
    void guardarEnBinario(std::ofstream& archivo) const;

    //Cargar
    void cargarDesdeBinario(std::ifstream& archivo);

};
