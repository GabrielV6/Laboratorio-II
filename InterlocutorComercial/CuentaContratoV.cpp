#include "CuentaContratoV.h"
#include "Validaciones.h"

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
			system("clear");
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
	int id = 0; 
	string datos; 
	char dato;

	do
	{
		system("clear");
		cout << this->separador << endl;
		cout << "Nuevo ID de Cuenta Contrato asignar: " << cuentaContratoRN.IdCuentaContrato(cuentaContrato) << endl;
		cout << this->separador << endl;
		cout << "Dar de alta? " << endl << endl;
		dato = Validaciones::DatoObligarorioChar("Si = 'S' || No = 'N'");

		if (toupper(dato) == 'S')
		{
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
		else {
			return;
		}
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
		cout << "0. Volver al menú anterior" << endl;
		cout << this->separador << endl;

		opcion = Validaciones::DatoObligarorioNum("Opcion:");

		string datos;
		char dato;

		switch (opcion)
		{
		case 1:
		{
			cout << "Modificar estado ";
			cout << "El estado de la Cuenta Contrato es: " << endl;
			cout << this->cuentaContrato.getEstado() << endl;
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			
			if (toupper(dato) == 'S')
				this->cuentaContrato.setEstado(!this->cuentaContrato.getEstado());
			break;

			cout << "El actual estado de la Cuenta Contrato es: " << endl;
			cout << this->cuentaContrato.getEstado() << endl;
		}
		case 0:

			break;
		default:
			cout << "Opcion invalida." << endl;
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





