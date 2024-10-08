#include "Controladora.h"

Controladora::Controladora()
{
    seguirVerificando = true;
	browser = new Browser();
	opcion = ' ';
}

Controladora::~Controladora()
{
	delete browser;
}

void Controladora::msjOpcionNoValida()
{
    std::cout << "Opcion no valida, por favor ingrese una de las opciones ofrecidas" << std::endl;
}

void Controladora::verificarSitiosEliminados()
{
    while (seguirVerificando) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));      //Verifica cada 0.1 segundos
        if(seguirVerificando) {
            Interfaz::eliminarSitios(*browser);  // Solo se ejecuta si seguirVerificando es true
        }
    }
}

void Controladora::controlMenuGeneral()
{
    // Bucle infinito hasta que el usuario lo detenga
    std::thread verificador(&Controladora::verificarSitiosEliminados, this); //Hilo que verifica si el tiempo de vida de un sitio web se acabó

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
                Interfaz::cambiarPestania(*browser, 72); // Ir a la siguiente pestania
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
            default:
                
                break;
            }
           
        }
        else if (tecla == 'q') {// Presionar 'q' para salir del bucle
            seguirVerificando = false;
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
                Interfaz::importarYExportar(*browser);
                break;
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
        
        
    } while (true);  // Bucle infinito hasta que se presione 'q'

    if (verificador.joinable()) {
        verificador.join();
    }
}


