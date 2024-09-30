#include "Pestania.h"

Pestania::Pestania(): incognito(false)
{
	historial = HistorialNavegacion();
}

HistorialNavegacion& Pestania::getHistorial()
{
	return historial;
}

void Pestania::setHistorial(HistorialNavegacion histo)
{
	historial = histo;
}

std::vector<Bookmark>& Pestania::geVectortBookmarks()
{
	return bookmarks;
}

void Pestania::agregarBookmark(Bookmark bo)
{
	bookmarks.push_back(bo);
}


void Pestania::mostrarBookmarks()
{
	for (Bookmark b : bookmarks) {
		std::cout << b.toString() << std::endl;
	}
}

void Pestania::activarIncognito()
{
	incognito = true;
}

void Pestania::desactivarIncognito()
{
	incognito = false;
}

bool Pestania::getEstadoIncognito()
{
	return incognito;
}



void Pestania::limpiarHistorialVentana()
{
	historial.limpiarHistorial();
}

bool Pestania::siguientePag()
{
		if (historial.puedeAvanzar()) {
			return true;
		}
		return false;
}

bool Pestania::anteriorPag()
{
	if (historial.puedeRetroceder()) {
		return true;
	}
	return false;
}

