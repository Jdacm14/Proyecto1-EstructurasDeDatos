#pragma once
#include"Nodo.h"
#include<iostream>

class HistorialNavegacion {
private:
	Nodo* head;
	Nodo* tail;
	Nodo* actual;
	int limiteEntradas;// Pol�ticas de administraci�n del historial : Implemente diferentes pol�ticas para el
		//historial de navegaci�n, tales como limitar la cantidad de entradas en el historial y
		//limpiar entradas viejas despu�s de cierta cantidad de tiempo.Esto debe ser
		//personalizable

public:
	HistorialNavegacion(int limite = 10); //Revisar esto
	~HistorialNavegacion();

	void agregarPagina(std::string& url, std::string& title);
	bool puedeRetroceder();
	bool puedeAvanzar();
	Nodo* atras();
	Nodo* adelante();
	void limpiarHistorial();
	void establecerLimite(int limite);






};
