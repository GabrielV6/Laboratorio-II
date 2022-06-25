#include "CuentaContratoV.h"
#include "Validaciones.h"

CuentaContratoV::CuentaContratoV(string nombreArchivo)
{
	this->cuentaContrato = CuentaContrato();
	this->nombreArchivo = nombreArchivo;
	this->cuentaContratoRN = CuentaContratoRN(nombreArchivo);
}
CuentaContratoV::~CuentaContratoV()
{
}
/// <summary>
/// M�todo que permite dar de alta una Cuenta Contrato y la graba en el archivo que contiene las Cuenta Contrato.
/// </summary>
void CuentaContratoV::NuevaCuentaContrato()
{
	this->cuentaContrato = CuentaContrato();
	long id_ic;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Nuevo ingreso de datos de la Cuenta Contrato" << endl;
		cout << "--------------------------------------------------" << endl;
		id_ic = Validaciones::DatoObligarorioNum("Id. Interlocutor Comercial");
		if (this->cuentaContratoRN.BuscarCuentaContrato(id_ic).getId_ic() == id_ic) // LLamar metodo de regla de negocio que valide si existe el ID de Interlocutor Comercial para asociar
		{
			cout << "Debe poseer una cuenta de Interlocutor Comercial" << endl;
			system("cls");
		}
		else
			break;
	} while (true);

	this->cuentaContrato.setId_cc(id_ic); // el Id de la Cuenta Contrato es la misma que id_cc ?


	//this->GuardarEnArchivo();
}
/// <summary>
/// Funci�n global para listar todas las Cuenta Contrato del archivo.
/// </summary>
void CuentaContratoV::ListarCuentaContrato()
{
	vector<CuentaContrato> cuentaContrato = this->cuentaContratoRN.VectorCuentaContrato();
	for (auto intLoc : cuentaContrato)
	{
		cout << intLoc.toStringCuentaContrato() << endl;
	}
}

void CuentaContratoV::MenuModificarCuentaContrato()
{
	long id_cc;
	int opcion;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Modificar datos de la Cuenta Contrato" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Id de la Cuenta Contrato: ";
		cin >> id_cc;
		this->cuentaContrato = this->cuentaContratoRN.BuscarCuentaContrato(id_cc);
		if (this->cuentaContrato.getId_cc() == id_cc) // LLamar metodo de regla de negocio que valida si existe el Id de la Cuenta Contrato
		{
			cout << "No existe Cuenta Contrato con el Id ingresado. " << endl;
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Cuenta Contrato: " << this->cuentaContrato.toStringCuentaContrato() << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Modificar direccion" << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		string datos;
		switch (opcion)
		{
		case 1:
			cout << "No vale" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Opcion invalida!" << endl;
			break;
		}
	} while (opcion != 0);
}

void CuentaContratoV::ModificarCuentaContrato()
{
	MenuModificarCuentaContrato();
	this->cuentaContratoRN.ControlModificaciones(this->cuentaContrato);
}
/// <summary>
/// Metodo que muestra un menu de opciones para las altas bajas y modificaciones de Cuentas Contrato.
/// </summary>
void CuentaContratoV::MenuCuentaContrato()
{
	bool salir = false;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Menu Cuenta Contrato" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Nueva Cuenta Contrato" << endl;
		cout << "2. Listar Cuenta Contrato" << endl;
		cout << "3. Modificar Cuenta Contrato" << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		int opcion;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			this->NuevaCuentaContrato();
			break;
		case 2:
			this->ListarCuentaContrato();
			break;
		case 3:
			this->ModificarCuentaContrato();
			break;
		case 0:
			salir = true;
			system("cls");
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	} while (salir == false);
}

void CuentaContratoV::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string CuentaContratoV::getNombreArchivo()
{
	return this->nombreArchivo;
}
void CuentaContratoV::setCuentaContrato(CuentaContrato& cuentaContrato)
{
	this->cuentaContrato = cuentaContrato;
}