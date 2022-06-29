#include "CuentaContratoV.h"
#include "Validaciones.h"
#include "InterlocutorComercialV.h"
#include "TarifaV.h"
#include "MedidorV.h"




CuentaContratoV::CuentaContratoV(string nombreArchivo)
{
	this->cuentaContrato = CuentaContrato();
	this->cuentaContratoRN = CuentaContratoRN(nombreArchivo);
}
CuentaContratoV::~CuentaContratoV()
{
}

void CuentaContratoV::setCuentaContrato(CuentaContrato& cuentaContrato)
{
	this->cuentaContrato = cuentaContrato;
}

void CuentaContratoV::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}

string CuentaContratoV::getNombreArchivo()
{
	return this->nombreArchivo;
}

CuentaContrato CuentaContratoV::getCuentaContrato()
{
	return CuentaContrato();
}

bool CuentaContratoV::AltaCuentaContrato(){

	InterlocutorComercialRN interlocutorRN(NOMBRE_ARCH_IC);
	InterlocutorComercial interlocutor;
	CuentaContrato cuenta;
	// busca el id del  Interlocutor comercial
	interlocutor = interlocutorRN.BuscarInterlocutorComercial(cuentaContrato.getId_ic());
	
	// busca si ya existe una CC con ese Id (id de cc y ic son iguales)
	cuenta = this->cuentaContratoRN.BuscarCuentaContrato(interlocutor.getId_ic());

	if (cuenta.getId_cc()!=0){ // existe CC con ese id
		
		cout << "Ya existe una Cuenta Contrato para el Interlocutor comercial " << endl;
		Validaciones::SystemPause();
		return false;

	} else {
		
		cout << "La Cuenta Contrato sera dada de alta para: " << endl;
		cout << endl;
		cout << interlocutor.toStringInterlocutor() << endl;
		cout << endl;

		// agregar confirmacion?
		cuentaContrato.setId_cc(interlocutor.getId_ic());
		cuentaContrato.setId_ic(interlocutor.getId_ic());
		cout << "El ID de la Cuenta Contrato es: " << cuentaContrato.getId_ic() << endl;
		cout << endl;
		this->cuentaContratoRN.AltaCuentaContrato(cuentaContrato);
		Validaciones::SystemPause();
		return true;
	}	

}

