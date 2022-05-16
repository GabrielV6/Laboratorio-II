/*
Crear un clase ContratoV.h que contenga todos los atributos y métodos que permitan cargar un contrato.h
*/
#include "ContratoRN.h"

class ContratoV
{
private:
	InterlocutorComercial InterlocutorComercial;
	Contrato Contrato;
public:
	ContratoV(InterlocutorComercial interlocutorComercial = InterlocutorComercial(), Contrato contrato);
	~ContratoV();
	void setInterlocutorComercial(InterlocutorComercial& interCom);
	InterlocutorComercial& getInterlocutorComercial();
	void setContrato(Contrato& contrato);
	Contrato& getContrato();
	void MenuContrato();
	bool NuevoContrato();
	bool ModificarContrato();
};