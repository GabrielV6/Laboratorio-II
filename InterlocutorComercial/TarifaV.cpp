#include "TarifaV.h"

TarifaV::TarifaV(string nombreArchivo)
{
	this->tarifa = tarifa(nombreArchivo);
	this->nombreArchivo = nombreArchivo;
	this->tarifaRN = TarifaRN(nombreArchivo);
}
TarifaV::~TarifaV()
{
}

void TarifaV::NuevaTarifa()
{
	this->tarifa = Tarifa(this->nombreArchivo);
	long id_tarifa;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Ingreso de nueva tarifa " << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Ingrese el Id de la nueva tarifa: ";
		cin >> id_tarifa;

		if (this->tarifaRN.BuscarTarifa(id_tarifa).getId_tarifa() == id_tarifa) // LLamar metodo de RN que valide si existe ese ID de Tarifa 
		{
            tarifa.cargarTarifa();
	        this->GuardarEnArchivo();
            system("cls");
			break;
		}
		else
            cout << "Ya existe una Tarifa con ese Id" << endl;
			system("cls");
			break;
	} while (true);

}
/// <summary>
/// Funci�n global para listar todas las Tarifas del archivo.
/// </summary>
void TarifaV::ListarTarifa()
{
	vector<Tarifa> tarifa = this->tarifaRN.VectorTarifa();
	for (auto tarifa : tarifa)
	{
		cout << tarifa.toStringTarifa() << endl;
	}
}

void TarifaV::MenuModificarTarifa()
{
	long id_tarifa;
	int opcion;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Modificar datos de la Tarifa" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Id de la Tarifa: ";
		cin >> id_tarifa;
		this->tarifa = this->tarifaRN.BuscarTarifa(id_tarifa);
		if (this->tarifa.getId_tarifa() == id_tarifa) // LLamar metodo de RN que valida si existe el Id de la Tarifa
		{
			cout << "No existe Tarifa con el Id ingresado. " << endl;
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Tarifa: " << this->tarifa.toStringTarifa() << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Modificar Cargo Fijo" << endl;
        cout << "2. Modificar Cargo Variable" << endl;
        cout << "3. Modificar Impuestos" << endl;
        cout << "4. Modificar Codigo de Tarifa" << endl;
        cout << "5. Modificar Tipo de Tarifa" << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		string datos;
		switch (opcion)
		{
		case 1:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Cargo Fijo : ";
			tarifa.setCargoFijo();
			break;
		}
		case 2:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Cargo Variable : ";
			tarifa.setCargoVariable();
			break;
		}
        case 3:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo monto de Impuestos : ";
			tarifa.setImpuestos();
			break;
		}
        case 4:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Codigo de Tarifa : ";
			tarifa.setCodigoDeTarifa();
			break;
		}
        case 5:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Tipo de Tarifa : ";
			tarifa.setTipoDeTarifa();
			break;
		}
        case 0:
			break;
		default:
			cout << "Opcion invalida." << endl;
			break;
		}

	} while (opcion != 0);
}
void TarifaV::ModificarTarifa()
{
	MenuModificarTarifa();
	this->tarifaRN.ControlModificaciones(this->tarifa);
}
/// <summary>
/// Metodo que muestra un menu de opciones para las altas bajas y modificaciones de Tarifas.
/// </summary>
void TarifaV::MenuTarifa()
{
	bool salir = false;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Menu Tarifas" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Nueva Tarifa" << endl;
		cout << "2. Listar Tarifas" << endl;
		cout << "3. Modificar Tarifa " << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		int opcion;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			this->NuevaTarifa();
			break;
		case 2:
			this->ListarTarifa();
			break;
		case 3:
			this->ModificarTarifa();
			break;
		case 0:
			salir = true;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	} while (salir == false);
}

void TarifaV::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string TarifaV::getNombreArchivo()
{
	return this->nombreArchivo;
}
void TarifaV::setTarifa(Tarifa &tarifa)
{
	this->tarifa = tarifa;
}