#include "UsuarioV.h"

/// <summary>
/// Incio solo para probar la clase no se debe poner para el resto del proyecto.
/// </summary>
/// <returns></returns>
const string NOMBRE_ARCH = "usuarios.dat";
int main()
{
	UsuarioV userVista(NOMBRE_ARCH);
	userVista.MenuUsuario();
	return EXIT_SUCCESS;
}