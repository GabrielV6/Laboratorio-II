#pragma once

#include "Instalacion.h"
#include "InterlocutorComercial.h"

class InstalacionV
{
public:
	InstalacionV();
	InstalacionV(string nombreArchivo);
	~InstalacionV();
	void setNombreArchivo(string nombreArchivo);
	void setInstalacion(Instalacion& instalacion);
	string getNombreArchivo();
	Instalacion getInstalacion();
	InterlocutorComercial BuscarInterlocutorComercialPorID();
	Instalacion BuscarContrato();
	void MenuInstalacion();
	bool NuevoInstalacion();
	bool ModificarInstalacion();
private:
	string nombreArchivo;
	InterlocutorComercial interlocutorComercial;
	Instalacion instalacion;
};