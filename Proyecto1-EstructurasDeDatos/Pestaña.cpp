#include "Pesta�a.h"

Pesta�a::Pesta�a(): incognito(false)
{
	historial = HistorialNavegacion();
}

HistorialNavegacion& Pesta�a::getHistorial()
{
	return historial;
}

void Pesta�a::setHistorial(HistorialNavegacion histo)
{
	historial = histo;
}

std::vector<Bookmark>& Pesta�a::geVectortBookmarks()
{
	return bookmarks;
}

void Pesta�a::agregarBookmark(Bookmark bo)
{
	bookmarks.push_back(bo);
}


void Pesta�a::mostrarBookmarks()
{
	for (Bookmark b : bookmarks) {
		std::cout << b.toString() << std::endl;
	}
}

void Pesta�a::activarIncognito()
{
	incognito = true;
}

void Pesta�a::desactivarIncognito()
{
	incognito = false;
}

bool Pesta�a::getEstadoIncognito()
{
	return incognito;
}

void Pesta�a::limpiarHistorialVentana()
{
	historial.limpiarHistorial();
}

bool Pesta�a::siguientePag()
{
		if (historial.puedeAvanzar()) {
			return true;
		}
		return false;
}

bool Pesta�a::anteriorPag()
{
	if (historial.puedeRetroceder()) {
		return true;
	}
	return false;
}



