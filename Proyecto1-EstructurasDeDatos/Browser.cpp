#include "Browser.h"
// Implementación de los métodos

Browser::Browser(int limite) : pestañaActual(0), limiteHistorial(limite) { // probablemente haya que cambiar este constructor
    // Crear la primera pestaña con el límite de historial dado
    pestañas.push_back(Pestaña());
}

std::vector<Pestaña>& Browser::getPestañas()
{
    return pestañas;
}

void Browser::setPestañas(std::vector<Pestaña> listaPestañas)
{
    pestañas = listaPestañas;
}

int Browser::getPestañaActual()
{
    return pestañaActual;
}

Pestaña& Browser::getPestañaEnPos(int pos)
{
    return pestañas.at(pos);
}

void Browser::setPestañaActual(int pest)
{
    pestañaActual = pest;
}

int Browser::getLimiteHistorial()
{
    return limiteHistorial;
}

void Browser::setLimiteHistorial(int lim){
    limiteHistorial = lim;
}

Pestaña& Browser::getPestañaActualReal()
{
    return pestañas.at(pestañaActual);
}


void Browser::nuevaPestaña() {
    pestañas.push_back(Pestaña());  // Añadir nueva pestaña
    pestañaActual = (int) pestañas.size() - 1;
    std::cout << "Nueva pestaña creada, ahora estás en la pestaña #" << pestañaActual << std::endl;
}

void Browser::cerrarPestaña(int index) {
    if (index >= 0 && index < pestañas.size()) {
        pestañas.erase(pestañas.begin() + index);  // Eliminar la pestaña del vector
        pestañaActual = (index == 0) ? 0 : index - 1;  // Cambiar a la pestaña anterior si se cierra la actual
        std::cout << "Pestaña cerrada, ahora estás en la pestaña #" << pestañaActual << std::endl;
    }
    else {
        std::cout << "Índice de pestaña inválido" << std::endl;
    }
}

void Browser::cambiarPestaña(int index) {
    if (index >= 0 && index < pestañas.size()) {
        pestañaActual = index;
        std::cout << "Cambiado a la pestaña #" << index << std::endl;
    }
    else {
        std::cout << "Índice de pestaña inválido" << std::endl;
    }
}

bool Browser::existeSigPes()
{
    if (pestañaActual == (int)pestañas.size()-1) {
        return false;
    }
    return true;
}


bool Browser::irAtras() {
    return pestañas[pestañaActual].anteriorPag();
}

bool Browser::irAdelante() {
   return pestañas[pestañaActual].siguientePag();
}

void Browser::limpiarHistorialPestañaActual() {
    pestañas[pestañaActual].limpiarHistorialVentana();
}

void Browser::agregarBookmarkPestañaActual(Bookmark b)
{
    pestañas.at(pestañaActual).agregarBookmark(b);
}

void Browser::mostrarBookmarksPestañaActual()
{
    pestañas.at(pestañaActual).mostrarBookmarks();
}

void Browser::activarIncognitoPestañaActual() {
    pestañas[pestañaActual].activarIncognito();
    std::cout << "Modo incógnito activado en la pestaña #" << pestañaActual << std::endl;
}

void Browser::desactivarIncognitoPestañaActual() {
    pestañas[pestañaActual].desactivarIncognito();
    std::cout << "Modo incógnito desactivado en la pestaña #" << pestañaActual << std::endl;
}

void Browser::mostrarTodosBookmarks()
{
    for (Pestaña p : pestañas) {
        p.mostrarBookmarks();
    }
}

void Browser::mostrarPestañas() {
    std::cout << "=== Pestañas abiertas ===" << std::endl;
    for (size_t i = 0; i < pestañas.size(); ++i) {
        std::cout << "Pestaña #" << i;
        if (i == pestañaActual) {
            std::cout << " (actual)";
        }
        std::cout << std::endl;
    }
}
