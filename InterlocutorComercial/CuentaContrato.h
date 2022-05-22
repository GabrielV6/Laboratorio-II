#pragma once
#include <fstream>
#include "Direccion.h"
#include "Fecha.h"

class CuentaContrato
{
private:
	long id_cc;
    long id_ic;
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
    void setId_cc(long id_cc);
	void setId_ic(long id_ic);
	void setFormaDePago(string formaDePago);
    void setCategoriaDeCliente(bool categoriaDeCliente);
    void setTipoDeInteres(bool tipoDeInteres);
	void setFechaIngresoId(Fecha fechaIn);
	void setDireccionId(Direccion direccionId);
	void setNumPosicionArchivo(long numPosArch);
	void setNombreArchivo(string nomArch);
	void setActivo(bool activo);
	long getId_cc();
    long getId_ic();
	string getFormaDePago();
    bool getCategoriaDeCliente();
    bool getTipoDeInteres();
	Fecha getFechaIngresoId();
	Direccion getDireccionId();
	long getNumPosicionArhivo();
	string getNombreArchivo();
	bool getActivo();
	string toStringCuentaContrato();	
};