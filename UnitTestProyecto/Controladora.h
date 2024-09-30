#pragma once
#include "Browser.h"
#include "Interfaz.h"
#include<atomic>

class Controladora
{
private:
	Browser* browser;
	char opcion;
	std::atomic_bool seguirVerificando;

public:
	Controladora();
	virtual ~Controladora();
	void msjOpcionNoValida();
	void verificarSitiosEliminados();

	//------------------------------------
	void controlMenuGeneral();

};
