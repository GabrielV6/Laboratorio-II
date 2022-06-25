#pragma once
#include <fstream>
#include "Direccion.h"
#include "Fecha.h"

class CuentaContrato
{
private:
	int id_cc;
    int id_ic;
	int id_tarifa;
	long numPosicionArch;
	bool activo;
public:
	CuentaContrato();
	CuentaContrato(string nombreArchivo);
	~CuentaContrato();
    void setId_cc(int id_cc);
	void setId_ic(int id_ic);
	void setId_tarifa(int id_tarifa);
	void setNumPosicionArchivo(int numPosArch);
	void setNombreArchivo(string nomArch);
	void setActivo(bool activo);
	int getId_cc();
    int getId_ic();
	int getId_Tarifa();
	int getNumPosicionArhivo();
	bool getActivo();
	string toStringCuentaContrato();	
};