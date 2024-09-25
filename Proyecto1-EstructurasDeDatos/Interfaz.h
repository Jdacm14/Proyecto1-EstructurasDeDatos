#pragma once
#include"Pesta�a.h"
#include"Browser.h"
#include"HistorialNavegacion.h"
#include"CSV.h"

class Interfaz {
public:
	static char buscadorPrincipal();
	void Interfaz::mostrarMenu();

	static void mostrarPaginaActual(Browser& navegador);

	static void irAlSitioWeb(Browser navegador);

	static void agregarBookmark();

	static void verBookmarks();

	static void busquedaFiltros();

	static std::string incognito();

	static std::string nuevaPestania();

	static std::string configuracion();




};