void CuentaContratoV::ModificarTarifa(){

	TarifaV tarifaV(NOMBRE_ARCH_TAR);
	TarifaAD tarifaAD(NOMBRE_ARCH_TAR);
	Tarifa tarifa;
	int tar=0;

	cout << "A continuacion se muestran las tarifas disponibles: " << endl;
	cout << endl;
	tarifaV.ListarTarifa();
	cout << endl;
	
	do{	

		tar= Validaciones::DatoObligarorioNum(" el ID de la tarifa que desea asigar: ");
		// validar que el numero ingresado corresponda con un id de tarifa

		tarifa = tarifaAD.getTarifaArchivo(tar);

	} while ( tarifa.getIdTarifa()==0 || tarifa.getEstado()==false );
	
	this->cuentaContrato.setId_tarifa(tar);
	this->cuentaContratoRN.ModificarTarifaCuentaContrato(this->cuentaContrato);

	cout << "La tarifa actual de la Cuenta Contrato es: ";
	cout << this->cuentaContrato.getId_Tarifa() << endl;
	cout << this->separador << endl;

}
void CuentaContratoV::AsociarMedidor(){

	MedidorV medidorV(NOMBRE_ARCH_MED);
	MedidorRN medidorRN (NOMBRE_ARCH_MED);
	MedidorAD medidorAD(NOMBRE_ARCH_MED);
	Medidor nuevoMedidor, medidorAnterior;
	InterlocutorComercialRN interlocutorRN(NOMBRE_ARCH_IC);
	InterlocutorComercial interlocutor;

	cout << "A continuacion se muestran todos los medidores disponibles: " << endl;
	cout << endl;
	
	medidorV.ListarMedidor(false); // se muestran medidores inactivos
	cout << endl;
	
	cout << endl;
	int med=0;
	do{
		med= Validaciones::DatoObligarorioNum("el ID del medidor que desea asigar: ");
	
		// validar que el numero ingresado corresponda con un id de medidor
		// si existe queda cargado en auxMedidor
		nuevoMedidor = medidorRN.BuscarCMedidor(med);
		

		if(nuevoMedidor.getId()!=0){ // si existe, modifico el estado del medidor anterior y lo grabo
			
			medidorAnterior = medidorRN.BuscarCMedidor(this->cuentaContrato.getId_Medidor());
			medidorAnterior.setIdCuentaContrato(0);
	        medidorAnterior.setEstado(false);
			medidorAD.ActualizarEnArchivoMedidor(medidorAnterior);
		}

	}while (nuevoMedidor.getId() == 0);
	
	// se asigna medidor a cc y su estado pasa a ser Activo
	cuentaContrato.setId_medidor(med);
	cuentaContrato.setEstado(true);
	
	// modificar el medidor asociado
	nuevoMedidor.setIdCuentaContrato(cuentaContrato.getId_cc());
	nuevoMedidor.setEstado(true);
	
	// grabar en disco medidor
	medidorAD.ActualizarEnArchivoMedidor(nuevoMedidor);
	
	// cambiar Estado de IC a true ---> buscar IC por ID, settearlo y grabarlo
	interlocutor = interlocutorRN.BuscarInterlocutorComercialPorID(cuentaContrato.getId_ic());
	interlocutor.setActivo(true);
	interlocutorRN.ModificaInterlocutorComercial(interlocutor);
	
	this->ModificarTarifa();
	
}

