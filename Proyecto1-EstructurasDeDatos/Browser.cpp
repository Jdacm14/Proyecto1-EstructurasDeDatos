#include "Browser.h"
// Implementación de los métodos

Browser::Browser(int limite) : PestaniaActual(0), limiteHistorial(limite) {
    // Crear la primera Pestania con el límite de historial dado, usando new y almacenando un puntero
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
    // Liberar la memoria actual antes de asignar nuevas pestañas
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
    Pestanias.push_back(Pestania());  // Añadir nueva Pestania
    PestaniaActual = static_cast<int>(Pestanias.size()) - 1;
    Pestanias.at(PestaniaActual - 1).getHistorial().setearActualAlPrincipio();
    std::cout << "Nueva Pestania creada, ahora estás en la Pestania #" << PestaniaActual << std::endl;
    return PestaniaActual;
}

void Browser::cerrarPestania(int index) {
    if (index >= 0 && index < Pestanias.size()) {
        Pestanias.erase(Pestanias.begin() + index);  // Eliminar la Pestania del vector
        PestaniaActual = (index == 0) ? 0 : index - 1;  // Cambiar a la Pestania anterior si se cierra la actual
        std::cout << "Pestania cerrada, ahora estás en la Pestania #" << PestaniaActual << std::endl;
    }
    else {
        std::cout << "Índice de Pestania inválido" << std::endl;
    }
}

void Browser::cambiarPestania(int index) {
    if (index >= 0 && index < Pestanias.size()) {
        PestaniaActual = index;
        std::cout << "Cambiado a la Pestania #" << index << std::endl;
    }
    else {
        std::cout << "Índice de Pestania inválido" << std::endl;
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
    return Pestanias[PestaniaActual]->anteriorPag();  // Usar -> para acceder a métodos de puntero
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
        p->mostrarBookmarks();  // Usar -> para acceder a los métodos de puntero
    }
}

void Browser::exportarSesion(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar la sesión del navegador." << std::endl;
        return;
    }

    // Guardar el número de pestañas
    size_t numPestanias = Pestanias.size();
    archivo.write(reinterpret_cast<const char*>(&numPestanias), sizeof(numPestanias));

    // Guardar cada pestaña
    for (const auto& pestania : Pestanias) {
        pestania->guardarEnBinario(nombreArchivo);  // Guardar cada pestaña, incluyendo su historial
    }

    // Guardar el índice de la pestaña actual
    archivo.write(reinterpret_cast<const char*>(&PestaniaActual), sizeof(PestaniaActual));

    archivo.close();
}


void Browser::importarSesion(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para importar la sesión del navegador." << std::endl;
        return;
    }

    // Leer el número de pestañas
    size_t numPestanias;
    archivo.read(reinterpret_cast<char*>(&numPestanias), sizeof(numPestanias));

    // Limpiar las pestañas actuales antes de importar nuevas
    for (auto pestania : Pestanias) {
        delete pestania;  // Liberar memoria de las pestañas actuales
    }
    Pestanias.clear();

    // Leer cada pestaña
    for (size_t i = 0; i < numPestanias; ++i) {

        Pestania* nuevaPestania = new Pestania();  // Crear nueva pestaña dinámicamente
        nuevaPestania->cargarDesdeBinario(nombreArchivo);  // Cargar el historial y los bookmarks de la pestaña
        Pestanias.push_back(nuevaPestania);  // Añadir la pestaña al navegador
    }

    // Leer el índice de la pestaña actual
    archivo.read(reinterpret_cast<char*>(&PestaniaActual), sizeof(PestaniaActual));

    archivo.close();
}

