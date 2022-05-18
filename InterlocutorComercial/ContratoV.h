/*
Crear un clase ContratoV.h que contenga todos los atributos y métodos que permitan cargar un contrato.h
*/
#pragma once
#include "ContratoRN.h"

class ContratoV
{
public:
	ContratoV();
	ContratoV(string nombreArchivo);
	~ContratoV();
	void setNombreArchivo(string nombreArchivo);
	void setContrato(Contrato& contrato);
	string getNombreArchivo();
	Contrato getContrato();
	InterlocutorComercial BuscarInterlocutorComercialPorID();
	Contrato BuscarContrato();
	void MenuContrato();
	bool NuevoContrato();
	bool ModificarContrato();
private:
	string nombreArchivo;
	InterlocutorComercial interlocutorComercial;
	Contrato contrato;
};