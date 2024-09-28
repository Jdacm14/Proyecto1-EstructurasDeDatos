#include "Bookmark.h"


Bookmark::Bookmark(const std::string url, const std::string title): url(url), title(title){}

void Bookmark::agregarEtiqueta(std::string& etiqueta){
	etiquetas.push_back(etiqueta);
}

void Bookmark::mostrarEtiquetas(){
	std::cout << "Etiquetas: ";
	for (const auto& etiqueta : etiquetas) {
		std::cout << etiqueta << " ";
	}
	std::cout << std::endl;
}

bool Bookmark::tieneEtiqueta(std::string& etiqueta)
{
	return std::find(etiquetas.begin(), etiquetas.end(), etiqueta) != etiquetas.end();
}

std::string Bookmark::getURL()
{
	return url;
}

std::string Bookmark::getTitle()
{
	return title;
}

std::string Bookmark::toString()
{
	std::stringstream s;

	s << "Titulo: " << title << ", "
		<< "URL: " << url << ", "
	    << "Etiquetas: ";
	mostrarEtiquetas();

	return s.str();
}
