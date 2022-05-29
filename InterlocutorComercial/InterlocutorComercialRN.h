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
	bool ExisteInterlocutorComercial(int dni);
	InterlocutorComercial BuscarInterlocutorComercial(int dni);
	bool AltaInterlocutorComercial(InterlocutorComercial& interlocutorComercial);
	bool ModificaInterlocutorComercial(InterlocutorComercial& interlocutorComercial);
	int CantidadInterlocutoresEnSistema();
	string getNombreArchivo();
	vector<InterlocutorComercial> VectorInterlocutores();
	void setNombreArchivo(string nombreArchivo);
};