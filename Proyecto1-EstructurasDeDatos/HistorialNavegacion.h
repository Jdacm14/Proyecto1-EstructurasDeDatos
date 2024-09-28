#pragma once
#include <list>
#include "SitioWeb.h"


class HistorialNavegacion {
private:
    std::list<SitioWeb> historial;  // Usamos std::list para manejar los sitios web
    std::list<SitioWeb>::iterator actual;  // Iterador para la p�gina actual
    int limiteEntradas;  // L�mite de entradas en el historial

public:
    HistorialNavegacion(int limite = 10);  // Constructor
    ~HistorialNavegacion();  // Destructor

    // M�todos
    void agregarPagina(const SitioWeb& sitio);
    SitioWeb& obtenerPaginaActual();
    bool puedeRetroceder();
    bool puedeAvanzar();
    void atras();
    void adelante();
    void limpiarHistorial();
    void establecerLimite(int limite);
    size_t getHistorialSize();
    std::list<std::pair<std::string, std::string>> obtenerHistorial();

};
