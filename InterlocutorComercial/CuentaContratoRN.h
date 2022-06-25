#pragma once
#include "CuentaContratoAD.h"
#include "InterlocutorComercialAD.h"
#include "TarifaAD.h"
#include "Validaciones.h"

class CuentaContratoRN
{
private:
	CuentaContratoAD cuentaContratoAD;
	string nombreArchivo;
	InterlocutorComercial interlocutorComercial;
	Tarifa tarifa;
public:
	CuentaContratoRN(string nombreArchivo = "");
	~CuentaContratoRN();
	CuentaContrato BuscarCuentaContrato(long id_cc);
	bool ControlModificaciones(CuentaContrato& cuentaContrato);
	bool AltaCuentaContrato(CuentaContrato& cuentaContrato);
	long CantidadCuentaContratoEnSistema();
	string getNombreArchivo();
	vector<CuentaContrato> VectorCuentaContrato();
	void setNombreArchivo(string nombreArchivo);
};