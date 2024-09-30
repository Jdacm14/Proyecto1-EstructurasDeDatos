#pragma once
#include <list>
#include "SitioWeb.h"
#include<algorithm>


class HistorialNavegacion {
private:
    std::list<SitioWeb> historial;  // Usamos std::list para manejar los sitios web
    std::list<SitioWeb>::iterator actual;  // Iterador para la página actual
    int limiteEntradas;  // Límite de entradas en el historial

public:
    HistorialNavegacion(int limite = 10);  // Constructor
    ~HistorialNavegacion();  // Destructor


    std::list<SitioWeb>::iterator Getactual();
    // Métodos
    void agregarPagina(const SitioWeb& sitio);
    SitioWeb& obtenerPaginaActual();
    std::list<SitioWeb> getLista();

    void setMinutosTodosSitios(int);
    void setearActualAlPrincipio();
    void eliminarSitiosWeb();
    void setPaginaActual(int);
    bool puedeRetroceder();
    bool puedeAvanzar();
    void atras();
    void adelante();
    void limpiarHistorial();
    void establecerLimite(int limite);
    size_t getHistorialSize();
    std::list<std::pair<std::string, std::string>> obtenerHistorial();
    std::list<SitioWeb>& getHistorial();

};

