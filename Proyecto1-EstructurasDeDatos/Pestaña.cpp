#include "Pesta�a.h"

Pesta�a::Pesta�a(): incognito(false)
{
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



