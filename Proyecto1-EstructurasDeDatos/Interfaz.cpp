#include "Interfaz.h"

char Interfaz::buscadorPrincipal()
{
    char op;
    system("cls");
    std::cout << std:: endl;
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
    std::cout << "================= Pestaña #" << navegador.getPestañaActual() << " =================\n";
    auto pagina = navegador.getPestañaEnPos(navegador.getPestañaActual()).getHistorial().obtenerPaginaActual();
    std::cout << "URL: " << pagina.first << "\n";
    std::cout << "Título: " << pagina.second << "\n";
    std::cout << "===============================================\n";
}

void Interfaz::irAlSitioWeb(Browser navegador)
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
    std::pair<std::string, std::string> resultado = csv.buscarSitioPorURL(urlIngresada);
    std::string url = resultado.first;
    std::string titulo = resultado.second;

    if (titulo != "404 - Not Found") {
        // Si la URL fue encontrada, mostrar URL y título
        std::cout << "Visitando: " << url << " - " << titulo << std::endl;
        // Agregar al historial de navegación (suponiendo que tienes la clase HistorialNavegacion)
        navegador.getPestañaEnPos(navegador.getPestañaActual()).getHistorial().agregarPagina(url, titulo);
        mostrarPaginaActual(navegador);
    }
    else {
        std::cout << titulo << std::endl;
    }
   

}

void Interfaz::agregarBookmark()
{
    std::string op;
    system("cls");
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            AGREGAR BOOKMARK                    " << std::endl;
    std::cout << " Ingresar URL: " << std::endl;
    std::cin >> op;
}

void Interfaz::verBookmarks()
{
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                          LISTA DE BOOKMARKS                    " << std::endl;
    //Mostrar la lista de bookmarks

}

void Interfaz::busquedaFiltros()
{
    std::string op;
    system("cls");
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            BUSQUEDA/FILTRAR                    " << std::endl;
    std::cout << " Ingresar tag o titulo: " << std::endl;
    std::cin >> op;
    
}

std::string Interfaz::incognito()
{
    return std::string();
}

std::string Interfaz::nuevaPestania()
{
    return std::string();
}

std::string Interfaz::configuracion()
{
    return std::string();
}
