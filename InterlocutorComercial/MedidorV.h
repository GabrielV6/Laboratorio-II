#pragma once

#include "MedidorRN.h"

class MedidorV
{
public:
	MedidorV();
	MedidorV(string nombreArchivo);
	~MedidorV();
	void setNombreArchivo(string nombreArchivo);
	void setMedidor(Medidor& medidor);
	string getNombreArchivo();
	Medidor getMedidor();
	InterlocutorComercial BuscarInterlocutorComercialPorID();
	Medidor BuscarContrato();
	void MenuMedidor();
	bool NuevoMedidor();
	bool ModificarMedidor();
private:
	string nombreArchivo;
	InterlocutorComercial interlocutorComercial;
	Medidor medidor;
};