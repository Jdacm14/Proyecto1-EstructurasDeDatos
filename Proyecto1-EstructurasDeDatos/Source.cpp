
//pair (Estructura)
//https://learn.microsoft.com/es-es/cpp/standard-library/pair-structure?view=msvc-170

//auto (C++)
// https://learn.microsoft.com/es-es/cpp/cpp/auto-cpp?view=msvc-170 

//clase string
// https://cplusplus.com/reference/string/string/

//para las  prubas unitarias usando el proyecto nativo de Microsof Visual Studio
// https://www.youtube.com/watch?v=IcPqONZEKAo&t=282s


#include"Controladora.h"


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Controladora Co;
	Co.controlMenuGeneral();

	system("pause");

	_CrtDumpMemoryLeaks();
	return 0;
}

