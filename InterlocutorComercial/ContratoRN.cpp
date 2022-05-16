#include "ContratoRN.h"

ContratoRN::ContratoRN(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
ContratoRN::~ContratoRN()
{}
Contrato ContratoRN::BuscarContrato(long idContrato)
{
	return	this->contratoAD.getContratoArchivo(idContrato);
}
bool ContratoRN::ControlModificacion(Contrato& contrato)
{
	//Generar todos los controles para validar la modificaciones
	return true;
}
bool ContratoRN::AltaContrato(Contrato& contrato)
{
	return true;
}
long ContratoRN::CantidadContratos(bool soloActivos)
{
	long cant = 0;
	vector<Contrato> contratos = this->contratoAD.getContratosArchivo();
	for (auto contrato : contratos)
	{
		if (soloActivos && contrato.getActivo())
			cant++;
		else
			cant++;
	}
	return cant;
}
string ContratoRN::getNombreArchivo()
{
	return this->nombreArchivo;
}
vector<Contrato> ContratoRN::getContratos(bool soloActivos)
{
	vector<Contrato> contratos = this->contratoAD.getContratosArchivo();
	vector<Contrato> contratosAux;
	for (auto &contrato : contratos)
	{
		if (soloActivos && contrato.getActivo())
			contratosAux.push_back(contrato);
		else
			contratosAux.push_back(contrato);
	}
	return contratosAux;
}
void ContratoRN::setNombreArchivo(string nombre)
{
	this->nombreArchivo = nombre;
}
bool ContratoRN::InterlocutorOK(InterlocutorComercial interlocutor)
{
	//Validacion sobre el interlocutor
	return true;
}