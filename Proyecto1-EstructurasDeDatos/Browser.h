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
    void agregarBookmarkPestañaActual(std::string& url, std::string& title);
    void mostrarBookmarksPestañaActual();

    // Modo incógnito
    void activarIncognitoPestañaActual();
    void desactivarIncognitoPestañaActual();

    // Mostrar información sobre pestañas
    void mostrarPestañas();
};

