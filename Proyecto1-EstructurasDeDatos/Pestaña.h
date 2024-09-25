#pragma once
#include <string>
#include "Windows.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <vector>

class Pesta�a {
public:
	Pesta�a();
	void agregarBookmark(std::string&, std::string&);
	void agregarEtiquetaBook(std::string&, std::string&);
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