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
	
	TarifaV tarifa(NOMBRE_ARCH_TAR);
	cout << "A continuacion se muestran las tarifas disponibles: " << endl;
	cout << endl;

	tarifa.ListarTarifa();
	
	cout << endl;
	int tar=0;
	tar= Validaciones::DatoObligarorioNum("Seleccione la tarifa que desea asigar: ");
	
	// validar que el numero ingresado corresponda con un id de tarifa
	cuentaContrato.setId_tarifa(tar);
	return this->cuentaContratoAD.ActualizarEnArchivoCuentaContrato(cuentaContrato);
}

bool CuentaContratoRN::ModificarCuentaContrato(CuentaContrato& cuentaContrato)
{
	return this->cuentaContratoAD.ActualizarEnArchivoCuentaContrato(cuentaContrato);
}

bool CuentaContratoRN::AltaCuentaContrato(CuentaContrato& cuentaContrato)
{
	InterlocutorComercialRN interlocutorRN(NOMBRE_ARCH_IC);
	InterlocutorComercial interlocutor;
	CuentaContrato cuenta;
	// busca el id del  Interlocutor comercial
	interlocutor = interlocutorRN.BuscarInterlocutorComercial(cuentaContrato.getId_ic());

	// busca si ya existe una CC con ese Id (id de cc y ic son iguales)
	cuenta = this->BuscarCuentaContrato(interlocutor.getId_ic());

	if (cuenta.getId_cc()!=0){ // existe CC con ese id
		
		cout << "Ya existe una Cuenta Contrato para el Interlocutor comercial " << endl;
		return false;

	} else {
		
		cout << "La Cuenta Contrato sera dada de alta para: " << endl;
		cout << interlocutor.toStringInterlocutor() << endl;
		cout << endl;

		// agregar confirmacion
		cuentaContrato.setId_cc(interlocutor.getId_ic());
		cuentaContrato.setId_ic(interlocutor.getId_ic());
		cout << "El ID de la Cuenta Contrato es: " << cuentaContrato.getId_ic() << endl;
		
		return this->cuentaContratoAD.GuardarEnArchivoCuentaContrato(cuentaContrato);

	}	
	
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