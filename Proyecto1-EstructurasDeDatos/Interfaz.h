#pragma once
#include"Pestaña.h"
#include"Browser.h"
#include"HistorialNavegacion.h"
#include"CSV.h"
#include<conio.h>

class Interfaz {
public:
	static char buscadorPrincipal(Browser&);
	static void mostrarMenu();

	static void mostrarPaginaActual(Browser& navegador);

	static void irAlSitioWeb(Browser& navegador);

	static void agregarBookmark(Browser&);

	static void verBookmarks(Browser&);

	static void busquedaFiltros(Browser&);

	static std::string incognito();

	static std::string nuevaPestania(Browser&);

	static std::string configuracion();

};
