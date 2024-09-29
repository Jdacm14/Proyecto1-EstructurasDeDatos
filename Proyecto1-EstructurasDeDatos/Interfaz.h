#pragma once
#include"Pestania.h"
#include"Browser.h"
#include"HistorialNavegacion.h"
#include"CSV.h"
#include<conio.h>

#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ESC 27

class Interfaz {
public:
	static char buscadorPrincipal(Browser&);
	static void mostrarMenu();


	static void mostrarPaginaActual(Browser&);


	static void irAlSitioWeb(Browser& navegador);

	static void agregarBookmark(Browser&);

	static void verBookmarks(Browser&);

	static void busquedaFiltros(Browser&);

	static std::string incognito(Browser&);


	static void nuevaPestania(Browser&);

	static void importarYExportar(Browser&);

	static void exportarSesion(Browser&);

	static void importarSesion(Browser&);

	static std::string nuevaPestania(Browser&);


	static void configuracion(Browser&);

	static void cambiarPestania(Browser&, int);

	static void cambiarHistorial(Browser&, int);

	static void eliminarSitios(Browser&);

};
