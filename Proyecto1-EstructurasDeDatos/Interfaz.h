#pragma once
#include"Pestaña.h"
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

	static void mostrarPaginaActual(Browser& navegador);

	static void irAlSitioWeb(Browser& navegador);

	static void agregarBookmark(Browser&);

	static void verBookmarks(Browser&);

	static void busquedaFiltros(Browser&);

	static std::string incognito(Browser&);

	static std::string nuevaPestania(Browser&);

	static std::string configuracion();

	static void cambiarPestania(Browser&, int);

	static void cambiarHistorial(Browser&, int);

};
