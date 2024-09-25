#pragma once
#include <string>
#include "Windows.h"
#include "HistorialNavegacion.h"
#include "Bookmark.h"
#include <vector>

class Pestaña {
public:
	Pestaña();
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