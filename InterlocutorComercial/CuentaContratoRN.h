#pragma once

#include "CuentaContrato.h"
#include "CuentaContratoAD.h"

#include "Validaciones.h"

class CuentaContratoRN
{
private:
	CuentaContratoAD cuentaContratoAD;
	string nombreArchivo;

public:
	CuentaContratoRN(string nombreArchivo);
	CuentaContratoRN();
	~CuentaContratoRN();
	
	CuentaContrato BuscarCuentaContrato(int id_cc);
	bool ExisteCuentaContrato(int id_cc);
	bool ModificarCuentaContrato(CuentaContrato& CuentaContrato);
	bool AltaCuentaContrato(CuentaContrato& CuentaContrato);
	int IdCuentaContrato(CuentaContrato& CuentaContrato);
	int CantidadCuentaContrato();
	string getNombreArchivo();
	vector<CuentaContrato> getCuentaContrato();
	void setNombreArchivo(string nombre);
};