#pragma once

#include "Medidor.h"
#include "MedidorAD.h"
#include "InterlocutorComercialRN.h"

class MedidorRN
{
public:
	MedidorRN(string nombreArchivo);
	~MedidorRN();
	Medidor BuscarCMedidor(long idMedidor);
	bool ControlModificacion(Medidor& medidor);
	bool AltaMedidor(Medidor& medidor);
	long CantidadMedidores(bool soloActivos);
	string getNombreArchivo();
	vector<Medidor> getMedidores(bool soloActivos);
	void setNombreArchivo(string nombre);
	bool InterlocutorOK(InterlocutorComercial interlocutorComercial);
	long IdContratoNuevo();

private:
	MedidorAD medidorAD;
	string nombreArchivo;
};