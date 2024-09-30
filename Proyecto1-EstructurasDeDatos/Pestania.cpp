#include "Pestania.h"

// constructor
Pestania::Pestania(): incognito(false)
{
	historial = HistorialNavegacion();
}

// getters y setters
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

// agrega un nuevo bookmark al vector de bookmarks
void Pestania::agregarBookmark(Bookmark bo)
{
	bookmarks.push_back(bo);
}

// muestra los bookmarks de la pestaña
void Pestania::mostrarBookmarks()
{
	for (Bookmark b : bookmarks) {
		std::cout << b.toString() << std::endl;
	}
}

// activa el incognito
void Pestania::activarIncognito()
{
	incognito = true;
}

// lo desactiva
void Pestania::desactivarIncognito()
{
	incognito = false;
}

// get del incognito
bool Pestania::getEstadoIncognito()
{
	return incognito;
}

// limpia el historia de la pestaña
void Pestania::limpiarHistorialVentana()
{
	historial.limpiarHistorial();
}

// verifica que se pueda avanzar 
bool Pestania::siguientePag()
{
		if (historial.puedeAvanzar()) {
			return true;
		}
		return false;
}

// verifica que se pueda retroceder
bool Pestania::anteriorPag()
{
	if (historial.puedeRetroceder()) {
		return true;
	}
	return false;
}
