#include "Bookmark.h"

// constructor
Bookmark::Bookmark(const std::string url, const std::string title): url(url), title(title){}

// agrega una etiqueda al vector del bookmark
void Bookmark::agregarEtiqueta(const std::string& etiqueta){
	etiquetas.push_back(etiqueta);
}

// muestra todas las etiquetas ingresadas
void Bookmark::mostrarEtiquetas(){
	std::cout << "Etiquetas: ";
	for (const auto& etiqueta : etiquetas) {	// itera e imprime
		std::cout << etiqueta << " ";
	}
	std::cout << std::endl;
}

// verifica que tenga una etiqueta en específico
bool Bookmark::tieneEtiqueta(const std::string& etiqueta)
{
	return std::find(etiquetas.begin(), etiquetas.end(), etiqueta) != etiquetas.end();	// true = se encontró
}

// getters
std::string Bookmark::getURL()
{
	return url;
}

std::string Bookmark::getTitle()
{
	return title;
}

// metodo toString
std::string Bookmark::toString()
{
	std::stringstream s;

	s << "Titulo: " << title << ", "
		<< "URL: " << url << " ";
	mostrarEtiquetas();
	s << std::endl;

	return s.str();
}