void CuentaContratoV::MenuCuentaContrato()
{
	bool salir = false;
	do
	{
		system("clear||cls");
		cout << this->separador << endl;
		cout << "Menu Cuenta Contrato" << endl;
		cout << this->separador << endl;
		cout << "1. Nueva Cuenta Contrato" << endl;
		cout << "2. Listar Cuentas Contrato Activas" << endl;
		cout << "3. Listar Cuentas Contrato Inactivas" << endl;
		cout << "4. Modificar Cuenta Contrato" << endl;
		cout << "0. Salir" << endl;
		cout << this->separador << endl;
		int opcion;

		opcion = Validaciones::DatoObligarorioNum("una opcion");

		switch (opcion)
		{
		case 1:
			this->NuevaCuentaContrato();
			break;

		case 2:
			ListarCuentaContrato(true);
			break;
		
		case 3:
			ListarCuentaContrato(false);
			break;

		case 4:
			this->ModificarCuentaContrato();


			break;

		case 0:
			salir = true;
			system("clear||cls");
			break;

		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	} while (salir == false);
}


void CuentaContratoV::NuevaCuentaContrato()
{
	this->cuentaContrato = CuentaContrato();
	int dni = 0; 
	string datos; 

	do
	{
		system("clear||cls");
		cout << this->separador << endl;

		InterlocutorComercialRN interlocutorRN(NOMBRE_ARCH_IC);
		dni = Validaciones::DatoObligarorioNum(" el numero de DNI del Interlocutor Comercial: "); 
		bool existe = interlocutorRN.ExisteInterlocutorComercial(dni);
		
			if(!existe){
				cout <<"No existe Interlocutor Comercial con el DNI ingresado." << endl;
				cout << this->separador << endl;
				Validaciones::SystemPause();
			} 
			else {

				this->cuentaContrato.setId_ic(dni);
			
				if (this->AltaCuentaContrato()) {
					cout << this->separador << endl;
					cout << "Alta realizada" << endl;
					cout << this->separador << endl;
					Validaciones::SystemPause();
					break;
				}
				else {
					cout << this->separador << endl;
					cout << "Alta no exitosa" << endl;
					cout << this->separador << endl;
					Validaciones::SystemPause();
					break;
				}

			}
			return;
		
	} while (true);
}

void CuentaContratoV::ListarCuentaContrato(bool estado)
{
	vector<CuentaContrato> cuentaContrato = this->cuentaContratoRN.getCuentaContrato();
	
	for (int i = 0; i < cuentaContrato.size(); i++) {

		if (cuentaContrato[i].getEstado() == estado){
			cout << cuentaContrato[i].toStringCuentaContrato() << endl;
		}
		
	}
	Validaciones::SystemPause();
}

void CuentaContratoV::ModificarCuentaContrato()
{
	int opcion = 0;

	do
	{
		int id = 0;
		system("cls||clear");
		cout << this->separador << endl;
		cout << "Modificar Cuenta Contrato " << endl;
		cout << this->separador << endl;
		id = Validaciones::DatoObligarorioNum(" el ID de la Cuenta Contrato o 0 para salir");

		if (id == 0) {
			return;
		}
		this->cuentaContrato = this->cuentaContratoRN.BuscarCuentaContrato(id);

		if (this->cuentaContrato.getId_cc() != id) // Valida si existe una CC con ese Id
		{
			cout << "No existe Cuenta Contrato con ese ID " << endl;
			cout << endl;
			Validaciones::SystemPause();
			system("cls || clear");
		}
		else
			break;
	} while (true);

	do
	{
		system("clear");
		cout << this->separador << endl;
		cout << "Cuenta Contrato : " << this->cuentaContrato.toStringCuentaContrato() << endl;
		cout << this->separador << endl;
		cout << "1. Modificar estado (Activo/Inactivo)" << endl;
		cout << "2. Modificar tarifa " << endl;
		cout << "3. Asociar medidor " << endl;
		cout << "0. Volver al menú anterior" << endl;
		cout << this->separador << endl;

		opcion = Validaciones::DatoObligarorioNum("una opcion:");

		string datos;
		char dato;

		switch (opcion)
		{
		case 1:
		{
			cout << "Modificar estado " << endl;
			cout << "El estado de la Cuenta Contrato es: ";
			cout << this->cuentaContrato.getEstado() << endl;
			dato = Validaciones::DatoObligarorioChar("'S' para confirmar la modificacion o 'N' para cancelar.");

			if (toupper(dato) == 'S')
				this->cuentaContrato.setEstado(!this->cuentaContrato.getEstado());
			break;

			cout << "El actual estado de la Cuenta Contrato es: ";
			cout << this->cuentaContrato.getEstado() << endl;
			cout << this->separador << endl;
		}
		case 2:
		{

		
			cout << "Modificar tarifa " << endl;
			cout << "La tarifa actual de la Cuenta Contrato es: ";
			cout << this->cuentaContrato.getId_Tarifa() << endl;
			dato = Validaciones::DatoObligarorioChar(" 'S' para modificar la tarifa o 'N' para conservala.");

				if (toupper(dato) == 'S')
					this->ModificarTarifa();
			

			break;
		}
		case 3:
		{
			cout << "Asociar medidor " << endl;
			cout << "El medidor actual de la Cuenta Contrato es: ";
			cout << this->cuentaContrato.getId_Medidor() << endl;
			dato = Validaciones::DatoObligarorioChar("'S' para seleccionar otro o 'N' para cancelar : ");

			if (toupper(dato) == 'S')
				this->AsociarMedidor();

			cout << "El medidor actual de la Cuenta Contrato es: ";
			cout << this->cuentaContrato.getId_Medidor() << endl;
			cout << this->separador << endl;
			break;
		}

		case 0:

			break;
		default:
			cout << "Opción invalida." << endl;
			break;
	}

		Validaciones::SystemPause();

	} while (opcion != 0);	
}





