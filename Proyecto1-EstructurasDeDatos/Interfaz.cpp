#include "Interfaz.h"

std::string Interfaz::buscadorPrincipal()
{
    std::string op;
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

std::string Interfaz::irAlSitioWeb()
{

    std::string op;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            SITIO WEB                           " << std::endl;
    std::cout << " Ingresar URL: " << std::endl;
    std::cin >> op;
    return op;

}

std::string Interfaz::agregarBookmark()
{
    std::string op;
    system("cls");
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            AGREGAR BOOKMARK                    " << std::endl;
    std::cout << " Ingresar URL: " << std::endl;
    std::cin >> op;
    return op;
}

void Interfaz::verBookmarks()
{
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                          LISTA DE BOOKMARKS                    " << std::endl;
    //Mostrar la lista de bookmarks

}

std::string Interfaz::busquedaFiltros()
{
    std::string op;
    system("cls");
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            BUSQUEDA/FILTRAR                    " << std::endl;
    std::cout << " Ingresar tag o titulo: " << std::endl;
    std::cin >> op;
    return op;
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
