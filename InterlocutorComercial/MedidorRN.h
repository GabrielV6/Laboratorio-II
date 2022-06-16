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
	bool AltaMedidor(Medidor& medidor);
	int CantidadMedidores();
	string getNombreArchivo();
	vector<Medidor> getMedidores(bool soloActivos);
	void setNombreArchivo(string nombre);
	
	

private:
	MedidorAD medidorAD;
	string nombreArchivo;
};