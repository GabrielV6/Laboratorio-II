#include "CuentaContratoRN.h"
#include "InterlocutorComercialV.h"
#include "Validaciones.h"
#include "TarifaV.h"
#include "MedidorV.h"

CuentaContratoRN::CuentaContratoRN(string nombreArchivo)
{
	this->cuentaContratoAD = CuentaContratoAD(nombreArchivo);
	this-> nombreArchivo= nombreArchivo;
}

CuentaContratoRN::CuentaContratoRN()
{

}

CuentaContratoRN::~CuentaContratoRN()
{

}

CuentaContrato CuentaContratoRN::BuscarCuentaContrato(int id_cc)
{
	CuentaContrato cuentaContrato = this->cuentaContratoAD.getCuentaContratoArchivo(id_cc);

	if (cuentaContrato.getId_cc() == id_cc)
		return cuentaContrato;

	return CuentaContrato();
}

bool CuentaContratoRN::ModificarMedidorCuentaContrato(CuentaContrato& cuentaContrato){

	return this->cuentaContratoAD.ActualizarEnArchivoCuentaContrato(cuentaContrato);
}

bool CuentaContratoRN::ModificarTarifaCuentaContrato(CuentaContrato& cuentaContrato){
	
	return this->cuentaContratoAD.ActualizarEnArchivoCuentaContrato(cuentaContrato);
}

bool CuentaContratoRN::ModificarCuentaContrato(CuentaContrato& cuentaContrato)
{
	return this->cuentaContratoAD.ActualizarEnArchivoCuentaContrato(cuentaContrato);
}

bool CuentaContratoRN::AltaCuentaContrato(CuentaContrato& cuentaContrato)
{
	return this->cuentaContratoAD.GuardarEnArchivoCuentaContrato(cuentaContrato);
}


int CuentaContratoRN::CantidadCuentaContrato()
{
	return this->cuentaContratoAD.TotalCuentaContratoEnArchivo();
}

string CuentaContratoRN::getNombreArchivo()
{
	return this->nombreArchivo;
}

vector<CuentaContrato> CuentaContratoRN::getCuentaContrato()
{
	return this->cuentaContratoAD.getCuentasContratoArchivo();
}

void CuentaContratoRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}