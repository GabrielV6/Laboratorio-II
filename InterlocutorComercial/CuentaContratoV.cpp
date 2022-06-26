#include "CuentaContratoV.h"
#include "Validaciones.h"
#include "InterlocutorComercialV.h"
#include "TarifaV.h"


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

void CuentaContratoV::MenuCuentaContrato()
{
	bool salir = false;
	do
	{
		system("clear");
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

		opcion = Validaciones::DatoObligarorioNum("una opción");

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
			system("clear");
			break;

		default:
			cout << "Opción no valida" << endl;
			break;
		}
	} while (salir == false);
}


void CuentaContratoV::NuevaCuentaContrato()
{
	this->cuentaContrato = CuentaContrato();
	int dni = 0; 
	string datos; 
	char dato;

	do
	{
		system("clear");
		cout << this->separador << endl;

		InterlocutorComercialRN interlocutorRN(NOMBRE_ARCH_IC);
		dni = Validaciones::DatoObligarorioNum("Ingrese el numero de DNI del Interlocutor Comercial: "); 
		bool existe = interlocutorRN.ExisteInterlocutorComercial(dni);
		
			if(!existe){
				cout <<"No existe Interlocutor Comercial con el DNI ingresado." << endl;
				cout << this->separador << endl;
			} 
			else {

				this->cuentaContrato.setId_ic(dni);
			
				if (this->cuentaContratoRN.AltaCuentaContrato(this->cuentaContrato)) {
					cout << this->separador << endl;
					cout << "Alta realizada" << endl;
					cout << this->separador << endl;
					system("pause");
					break;
				}
				else {
					cout << this->separador << endl;
					cout << "Alta no exitosa" << endl;
					cout << this->separador << endl;
					system("pause");
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
	system("pause");
}

void CuentaContratoV::ModificarCuentaContrato()
{
	int opcion = 0;

	do
	{
		int id = 0;
		system("cls");
		cout << this->separador << endl;
		cout << "Modificar Cuenta Contrato " << endl;
		cout << this->separador << endl;
		id = Validaciones::DatoObligarorioNum("ID o 0 - Para salir");

		if (id == 0) {
			return;
		}
		this->cuentaContrato = this->cuentaContratoRN.BuscarCuentaContrato(id);

		if (this->cuentaContrato.getId_cc() != id) // Valida si existe una CC con ese Id
		{
			cout << "No existe Cuenta Contrato con ese ID " << endl;
			system("pause");
			system("cls");
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
		cout << "0. Volver al menú anterior" << endl;
		cout << this->separador << endl;

		opcion = Validaciones::DatoObligarorioNum("Opción:");

		string datos;
		char dato;

		switch (opcion)
		{
		case 1:
		{
			cout << "Modificar estado " << endl;
			cout << "El estado de la Cuenta Contrato es: " << endl;
			cout << this->cuentaContrato.getEstado() << endl;
			dato = Validaciones::DatoObligarorioChar(" Confirma la modificacion: 'S' o 'N'");
			
			if (toupper(dato) == 'S')
				this->cuentaContrato.setEstado(!this->cuentaContrato.getEstado());
			break;

			cout << "El actual estado de la Cuenta Contrato es: " << endl;
			cout << this->cuentaContrato.getEstado() << endl;
			cout << this->separador << endl;
		}
		case 2:
			cout << "Modificar tarifa " << endl;
			cout << "La tarifa actual de la Cuenta Contrato es: " << endl;
			cout << this->cuentaContrato.getId_Tarifa() << endl;
			dato = Validaciones::DatoObligarorioChar(" Desea modificar la tarifa? 'S' o 'N'");
			
			if (toupper(dato) == 'S')
				this->cuentaContratoRN.ModificarTarifaCuentaContrato(this->cuentaContrato);
			
			cout << "La tarifa actual de la Cuenta Contrato es: " << endl;
			cout << this->cuentaContrato.getId_Tarifa() << endl;
			cout << this->separador << endl;
			break;
		
		case 0:

			break;
		default:
			cout << "Opción invalida." << endl;
			break;
		}

		if (opcion != 0)
		{
			if (!this->cuentaContratoRN.ModificarCuentaContrato(this->cuentaContrato))
				cout << "Falló la modificación, intente nuevamante" << endl;
			else
				cout << "Modificación realizada correctamente" << endl;
		}

		system("pause");

	} while (opcion != 0);	
}





