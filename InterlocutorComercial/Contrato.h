/*
 Crear una clase Contrato Contrato que firmara la empresa con el cliente.
 Atributos:
-ID del contrato (C)
-ID Interlocutor Comercial (IC)
-ID de la Cuenta contrato (CC)
-ID del Medidor
-ID de la instalación
-Zona
-Fecha alta contrato
-Fecha baja contrato
-Tarifas
-Consumo promedio
*/
#pragma once
#include <iostream>
#include "InterlocutorComercialRN.h"
#include "TarifaRN.h"

class Contrato
{

public:
	Contrato();	
	void setIdContrato(int idContrato);
	unsigned int getIdContrato();
	void setIdInterlocutorComercial(unsigned int idInterlocutorComercial);
	unsigned int getIdInterlocutorComercial();
	void setIdCuentaContrato(int idCuentaContrato);
	unsigned int getIdCuentaContrato();
	void setIdMedidor(int idMedidor);
	unsigned int getIdMedidor();
	void setIdInstalacion(int idInstalacion);
	unsigned int getIdInstalacion();
	void setZona(string zona);
	string getZona();
	void setFechaAltaContrato(Fecha fecAlta);
	Fecha getFechaAltaContrato();
	void setFechaBajaContrato(Fecha fecBaja);
	Fecha getFechaBajaContrato();
	void setCodigoTarifa(unsigned int codTarifa);
	unsigned int getCodigoTarifa();
	void setConsumoPromedio(float consumoPromedio);
	float getConsumoPromedio();
	void setPoscicionArchivo(long posicionArchivo);
	long getPosicionArchivo();
	void setActivo(bool activo);
	bool getActivo();
	string toStringContrato();

private:
	unsigned int idContrato;
	unsigned int IdInterlocutorComercial;
	unsigned int idCuentaContrato;
	unsigned int idMedidor;
	unsigned int idInstalacion;
	char zona[40];
	Fecha fechaAltaContrato;
	Fecha fechaBajaContrato;
	unsigned int codigoTarifa;
	float consumoPromedio;
	long posicionArchivo;
	bool activo;
};