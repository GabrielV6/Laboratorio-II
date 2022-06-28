
#include "InterfaceSalida.h"


int main()
{	
	setlocale(LC_CTYPE, "Spanish");
	InterfaceSalida interSalida;
	interSalida.MenuPrincipal();
	//interSalida.LeeTextosEntradaInterlocutor("InterlocutoresMock.csv");
	return EXIT_SUCCESS;
}