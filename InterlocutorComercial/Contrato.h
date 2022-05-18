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

class Contrato
{

public:
	Contrato();
	Contrato(int idContrato, InterlocutorComercial& interlocutorComercial, int idCuentaContrato, int idMedidor, int idInstalacion, string zona, Fecha fecAlta, Fecha fecBaja, float tarifas, float consumoPromedio, long posicionArchivo, bool activo);
	void setIdContrato(int idContrato);
	int getIdContrato();
	void setIdInterlocutorComercial(InterlocutorComercial& idInterlocutorComercial);
	InterlocutorComercial& getIdInterlocutorComercial();
	void setIdCuentaContrato(int idCuentaContrato);
	int getIdCuentaContrato();
	void setIdMedidor(int idMedidor);
	int getIdMedidor();
	void setIdInstalacion(int idInstalacion);
	int getIdInstalacion();
	void setZona(string zona);
	string getZona();
	void setFechaAltaContrato(Fecha fecAlta);
	Fecha getFechaAltaContrato();
	void setFechaBajaContrato(Fecha fecBaja);
	Fecha getFechaBajaContrato();
	void setTarifas(float tarifas);
	float getTarifas();
	void setConsumoPromedio(float consumoPromedio);
	float getConsumoPromedio();
	void setPoscicionArchivo(long posicionArchivo);
	long getPosicionArchivo();
	void setActivo(bool activo);
	bool getActivo();
	string toStringContrato();

private:
	int idContrato;
	InterlocutorComercial interlocutorComercial;
	int idCuentaContrato;
	int idMedidor;
	int idInstalacion;
	char zona[40];
	Fecha fechaAltaContrato;
	Fecha fechaBajaContrato;
	float tarifas;
	float consumoPromedio;
	float posicionArchivo;
	bool activo;
};