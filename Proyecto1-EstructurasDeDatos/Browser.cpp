#include "Browser.h"
// Implementaci�n de los m�todos

Browser::Browser(int limite) : PestaniaActual(0), limiteHistorial(limite) {
    // Crear la primera Pestania con el l�mite de historial dado, usando new y almacenando un puntero
    Pestanias.push_back(new Pestania());
}

Browser::~Browser()
{
    // Liberar memoria de cada Pestania
        for (auto pestania : Pestanias) {
            delete pestania;
        }
    Pestanias.clear();
}

std::vector<Pestania*>& Browser::getPestanias()
{
    return Pestanias;
}

void Browser::setPestanias(std::vector<Pestania*>& listaPestanias)
{
    // Liberar la memoria actual antes de asignar nuevas pesta�as
    for (auto pestania : Pestanias) {
        delete pestania;
    }
    Pestanias = listaPestanias;
}

int Browser::getPestaniaActual()
{
    return PestaniaActual;
}

Pestania* Browser::getPestaniaEnPos(int pos)
{
    if (pos >= 0 && pos < Pestanias.size()) {
        return Pestanias[pos];
    }
    return nullptr;
}

void Browser::setPestaniaActual(int pest)
{
    if (pest >= 0 && pest < Pestanias.size()) {
        PestaniaActual = pest;
    }
}

int Browser::getLimiteHistorial()
{
    return limiteHistorial;
}

void Browser::setLimiteHistorial(int lim){
    limiteHistorial = lim;
}

Pestania* Browser::getPestaniaActualReal()
{
    if (PestaniaActual >= 0 && PestaniaActual < Pestanias.size()) {
        return Pestanias[PestaniaActual];
    }
    return nullptr;
}


int Browser::nuevaPestania() {
    Pestanias.push_back(Pestania());  // A�adir nueva Pestania
    PestaniaActual = static_cast<int>(Pestanias.size()) - 1;
    Pestanias.at(PestaniaActual - 1).getHistorial().setearActualAlPrincipio();
    std::cout << "Nueva Pestania creada, ahora est�s en la Pestania #" << PestaniaActual << std::endl;
    return PestaniaActual;
}

void Browser::cerrarPestania(int index) {
    if (index >= 0 && index < Pestanias.size()) {
        Pestanias.erase(Pestanias.begin() + index);  // Eliminar la Pestania del vector
        PestaniaActual = (index == 0) ? 0 : index - 1;  // Cambiar a la Pestania anterior si se cierra la actual
        std::cout << "Pestania cerrada, ahora est�s en la Pestania #" << PestaniaActual << std::endl;
    }
    else {
        std::cout << "�ndice de Pestania inv�lido" << std::endl;
    }
}

void Browser::cambiarPestania(int index) {
    if (index >= 0 && index < Pestanias.size()) {
        PestaniaActual = index;
        std::cout << "Cambiado a la Pestania #" << index << std::endl;
    }
    else {
        std::cout << "�ndice de Pestania inv�lido" << std::endl;
    }
}

bool Browser::existeSigPes()
{
    if (PestaniaActual == (int)Pestanias.size()-1) {
        return false;
    }
    return true;
}


bool Browser::irAtras() {
    return Pestanias[PestaniaActual]->anteriorPag();  // Usar -> para acceder a m�todos de puntero
}

bool Browser::irAdelante() {
    return Pestanias[PestaniaActual]->siguientePag();  // Usar ->
}

void Browser::limpiarHistorialPestaniaActual() {
    Pestanias[PestaniaActual]->limpiarHistorialVentana();  // Usar ->
}

void Browser::agregarBookmarkPestaniaActual(Bookmark b) {
    Pestanias.at(PestaniaActual)->agregarBookmark(b);  // Usar ->
}

void Browser::mostrarBookmarksPestaniaActual() {
    Pestanias.at(PestaniaActual)->mostrarBookmarks();  // Usar ->
}

void Browser::activarIncognitoPestaniaActual() {
    Pestanias[PestaniaActual]->activarIncognito();  // Usar ->
    std::cout << "Modo incognito activado en la Pestania #" << PestaniaActual << std::endl;
}

