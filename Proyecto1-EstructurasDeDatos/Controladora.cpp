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
    // Bucle infinito hasta que el usuario lo detenga
    do {
        // Mostrar el menú y la pestaña actual
        system("cls");  // Limpiar la pantalla
        
        Interfaz::mostrarPaginaActual(*browser); // Mostrar la página actual
        

        // Capturar teclas
        int tecla = _getch();            // Capturar una tecla
        if (tecla == 0 || tecla == 224) {  // Teclas especiales (flechas)
            tecla = _getch();  // Capturar el segundo valor de la tecla especial

            switch (tecla) {
            case 72:  // Flecha arriba
                Interfaz::cambiarPestania(*browser, 72); // Ir a la siguiente pestannia
                break;
            case 80:  // Flecha abajo
                Interfaz::cambiarPestania(*browser, 80); //Ir a la pestania anterior
                break;
            case 75:  // Flecha izquierda
                Interfaz::cambiarHistorial(*browser, 75);  // Ir al historial anterior
                break;
            case 77:  // Flecha derecha
                Interfaz::cambiarHistorial(*browser, 77);  // Ir al historial siguiente
                break;
            }

            //system("cls");
        }
        else if (tecla == 'q') {  // Presionar 'q' para salir del bucle
            break; // Salir del bucle
        }
        else {
            // Manejo de otras opciones del menú
            opcion = Interfaz::buscadorPrincipal(*browser);  // Captura la opción del menú

            // Ejecutar la opción seleccionada
            switch (opcion) {
            case 'a':
                Interfaz::irAlSitioWeb(*browser);
                break;
            case 'b':
                Interfaz::agregarBookmark(*browser);
                break;
            case 'c':
                //Interfaz::a
            case 'd':
                Interfaz::verBookmarks(*browser);
                break;
            case 'e':
                Interfaz::busquedaFiltros(*browser);
                break;
            case 'f':
                Interfaz::incognito(*browser);
                break;
            case 'g':
                Interfaz::nuevaPestania(*browser);
                break;
            case 'h':
                Interfaz::configuracion(*browser);
                break;
            default:
                msjOpcionNoValida(); // Mostrar mensaje de opción no válida
                break;
            }

        }
        
        // Pausa para mostrar el resultado
        std::cout << "\nPresione 'q' para salir o use las flechas para navegar.\n";
        
    } while (true);  // Bucle infinito hasta que se presione 'q'


}
