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
	bool ExisteInterlocutorComercial(long dni);
	InterlocutorComercial BuscarInterlocutorComercial(long dni);
	bool AltaInterlocutorComercial(InterlocutorComercial& interlocutorComercial);
	bool ModificaInterlocutorComercial(InterlocutorComercial& interlocutorComercial);
	long CantidadInterlocutoresEnSistema();
	string getNombreArchivo();
	vector<InterlocutorComercial> VectorInterlocutores();
	void setNombreArchivo(string nombreArchivo);
};