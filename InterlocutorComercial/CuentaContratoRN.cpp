#include "CuentaContratoRN.h"
#include "InterlocutorComercialV.h"
#include "Validaciones.h"

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

bool CuentaContratoRN::ModificarCuentaContrato(CuentaContrato& cuentaContrato)
{
	return this->cuentaContratoAD.ActualizarEnArchivoCuentaContrato(cuentaContrato);
}

bool CuentaContratoRN::AltaCuentaContrato(CuentaContrato& cuentaContrato)
{
	InterlocutorComercial interlocutor;
	InterlocutorComercialRN interlocutorRN(NOMBRE_ARCH_IC);

	interlocutor = interlocutorRN.BuscarInterlocutorComercial(cuentaContrato.getId_ic());
	if (interlocutor.getId_ic()!=0){
		cout << "La Cuenta Contrato sera dada de alta para: " << endl;
		interlocutor.toStringInterlocutor();
		cout << endl;
		// agregar confirmacion
		cuentaContrato.setId_cc(interlocutor.getId_ic());
		cuentaContrato.setId_ic(interlocutor.getId_ic());
		cout << "El ID de la Cuenta Contrato es: " + cuentaContrato.getId_ic() << endl;
		
		return this->cuentaContratoAD.GuardarEnArchivoCuentaContrato(cuentaContrato);;
	}

	return false;
}

int CuentaContratoRN::IdCuentaContrato(CuentaContrato& cuentaContrato)
{
	//modificar para que el ID de CC sea el mismo que del Interlocutor Comercial
	int id = this->cuentaContratoAD.TotalCuentaContratoEnArchivo();
    
	if (id == -1) {
		id = 0;
	}
	id++;

	cuentaContrato.setId_cc(id);
	
	return cuentaContrato.getId_cc();
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