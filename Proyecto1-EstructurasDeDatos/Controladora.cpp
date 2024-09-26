#include "Controladora.h"

Controladora::Controladora()
{
	browser = new Browser();
	opcion = ' ';
}

Controladora::~Controladora()
{
}

void Controladora::msjOpcionNoValida()
{
}

void Controladora::controlMenuGeneral()
{
    do {
        // Mostrar el men� antes de cada operaci�n
        system("cls");  // Limpiar la pantalla
        Interfaz::mostrarMenu();  // Mostrar el men� en la parte superior

        Interfaz::mostrarPaginaActual(*browser);

        opcion = Interfaz::buscadorPrincipal();

        // Ejecutar la opci�n seleccionada
        switch (opcion) {
        case 'a':
            Interfaz::irAlSitioWeb(*browser);
            break;
        case 'b':
            Interfaz::agregarBookmark(*browser);
            break;
        case 'd':
            Interfaz::verBookmarks(*browser);
            break;
        default:
           // Interfaz::msjOpcionNoValida();
            break;
        }

        // Pausa despu�s de ejecutar cada opci�n para que el usuario vea el resultado
        std::cout << "\nPresione cualquier tecla para continuar...\n";
        std::cin.get();  // Esperar entrada para pausar
        std::cin.get();  // Capturar la tecla de continuar
    } while (opcion != 'q');  // Cambiar a 'q' o cualquier otra tecla de salida
}
