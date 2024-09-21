#pragma once
#include <string>
#include "Windows.h"
#include "HistorialNavegacion.h"

class Pestaña {
public:
	Pestaña();
	void activarIncognito();
	void desactivarIncognito();
	bool getEstadoIncognito();

	void limpiarHistorialVentana();

	void siguientePag();
	void anteriorPag();


private:
	//std::string urlActual;
	bool incognito;
	HistorialNavegacion historial;
};