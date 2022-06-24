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
	char formaDePago[30];
	bool categoriaDeCliente;
    bool tipoDeInteres;
	Fecha fechaIngresoID;
	Direccion direccionID;
	long numPosicionArch;
	char nombreArchivo[30];
	bool activo;
public:
	CuentaContrato();
	CuentaContrato(string nombreArchivo);
	~CuentaContrato();
    void setId_cc(int id_cc);
	void setId_ic(int id_ic);
	void setId_tarifa(int id_tarifa);
	void setFormaDePago(string formaDePago);
    void setCategoriaDeCliente(bool categoriaDeCliente);
    void setTipoDeInteres(bool tipoDeInteres);
	void setFechaIngresoId(Fecha fechaIn);
	void setDireccionId(Direccion direccionId);
	void setNumPosicionArchivo(int numPosArch);
	void setNombreArchivo(string nomArch);
	void setActivo(bool activo);
	int getId_cc();
    int getId_ic();
	int getId_Tarifa();
	string getFormaDePago();
    bool getCategoriaDeCliente();
    bool getTipoDeInteres();
	Fecha getFechaIngresoId();
	Direccion getDireccionId();
	int getNumPosicionArhivo();
	string getNombreArchivo();
	bool getActivo();
	string toStringCuentaContrato();	
};