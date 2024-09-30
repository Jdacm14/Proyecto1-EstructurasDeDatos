#pragma once
#include <vector>
#include "Pestania.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <mutex>

class Browser {
private:
    std::vector<Pestania> Pestanias;    // Lista de Pestanias abiertas
    int PestaniaActual;                // Índice de la Pestania actual
    int limiteHistorial;              // Límite global para el historial de cada Pestania
    std::mutex mtx;

public:
    Browser(int limiteHistorial = 10);

    std::vector <Pestania>& getPestanias();
    void setPestanias(std::vector<Pestania>);
    int getPestaniaActual();
    Pestania& getPestaniaEnPos(int);
    void setPestaniaActual(int);
    int getLimiteHistorial();
    void setLimiteHistorial(int);
    void setMinutosDeTodasLasPest(int);

    Pestania& getPestaniaActualReal();

    bool haysitios();
    void agregarSitioWeb(const SitioWeb&);
    // Manejo de Pestanias
    int nuevaPestania();
    void cerrarPestania(int index);
    void cambiarPestania(int index);
    bool existeSigPes();

    // Navegación en la Pestania actual
    bool irAtras();
    bool irAdelante();

    // Historial
    void limpiarHistorialPestaniaActual();

    // Gestión de bookmarks
    void agregarBookmarkPestaniaActual(Bookmark);
    void mostrarBookmarksPestaniaActual();

    // Modo incógnito
    void activarIncognitoPestaniaActual();
    void desactivarIncognitoPestaniaActual();

    void mostrarTodosBookmarks();

    // Mostrar información sobre Pestanias
    void mostrarPestanias();

    //Exportar/Serializar datos
    void exportarSesion(const std::string&);

    //Importar/Deserializar datos
    void importarSesion(const std::string&);

    void verificarSitios();
};

