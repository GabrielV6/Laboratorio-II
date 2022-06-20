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
	//Busca el total de interlocuteres, lo incrementa en 1 y le suma 1000 
	int id = this->interlocutorComercialAD.TotalInterlocutoresEnArchivo();
	if (id == -1)
		id = 0;
	id += 1001;
	interlocutorComercial.setId_ic(id);
	return this->interlocutorComercialAD.GuardarEnArchivoInterlocutor(interlocutorComercial);
}
bool InterlocutorComercialRN::ModificaInterlocutorComercial(InterlocutorComercial& interlocutorComercial)
{
	return this->interlocutorComercialAD.ActualizarEnArchivoIneterlocurtor(interlocutorComercial);
}
bool InterlocutorComercialRN::ExisteInterlocutorComercial(int dni)
{
	InterlocutorComercial intlocutorExiste = this->BuscarInterlocutorComercial(dni);
	if (intlocutorExiste.getNombre() == "" && intlocutorExiste.getApellido() == "")
		return false;
	return true;
}
InterlocutorComercial InterlocutorComercialRN::BuscarInterlocutorComercial(int dni)
{
	InterlocutorComercial intComAD = this->interlocutorComercialAD.getInterlocutorArchivo(dni);
	if (intComAD.getDni() == dni)
		return intComAD;
	return InterlocutorComercial();
}
int InterlocutorComercialRN::CantidadInterlocutoresEnSistema()
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