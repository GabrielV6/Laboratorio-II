#pragma once
#include "InterlocutorComercialAD.h"
class InterlocutorComercialRN
{
private:
	InterlocutorComercialAD interlocutorComercialAD;
	string nombreArchivo;
public:
	InterlocutorComercialRN(string nombreArchivo = "");
	~InterlocutorComercialRN();
	InterlocutorComercial BuscarInterlocutorComercial(long dni);
	bool ControlModificaciones(InterlocutorComercial& interlocutorComercial);
	bool AltaInterlocutorComercial(InterlocutorComercial& interlocutorComercial);
	long CantidadInterLocutoresEnSistema();
	string getNombreArchivo();
	vector<InterlocutorComercial> VectorInterlocutores();
	void setNombreArchivo(string nombreArchivo);
};