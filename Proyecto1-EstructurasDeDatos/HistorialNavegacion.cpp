#include "HistorialNavegacion.h"

HistorialNavegacion::HistorialNavegacion(int limite) : actual(historial.begin()), limiteEntradas(limite) {};

HistorialNavegacion::~HistorialNavegacion(){
	limpiarHistorial();
}


void HistorialNavegacion::agregarPagina(std::string& url, std::string& title) {
     //Si no estamos al final, eliminamos todo lo que sigue al iterador actual
    if (actual != historial.end()) {
        historial.erase(std::next(actual), historial.end());
    }

    // Agregar la nueva entrada al historial
    historial.push_back({ url, title });
    actual = std::prev(historial.end()); // Actualizar 'actual' al último elemento

    // Limitar el tamaño del historial si supera el límite
    if (historial.size() > static_cast<std::size_t>(limiteEntradas)) {
        // Si el iterador 'actual' apunta al primer elemento, actualízalo después de pop_front()
        if (actual == historial.begin()) {
            historial.pop_front();
            actual = historial.begin(); // Reasignar a la nueva primera entrada
        }
        else {
            historial.pop_front();
            actual = std::prev(historial.end()); // Si no está al inicio, reasigna a la nueva última entrada
        }
    }
}

//
//void HistorialNavegacion::agregarPagina(std::string& url, std::string& title){ 
//    // Si no estamos en el final, eliminamos lo que viene después
//    if (actual != historial.end()) {
//        historial.erase(std::next(actual), historial.end());
//    }
//
//    // Agregar la nueva entrada
//    historial.push_back({ url, title });
//    actual = std::prev(historial.end());
//
//    // Limitar el tamaño del historial
//    if (historial.size() > static_cast<std::size_t>(limiteEntradas)) {
//        historial.pop_front();
//        actual = historial.end();
//    }
//}

std::pair<std::string, std::string> HistorialNavegacion::obtenerPaginaActual()
{
    std::pair<std::string, std::string> null_pair = { "", "" };

    if ( historial.empty() || actual == historial.end()) {
        std::cout << "No hay pagina actual" << std::endl;
    }
    else {
        return *actual;
    }

    return null_pair;
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
