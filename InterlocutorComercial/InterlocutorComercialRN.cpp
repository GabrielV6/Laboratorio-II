#include "InterlocutorComercialRN.h"

InterlocutorComercialRN::InterlocutorComercialRN(string nombreArchivo)
{
	this->interlocutorComercialAD = InterlocutorComercialAD(nombreArchivo);
}
InterlocutorComercialRN::~InterlocutorComercialRN()
{}
bool InterlocutorComercialRN::AltaInterlocutorComercial(InterlocutorComercial& interlocutorComercial)
{
	//Ver si se hace una busqueda en el archivo de interlocutores para asignar el númerador de id
	interlocutorComercial.setId_ic(interlocutorComercial.getDni());
	return this->interlocutorComercialAD.GuardarEnArchivoInterlocutor(interlocutorComercial);
}
bool InterlocutorComercialRN::ModificaInterlocutorComercial(InterlocutorComercial& interlocutorComercial)
{
	return this->interlocutorComercialAD.ActualizarEnArchivoIneterlocurtor(interlocutorComercial);
}
bool InterlocutorComercialRN::ExisteInterlocutorComercial(long dni)
{
	InterlocutorComercial intlocutorExiste = this->BuscarInterlocutorComercial(dni);
	if (intlocutorExiste.getNombre() != "" || intlocutorExiste.getApellido() != "")
		return false;
	return true;
}
InterlocutorComercial InterlocutorComercialRN::BuscarInterlocutorComercial(long dni)
{
	InterlocutorComercial intComAD = this->interlocutorComercialAD.getInterlocutorArchivo(dni);
	if (intComAD.getDni() == dni)
		return intComAD;
	return InterlocutorComercial();
}
string InterlocutorComercialRN::ControlModificaciones(InterlocutorComercial& interlocutorComercial)
{	
	if (interlocutorComercial.getNombre() == "")
		return "No se cargo nombre al inerlocutor comercial\n";
	if (interlocutorComercial.getApellido() == "")
		return "No se cargo apellido al inerlocutor comercial\n";;
	string correo = interlocutorComercial.getEmail();
	string letra = "@";
	if (!strstr(correo.c_str(), letra.c_str()))
		return "No se cargo correctamente el correo al inerlocutor comercial\n";;

	return "OK";
}
long InterlocutorComercialRN::CantidadInterlocutoresEnSistema()
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