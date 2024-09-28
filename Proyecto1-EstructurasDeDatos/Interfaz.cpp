#include "Interfaz.h"

char Interfaz::buscadorPrincipal(Browser& b)
{
    char op;
    system("cls");
    std::cout << std:: endl;
    /*std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                             BUSCADOR                           " << std::endl;
    std::cout << " a - Ir a sitio web                                             " << std::endl;
    std::cout << " b - Agregar bookmark                                           " << std::endl;
    std::cout << " c - Importar/Exportar                                          " << std::endl;
    std::cout << " d - Ver bookmark                                               " << std::endl;
    std::cout << " e - Busqueda/filtros                                           " << std::endl;
    std::cout << " f - Incognito                                                  " << std::endl;
    std::cout << " g - Nueva Pestania                                             " << std::endl;
    std::cout << " h - Configuracion                                              " << std::endl;*/
    mostrarPaginaActual(b);
    std::cin >> op;
    return op;


}

void Interfaz::mostrarMenu() {
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                             BUSCADOR                           " << std::endl;
    std::cout << " a - Ir a sitio web                                             " << std::endl;
    std::cout << " b - Agregar bookmark                                           " << std::endl;
    std::cout << " c - Importar/Exportar                                          " << std::endl;
    std::cout << " d - Ver bookmark                                               " << std::endl;
    std::cout << " e - Busqueda/filtros                                           " << std::endl;
    std::cout << " f - Incognito                                                  " << std::endl;
    std::cout << " g - Nueva Pestania                                             " << std::endl;
    std::cout << " h - Configuracion                                              " << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
   
}


void Interfaz::mostrarPaginaActual(Browser& navegador)
{
    if (navegador.getPesta�as().empty()) {
        std::cout << "No hay pesta�a abiertas..." << std::endl;
        return;
    }

    // Obtener la p�gina actual en la pesta�a actual
    SitioWeb pagina = navegador.getPesta�aEnPos(navegador.getPesta�aActual()).getHistorial().obtenerPaginaActual();

    // Mostrar los detalles de la p�gina actual usando los getters
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                             BUSCADOR                           " << std::endl;
    std::cout << " a - Ir a sitio web                                             " << std::endl;
    std::cout << " b - Agregar bookmark                                           " << std::endl;
    std::cout << " c - Importar/Exportar                                          " << std::endl;
    std::cout << " d - Ver bookmark                                               " << std::endl;
    std::cout << " e - Busqueda/filtros                                           " << std::endl;
    std::cout << " f - Incognito                                                  " << std::endl;
    std::cout << " g - Nueva Pestania                                             " << std::endl;
    std::cout << " h - Configuracion                                              " << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "================= Pesta�a #" << navegador.getPesta�aActual() << " =================\n";
    std::cout << "URL: " << pagina.getUrl() << "\n";
    std::cout << "T�tulo: " << pagina.getTitulo() << "\n";
    std::cout << "===============================================\n";
}

void Interfaz::irAlSitioWeb(Browser& navegador)  // Pasar navegador por referencia
{
    std::string urlIngresada;
    CSV csv;  // Crear instancia para cargar y buscar en el CSV
    std::string archivo = "sitiosWeb.csv";

    // Cargar los sitios web desde el archivo CSV
    if (!csv.cargarSitiosDesdeCSV(archivo)) {
        std::cout << "Error al cargar los sitios web." << std::endl;
        return;
    }

    // Solicitar al usuario que ingrese una URL
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            SITIO WEB                           " << std::endl;
    std::cout << " Ingresar URL: ";
    std::cin >> urlIngresada;

    // Buscar la URL en los sitios cargados
    SitioWeb sitioEncontrado = csv.buscarSitioPorURL(urlIngresada);

    if (sitioEncontrado.getTitulo() != "404 - Not Found") {
        // Si la URL fue encontrada, mostrar URL y t�tulo
       /* std::cout << "Visitando: " << sitioEncontrado.getUrl() << " - " << sitioEncontrado.getTitulo() << std::endl;*/

        // Agregar al historial de navegaci�n
        navegador.getPesta�aEnPos(navegador.getPesta�aActual()).getHistorial().agregarPagina(sitioEncontrado);

        // Mostrar la p�gina actual
        /*mostrarPaginaActual(navegador);*/
    }
    else {
        // Si no se encuentra, mostrar el error
        std::cout << sitioEncontrado.getTitulo() << std::endl;  // "404 - Not Found"
    }
}


void Interfaz::agregarBookmark(Browser& b)
{
    std::string op;
    std::string op2;
    std::vector<std::string> pes;
    bool s = false;
    system("cls");
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            AGREGAR BOOKMARK                    " << std::endl;
    std::cout << " Ingresar URL: ";
    std::cin >> op;
    std::cout << " Ingresar titulo: ";
    std::cin >> op2;
    while (s==false) {
        int siono;
        std::string eti;
        std::cout << " Desea agregar una etiqueta?... si(1) / no(2)";
        std::cin >> siono;
        if (siono == 2) {
            s = true;
        }
        else {
            std::cout << " Ingresar etiqueta: ";
            std::cin >> eti;
            pes.push_back(eti);

        }
        system("cls");
    }

    Bookmark bo(op, op2);
    for (std::string s : pes) {
        bo.agregarEtiqueta(s);
    }

    b.getPesta�aActualReal().agregarBookmark(bo);

}

void Interfaz::verBookmarks(Browser& b)
{
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                          LISTA DE BOOKMARKS                    " << std::endl;
    b.mostrarTodosBookmarks();
}

void Interfaz::busquedaFiltros(Browser& b)
{
    std::string op;
    system("cls");
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            BUSQUEDA/FILTRAR                    " << std::endl;
    std::cout << " Ingresar tag o titulo: " << std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, op);

    std::vector<std::pair<std::string, std::string>> coincidencias; // almacena las coincidencias

    for (auto& pesta�a : b.getPesta�as()) {
        auto& historial = pesta�a.getHistorial();
        for (const auto& pagina : historial.obtenerHistorial()) {
            if (pagina.second.find(op) != std::string::npos) {
                coincidencias.emplace_back(pagina.second, pagina.first);    // guarda la pagina si coincide
            }
        }
    }
    if (!coincidencias.empty()) {
        std::cout << "Titulos encontrados: " << std::endl;
        for (const auto& coincidencia : coincidencias) {
            std::cout << "Titulo: " << coincidencia.first << " en la URL: " << coincidencia.second << std::endl;
        }
    }
    else {
        std::cout << "No se encontraron t�tulos..." << std::endl;
    }
    system("pause");
}


std::string Interfaz::incognito()
{
    return " ";
}

std::string Interfaz::nuevaPestania(Browser& b)
{
    b.nuevaPesta�a();
    return " ";
}

std::string Interfaz::configuracion()
{
    return std::string();
}

