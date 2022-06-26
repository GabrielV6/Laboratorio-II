#include "TarifaV.h"
#include "Validaciones.h"

TarifaV::TarifaV(string nombreArchivo)
{
	this->tarifa = Tarifa();
	this->tarifaRN = TarifaRN(nombreArchivo);
}

TarifaV::~TarifaV()
{
}

void TarifaV::setTarifa(Tarifa& tarifa)
{
	this->tarifa = tarifa;
}

void TarifaV::setNombreArchivo(string nombreArchivo)
{

	this->nombreArchivo = nombreArchivo;
}

string TarifaV::getNombreArchivo()
{
	return this->nombreArchivo;
}

Tarifa TarifaV::getTarifa()
{
	return Tarifa();
}

void TarifaV::MenuTarifa()
{
	bool salir = false;
	do
	{
		system("cls");
		cout << this->separador << endl;
		cout << "Menu Tarifas" << endl;
		cout << this->separador << endl;
		cout << "1. Nueva Tarifa" << endl;
		cout << "2. Listar Tarifas" << endl;
		cout << "3. Modificar Tarifa " << endl;
		cout << "0. Salir del menu Medidor" << endl;
		cout << this->separador << endl;
		int opcion;

		opcion = Validaciones::DatoObligarorioNum("una opcion");

		switch (opcion)
		{
		case 1:
		{
			this->NuevaTarifa();
			break;
		}
		case 2:
		{
			this->ListarTarifa();

			break;
		}
		case 3:
		{
			this->ModificarTarifa();

			break;
		}
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

void TarifaV::NuevaTarifa()
{
	char dato;
	float valor;
	int valor2;

	this->tarifa = Tarifa();
	do {

		system("cls");
		cout << this->separador << endl;
		cout << "Nuevo ID de tarifa asignar: " << tarifaRN.IdTarifa(tarifa) << endl;
		cout << this->separador << endl;

		valor = Validaciones::DatoObligarorioDecimal("Ingrese Cargo fijo: ");
		if (toupper(valor) != 0)
			this->tarifa.setCargoFijo(valor);

		valor = Validaciones::DatoObligarorioDecimal("Ingrese Cargo Variable: ");
		if (toupper(valor) != 0)
			this->tarifa.setCargoVariable(valor);

		valor = Validaciones::DatoObligarorioDecimal("Ingrese % de impuesto: ");
		if (toupper(valor) != 0)
			this->tarifa.setImpuestos(valor);

		valor2 = Validaciones::DatoObligarorioNum("Tipo de tarifa: (0) Domestico - (1) Industrial ");
		if (toupper(valor) != 0)
			this->tarifa.setTipoDeTarifa(valor2);

		cout << this->separador << endl;
		cout << "Desea dar de alta?" << endl << endl;
		dato = Validaciones::DatoObligarorioChar("Si = 'S' || No = 'N'");
		if (toupper(dato) == 'S')
		{
			if (this->tarifaRN.AltaTarifa(this->tarifa)) {
				cout << this->separador << endl;
				cout << "ALTA EXITOSA" << endl;
				cout << this->separador << endl;
				system("pause");
				break;
			}
			else {
				cout << this->separador << endl;
				cout << "ALTA NO EXITOSA" << endl;
				cout << this->separador << endl;
				system("pause");
				break;
			}

		}
		else {
			system("cls");
			system("pause");
			return;

		}

	} while (true);
}

void TarifaV::ListarTarifa()
{
	vector<Tarifa> tarifas = this->tarifaRN.getTarifas();

	for (int i = 0; i < tarifas.size(); i++) {

		cout << tarifas[i].toStringTarifa() << endl;

	}

	system("pause");
}

void TarifaV::ModificarTarifa()
{
	int opcion = 0;

	do
	{
		int id = 0;
		system("cls");
		cout << this->separador << endl;
		cout << "Modificar datos de la Tarifa " << endl;
		cout << this->separador << endl;
		id = Validaciones::DatoObligarorioNum("ID o 0 - Para salir");

		if (id == 0) {
			return;
		}
		this->tarifa = this->tarifaRN.BuscarTarifa(id);

		if (this->tarifa.getIdTarifa() != id) // LLamar metodo de regla de negocio que valida si existe el ID
		{
			cout << "ID ingresado no existe " << endl;
			system("pause");
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		system("cls");
		cout << this->separador << endl;
		cout << "Tarifa - " << this->tarifa.toStringTarifa() << endl;
		cout << this->separador << endl;
		cout << "1. Modificar Cargo Fijo" << endl;
		cout << "2. Modificar Cargo Variable" << endl;
		cout << "3. Modificar Impuestos" << endl;
		cout << "4. Modificar Tipo de Tarifa ('Industrial' 1, 'Domestico' 0)" << endl;
		cout << "5. Modificar estado (Activo/Inactivo)" << endl;
		cout << "0. Volver al menú anteriror" << endl;
		cout << this->separador << endl;

		opcion = Validaciones::DatoObligarorioNum("Opcion:");

		string datos;
		char dato;
		float dato2;

		switch (opcion)
		{
		case 1:
		{
			cout << "Modificar Cargo Fijo ";
			dato2 = Validaciones::DatoObligarorioNum("Valor");
			if (toupper(dato2) != 0)
				this->tarifa.setCargoFijo(dato2);
			break;
		}
		case 2:
		{
			cout << "Modificar Cargo Variable ";
			dato2 = Validaciones::DatoObligarorioNum("Valor");
			if (toupper(dato2) != 0)
				this->tarifa.setCargoVariable(dato2);
			break;
		}
		case 3:
		{
			cout << "Modificar Cargo Impuesto ";
			dato2 = Validaciones::DatoObligarorioNum("Valor");
			if (toupper(dato2) != 0)
				this->tarifa.setImpuestos(dato2);
			break;
		}
		case 4:
		{
			cout << "Modificar Tipo de Tarifa 1 - Industrial 0 - Domestico ";
			dato2 = Validaciones::DatoObligarorioNum("Valor");
			if (toupper(dato2) >= 0 && toupper(dato2) < 2)
				this->tarifa.setTipoDeTarifa(dato2);
			break;
		}
		case 5:
		{
			cout << "Modificar estado ";
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S')
				this->tarifa.setEstado(!this->tarifa.getEstado());

			break;
		}
		case 0:
		{
			break;
		}
			
		default:
			cout << "Opcion invalida!!!" << endl;
			break;
		}

		if (opcion != 0)
		{
			if (!this->tarifaRN.ModificarTarifa(this->tarifa))
				cout << "Fallo la modificación intente nuevamante" << endl;
			else
				cout << "Modificación correcta" << endl;
		}
		system("pause");
	} while (opcion != 0);
}