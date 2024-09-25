#include "Pestaña.h"

Pestaña::Pestaña(): incognito(false)
{
	historial = HistorialNavegacion();
}

HistorialNavegacion Pestaña::getHistorial()
{
	return historial;
}

void Pestaña::setHistorial(HistorialNavegacion histo)
{
	historial = histo;
}

std::vector<Bookmark> Pestaña::geVectortBookmarks()
{
	return std::vector<Bookmark>();
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

void Pestaña::siguientePag()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		if (historial.puedeAvanzar()) {
			historial.adelante();
		}
	}
}

void Pestaña::anteriorPag()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		if (historial.puedeRetroceder()) {
			historial.atras();
		}
	}
}