void Browser::desactivarIncognitoPestaniaActual() {
    Pestanias[PestaniaActual]->desactivarIncognito();  // Usar ->
    std::cout << "Modo incognito desactivado en la Pestania #" << PestaniaActual << std::endl;
}

void Browser::mostrarTodosBookmarks() {
    for (auto p : Pestanias) {
        p->mostrarBookmarks();  // Usar -> para acceder a los m�todos de puntero
    }
}

void Browser::exportarSesion(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar la sesi�n del navegador." << std::endl;
        return;
    }

    // Guardar el n�mero de pesta�as
    size_t numPestanias = Pestanias.size();
    archivo.write(reinterpret_cast<const char*>(&numPestanias), sizeof(numPestanias));

    // Guardar cada pesta�a
    for (const auto& pestania : Pestanias) {
        pestania->guardarEnBinario(nombreArchivo);  // Guardar cada pesta�a, incluyendo su historial
    }

    // Guardar el �ndice de la pesta�a actual
    archivo.write(reinterpret_cast<const char*>(&PestaniaActual), sizeof(PestaniaActual));

    archivo.close();
}


void Browser::importarSesion(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para importar la sesi�n del navegador." << std::endl;
        return;
    }

    // Leer el n�mero de pesta�as
    size_t numPestanias;
    archivo.read(reinterpret_cast<char*>(&numPestanias), sizeof(numPestanias));

    // Limpiar las pesta�as actuales antes de importar nuevas
    for (auto pestania : Pestanias) {
        delete pestania;  // Liberar memoria de las pesta�as actuales
    }
    Pestanias.clear();

    // Leer cada pesta�a
    for (size_t i = 0; i < numPestanias; ++i) {

        Pestania* nuevaPestania = new Pestania();  // Crear nueva pesta�a din�micamente
        nuevaPestania->cargarDesdeBinario(nombreArchivo);  // Cargar el historial y los bookmarks de la pesta�a
        Pestanias.push_back(nuevaPestania);  // A�adir la pesta�a al navegador
    }

    // Leer el �ndice de la pesta�a actual
    archivo.read(reinterpret_cast<char*>(&PestaniaActual), sizeof(PestaniaActual));

    archivo.close();
}

