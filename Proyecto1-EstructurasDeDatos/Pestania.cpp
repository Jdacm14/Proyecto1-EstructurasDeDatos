#include "Pestania.h"

Pestania::Pestania(): incognito(false)
{
	historial = HistorialNavegacion();
}

HistorialNavegacion& Pestania::getHistorial()
{
	return historial;
}

void Pestania::setHistorial(HistorialNavegacion& histo)
{
	historial = histo;
}

std::vector<Bookmark>& Pestania::geVectortBookmarks()
{
	return bookmarks;
}

void Pestania::agregarBookmark(Bookmark& bo)
{
	bookmarks.push_back(bo);
}


void Pestania::mostrarBookmarks()
{
	for (Bookmark b : bookmarks) {
		std::cout << b.toString() << std::endl;
	}
}

void Pestania::activarIncognito()
{
	incognito = true;
}

void Pestania::desactivarIncognito()
{
	incognito = false;
}

bool Pestania::getEstadoIncognito()
{
	return incognito;
}



void Pestania::limpiarHistorialVentana()
{
	historial.limpiarHistorial();
}

bool Pestania::siguientePag()
{
		if (historial.puedeAvanzar()) {
			return true;
		}
		return false;
}

bool Pestania::anteriorPag()
{
	if (historial.puedeRetroceder()) {
		return true;
	}
	return false;
}

void Pestania::guardarEnBinario(std::ofstream& archivo) const {
	std::cout << "Guardando pestania..." << std::endl;

	// Guardar el estado de incógnito
	archivo.write(reinterpret_cast<const char*>(&incognito), sizeof(incognito));
	std::cout << "Modo incógnito: " << incognito << std::endl;

	// Guardar el historial de navegación
	std::cout << "Guardando historial de navegación..." << std::endl;
	historial.guardarEnBinario(archivo);

	// Guardar el número de bookmarks
	size_t numBookmarks = bookmarks.size();
	archivo.write(reinterpret_cast<const char*>(&numBookmarks), sizeof(numBookmarks));
	std::cout << "Número de bookmarks a guardar: " << numBookmarks << std::endl;

	// Guardar cada bookmark
	for (Bookmark bookmark : bookmarks) {
		bookmark.guardarEnBinario(archivo);
		std::cout << "Guardando bookmark: " << bookmark.getURL() << ", " << bookmark.getTitle() << std::endl;
	}
	std::cout << "Pestania guardada correctamente." << std::endl;
}


void Pestania::cargarDesdeBinario(std::ifstream& archivo) {
	std::cout << "Cargando pestania..." << std::endl;

	// Cargar el estado de incógnito
	archivo.read(reinterpret_cast<char*>(&incognito), sizeof(incognito));
	std::cout << "Modo incógnito cargado: " << incognito << std::endl;

	// Cargar el historial de navegación
	std::cout << "Cargando historial de navegación..." << std::endl;
	historial.cargarDesdeBinario(archivo);

	// Cargar el número de bookmarks
	//size_t numBookmarks;
	//archivo.read(reinterpret_cast<char*>(&numBookmarks), sizeof(numBookmarks));
	//std::cout << "Número de bookmarks a cargar: " << numBookmarks << std::endl;

	//// Limpiar la lista de bookmarks y cargar cada uno
	//bookmarks.clear();
	//for (size_t i = 0; i < numBookmarks; ++i) {
	//	Bookmark bookmark("", "");
	//	bookmark.cargarDesdeBinario(archivo);
	//	bookmarks.push_back(bookmark);
	//	std::cout << "Bookmark cargado: " << bookmark.getURL() << ", " << bookmark.getTitle() << std::endl;
	//}
	//std::cout << "Pestania cargada correctamente." << std::endl;
}




