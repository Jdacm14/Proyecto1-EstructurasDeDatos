#pragma once
#include"Nodo.h"
#include<iostream>

class HistorialNavegacion {
private:
	Nodo* head;
	Nodo* tail;
	Nodo* actual;
	int limiteEntradas;// Políticas de administración del historial : Implemente diferentes políticas para el
		//historial de navegación, tales como limitar la cantidad de entradas en el historial y
		//limpiar entradas viejas después de cierta cantidad de tiempo.Esto debe ser
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
