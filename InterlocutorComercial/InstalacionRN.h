#pragma once

#include "Medidor.h"
#include "instalacionAD.h"
#include "InterlocutorComercialRN.h"

class InstalacionRN
{
public:
	InstalacionRN(string nombreArchivo);
	~InstalacionRN();
	Medidor BuscarCInstalacionr(long idInstalacion);
	bool ControlModificacion(Instalacion& instalacion);
	bool AltaInstalacion(Instalacion& instalacion);
	long CantidadInstalaciones(bool soloActivos);
	string getNombreArchivo();
	vector<Instalacion> getMedidores(bool soloActivos);
	void setNombreArchivo(string nombre);
	bool InterlocutorOK(InterlocutorComercial interlocutorComercial);
	long IdContratoNuevo();

private:
	InstalacionAD medidorAD;
	string nombreArchivo;
};