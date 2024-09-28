#pragma once
#include <string>
#include "Windows.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <vector>

class Pestaña {
public:
	Pestaña();


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

	void siguientePag();
	void anteriorPag();


private:
	std::vector<Bookmark> bookmarks;
	bool incognito;
	HistorialNavegacion historial;
};