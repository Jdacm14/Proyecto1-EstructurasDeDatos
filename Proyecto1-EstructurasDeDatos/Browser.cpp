#include "Browser.h"
// Implementación de los métodos

Browser::Browser(int limite) : PestaniaActual(0), limiteHistorial(limite) { // probablemente haya que cambiar este constructor
    // Crear la primera Pestania con el límite de historial dado
    Pestanias.push_back(Pestania());
}

std::vector<Pestania>& Browser::getPestanias()
{
    return Pestanias;
}

void Browser::setPestanias(std::vector<Pestania> listaPestanias)
{
    Pestanias = listaPestanias;
}

int Browser::getPestaniaActual()
{
    return PestaniaActual;
}

Pestania& Browser::getPestaniaEnPos(int pos)
{
    return Pestanias.at(pos);
}

void Browser::setPestaniaActual(int pest)
{
    PestaniaActual = pest;
}

int Browser::getLimiteHistorial()
{
    return limiteHistorial;
}

void Browser::setLimiteHistorial(int lim){
    limiteHistorial = lim;
}

Pestania& Browser::getPestaniaActualReal()
{
    return Pestanias.at(PestaniaActual);
}


int Browser::nuevaPestania() {
    Pestanias.push_back(Pestania());  // Añadir nueva Pestania
    PestaniaActual = static_cast<int>(Pestanias.size()) - 1;
    std::cout << "Nueva Pestania creada, ahora estás en la Pestania #" << PestaniaActual << std::endl;
    return PestaniaActual;
}

void Browser::cerrarPestania(int index) {
    if (index >= 0 && index < Pestanias.size()) {
        Pestanias.erase(Pestanias.begin() + index);  // Eliminar la Pestania del vector
        PestaniaActual = (index == 0) ? 0 : index - 1;  // Cambiar a la Pestania anterior si se cierra la actual
        std::cout << "Pestania cerrada, ahora estás en la Pestania #" << PestaniaActual << std::endl;
    }
    else {
        std::cout << "Índice de Pestania inválido" << std::endl;
    }
}

void Browser::cambiarPestania(int index) {
    if (index >= 0 && index < Pestanias.size()) {
        PestaniaActual = index;
        std::cout << "Cambiado a la Pestania #" << index << std::endl;
    }
    else {
        std::cout << "Índice de Pestania inválido" << std::endl;
    }
}

bool Browser::existeSigPes()
{
    if (PestaniaActual == (int)Pestanias.size()-1) {
        return false;
    }
    return true;
}


bool Browser::irAtras() {
    return Pestanias[PestaniaActual].anteriorPag();
}

bool Browser::irAdelante() {
   return Pestanias[PestaniaActual].siguientePag();
}

void Browser::limpiarHistorialPestaniaActual() {
    Pestanias[PestaniaActual].limpiarHistorialVentana();
}

void Browser::agregarBookmarkPestaniaActual(Bookmark b)
{
    Pestanias.at(PestaniaActual).agregarBookmark(b);
}

void Browser::mostrarBookmarksPestaniaActual()
{
    Pestanias.at(PestaniaActual).mostrarBookmarks();
}

void Browser::activarIncognitoPestaniaActual() {
    Pestanias[PestaniaActual].activarIncognito();
    std::cout << "Modo incognito activado en la Pestania #" << PestaniaActual << std::endl;
}

void Browser::desactivarIncognitoPestaniaActual() {
    Pestanias[PestaniaActual].desactivarIncognito();
    std::cout << "Modo incognito desactivado en la Pestania #" << PestaniaActual << std::endl;
}

void Browser::mostrarTodosBookmarks()
{
    for (Pestania p : Pestanias) {
        p.mostrarBookmarks();
    }
}

void Browser::mostrarPestanias() {
    std::cout << "=== Pestanias abiertas ===" << std::endl;
    for (size_t i = 0; i < Pestanias.size(); ++i) {
        std::cout << "Pestania #" << i;
        if (i == PestaniaActual) {
            std::cout << " (actual)";
        }
        std::cout << std::endl;
    }
}
