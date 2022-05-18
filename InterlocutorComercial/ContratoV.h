/*
Crear un clase ContratoV.h que contenga todos los atributos y métodos que permitan cargar un contrato.h
*/
#pragma once
#include "ContratoRN.h"

class ContratoV
{
public:
	ContratoV();
	ContratoV(string nombreArchivo, InterlocutorComercial& interCom, Contrato contrato);
	~ContratoV();
	void setNombreArchivo(string nombreArchivo);	
	void setInterlocutorComercial(InterlocutorComercial& interCom);
	void setContrato(Contrato& contrato);
	string getNombreArchivo();
	InterlocutorComercial getInterlocutorComercial();	
	Contrato getContrato();
	void MenuContrato();
	bool NuevoContrato();
	bool ModificarContrato();
private:
	string nombreArchivo;
	InterlocutorComercial InterlocutorComercial;
	Contrato Contrato;
};