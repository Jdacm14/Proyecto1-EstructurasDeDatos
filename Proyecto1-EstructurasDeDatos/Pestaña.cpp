#include "Pesta�a.h"

Pesta�a::Pesta�a(): incognito(false)
{
	historial = HistorialNavegacion();
}

HistorialNavegacion Pesta�a::getHistorial()
{
	return historial;
}

void Pesta�a::setHistorial(HistorialNavegacion histo)
{
	historial = histo;
}

std::vector<Bookmark> Pesta�a::geVectortBookmarks()
{
	return std::vector<Bookmark>();
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

void Pesta�a::siguientePag()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		if (historial.puedeAvanzar()) {
			historial.adelante();
		}
	}
}

void Pesta�a::anteriorPag()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		if (historial.puedeRetroceder()) {
			historial.atras();
		}
	}
}



