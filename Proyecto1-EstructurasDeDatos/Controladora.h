#pragma once
#include "Browser.h"
#include "Interfaz.h"
#include<condition_variable>

class Controladora
{
private:
	Browser* browser;
	char opcion;
	std::condition_variable cv;

public:
	Controladora();
	virtual ~Controladora();
	void msjOpcionNoValida();
	void verificarSitiosEliminados();

	//------------------------------------
	void controlMenuGeneral();

};
