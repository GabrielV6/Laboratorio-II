#include "InterlocutorComercialV.h"

/// <summary>
/// Incio solo para probar la clase no se debe poner para el resto del proyecto.
/// </summary>
/// <returns></returns>
const string NOMBRE_ARCH = "interlocutores.dat";
int main()
{
	//Prueba de conexion Gabriel v.1
	InterlocutorComercialV interVista(NOMBRE_ARCH);
	interVista.MenuInterlocutorComecial();
	return EXIT_SUCCESS;
}