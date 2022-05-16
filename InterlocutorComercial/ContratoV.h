/*
Crear un clase ContratoV.h que contenga todos los atributos y métodos que permitan cargar un contrato.h
*/
#include "ContratoRN.h"

class ContratoV
{
private:
	string nombreArchivo;
	InterlocutorComercial InterlocutorComercial;
	Contrato Contrato;
public:
	ContratoV();
	ContratoV(string nombreArchivo, InterlocutorComercial& interCom, Contrato contrato);
	~ContratoV();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	void setInterlocutorComercial(InterlocutorComercial& interCom);
	InterlocutorComercial getInterlocutorComercial();
	void setContrato(Contrato& contrato);
	Contrato getContrato();
	void MenuContrato();
	bool NuevoContrato();
	bool ModificarContrato();
};