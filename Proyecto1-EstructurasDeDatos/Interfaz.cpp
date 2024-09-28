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
    if (navegador.getPestañas().empty()) {
        std::cout << "No hay pestaña abiertas..." << std::endl;
        return;
    }

    // Obtener la página actual en la pestaña actual
    SitioWeb pagina = navegador.getPestañaEnPos(navegador.getPestañaActual()).getHistorial().obtenerPaginaActual();

    // Mostrar los detalles de la página actual usando los getters
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
    std::cout << "================= Pestaña #" << navegador.getPestañaActual() << " =================\n";
    std::cout << "URL: " << pagina.getUrl() << "\n";
    std::cout << "Título: " << pagina.getTitulo() << "\n";
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
        // Si la URL fue encontrada, mostrar URL y título
       /* std::cout << "Visitando: " << sitioEncontrado.getUrl() << " - " << sitioEncontrado.getTitulo() << std::endl;*/

        // Agregar al historial de navegación
        navegador.getPestañaEnPos(navegador.getPestañaActual()).getHistorial().agregarPagina(sitioEncontrado);

        // Mostrar la página actual
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
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            AGREGAR BOOKMARK                    " << std::endl;
    std::cout << " Ingresar URL: ";
    std::cin >> op;

    CSV csv;  
    std::string archivo = "sitiosWeb.csv";

    // Cargar los sitios web desde el archivo CSV
    if (!csv.cargarSitiosDesdeCSV(archivo)) {
        std::cout << "Error al cargar los sitios web." << std::endl;
        return;
    }

    // Buscar la URL en los sitios cargados
    SitioWeb sitioEncontrado = csv.buscarSitioPorURL(op);

    if (sitioEncontrado.getTitulo() != "404 - Not Found") {
        // Si la URL fue encontrada, mostrar URL y título
       /* std::cout << "Visitando: " << sitioEncontrado.getUrl() << " - " << sitioEncontrado.getTitulo() << std::endl;*/
        for (Pestaña p : b.getPestañas()) {
            for (Bookmark bo : p.geVectortBookmarks()) {
                if (sitioEncontrado.getUrl() == bo.getURL()) {
                    std::cout << "Este sitio ya es un bookmark" << "\n";
                    system("pause");
                    return;
                }
            }
        }

        while (s == false) {
            int siono;
            std::string eti;
            std::cout << " Desea agregar una etiqueta?... si(1) / no(2): ";
            std::cin >> siono;
            if (siono != 1) {
                s = true;
            }
            else {
                std::cout << " Ingresar etiqueta: ";
                std::cin >> eti;
                pes.push_back(eti);

            }
            std::cout << std::endl;
        }

        Bookmark bo(op, sitioEncontrado.getTitulo());
        for (std::string s : pes) {
            bo.agregarEtiqueta(s);
        }

        b.getPestañaActualReal().agregarBookmark(bo);
      
    }
    else {
        // Si no se encuentra, mostrar el error
        std::cout << sitioEncontrado.getTitulo() << std::endl;  // "404 - Not Found"
        system("pause");
    }
    system("pause");
   
}

void Interfaz::verBookmarks(Browser& b)
{
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                          LISTA DE BOOKMARKS                    " << std::endl;
    b.mostrarTodosBookmarks();
    system("pause");
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

std::string Interfaz::incognito(Browser& b)
{
    b.activarIncognitoPestañaActual();
    system("pause");
    return " ";
}

std::string Interfaz::nuevaPestania(Browser& b)
{
    b.nuevaPestaña();
    return " ";
}

std::string Interfaz::configuracion()
{
    return std::string();
}


void Interfaz::cambiarPestania(Browser& b, int n) {
    if (n == 72 && b.getPestañaActual() > 0) {
        b.setPestañaActual(b.getPestañaActual() - 1);
        mostrarPaginaActual(b);
     
    }
    if (n == 80 && b.getPestañaActual() < 10 && b.existeSigPes() ) {
        b.setPestañaActual(b.getPestañaActual() + 1);
        mostrarPaginaActual(b);
      
    }
    
}

void Interfaz::cambiarHistorial(Browser& b, int n) {
    if (n == 75 && b.irAtras()) {
        std::cout << "Falta esta parte" << "\n";
    }
    if (n == 77 && b.irAdelante()) {
        std::cout << "Falta esta parte" << "\n";
    }


}