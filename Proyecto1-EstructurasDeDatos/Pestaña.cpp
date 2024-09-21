#include "Pestaña.h"

Pestaña::Pestaña(): incognito(false)
{
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



