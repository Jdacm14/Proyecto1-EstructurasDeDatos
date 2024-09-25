#pragma once
#include "Browser.h"
#include "Interfaz.h"
class Controladora
{
private:
	Browser* browser;
	char opcion;

public:
	Controladora();
	virtual ~Controladora();
	void msjOpcionNoValida();

	//------------------------------------
	void controlMenuGeneral();

	


};
