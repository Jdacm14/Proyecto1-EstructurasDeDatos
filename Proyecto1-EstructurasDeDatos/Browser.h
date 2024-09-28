#pragma once
#include <vector>
#include "Pestania.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <iostream>
#include<windows.h>

class Browser {
private:
    std::vector<Pestania> Pestanias;    // Lista de Pestanias abiertas
    int PestaniaActual;                // �ndice de la Pestania actual
    int limiteHistorial;              // L�mite global para el historial de cada Pestania

public:
    Browser(int limiteHistorial = 10);

    std::vector <Pestania>& getPestanias();
    void setPestanias(std::vector<Pestania>);
    int getPestaniaActual();
    Pestania& getPestaniaEnPos(int);
    void setPestaniaActual(int);
    int getLimiteHistorial();
    void setLimiteHistorial(int);

    Pestania& getPestaniaActualReal();

    // Manejo de Pestanias
    int nuevaPestania();
    void cerrarPestania(int index);
    void cambiarPestania(int index);
    bool existeSigPes();

    // Navegaci�n en la Pestania actual
    bool irAtras();
    bool irAdelante();

    // Historial
    void limpiarHistorialPestaniaActual();

    // Gesti�n de bookmarks
    void agregarBookmarkPestaniaActual(Bookmark);
    void mostrarBookmarksPestaniaActual();

    // Modo inc�gnito
    void activarIncognitoPestaniaActual();
    void desactivarIncognitoPestaniaActual();

    void mostrarTodosBookmarks();

    // Mostrar informaci�n sobre Pestanias
    void mostrarPestanias();
};

