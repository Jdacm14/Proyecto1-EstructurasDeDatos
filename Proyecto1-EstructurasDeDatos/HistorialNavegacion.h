#pragma once
#include <list>
#include <iterator> 
#include "SitioWeb.h"
#include "CSV.h"
#include<algorithm>



class HistorialNavegacion {
private:
    std::list<SitioWeb*>* historial;  // Usamos std::list para manejar los sitios web
    std::list<SitioWeb*>::iterator actual;  // Iterador para la pï¿½gina actual
    int limiteEntradas;  // Lï¿½mite de entradas en el historial

public:
    HistorialNavegacion(int limite = 10);  // Constructor
    ~HistorialNavegacion();  // Destructor


    std::list<SitioWeb>::iterator Getactual();

    // Mï¿½todos
    void agregarPagina(SitioWeb* sitio);
    SitioWeb* obtenerPaginaActual();
    std::list<SitioWeb*>* getHistorialList() const;
    size_t getHistorialSize() const;

    bool estaVacio();
    void setActualAlUltimo();

    // Métodos
    //void agregarPagina(const SitioWeb& sitio);
    //SitioWeb& obtenerPaginaActual();
    //std::list<SitioWeb> getLista();

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
    std::list<SitioWeb*>* getHistorial();

    //Guardar
    void guardarEnBinario(const std::string& nombreArchivo) const;

    //Cargar
    void cargarDesdeBinario(const std::string& nombreArchivo);

};
