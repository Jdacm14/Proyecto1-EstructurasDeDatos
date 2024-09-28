#include "Browser.h"
// Implementaci�n de los m�todos

Browser::Browser(int limite) : pesta�aActual(0), limiteHistorial(limite) { // probablemente haya que cambiar este constructor
    // Crear la primera pesta�a con el l�mite de historial dado
    pesta�as.push_back(Pesta�a());
}

std::vector<Pesta�a>& Browser::getPesta�as()
{
    return pesta�as;
}

void Browser::setPesta�as(std::vector<Pesta�a> listaPesta�as)
{
    pesta�as = listaPesta�as;
}

int Browser::getPesta�aActual()
{
    return pesta�aActual;
}

Pesta�a& Browser::getPesta�aEnPos(int pos)
{
    return pesta�as.at(pos);
}

void Browser::setPesta�aActual(int pest)
{
    pesta�aActual = pest;
}

int Browser::getLimiteHistorial()
{
    return limiteHistorial;
}

void Browser::setLimiteHistorial(int lim){
    limiteHistorial = lim;
}

Pesta�a& Browser::getPesta�aActualReal()
{
    return pesta�as.at(pesta�aActual);
}


void Browser::nuevaPesta�a() {
    pesta�as.push_back(Pesta�a());  // A�adir nueva pesta�a
    pesta�aActual = (int) pesta�as.size() - 1;
    std::cout << "Nueva pesta�a creada, ahora est�s en la pesta�a #" << pesta�aActual << std::endl;
}

void Browser::cerrarPesta�a(int index) {
    if (index >= 0 && index < pesta�as.size()) {
        pesta�as.erase(pesta�as.begin() + index);  // Eliminar la pesta�a del vector
        pesta�aActual = (index == 0) ? 0 : index - 1;  // Cambiar a la pesta�a anterior si se cierra la actual
        std::cout << "Pesta�a cerrada, ahora est�s en la pesta�a #" << pesta�aActual << std::endl;
    }
    else {
        std::cout << "�ndice de pesta�a inv�lido" << std::endl;
    }
}

void Browser::cambiarPesta�a(int index) {
    if (index >= 0 && index < pesta�as.size()) {
        pesta�aActual = index;
        std::cout << "Cambiado a la pesta�a #" << index << std::endl;
    }
    else {
        std::cout << "�ndice de pesta�a inv�lido" << std::endl;
    }
}

bool Browser::existeSigPes()
{
    if (pesta�aActual == (int)pesta�as.size()-1) {
        return false;
    }
    return true;
}


bool Browser::irAtras() {
    return pesta�as[pesta�aActual].anteriorPag();
}

bool Browser::irAdelante() {
   return pesta�as[pesta�aActual].siguientePag();
}

void Browser::limpiarHistorialPesta�aActual() {
    pesta�as[pesta�aActual].limpiarHistorialVentana();
}

void Browser::agregarBookmarkPesta�aActual(Bookmark b)
{
    pesta�as.at(pesta�aActual).agregarBookmark(b);
}

void Browser::mostrarBookmarksPesta�aActual()
{
    pesta�as.at(pesta�aActual).mostrarBookmarks();
}

void Browser::activarIncognitoPesta�aActual() {
    pesta�as[pesta�aActual].activarIncognito();
    std::cout << "Modo inc�gnito activado en la pesta�a #" << pesta�aActual << std::endl;
}

void Browser::desactivarIncognitoPesta�aActual() {
    pesta�as[pesta�aActual].desactivarIncognito();
    std::cout << "Modo inc�gnito desactivado en la pesta�a #" << pesta�aActual << std::endl;
}

void Browser::mostrarTodosBookmarks()
{
    for (Pesta�a p : pesta�as) {
        p.mostrarBookmarks();
    }
}

void Browser::mostrarPesta�as() {
    std::cout << "=== Pesta�as abiertas ===" << std::endl;
    for (size_t i = 0; i < pesta�as.size(); ++i) {
        std::cout << "Pesta�a #" << i;
        if (i == pesta�aActual) {
            std::cout << " (actual)";
        }
        std::cout << std::endl;
    }
}
