#pragma once
#include "ContratoAD.h"
#include "InterlocutorComercialRN.h"

class ContratoRN
{
public:
	ContratoRN();
	~ContratoRN();
	Contrato BuscarContrato(long idContrato);
	bool ControlModificacion(Contrato& contrato);
	bool AltaContrato(Contrato& contrato);
	long CantidadContratos(bool soloActivos);
	string getNombreArchivo();
	vector<Contrato> getContratos(bool soloActivos);
	void setNombreArchivo(string nombre);	

private:
	ContratoAD contratoAD;
	string nombreArchivo;
	bool InterlocutorOK(InterlocutorComercial interlocutorComercial);
};