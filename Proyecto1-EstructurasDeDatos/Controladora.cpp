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
    //bool ejecutar = true;

    //// Bucle infinito hasta que el usuario lo detenga
    //while (ejecutar) {
    //    // Mostrar la pestaña actual y su historial
    //    system("cls");  // Limpiar la pantalla
    //   /* Interfaz::mostrarMenu(); */ // Mostrar el menú
    //    Interfaz::mostrarPaginaActual(*browser);  // Mostrar la página actual

    //    // Capturar teclas
    //    int tecla = _getch();  // Capturar una tecla
    //    if (tecla == 0 || tecla == 224) {  // Teclas especiales (flechas)
    //        tecla = _getch();  // Capturar el segundo valor de la tecla especial

    //        switch (tecla) {
    //        case 72:  // Flecha arriba
    //            browser->cambiarPestaña(browser->getPestañaActual() - 1);  // Cambiar a la pestaña anterior
    //            break;
    //        case 80:  // Flecha abajo
    //            browser->cambiarPestaña(browser->getPestañaActual() + 1);  // Cambiar a la siguiente pestaña
    //            break;
    //        case 75:  // Flecha izquierda
    //            browser->irAtras();  // Ir al historial anterior
    //            break;
    //        case 77:  // Flecha derecha
    //            browser->irAdelante();  // Ir al historial siguiente
    //            break;
    //        }
    //    }
    //    else if (tecla == 'q') {  // Presionar 'q' para salir del bucle
    //        ejecutar = false;
    //    }

    //    // Pausar para ver el resultado antes de volver al bucle
    //    std::cout << "\nPresione 'q' para salir o use las flechas para navegar.\n";
    //}
    do {
        // Mostrar el menú antes de cada operación
        system("cls");  // Limpiar la pantalla
        /*Interfaz::mostrarMenu(); */ // Mostrar el menú en la parte superior
        /*Interfaz::mostrarPaginaActual(*browser);*/
        opcion = Interfaz::buscadorPrincipal(*browser);

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
        case 'e':
            Interfaz::busquedaFiltros(*browser);
        default:
           // Interfaz::msjOpcionNoValida();
            break;
        }

        // Pausa después de ejecutar cada opción para que el usuario vea el resultado
        //std::cout << "\nPresione cualquier tecla para continuar...\n";
        //std::cin.get();  // Esperar entrada para pausar
        //std::cin.get();  // Capturar la tecla de continuar
    } while (opcion != 'q');  // Cambiar a 'q' o cualquier otra tecla de salida
}
