#include "Pestania.h"

Pestania::Pestania(): incognito(false)
{
	historial = new HistorialNavegacion();
}

Pestania::~Pestania()
{
	delete historial;
}

HistorialNavegacion* Pestania::getHistorial()
{
	return historial;
}

void Pestania::setHistorial(HistorialNavegacion* histo)
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
	if (historial) {  // Verifica que el puntero no sea nulo
		historial->limpiarHistorial();  // Accede al método usando '->' ya que es un puntero
	}
}

bool Pestania::siguientePag()
{
	return historial && historial->puedeAvanzar();
}

bool Pestania::anteriorPag()
{
	return historial && historial->puedeRetroceder();
}

void Pestania::guardarEnBinario(const std::string& nombreArchivo) const {
	// Abrir el archivo en modo binario
	std::ofstream archivo(nombreArchivo, std::ios::binary);

	if (!archivo.is_open()) {
		std::cerr << "Error al abrir el archivo para guardar el historial." << std::endl;
		return;
	}

	// Guardar el historial de navegación usando el método de HistorialNavegacion
	if (historial != nullptr) {
		historial->guardarEnBinario(nombreArchivo);  // Delegar la tarea a HistorialNavegacion
	}
	else {
		std::cerr << "No hay historial disponible para guardar." << std::endl;
	}

	// Cerrar el archivo después de guardar los datos
	archivo.close();
}


void Pestania::cargarDesdeBinario(const std::string& nombreArchivo) {
	std::ifstream archivo(nombreArchivo, std::ios::binary);

	if (!archivo.is_open()) {
		std::cerr << "Error al abrir el archivo para cargar los datos de la pestaña." << std::endl;
		return;
	}

	// Cargar el estado de incógnito
	archivo.read(reinterpret_cast<char*>(&incognito), sizeof(incognito));

	// Cargar el historial de navegación
	historial->cargarDesdeBinario(nombreArchivo);

	// Cargar el número de bookmarks
	size_t numBookmarks;
	archivo.read(reinterpret_cast<char*>(&numBookmarks), sizeof(numBookmarks));
	bookmarks.clear();
	for (size_t i = 0; i < numBookmarks; ++i) {
		Bookmark bookmark("", "");
		bookmark.cargarDesdeBinario(archivo);
		bookmarks.push_back(bookmark);
	}

	archivo.close();
}






