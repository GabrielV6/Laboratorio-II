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
			/*
			this->ModificarInterlocutor();
			*/
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