#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Daniel\source\repos\Jdacm14\Proyecto1-EstructurasDeDatos\Proyecto1-EstructurasDeDatos\HistorialNavegacion.h"
#include "C:\Users\Daniel\source\repos\Jdacm14\Proyecto1-EstructurasDeDatos\Proyecto1-EstructurasDeDatos\SitioWeb.h"
#include "C:\Users\Daniel\source\repos\Jdacm14\Proyecto1-EstructurasDeDatos\Proyecto1-EstructurasDeDatos\Pestania.h"
#include "C:\Users\Daniel\source\repos\Jdacm14\Proyecto1-EstructurasDeDatos\Proyecto1-EstructurasDeDatos\Bookmark.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProyecto
{
	TEST_CLASS(UnitTestProyecto)
	{
	public:

        // test para agregarPagina() de HistorialNavegacion.h
        TEST_METHOD(TestAgregarPagina) {
            HistorialNavegacion historial(5); // lo inicia con un limite de entradas

            SitioWeb pagina1("www.prueba1.com", "Prueba1");
            SitioWeb pagina2("www.prueba2.com", "Prueba2");
            // se crean los sitios web para posteriomente agregarlos

            historial.agregarPagina(pagina1);

            Assert::AreEqual(static_cast<size_t>(1), historial.getHistorialSize(), L"El tamaño del historial debería ser 1."); // verifica que el historial tiene 1 entrada

            SitioWeb& actual = historial.obtenerPaginaActual();
            Assert::AreEqual(std::string("www.prueba1.com"), actual.getUrl(), L"La URL de la página actual debería ser 'www.prueba1.com'.");
            Assert::AreEqual(std::string("Prueba1"), actual.getTitulo(), L"El titulo de la página actual debería ser 'Prueba1'.");
            // luego verifica si es la que agregamos

            historial.agregarPagina(pagina2);

            Assert::AreEqual(static_cast<size_t>(2), historial.getHistorialSize(), L"El tamaño del historial debería ser 2.");  // verifica que hayan dos entradas

            SitioWeb& actual2 = historial.obtenerPaginaActual();
            Assert::AreEqual(std::string("www.prueba2.com"), actual2.getUrl(), L"La URL de la página actual debería ser 'www.prueba2.com'.");
            Assert::AreEqual(std::string("Prueba2"), actual2.getTitulo(), L"El titulo de la página actual debería ser 'Prueba2'.");
        }
        // test para limpiarHistorial() de HistorialNavegacion.h
        TEST_METHOD(TestLimpiarHistorial) {
            HistorialNavegacion historial(5);
            SitioWeb sitio1("www.prueba1.com", "Prueba1");
            SitioWeb sitio2("Prueba2", "www.prueba2.com");

            historial.agregarPagina(sitio1);
            historial.agregarPagina(sitio2);

            Assert::AreEqual(static_cast<size_t>(2), historial.getHistorialSize()); // verifica que hayan 2 entradas

            historial.limpiarHistorial();

            Assert::AreEqual(static_cast<size_t>(0), historial.getHistorialSize()); // verifica que el tamaño sea 0
        }

        // test para ObtenerHistorial() de HistorialNavegacion.h
        TEST_METHOD(TestObtenerHistorial) {
            HistorialNavegacion historial(5);
            SitioWeb sitio1("www.prueba1.com", "Prueba1");
            SitioWeb sitio2("www.prueba2.com", "Prueba2");

            historial.agregarPagina(sitio1);
            historial.agregarPagina(sitio2);

            auto historialDevuelto = historial.obtenerHistorial();  // devuelve el historial

            Assert::AreEqual(static_cast<size_t>(2), historialDevuelto.size()); // verifica que contenga 2 entradas

            Assert::AreEqual(std::string("www.prueba1.com"), historialDevuelto.front().first);
            Assert::AreEqual(std::string("Prueba1"), historialDevuelto.front().second);
            Assert::AreEqual(std::string("www.prueba2.com"), historialDevuelto.back().first);
            Assert::AreEqual(std::string("Prueba2"), historialDevuelto.back().second);
        }

        // test para LimpiarHistorialVentana() de Pestania.h
        TEST_METHOD(TestLimpiarHistorialVentana) {
            Pestania pestania;
            SitioWeb sitio1("www.prueba1.com", "Prueba1");
            SitioWeb sitio2("www.pagina2.com", "Página 2");

            pestania.getHistorial().agregarPagina(sitio1);
            pestania.getHistorial().agregarPagina(sitio2);

            Assert::AreEqual(static_cast<size_t>(2), pestania.getHistorial().getHistorialSize()); // Verifica que haya 2 entradas 

            pestania.limpiarHistorialVentana(); // borra

            Assert::AreEqual(static_cast<size_t>(0), pestania.getHistorial().getHistorialSize()); // Verifica hayan 0 entradas
        }

        // test para agregarEtiqueta de Bookmark.h
        TEST_METHOD(TestAgregarEtiqueta) {
            Bookmark bookmark("www.prueba1.com", "Prueba1");
            std::string etiqueta = "etiqueta1";

            bookmark.agregarEtiqueta(etiqueta); 

            Assert::IsTrue(bookmark.tieneEtiqueta(etiqueta));   // verifica que se haya agregado
        }

        // test para mostrarEtiquetas() de Bookmark.h
        TEST_METHOD(TestMostrarEtiquetas) {
            Bookmark bookmark("www.prueba1.com", "Prueba1");
            std::string etiqueta1 = "etiqueta1";
            std::string etiqueta2 = "etiqueta2";

            bookmark.agregarEtiqueta(etiqueta1);
            bookmark.agregarEtiqueta(etiqueta2);

            // Captura de salida estándar
            std::streambuf* orig = std::cout.rdbuf();  // guarda el buffer
            std::stringstream ss;                      
            std::cout.rdbuf(ss.rdbuf());    // manda la salida al stringstream

            bookmark.mostrarEtiquetas();  // Mostrar etiquetas

            std::cout.rdbuf(orig);  // restaurar el buffer

            std::string salida = "Etiquetas: etiqueta1 etiqueta2 \n";  
            Assert::AreEqual(salida, ss.str());  // Verificar que la salida sea correcta
        }

        // test para tieneEtiqueta() de Bookmark.h
        TEST_METHOD(TestTieneEtiqueta) {
            Bookmark bookmark("www.prueba1.com", "Prueba1");
            std::string etiqueta1 = "etiqueta1";
            std::string etiqueta2 = "etiqueta2";

            bookmark.agregarEtiqueta(etiqueta1); 

            Assert::IsTrue(bookmark.tieneEtiqueta(etiqueta1));  // verificar que tiene esa etiqueda

            Assert::IsFalse(bookmark.tieneEtiqueta(etiqueta2)); // verificar que no tenga una que no se haya agregado
        }
	};
}
