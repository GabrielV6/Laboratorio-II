#pragma once

#include "CuentaContrato.h"

using namespace std;

class CuentaContratoAD{

private:
	string nombreArchivo;
	vector<CuentaContrato> cuentasC;

public:
	CuentaContratoAD(string nombreArchivo = "");
	~CuentaContratoAD();

	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();

	int TotalCuentaContratoEnArchivo();
	bool GuardarEnArchivoCuentaContrato(CuentaContrato& contrato);
	bool ActualizarEnArchivoCuentaContrato(CuentaContrato& contrato);

	CuentaContrato getCuentaContratoArchivo(int id_cc);
	vector<CuentaContrato> getCuentasContratoArchivo();

};