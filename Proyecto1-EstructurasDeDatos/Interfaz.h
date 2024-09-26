#pragma once
#include"Pestaña.h"
#include"Browser.h"
#include"HistorialNavegacion.h"
#include"CSV.h"

class Interfaz {
public:
	static char buscadorPrincipal();
	static void mostrarMenu();

	static void mostrarPaginaActual(Browser& navegador);

	static void irAlSitioWeb(Browser navegador);

	static void agregarBookmark(Browser);

	static void verBookmarks(Browser);

	static void busquedaFiltros();

	static std::string incognito();

	static std::string nuevaPestania(Browser);

	static std::string configuracion();

};
