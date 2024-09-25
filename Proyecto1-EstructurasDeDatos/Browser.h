#pragma once
#include <vector>
#include "Pesta�a.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <iostream>

class Browser {
private:
    std::vector<Pesta�a> pesta�as;    // Lista de pesta�as abiertas
    int pesta�aActual;                // �ndice de la pesta�a actual
    int limiteHistorial;              // L�mite global para el historial de cada pesta�a

public:
    Browser(int limiteHistorial = 10);

    // Manejo de pesta�as
    void nuevaPesta�a();
    void cerrarPesta�a(int index);
    void cambiarPesta�a(int index);

    // Navegaci�n en la pesta�a actual
    void irAtras();
    void irAdelante();

    // Historial
    void limpiarHistorialPesta�aActual();

    // Gesti�n de bookmarks
    void agregarBookmarkPesta�aActual(std::string& url, std::string& title);
    void mostrarBookmarksPesta�aActual();

    // Modo inc�gnito
    void activarIncognitoPesta�aActual();
    void desactivarIncognitoPesta�aActual();

    // Mostrar informaci�n sobre pesta�as
    void mostrarPesta�as();
};

