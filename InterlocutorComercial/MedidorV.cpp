#include "MedidorV.h"
#include "Validaciones.h"


MedidorV::MedidorV(string nombreArchivo)
{
	this->medidor = Medidor();
	this->medidorRN = MedidorRN(nombreArchivo);
}

MedidorV::~MedidorV()
{

}

void MedidorV::setMedidor(Medidor& medidor)
{
	this->medidor = medidor;
}

void MedidorV::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}

string MedidorV::getNombreArchivo()
{
	return this->nombreArchivo;
}

Medidor MedidorV::getMedidor()
{
	return Medidor();
}

void MedidorV::MenuMedidor()
{

	bool salir = false;
	do
	{
		system("cls");
		cout << this->separador << endl;
		cout << "Menu Medidor" << endl;
		cout << this->separador << endl;
		cout << "1. Nuevo Medidor" << endl;
		cout << "2. Listar Medidores Instalados" << endl;
		cout << "3. Listar Medidor Desinstalados" << endl;
		cout << "4. Modificar Medidor" << endl;
		cout << "0. Salir del menu Medidor" << endl;
		cout << this->separador << endl;
		int opcion;

		opcion = Validaciones::DatoObligarorioNum("una opcion");

		switch (opcion)
		{
		case 1:
		{
			this->NuevoMedidor();
			break;
		}
		case 2:
		{
			ListarMedidor(true);

			break;
		}
		case 3:
		{
			ListarMedidor(false);

			break;
		}
		case 4:
		{
			this->ModificarMedidor();

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

void MedidorV::NuevoMedidor()
{
	this->medidor = Medidor();
	int id = 0; //verificar si eliminar
	string datos; //verificar si eliminar
	char dato;

	do
	{
		system("cls");
		cout << this->separador << endl;
		cout << "Nuevo ID Medidor asignar: " << medidorRN.IdMedidor(medidor) << endl;
		cout << this->separador << endl;
		cout << "Dar de alta " << endl << endl;
		dato = Validaciones::DatoObligarorioChar("Si = 'S' || No = 'N'");
		if (toupper(dato) == 'S')
		{
			if (this->medidorRN.AltaMedidor(this->medidor)) {
				cout << this->separador << endl;
				cout << "ALTA EXITOSA" << endl;
				cout << this->separador << endl;
				Validaciones::SystemPause();
				break;
			}
			else {
				cout << this->separador << endl;
				cout << "ALTA NO EXITOSA" << endl;
				cout << this->separador << endl;
				Validaciones::SystemPause();
				break;
			}

		}
		else {
			return;
		}
	} while (true);
}


void MedidorV::ListarMedidor(bool estado)
{
	vector<Medidor> medidores = this->medidorRN.getMedidores();
	bool mostrar = false;
	for (int i = 0; i < medidores.size(); i++) {
		if (medidores[i].getEstado() == estado) {
			cout << medidores[i].toStringMedidor() << endl;
			mostrar = true;
		}

	}

	if (!mostrar) {
		cout << this->separador << endl;
		cout << "No hay medidores instalados" << endl;
		cout << this->separador << endl;
	}


	Validaciones::SystemPause();

}

void MedidorV::ModificarMedidor()
{

	int opcion = 0;

	do
	{
		int id = 0;
		system("cls");
		cout << this->separador << endl;
		cout << "Modificar datos del Medidor " << endl;
		cout << this->separador << endl;
		id = Validaciones::DatoObligarorioNum("ID o 0 - Para salir");

		if (id == 0) {
			return;
		}
		this->medidor = this->medidorRN.BuscarCMedidor(id);

		if (this->medidor.getId() != id) // LLamar metodo de regla de negocio que valida si existe el DNI
		{
			cout << "ID ingresado no existe " << endl;
			Validaciones::SystemPause();
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		system("cls");
		cout << this->separador << endl;
		cout << "Medidor : " << this->medidor.toStringMedidor() << endl;
		cout << this->separador << endl;
		cout << "1. Modificar estado (Activo/Inactivo)" << endl;
		cout << "0. Volver al menú anteriror" << endl;
		cout << this->separador << endl;

		opcion = Validaciones::DatoObligarorioNum("Opcion:");

		string datos;
		char dato;

		switch (opcion)
		{
		case 1:
		{
			cout << "Modificar estado ";
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S')
				this->medidor.setEstado(!this->medidor.getEstado());
			break;
		}
		case 0:

			break;
		default:
			cout << "Opcion invalida!!!" << endl;
			break;
		}

		if (opcion != 0)
		{
			if (!this->medidorRN.ModificaMedidor(this->medidor))
				cout << "Fallo la modificación intente nuevamante" << endl;
			else
				cout << "Modificación correcta" << endl;
		}
		Validaciones::SystemPause();
	} while (opcion != 0);
}