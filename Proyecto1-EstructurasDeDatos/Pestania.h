#pragma once
#include <string>
#include "Windows.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <vector>

class Pestania {
public:
	Pestania();


	HistorialNavegacion& getHistorial();
	void setHistorial(HistorialNavegacion);
	std::vector<Bookmark>& geVectortBookmarks();
	
	//void agregarSitioWeb();


	void agregarBookmark(Bookmark);
	void mostrarBookmarks();
	void activarIncognito();
	void desactivarIncognito();
	bool getEstadoIncognito();
	

	void limpiarHistorialVentana();

	bool siguientePag();
	bool anteriorPag();


private:
	std::vector<Bookmark> bookmarks;
	bool incognito;
	HistorialNavegacion historial;
};