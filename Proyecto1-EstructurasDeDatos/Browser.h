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
    int PestaniaActual;                // �ndice de la Pestania actual
    int limiteHistorial;              // L�mite global para el historial de cada Pestania
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

    //Exportar/Serializar datos
    void exportarSesion(const std::string&);

    //Importar/Deserializar datos
    void importarSesion(const std::string&);

    void verificarSitios();
};

