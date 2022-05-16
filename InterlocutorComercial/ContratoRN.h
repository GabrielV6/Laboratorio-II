#pragma once
#include "ContratoAD.h"

class ContratoRN
{
public:
	ContratoRN(string nombreArchivo);
	~ContratoRN();
	Contrato BuscarContrato(long idContrato);
	bool ControlModificacion(Contrato& contrato);
	bool AltaContrato(Contrato& contrato);
	long CantidadContratos(bool soloActivos);
	string getNombreArchivo();
	vector<Contrato> getContratos(bool soloActivos);
	void setNombreArchivo(string nombre);	
	bool InterlocutorOK(InterlocutorComercial interlocutorComercial);

private:
	ContratoAD contratoAD;
	string nombreArchivo;	
};