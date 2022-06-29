
#include "InterfaceSalida.h"


int main()
{	
	setlocale(LC_CTYPE, "Spanish");
	InterfaceSalida interSalida;
	interSalida.MenuPrincipal();


	
	//interSalida.LeeTextosEntradaInterlocutor("InterlocutoresMock.csv");
	//interSalida.LeeTextosEntrada("MedidorCsv.csv");
	return EXIT_SUCCESS;
}