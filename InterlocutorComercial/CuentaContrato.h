#pragma once
#include <vector>
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

class CuentaContrato
{
private:
	int id_cc;
    int id_ic;
	int id_tarifa;
	int id_medidor;
	int numPosicionArch;
	bool estado;
public:
	CuentaContrato();
	~CuentaContrato();
    void setId_cc(int id_cc);
	void setId_ic(int id_ic);
	void setId_tarifa(int id_tarifa);
	void setId_medidor(int id_medidor);
	void setNumPosicionArchivo(int numPosArch);
	void setEstado(bool activo);

	int getId_cc();
    int getId_ic();
	int getId_Tarifa();
	int getId_Medidor();
	int getNumPosicionArhivo();
	bool getEstado();

	string toStringCuentaContrato();	
};