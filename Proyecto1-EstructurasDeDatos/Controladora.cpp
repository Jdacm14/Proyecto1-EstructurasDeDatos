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
        // Mostrar el menú antes de cada operación
        system("cls");  // Limpiar la pantalla
        Interfaz::mostrarMenu();  // Mostrar el menú en la parte superior

        Interfaz::mostrarPaginaActual(*browser);

        opcion = Interfaz::buscadorPrincipal();

        // Ejecutar la opción seleccionada
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

        // Pausa después de ejecutar cada opción para que el usuario vea el resultado
        std::cout << "\nPresione cualquier tecla para continuar...\n";
        std::cin.get();  // Esperar entrada para pausar
        std::cin.get();  // Capturar la tecla de continuar
    } while (opcion != 'q');  // Cambiar a 'q' o cualquier otra tecla de salida
}
