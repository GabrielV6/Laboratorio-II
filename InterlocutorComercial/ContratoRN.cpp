#include "ContratoRN.h"

ContratoRN::ContratoRN()
{

}
ContratoRN::~ContratoRN()
{}
Contrato ContratoRN::BuscarContrato(long idContrato)
{}
bool ContratoRN::ControlModificacion(Contrato& contrato)
{}
bool ContratoRN::AltaContrato(Contrato& contrato)
{}
long ContratoRN::CantidadContratos(bool soloActivos)
{}
string ContratoRN::getNombreArchivo()
{}
vector<Contrato> ContratoRN::getContratos(bool soloActivos)
{}
void ContratoRN::setNombreArchivo(string nombre)
{}
bool ContratoRN::InterlocutorOK(InterlocutorComercial interlocutor)
{
	return true;
}