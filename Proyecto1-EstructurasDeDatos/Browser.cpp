#include "Browser.h"
// Implementación de los métodos

Browser::Browser(int limite) : PestaniaActual(0), limiteHistorial(limite) { // probablemente haya que cambiar este constructor
    // Crear la primera Pestania con el límite de historial dado
    Pestanias.push_back(Pestania());
}

std::vector<Pestania>& Browser::getPestanias()
{
    return Pestanias;
}

void Browser::setPestanias(std::vector<Pestania> listaPestanias)
{
    Pestanias = listaPestanias;
}

int Browser::getPestaniaActual()
{
    return PestaniaActual;
}

Pestania& Browser::getPestaniaEnPos(int pos)
{
    return Pestanias.at(pos);
}

void Browser::setPestaniaActual(int pest)
{
    PestaniaActual = pest;
}

int Browser::getLimiteHistorial()
{
    return limiteHistorial;
}

void Browser::setLimiteHistorial(int lim){
    limiteHistorial = lim;
}

void Browser::setMinutosDeTodasLasPest(int min)
{

    for (Pestania& p : Pestanias) {
        p.getHistorial().setMinutosTodosSitios(min);
    }
}

Pestania& Browser::getPestaniaActualReal()
{
    return Pestanias.at(PestaniaActual);
}

bool Browser::haysitios()
{
    int cont = 0;
    for (Pestania p : Pestanias) {
        if (!p.getHistorial().getLista().empty()) {
            cont++;
        }
    }
    if (cont > 0) {
        return true;
    }
    return false;
}

void Browser::agregarSitioWeb(const SitioWeb& s)
{
    std::lock_guard<std::mutex> lock(mtx);
   
   Pestanias[PestaniaActual].getHistorial().agregarPagina(s);
   std::cout << "Sitio web agregado." << std::endl;
    
    
}


int Browser::nuevaPestania() {
    std::lock_guard<std::mutex> lock(mtx);
    Pestanias.push_back(Pestania());  // Añadir nueva Pestania
    PestaniaActual = static_cast<int>(Pestanias.size()) - 1;
    for (int i = (int)Pestanias.size() - 1; i > 0; i--) {
        Pestanias.at(PestaniaActual - i).getHistorial().setearActualAlPrincipio();
    }
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
    return Pestanias[PestaniaActual].anteriorPag();
}

bool Browser::irAdelante() {
   return Pestanias[PestaniaActual].siguientePag();
}

void Browser::limpiarHistorialPestaniaActual() {
    Pestanias[PestaniaActual].limpiarHistorialVentana();
}

void Browser::agregarBookmarkPestaniaActual(Bookmark b)
{
    Pestanias.at(PestaniaActual).agregarBookmark(b);
}

void Browser::mostrarBookmarksPestaniaActual()
{
    Pestanias.at(PestaniaActual).mostrarBookmarks();
}

void Browser::activarIncognitoPestaniaActual() {
    Pestanias[PestaniaActual].activarIncognito();
    std::cout << "Modo incognito activado en la Pestania #" << PestaniaActual << std::endl;
}

void Browser::desactivarIncognitoPestaniaActual() {
    Pestanias[PestaniaActual].desactivarIncognito();
    std::cout << "Modo incognito desactivado en la Pestania #" << PestaniaActual << std::endl;
}

void Browser::mostrarTodosBookmarks()
{
    for (Pestania p : Pestanias) {
        p.mostrarBookmarks();
    }
}

void Browser::mostrarPestanias() {
    std::cout << "=== Pestanias abiertas ===" << std::endl;
    for (size_t i = 0; i < Pestanias.size(); ++i) {
        std::cout << "Pestania #" << i;
        if (i == PestaniaActual) {
            std::cout << " (actual)";
        }
        std::cout << std::endl;
    }
}

