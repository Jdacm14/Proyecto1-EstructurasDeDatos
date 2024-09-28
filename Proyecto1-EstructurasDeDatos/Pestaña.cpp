#include "Pestaña.h"

Pestaña::Pestaña(): incognito(false)
{
	historial = HistorialNavegacion();
}

HistorialNavegacion& Pestaña::getHistorial()
{
	return historial;
}

void Pestaña::setHistorial(HistorialNavegacion histo)
{
	historial = histo;
}

std::vector<Bookmark>& Pestaña::geVectortBookmarks()
{
	return bookmarks;
}

void Pestaña::agregarBookmark(Bookmark bo)
{
	bookmarks.push_back(bo);
}


void Pestaña::mostrarBookmarks()
{
	for (Bookmark b : bookmarks) {
		std::cout << b.toString() << std::endl;
	}
}

void Pestaña::activarIncognito()
{
	incognito = true;
}

void Pestaña::desactivarIncognito()
{
	incognito = false;
}

bool Pestaña::getEstadoIncognito()
{
	return incognito;
}

void Pestaña::limpiarHistorialVentana()
{
	historial.limpiarHistorial();
}

bool Pestaña::siguientePag()
{
		if (historial.puedeAvanzar()) {
			return true;
		}
		return false;
}

bool Pestaña::anteriorPag()
{
	if (historial.puedeRetroceder()) {
		return true;
	}
	return false;
}



