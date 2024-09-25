#pragma once
#include<string>
#include<list>
#include<iostream>

class HistorialNavegacion {
private:
	std::list<std::pair<std::string, std::string>> historial;
	std::list<std::pair<std::string, std::string >> ::iterator actual;
	int limiteEntradas;// Políticas de administración del historial : Implemente diferentes políticas para el
		//historial de navegación, tales como limitar la cantidad de entradas en el historial y
		//limpiar entradas viejas después de cierta cantidad de tiempo.Esto debe ser
		//personalizable

public:
	HistorialNavegacion(int limite = 10); //Revisar esto
	~HistorialNavegacion();

	void agregarPagina(std::string& url, std::string& title);
	std::pair<std::string, std::string> obtenerPaginaActual();
	bool puedeRetroceder();
	bool puedeAvanzar();
	void atras();
	void adelante();
	void limpiarHistorial();
	void establecerLimite(int limite);






};
