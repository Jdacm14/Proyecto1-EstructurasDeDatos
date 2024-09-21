#include "HistorialNavegacion.h"

HistorialNavegacion::HistorialNavegacion(int limite) : head(nullptr), tail(nullptr), actual(nullptr), limiteEntradas(limite) {};

HistorialNavegacion::~HistorialNavegacion(){
	limpiarHistorial();
}

void HistorialNavegacion::agregarPagina(std::string& url, std::string& title){ // esto es un insertar al final de la lista
	Nodo* nuevo = new Nodo(url, title);
  

    if (!head) {
        head = tail = actual = nuevo;
    }
    else {
        // Si no estamos al final del historial, eliminar nodos hacia adelante
        if (actual->next) {
            Nodo* temp = actual->next;
            while (temp) {
                Nodo* siguiente = temp->next;
                delete temp;
                temp = siguiente;
            }
            actual->next = nullptr;
            tail = actual;
        }

        // Enlazar el nuevo nodo
        actual->next = nuevo;
        nuevo->prev = actual;
        actual = nuevo;
        tail = nuevo;
    }
}

bool HistorialNavegacion::puedeRetroceder() //faltan los demas metodos
{
	return false;
}

bool HistorialNavegacion::puedeAvanzar()
{
	return false;
}

Nodo* HistorialNavegacion::atras()
{
	return nullptr;
}

Nodo* HistorialNavegacion::adelante()
{
	return nullptr;
}

void HistorialNavegacion::limpiarHistorial()
{
}

void HistorialNavegacion::establecerLimite(int limite)
{
}
