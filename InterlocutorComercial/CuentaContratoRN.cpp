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
	MedidorV medidor(NOMBRE_ARCH_MED);
	Medidor auxMedidor;

	cout << "A continuacion se muestran todos los medidores disponibles: " << endl;
	cout << endl;
	
	medidor.ListarMedidor(false); // se muestran medidores inactivos
	
	cout << endl;
	int med=0;
	med= Validaciones::DatoObligarorioNum("el medidor que desea asigar: ");
	
	// validar que el numero ingresado corresponda con un id de medidor
	// poner en 0 la cc en el medidor que se cambia
	// se asigna medidor a cc y su estado pasa a ser Activo
	cuentaContrato.setId_medidor(med);
	cuentaContrato.setEstado(true);
	// buscar medidor y cargarlo
	auxMedidor = MedidorRN().BuscarCMedidor(med);
	// modificar la cc asociada
	auxMedidor.setIdCuentaContrato(cuentaContrato.getId_cc());
	auxMedidor.setEstado(true);
	// grabar en disco meiddor
	// 
	MedidorAD medidorAD(NOMBRE_ARCH_MED);
	medidorAD.ActualizarEnArchivoMedidor(auxMedidor);

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