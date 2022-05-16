#pragma once
#include <vector>
#include "Contrato.h"

class ContratoAD
{
public:

	ContratoAD(string nombreArchivo = "");
	~ContratoAD();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	long TotalContratosEnArchivo();
	bool GuardarEnArchivoContrato(Contrato& contrato);
	bool ActualizarEnArchivoContrato(Contrato& contrato);
	Contrato getContratoArchivo(long dni);
	vector<Contrato> getContratosArchivo();
private:
	string nombreArchivo;
	Contrato contrato;
};