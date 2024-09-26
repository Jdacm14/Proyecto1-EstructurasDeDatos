#pragma once
#include <vector>
#include "Pestaña.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <iostream>

class Browser {
private:
    std::vector<Pestaña> pestañas;    // Lista de pestañas abiertas
    int pestañaActual;                // Índice de la pestaña actual
    int limiteHistorial;              // Límite global para el historial de cada pestaña

public:
    Browser(int limiteHistorial = 10);

    std::vector <Pestaña> getPestañas();
    void setPestañas(std::vector<Pestaña>);
    int getPestañaActual();
    Pestaña getPestañaEnPos(int);
    void setPestañaActual(int);
    int getLimiteHistorial();
    void setLimiteHistorial(int);

    Pestaña getPestañaActualReal();

    // Manejo de pestañas
    void nuevaPestaña();
    void cerrarPestaña(int index);
    void cambiarPestaña(int index);

    // Navegación en la pestaña actual
    void irAtras();
    void irAdelante();

    // Historial
    void limpiarHistorialPestañaActual();

    // Gestión de bookmarks
    void agregarBookmarkPestañaActual(Bookmark);
    void mostrarBookmarksPestañaActual();

    // Modo incógnito
    void activarIncognitoPestañaActual();
    void desactivarIncognitoPestañaActual();

    // Mostrar información sobre pestañas
    void mostrarPestañas();
};

