#pragma once
#include <list>
#include <iterator> 
#include "SitioWeb.h"
#include "CSV.h"


class HistorialNavegacion {
private:
    std::list<SitioWeb*>* historial;  // Usamos std::list para manejar los sitios web
    std::list<SitioWeb*>::iterator actual;  // Iterador para la p�gina actual
    int limiteEntradas;  // L�mite de entradas en el historial

public:
    HistorialNavegacion(int limite = 10);  // Constructor
    ~HistorialNavegacion();  // Destructor


    std::list<SitioWeb>::iterator Getactual();
    // M�todos
    void agregarPagina(SitioWeb* sitio);
    SitioWeb* obtenerPaginaActual();
    std::list<SitioWeb*>* getHistorialList() const;
    size_t getHistorialSize() const;

    bool estaVacio();
    void setActualAlUltimo();
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

    //Guardar
    void guardarEnBinario(const std::string& nombreArchivo) const;

    //Cargar
    void cargarDesdeBinario(const std::string& nombreArchivo);

};
