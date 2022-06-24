#include "InterlocutorComercialV.h"
#include "MedidorV.h"
#include "Validaciones.h"
#include "DocumentoV.h"

/// <summary>
/// Incio solo para probar la clase no se debe poner para el resto del proyecto.
/// </summary>
/// <returns></returns>
const string NOMBRE_ARCH = "interlocutores.dat";
const string NOMBRE_ARCH_MED = "medidores.dat";
const string NOMBRE_ARCH_DOC = "documentos.dat";

int main()
{
	
	setlocale(LC_CTYPE, "Spanish");
	//InterlocutorComercialV interVista(NOMBRE_ARCH);
	//interVista.MenuInterlocutorComecial();
	DocumentoV documento(NOMBRE_ARCH);
	documento.MenuDocumento();

	//MedidorV medidor(NOMBRE_ARCH_MED);
	//medidor.MenuMedidor();


	return EXIT_SUCCESS;
}