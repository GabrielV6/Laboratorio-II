#pragma once

#include "Medidor.h"
#include "MedidorAD.h"


class MedidorRN
{
public:
	MedidorRN(string nombreArchivo);
	MedidorRN();
	~MedidorRN();
	Medidor BuscarCMedidor(long idMedidor);
	bool ModificaMedidor(Medidor& medidor);
	bool AltaMedidor(Medidor& medidor);
	int IdMedidor(Medidor& medidor);
	int CantidadMedidores();
	string getNombreArchivo();
	vector<Medidor> getMedidores(bool soloActivos);
	void setNombreArchivo(string nombre);
	

private:
	MedidorAD medidorAD;
	string nombreArchivo;
};