void Browser::exportarSesion(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para exportar la sesion." << std::endl;
        return;
    }

    // Guardar el número de pestañas
    int numeroPestanias = (int) Pestanias.size();
    archivo.write(reinterpret_cast<const char*>(&numeroPestanias), sizeof(numeroPestanias));

    // Guardar la pestaña actual
    archivo.write(reinterpret_cast<const char*>(&PestaniaActual), sizeof(PestaniaActual));

    // Exportar cada pestaña
    for (auto& pestaña : Pestanias) {
        HistorialNavegacion& historial = pestaña.getHistorial();
        int historialSize = (int) historial.getHistorialSize();
        archivo.write(reinterpret_cast<const char*>(&historialSize), sizeof(historialSize));

        // Exportar cada página del historial
        for (const auto& pagina : historial.obtenerHistorial()) {
            size_t urlLength = pagina.first.size();
            size_t tituloLength = pagina.second.size();

            archivo.write(reinterpret_cast<const char*>(&urlLength), sizeof(urlLength));
            archivo.write(pagina.first.c_str(), urlLength);

            archivo.write(reinterpret_cast<const char*>(&tituloLength), sizeof(tituloLength));
            archivo.write(pagina.second.c_str(), tituloLength);
        }

        // Exportar los bookmarks
        std::vector<Bookmark>& bookmarks = pestaña.geVectortBookmarks();
        int numBookmarks = (int) bookmarks.size();
        archivo.write(reinterpret_cast<const char*>(&numBookmarks), sizeof(numBookmarks));

        for (auto& bookmark : bookmarks) {
            size_t urlLength = bookmark.getURL().size();
            size_t titleLength = bookmark.getTitle().size();

            archivo.write(reinterpret_cast<const char*>(&urlLength), sizeof(urlLength));
            archivo.write(bookmark.getURL().c_str(), urlLength);

            archivo.write(reinterpret_cast<const char*>(&titleLength), sizeof(titleLength));
            archivo.write(bookmark.getTitle().c_str(), titleLength);
        }
    }

    archivo.close();
}

void Browser::importarSesion(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para importar la sesion." << std::endl;
        return;
    }

    // Limpiar las pestañas actuales antes de cargar las nuevas
    Pestanias.clear();

    // Leer el número de pestañas
    int numeroPestanias;
    archivo.read(reinterpret_cast<char*>(&numeroPestanias), sizeof(numeroPestanias));

    // Leer la pestaña actual
    archivo.read(reinterpret_cast<char*>(&PestaniaActual), sizeof(PestaniaActual));

    for (int i = 0; i < numeroPestanias; ++i) {
        Pestania nuevaPestania;
        HistorialNavegacion nuevoHistorial;

        // Leer el tamaño del historial
        int historialSize;
        archivo.read(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));

        // Leer cada página del historial
        for (int j = 0; j < historialSize; ++j) {
            size_t urlLength, tituloLength;
            archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));

            std::string url(urlLength, ' ');
            archivo.read(&url[0], urlLength);

            archivo.read(reinterpret_cast<char*>(&tituloLength), sizeof(tituloLength));
            std::string titulo(tituloLength, ' ');
            archivo.read(&titulo[0], tituloLength);

            SitioWeb sitio(url, titulo);
            nuevoHistorial.agregarPagina(sitio);
        }

        if (!nuevoHistorial.getHistorial().empty()) {   // aseguramos que el historial no esté vacío
            nuevoHistorial.setearActualAlPrincipio();
        }
        else {
            std::cerr << "Historial vacio despues de importar. " << std::endl;
        }

        nuevaPestania.setHistorial(nuevoHistorial);

        // Leer los bookmarks
        int numBookmarks;
        archivo.read(reinterpret_cast<char*>(&numBookmarks), sizeof(numBookmarks));

        for (int k = 0; k < numBookmarks; ++k) {
            size_t urlLength, titleLength;
            archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));

            std::string url(urlLength, ' ');
            archivo.read(&url[0], urlLength);

            archivo.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength));
            std::string title(titleLength, ' ');
            archivo.read(&title[0], titleLength);

            Bookmark bookmark(url, title);
            nuevaPestania.agregarBookmark(bookmark);
        }

        Pestanias.push_back(nuevaPestania);
    }

    archivo.close();
}

void Browser::verificarSitios()
{
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& pestana : Pestanias) {
        pestana.getHistorial().eliminarSitiosWeb();
    }
}