//std::vector<Pestania> Browser::importarPestaniasConHistorial(const std::string& nombreArchivo) {
//    std::ifstream archivo(nombreArchivo, std::ios::binary);
//    std::vector<Pestania> nuevasPestanias;
//
//    if (!archivo.is_open()) {
//        std::cerr << "No se pudo abrir el archivo para importar la sesión de pestañas." << std::endl;
//        return nuevasPestanias;  // Devuelve un vector vacío si no se puede abrir el archivo
//    }
//
//    // Leer el número de pestañas
//    int numeroPestanias;
//    archivo.read(reinterpret_cast<char*>(&numeroPestanias), sizeof(numeroPestanias));
//    if (archivo.fail()) {
//        std::cerr << "Error al leer el número de pestañas." << std::endl;
//        return nuevasPestanias;
//    }
//    std::cout << "Importando " << numeroPestanias << " pestañas..." << std::endl;
//
//    // Leer la pestaña actual
//    archivo.read(reinterpret_cast<char*>(&PestaniaActual), sizeof(PestaniaActual));
//    if (archivo.fail()) {
//        std::cerr << "Error al leer la pestaña actual." << std::endl;
//        return nuevasPestanias;
//    }
//    std::cout << "Pestaña actual es: " << PestaniaActual << std::endl;
//
//    // Importar cada pestaña
//    for (int i = 0; i < numeroPestanias; ++i) {
//        Pestania nuevaPestania;
//        HistorialNavegacion nuevoHistorial;
//
//        // Leer el tamaño del historial
//        int historialSize;
//        archivo.read(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));
//        if (archivo.fail()) {
//            std::cerr << "Error al leer el tamaño del historial de la pestaña " << i << std::endl;
//            return nuevasPestanias;
//        }
//        std::cout << "Pestaña #" << i << " tiene " << historialSize << " páginas en el historial." << std::endl;
//
//        // Leer cada página del historial
//        for (int j = 0; j < historialSize; ++j) {
//            size_t urlLength, tituloLength;
//
//            // Leer el tamaño de la URL
//            archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tamaño de la URL de la página " << j << " en la pestaña " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer la URL
//            std::string url(urlLength, ' ');
//            archivo.read(&url[0], urlLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer la URL de la página " << j << " en la pestaña " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el tamaño del título
//            archivo.read(reinterpret_cast<char*>(&tituloLength), sizeof(tituloLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tamaño del título de la página " << j << " en la pestaña " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el título
//            std::string titulo(tituloLength, ' ');
//            archivo.read(&titulo[0], tituloLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el título de la página " << j << " en la pestaña " << i << std::endl;
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
//            std::cerr << "Error: El historial de la pestaña " << i << " está vacío." << std::endl;
//        }
//
//        // Establecer el historial de la pestaña
//        nuevaPestania.setHistorial(nuevoHistorial);
//
//        // Leer los bookmarks
//        int numBookmarks;
//        archivo.read(reinterpret_cast<char*>(&numBookmarks), sizeof(numBookmarks));
//        if (archivo.fail()) {
//            std::cerr << "Error al leer el número de bookmarks de la pestaña " << i << std::endl;
//            return nuevasPestanias;
//        }
//
//        // Leer cada bookmark
//        for (int k = 0; k < numBookmarks; ++k) {
//            size_t urlLength, titleLength;
//
//            // Leer el tamaño de la URL del bookmark
//            archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tamaño de la URL del bookmark " << k << " en la pestaña " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer la URL del bookmark
//            std::string bookmarkUrl(urlLength, ' ');
//            archivo.read(&bookmarkUrl[0], urlLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer la URL del bookmark " << k << " en la pestaña " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el tamaño del título del bookmark
//            archivo.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength));
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el tamaño del título del bookmark " << k << " en la pestaña " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Leer el título del bookmark
//            std::string bookmarkTitle(titleLength, ' ');
//            archivo.read(&bookmarkTitle[0], titleLength);
//            if (archivo.fail()) {
//                std::cerr << "Error al leer el título del bookmark " << k << " en la pestaña " << i << std::endl;
//                return nuevasPestanias;
//            }
//
//            // Crear el objeto Bookmark y agregarlo a la pestaña
//            Bookmark bookmark(bookmarkUrl, bookmarkTitle);
//            nuevaPestania.agregarBookmark(bookmark);
//        }
//
//        // Finalmente, agregar la pestaña completa
//        nuevasPestanias.push_back(nuevaPestania);
//    }
//
//    archivo.close();
//    std::cout << "Sesión importada con éxito." << std::endl;
//
//    return nuevasPestanias;  // Devuelve el vector con las nuevas pestañas e historiales
//}



std::vector<Bookmark> Browser::importarBookmarks(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);

    std::vector<Bookmark> listaBookmarks;

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para importar los bookmarks." << std::endl;
        return listaBookmarks;  // Devuelve un vector vacío si no se puede abrir el archivo
    }

    // Leer el número de bookmarks
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