//std::vector<Pestania> Browser::importarPestaniasConHistorial(const std::string& nombreArchivo) {
//    std::ifstream archivo(nombreArchivo, std::ios::binary);
//    std::vector<Pestania> nuevasPestanias;
//
//    if (!archivo.is_open()) {
//        std::cerr << "No se pudo abrir el archivo para importar la sesi�n de pesta�as." << std::endl;
//        return nuevasPestanias;  // Devuelve un vector vac�o si no se puede abrir el archivo
//    }
//
//    // Leer el n�mero de pesta�as
//    int numeroPestanias;
//    archivo.read(reinterpret_cast<char*>(&numeroPestanias), sizeof(numeroPestanias));
//    if (archivo.fail()) {
//        std::cerr << "Error al leer el n�mero de pesta�as." << std::endl;
//        return nuevasPestanias;
//    }
//    std::cout << "Importando " << numeroPestanias << " pesta�as..." << std::endl;
//
//    // Leer la pesta�a actual
//    archivo.read(reinterpret_cast<char*>(&PestaniaActual), sizeof(PestaniaActual));
//    if (archivo.fail()) {
//        std::cerr << "Error al leer la pesta�a actual." << std::endl;
//        return nuevasPestanias;
//    }
//    std::cout << "Pesta�a actual es: " << PestaniaActual << std::endl;
//
//    // Importar cada pesta�a
//    for (int i = 0; i < numeroPestanias; ++i) {
//        Pestania nuevaPestania;
//        HistorialNavegacion nuevoHistorial;
//
//        // Leer el tama�o del historial
//        int historialSize;
//        archivo.read(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));
//        if (archivo.fail()) {
//            std::cerr << "Error al leer el tama�o del historial de la pesta�a " << i << std::endl;
//            return nuevasPestanias;
//        }
//        std::cout << "Pesta�a #" << i << " tiene " << historialSize << " p�ginas en el historial." << std::endl;
//
//        // Leer cada p�gina del historial
//        for (int j = 0; j < historialSize; ++j) {
//            size_t urlLength, tituloLength;
//
//            // Leer el tama�o de la URL
//            archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tama�o de la URL de la p�gina " << j << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer la URL
//            std::string url(urlLength, ' ');
//            archivo.read(&url[0], urlLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer la URL de la p�gina " << j << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el tama�o del t�tulo
//            archivo.read(reinterpret_cast<char*>(&tituloLength), sizeof(tituloLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tama�o del t�tulo de la p�gina " << j << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el t�tulo
//            std::string titulo(tituloLength, ' ');
//            archivo.read(&titulo[0], tituloLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el t�tulo de la p�gina " << j << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Crear el objeto SitioWeb y agregarlo al historial
//            SitioWeb sitio(url, titulo);
//            nuevoHistorial.agregarPagina(sitio);
//        }
//
//        // Validar el historial antes de asignar el iterador actual
//        if (!nuevoHistorial.estaVacio()) {
//            nuevoHistorial.setActualAlUltimo();
//        }
//        else {
//            std::cerr << "Error: El historial de la pesta�a " << i << " est� vac�o." << std::endl;
//        }
//
//        // Establecer el historial de la pesta�a
//        nuevaPestania.setHistorial(nuevoHistorial);
//
//        // Leer los bookmarks
//        int numBookmarks;
//        archivo.read(reinterpret_cast<char*>(&numBookmarks), sizeof(numBookmarks));
//        if (archivo.fail()) {
//            std::cerr << "Error al leer el n�mero de bookmarks de la pesta�a " << i << std::endl;
//            return nuevasPestanias;
//        }
//
//        // Leer cada bookmark
//        for (int k = 0; k < numBookmarks; ++k) {
//            size_t urlLength, titleLength;
//
//            // Leer el tama�o de la URL del bookmark
//            archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tama�o de la URL del bookmark " << k << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer la URL del bookmark
//            std::string bookmarkUrl(urlLength, ' ');
//            archivo.read(&bookmarkUrl[0], urlLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer la URL del bookmark " << k << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el tama�o del t�tulo del bookmark
//            archivo.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tama�o del t�tulo del bookmark " << k << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el t�tulo del bookmark
//            std::string bookmarkTitle(titleLength, ' ');
//            archivo.read(&bookmarkTitle[0], titleLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el t�tulo del bookmark " << k << " en la pesta�a " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Crear el objeto Bookmark y agregarlo a la pesta�a
//            Bookmark bookmark(bookmarkUrl, bookmarkTitle);
//            nuevaPestania.agregarBookmark(bookmark);
//        }
//
//        // Finalmente, agregar la pesta�a completa
//        nuevasPestanias.push_back(nuevaPestania);
//    }
//
//    archivo.close();
//    std::cout << "Sesi�n importada con �xito." << std::endl;
//
//    return nuevasPestanias;  // Devuelve el vector con las nuevas pesta�as e historiales
//}



std::vector<Bookmark> Browser::importarBookmarks(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);

    std::vector<Bookmark> listaBookmarks;

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para importar los bookmarks." << std::endl;
        return listaBookmarks;  // Devuelve un vector vac�o si no se puede abrir el archivo
    }

    // Leer el n�mero de bookmarks
    int numBookmarks;
    archivo.read(reinterpret_cast<char*>(&numBookmarks), sizeof(numBookmarks));

    // Leer cada bookmark
    for (int k = 0; k < numBookmarks; ++k) {
        size_t urlLength, titleLength;
        archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));

        std::string url(urlLength, ' ');
        archivo.read(&url[0], urlLength);

        archivo.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength));
        std::string title(titleLength, ' ');
        archivo.read(&title[0], titleLength);

        Bookmark bookmark(url, title);
        listaBookmarks.push_back(bookmark);
    }

    archivo.close();
    return listaBookmarks;  // Devuelve el vector de bookmarks
}


