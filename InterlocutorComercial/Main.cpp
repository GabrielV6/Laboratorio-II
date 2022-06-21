#include "InterlocutorComercialV.h"
#include "MedidorV.h"
#include "Validaciones.h"

/// <summary>
/// Incio solo para probar la clase no se debe poner para el resto del proyecto.
/// </summary>
/// <returns></returns>
const string NOMBRE_ARCH = "interlocutores.dat";
const string NOMBRE_ARCH_MED = "medidores.dat";

int main()
{
	
	setlocale(LC_CTYPE, "Spanish");
	//InterlocutorComercialV interVista(NOMBRE_ARCH);
	//interVista.MenuInterlocutorComecial();

	MedidorV medidor(NOMBRE_ARCH_MED);
	medidor.MenuMedidor();


	return EXIT_SUCCESS;
}