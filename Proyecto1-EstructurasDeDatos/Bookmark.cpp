#include "Bookmark.h"


Bookmark::Bookmark(const std::string& url, const std::string& title): url(url), title(title){}

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

void Bookmark::guardarEnBinario(std::ofstream& archivo) const {
    // Guardar la longitud de la URL y luego la URL
    size_t urlSize = url.size();
    archivo.write(reinterpret_cast<const char*>(&urlSize), sizeof(urlSize));
    archivo.write(url.c_str(), urlSize);

    // Guardar la longitud del título y luego el título
    size_t titleSize = title.size();
    archivo.write(reinterpret_cast<const char*>(&titleSize), sizeof(titleSize));
    archivo.write(title.c_str(), titleSize);

    // Guardar el número de etiquetas
    size_t numEtiquetas = etiquetas.size();
    archivo.write(reinterpret_cast<const char*>(&numEtiquetas), sizeof(numEtiquetas));

    // Guardar cada etiqueta (su tamaño seguido de su contenido)
    for (const auto& etiqueta : etiquetas) {
        size_t etiquetaSize = etiqueta.size();
        archivo.write(reinterpret_cast<const char*>(&etiquetaSize), sizeof(etiquetaSize));
        archivo.write(etiqueta.c_str(), etiquetaSize);
    }
}

void Bookmark::cargarDesdeBinario(std::ifstream& archivo) {
    // Leer la longitud de la URL y luego la URL
    size_t urlSize;
    archivo.read(reinterpret_cast<char*>(&urlSize), sizeof(urlSize));
    url.resize(urlSize);
    archivo.read(&url[0], urlSize);

    // Leer la longitud del título y luego el título
    size_t titleSize;
    archivo.read(reinterpret_cast<char*>(&titleSize), sizeof(titleSize));
    title.resize(titleSize);
    archivo.read(&title[0], titleSize);

    // Leer el número de etiquetas
    size_t numEtiquetas;
    archivo.read(reinterpret_cast<char*>(&numEtiquetas), sizeof(numEtiquetas));

    // Limpiar las etiquetas actuales y leer las nuevas
    etiquetas.clear();
    for (size_t i = 0; i < numEtiquetas; ++i) {
        size_t etiquetaSize;
        archivo.read(reinterpret_cast<char*>(&etiquetaSize), sizeof(etiquetaSize));

        std::string etiqueta(etiquetaSize, ' ');
        archivo.read(&etiqueta[0], etiquetaSize);
        etiquetas.push_back(etiqueta);
    }
}

std::string Bookmark::toString()
{
	std::stringstream s;

	s << "Titulo: " << title << ", "
		<< "URL: " << url << " ";
	mostrarEtiquetas();

	return s.str();
}
