#include "TarifaV.h"
#include "Validaciones.h"

TarifaV::TarifaV(string nombreArchivo)
{
	this->tarifa = Tarifa();
	this->nombreArchivo = nombreArchivo;
	this->tarifaRN = TarifaRN(nombreArchivo);
}

TarifaV::~TarifaV()
{
}

void TarifaV::NuevaTarifa()
{	
	char dato;

	this->tarifa = Tarifa();
	do {

		system("cls");
		cout << this->separador << endl;
		cout << "Nuevo ID de tarifa asignar: " <<tarifaRN.IdTarifa(tarifa) << endl;
		cout << this->separador << endl;
		cout << "Dar de alta " << endl << endl;
		dato = Validaciones::DatoObligarorioChar("Si = 'S' || No = 'N'");
		if (toupper(dato) == 'S')
		{
		this->tarifaRN.AltaTarifa(this->tarifa);
		cout << this->separador << endl;
		cout << "ALTA EXITOSA" << endl;
		cout << this->separador << endl;
		system("pause");
		break;
		}
		else {
			system("cls");
			system("pause");
			return;
		
		}
		
	} while (true);
	
}
/// <summary>
/// Funci�n global para listar todas las Tarifas del archivo.
/// </summary>
void TarifaV::ListarTarifa()
{
	vector<Tarifa> tarifa = this->tarifaRN.VectorTarifa();

	for (int i = 0; i < tarifa.size(); i++) {
		
			cout << tarifa[i].toStringTarifa() << endl;

	}

	system("pause");
}

void TarifaV::MenuModificarTarifa()
{
	long id_tarifa;
	int opcion;
	do
	{
		cout << this->separador << endl;
		cout << "Modificar datos de la Tarifa" << endl;
		cout << this->separador << endl;
		cout << "Id de la Tarifa: ";
		cin >> id_tarifa;
		this->tarifa = this->tarifaRN.BuscarTarifa(id_tarifa);
		if (this->tarifa.getIdTarifa() != id_tarifa)
		{
			cout << "No existe Tarifa con el Id ingresado. " << endl;
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		cout << this->separador << endl;
		cout << "Tarifa: " << this->tarifa.toStringTarifa() << endl;
		cout << this->separador << endl;
		cout << "1. Modificar Cargo Fijo" << endl;
        cout << "2. Modificar Cargo Variable" << endl;
        cout << "3. Modificar Impuestos" << endl;
        cout << "4. Modificar Tipo de Tarifa ('Industrial' 1, 'Domestico' 0)" << endl;
        cout << "5. Modificar Estado de Tarifa ('Activo' 1, 'Inactivo' 0)" << endl;
		cout << "0. Salir" << endl;
		cout << this->separador << endl;
		cout << "Opcion: ";
		cin >> opcion;
		string datos;
		switch (opcion)
		{
		case 1:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Cargo Fijo : ";
			float cargo;
			cin>>cargo;
			tarifa.setCargoFijo(cargo);
			break;
		}
		case 2:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Cargo Variable : ";
			float cargo;
			cin>>cargo;
			tarifa.setCargoVariable(cargo);
			break;
		}
        case 3:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo monto de Impuestos : ";
			float impuestos;
			cin>>impuestos;
			tarifa.setImpuestos(impuestos);
			break;
		}
        case 4:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Tipo de Tarifa : ('Industrial' 1, 'Domestico' 0)";
			bool n;
			cin >> n;
			tarifa.setTipoDeTarifa(n);
			break;
		}
		case 5:
		{
			Tarifa tarifa;
			cout << "Ingrese el nuevo Estado  de la  Tarifa : ('Activo' 1, 'Inactivo' 0)";
			bool n;
			cin >> n;
			tarifa.setEstado(n);
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
