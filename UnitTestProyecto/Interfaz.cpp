#include "Interfaz.h"

char Interfaz::buscadorPrincipal(Browser& b)
{
    char op;
    try {
        system("cls");
        std::cout << std::endl;
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
    }
    catch (const std::exception& e) {
        std::cerr << "Error en el buscador principal: " << e.what() << std::endl;
        op = ' ';
    }
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
    if (navegador.getPestanias().empty()) {
        std::cout << "No hay Pestania abiertas..." << std::endl;
        return;
    }

    try {
        // Obtener la página actual en la Pestania actual
        SitioWeb pagina = navegador.getPestaniaEnPos(navegador.getPestaniaActual()).getHistorial().obtenerPaginaActual();

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
        std::cout << std::endl;
        std::cout << " Presiones 'q' para salir...                                    " << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "================= Pestania #" << navegador.getPestaniaActual() << " =================\n";
        std::cout << "URL: " << pagina.getUrl() << "\n";
        std::cout << "Titulo: " << pagina.getTitulo() << "\n";
        std::cout << "===============================================\n";
    } 
    catch (const std::exception& e) {
        std::cerr << "Error al mostrar la pagina actual: " << e.what() << std::endl;
    }
}

void Interfaz::irAlSitioWeb(Browser& navegador)  // Pasar navegador por referencia
{
    std::string urlIngresada;
    CSV csv;  // Crear instancia para cargar y buscar en el CSV
    std::string archivo = "sitiosWeb.csv";

    try {
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
            if (navegador.getPestaniaActualReal().getHistorial().getHistorialSize() < navegador.getLimiteHistorial()) {
                navegador.agregarSitioWeb(sitioEncontrado);
                //navegador.getPestaniaEnPos(navegador.getPestaniaActual()).getHistorial().agregarPagina(sitioEncontrado);
               
            }else{
                std::cout << "No hay espacio para mas sitios... " << std::endl;
                system("pause");
            }
            // Mostrar la página actual
            /*mostrarPaginaActual(navegador);*/
        }
        else {
            // Si no se encuentra, mostrar el error
            std::cout << sitioEncontrado.getTitulo() << std::endl;  // "404 - Not Found"
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error al ir al sitio web: " << e.what() << std::endl;
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

    if (sitioEncontrado.getUrl() != "404 - Not Found") {
        // Si la URL fue encontrada, mostrar URL y título
        
        for (SitioWeb sitio : b.getPestaniaActualReal().getHistorial().getLista()) {
            if (sitio.getUrl() == sitioEncontrado.getUrl()) {
                std::cout << " Sitio encontrado en el historial" << std::endl;
                for (Bookmark bo : b.getPestaniaActualReal().geVectortBookmarks()) {
                    if (sitioEncontrado.getUrl() == bo.getURL()) {
                        std::cout << "Este sitio ya es un bookmark en esta pestania" << "\n";
                        system("pause");
                        return;
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

                b.getPestaniaActualReal().agregarBookmark(bo);
                return;
            }
        }

        
        std::cout << "Sitio no se encuentra en el historial de esta pestania... " << std::endl;
       
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
  
    b.getPestaniaActualReal().mostrarBookmarks();
    system("pause");
}

void Interfaz::busquedaFiltros(Browser& b)
{
    std::string op;
    system("cls");
    try {
        std::cout << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "                            BUSQUEDA/FILTRAR                    " << std::endl;
        std::cout << " Ingrese un titulo o parte de este: " << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin, op);

        std::vector<std::pair<std::string, std::string>> coincidencias; // contendra las coincidencias

        for (auto& Pestania : b.getPestanias()) { // recorre cada historias registrado en cada una de las Pestanias
            auto& historial = Pestania.getHistorial();
            for (const auto& pagina : historial.obtenerHistorial()) {
                if (pagina.second.find(op) != std::string::npos) {
                    coincidencias.emplace_back(pagina.second, pagina.first);    // guarda la pagina si coincide
                }
            }
        }
        if (!coincidencias.empty()) {   // si encuentra al menos una coincidencia, crea una nueva Pestania
            int nuevaPestania = b.nuevaPestania();
            auto& nuevaHistorial = b.getPestaniaEnPos(nuevaPestania).getHistorial();

            std::set<std::pair<std::string, std::string>> agregadas;

            for (const auto& coincidencia : coincidencias) {
                SitioWeb encontrados(coincidencia.first, coincidencia.second);
                auto entrada = std::make_pair(encontrados.getTitulo(), encontrados.getUrl());

                if (agregadas.find(entrada) == agregadas.end()) {
                    nuevaHistorial.agregarPagina(encontrados);
                    agregadas.insert(entrada);
                }
            }
            b.setPestaniaActual(nuevaPestania);
            std::cout << "Titulos encontrados: " << std::endl;
            for (const auto& coincidencia : coincidencias) {
                std::cout << "Titulo: " << coincidencia.first << " en la URL: " << coincidencia.second << std::endl;
            }
            mostrarPaginaActual(b);
        }
        else {
            std::cout << "No se encontraron títulos..." << std::endl;
        }
        system("pause");
    }
    catch (const std::exception& e) {
        std::cerr << "Error en la busqueda de filtros: " << e.what() << std::endl;
    }
}


std::string Interfaz::incognito(Browser& b)
{
    b.activarIncognitoPestaniaActual();
    system("pause");
    return " ";
}

void Interfaz::importarYExportar(Browser& b)
{
    char op;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                         Exportar e Importar                    " << std::endl;
    std::cout << "Seleccione una opcion: Importar (i) o Exportar(e) los datos: ";
    std::cin >> op;
    try {
        if (op == 'i') {
            Browser* bb = imp(b);
            system("cls");
            mostrarPaginaActual(*bb);
        }
        else if (op == 'e') {
            exp(b);
        }
    }
    catch (const std::exception&) {
        std::cerr << "/////// Error al momento de serializar o deserializar los datos ////////";
    }
}

//void Interfaz::exportarSesion(Browser& navegador) {
//    std::string nombreArchivo;
//    std::cout << "Ingrese el nombre del archivo para exportar la sesión: ";
//    std::cin >> nombreArchivo;
//
//    navegador.exportarSesion(nombreArchivo);
//    std::cout << "Sesión exportada con éxito." << std::endl;
//}
//
//void Interfaz::importarSesion(Browser& navegador){
//    std::string nombreArchivo;
//    std::cout << "Ingrese el nombre del archivo para importar la sesión: ";
//    std::cin >> nombreArchivo;
//
//    navegador.importarSesion(nombreArchivo);
//    std::cout << "Sesión importada con éxito." << std::endl;
//}

Browser* Interfaz::imp(Browser& b)
{
    std::string op;
    std::cout << "Ingrese el nombre de la sesion: ";
    std::cin >> op;

    std::ifstream arch(op + ".bin", std::ios::binary);
    if (!arch) {
        std::cout<<"No se ha podido abrir el archivo";
    }

    Browser* browser = Browser::cargarArchivoNavegador(arch);

    if (browser) {
        std::cout << "Se ha importado." << std::endl;
        system("pause");
    }
    else {
        std::cout<<"No se ha podido importar el historial.";
    }

    arch.close();
    return browser;

}

void Interfaz::exp(Browser& b)
{
    std::string opcion;
    std::cout << "Nombre de la sesiona a guardar: ";
    std::cin >> opcion;

    std::ofstream arch(opcion + ".bin", std::ios::binary);
    if (!arch) {
        std::cout<<"Error: No se ha podido crear el archivo.";
        system("pause");
        return;
    }
    b.guardarArchivoNavegador(arch);
    arch.close();
    std::cout << "Se ha exportado el historial." << std::endl;
    system("pause");
    
}


void Interfaz::nuevaPestania(Browser& b)
{
    b.nuevaPestania();
    
}

void Interfaz::configuracion(Browser& b)
{

    int opcion;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "                            CONFIGURACION                       " << std::endl;
    std::cout << " 1 - Limitar cantidad de sitios por pestania                    " << std::endl;
    std::cout << " 2 - Configurar el tiempo de cada sitio                         " << std::endl;
    std::cout << " Ingrese una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        int cant;
        std::cout << std::endl;
        std::cout << "Ingrese la cantidad de sitios por pestania: ";
        std::cin >> cant;
        if (cant <= 0) {
            std::cout << "Numero incorrecto" << std::endl;

        }else{
            b.setLimiteHistorial(cant);
        }

        break;
    case 2: 
        int tiempo;
        std::cout << std::endl;
        std::cout << "Ingrese la cantidad de minutos: ";
        std::cin >> tiempo;

        if (std::cin.fail()) {
            std::cin.clear();  // Limpia el estado de error de cin
            std::cout << "Entrada no valida. Por favor, ingresa un numero entero.\n";
            system("pause");
        }
        else {
            if (tiempo <= 0) {                                              //Si el tiempo es mayor o diferente de 0
                std::cout << "Valor fuera de rango" << std::endl;
            }
            else {
                if (b.haysitios()) {                                   //Si hay sitios en alguna de las pestanias
                    b.setMinutosDeTodasLasPest(tiempo);
                }
                else {
                    std::cout << "No hay sitios web para modificar... " << std::endl;
                    system("pause");
                }
            }
        }
        break;
    default:
        break;
    }

}


void Interfaz::cambiarPestania(Browser& b, int n) {
    if (n == 72 && b.getPestaniaActual() > 0) {  //Si la tecla que se tocó fue la #72 y solo si la pestania actual no es la 0, se puede ir hacia atras
        b.setPestaniaActual(b.getPestaniaActual() - 1); //Se setea una nueva pestania actual
        mostrarPaginaActual(b);  //Y se muestra la pagina de la nueva pestania actual
     
    }
    if (n == 80 &&  b.existeSigPes() ) {    //Si la tecla que se toco fue la 80 y si siguiente pestania existe
        b.setPestaniaActual(b.getPestaniaActual() + 1);     //Seter pestania actual
        mostrarPaginaActual(b);  //Mostrar pagina de la nueva pestania
      
    }
    
}

void Interfaz::cambiarHistorial(Browser& b, int n) {
    if (n == 75 && b.getPestaniaActualReal().getHistorial().obtenerPaginaActual().getUrl() != "404 - Not Found") {
        if (b.irAtras()) {
            b.getPestaniaActualReal().getHistorial().setPaginaActual(n);
            mostrarPaginaActual(b);
        }
    }
    if (n == 77 && b.getPestaniaActualReal().getHistorial().obtenerPaginaActual().getUrl() != "404 - Not Found") {
        if (b.irAdelante()) {
            b.getPestaniaActualReal().getHistorial().setPaginaActual(n);
            mostrarPaginaActual(b);
        }
    }

}


void Interfaz::eliminarSitios(Browser& b) {
    
    b.verificarSitios();
    
}
