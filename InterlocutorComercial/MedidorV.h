#pragma once

#include "MedidorRN.h"

class MedidorV
{
private:
	Medidor medidor;
	MedidorRN medidorRN;
	string nombreArchivo;
	string separador = "-------------------------------------------------------------------------------------------------------------";

public:
	MedidorV(string nombreArchivo);
	~MedidorV();
	
	void setMedidor(Medidor& medidor);
	void setNombreArchivo(string nombreArchivo);

	string getNombreArchivo();
	Medidor getMedidor();
	Medidor BuscarMedidorPorID();

	void MenuMedidor();
	void NuevoMedidor();
	void ListarMedidor();
	bool ModificarMedidor();

};