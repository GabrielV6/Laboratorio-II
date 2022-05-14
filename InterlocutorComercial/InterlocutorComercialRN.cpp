#include "InterlocutorComercialRN.h"

InterlocutorComercialRN::InterlocutorComercialRN(string nombreArchivo)
{
	this->interlocutorComercialAD = InterlocutorComercialAD(nombreArchivo);
}
InterlocutorComercialRN::~InterlocutorComercialRN()
{}
bool InterlocutorComercialRN::AltaInterlocutorComercial(InterlocutorComercial& interlocutorComercial)
{
	return this->interlocutorComercialAD.GuardarEnArchivoInterlocutor(interlocutorComercial);
}
InterlocutorComercial InterlocutorComercialRN::BuscarInterlocutorComercial(long dni)
{
	InterlocutorComercial intComAD = this->interlocutorComercialAD.getInterlocutorArchivo(dni);
	if (intComAD.getDni() == dni)
		return intComAD;
	return InterlocutorComercial();
}
bool InterlocutorComercialRN::ControlModificaciones(InterlocutorComercial& interlocutorComercial)
{
	///Hacer la validadciones correspondientes al interlocutor pasado por parametro
	return true;
}
long InterlocutorComercialRN::CantidadInterLocutoresEnSistema()
{
	return this->interlocutorComercialAD.TotalInterlocutoresEnArchivo();
}
string InterlocutorComercialRN::getNombreArchivo()
{
	return this->nombreArchivo;
}
vector<InterlocutorComercial> InterlocutorComercialRN::VectorInterlocutores()
{
	return this->interlocutorComercialAD.getInterlocutoresArchivo();
}
void InterlocutorComercialRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}