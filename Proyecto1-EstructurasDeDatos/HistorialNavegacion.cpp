#include "HistorialNavegacion.h"

HistorialNavegacion::HistorialNavegacion(int limite) : actual(historial.end()), limiteEntradas(limite) {};

HistorialNavegacion::~HistorialNavegacion(){
	limpiarHistorial();
}

void HistorialNavegacion::agregarPagina(std::string& url, std::string& title){ 
    // Si no estamos en el final, eliminamos lo que viene después
    if (actual != historial.end()) {
        historial.erase(std::next(actual), historial.end());
    }

    // Agregar la nueva entrada
    historial.push_back({ url, title });
    actual = std::prev(historial.end());

    // Limitar el tamaño del historial
    if (historial.size() > limiteEntradas) {
        historial.pop_front();
    }
    
}

std::pair<std::string, std::string> HistorialNavegacion::obtenerPaginaActual()
{
    return *actual;
}

bool HistorialNavegacion::puedeRetroceder() //faltan los demas metodos
{
	return actual != historial.begin();
}

bool HistorialNavegacion::puedeAvanzar()
{
    return actual != std::prev(historial.end());
}

void HistorialNavegacion::atras()
{
    if (puedeRetroceder())
        --actual;
}

void HistorialNavegacion::adelante()
{
    if (puedeAvanzar())
        ++actual;
}

void HistorialNavegacion::limpiarHistorial(){
    historial.clear();
}

void HistorialNavegacion::establecerLimite(int limite){
    limiteEntradas = limite;
}
