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
		cout << "2. Listar Medidor" << endl;
		cout << "3. Modificar Medidor" << endl;
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
			ListarMedidor();
			
			break;
		}
		case 3:
		{
			
			this->ModificarMedidor();
			
			break;
		}
		case 0:
			salir = true;
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
	unsigned int id;
	string datos;
	char dato;

	do
	{
		cout << this->separador << endl;
		cout << "Nuevo dato Medidor" << endl;
		cout << this->separador << endl;

		cout << medidorRN.IdMedidor(medidor) << endl << endl;
		cout << "Dar de alta " << endl;
		dato = Validaciones::DatoObligarorioChar("Si = 'S' || No = 'N'");
		if (toupper(dato) == 'S')
		{
			this->medidorRN.AltaMedidor(this->medidor);
			break;
		}
	} while (true);
}


void MedidorV::ListarMedidor()
{
	vector<Medidor> medidores = this->medidorRN.getMedidores(false);
	
	for (int i = 0; i < medidores.size(); i++) {
		cout << medidores[i].toStringMedidor() << endl;
	}

	system("pause");

}

void MedidorV::ModificarMedidor()
{
	
	int opcion;

	do
	{	
		long id=0;
		system("cls");
		cout << this->separador << endl;
		cout << "Modificar datos del Medidor " << endl;
		cout << this->separador << endl;
		id=Validaciones::DatoObligarorioNum("ID o 0 - Para salir");
		
		if (id == 0) {
			return;
		}
		this->medidor = this->medidorRN.BuscarCMedidor(id);
		
		if (this->medidor.getId() != id) // LLamar metodo de regla de negocio que valida si existe el DNI
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
		cout << "Medidor : " << this->medidor.toStringMedidor() << endl;
		cout << this->separador << endl;
		cout << "1. Modificar estado (Activo/Inactivo)" << endl;
		cout << "0. Volver al menú anteriror" << endl;
		cout << this->separador << endl;
		
		opcion = Validaciones::DatoObligarorioNum("Opcion:");
		
		string datos;
		char dato;
		long cc;
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
		system("pause");
	} while (opcion != 0);
}
