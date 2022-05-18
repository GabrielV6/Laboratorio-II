#include "CuentaContratoRN.h"

CuentaContratoRN::CuentaContratoRN(string nombreArchivo)
{
	this->cuentaContratoAD = CuentaContratoAD(nombreArchivo);
}
CuentaContratoRN::~CuentaContratoRN()
{}
bool CuentaContratoRN::AltaCuentaContrato(CuentaContrato& cuentaContrato)
{
	return this->cuentaContratoAD.GuardarEnArchivoCuentaContrato(cuentaContrato);
}
CuentaContrato CuentaContratoRN::BuscarCuentaContrato(long id_cc)
{
	CuentaContrato intComAD = this->cuentaContratoAD.getCuentaContratoArchivo(id_cc);
	if (intComAD.getId_cc() == id_cc)
		return intComAD;
	return CuentaContrato();
}
bool CuentaContratoRN::ControlModificaciones(CuentaContrato& cuentaContrato)
{
	///Hacer la validaciones correspondientes a la Cuenta Contrato pasada por parametro
	return true;
}
long CuentaContratoRN::CantidadCuentaContratoEnSistema()
{
	return this->cuentaContratoAD.TotalCuentaContratoEnArchivo();
}
string CuentaContratoRN::getNombreArchivo()
{
	return this->nombreArchivo;
}
vector<CuentaContrato> CuentaContratoRN::VectorCuentaContrato()
{
	return this->cuentaContratoAD.getCuentasContratoArchivo();
}
void CuentaContratoRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}