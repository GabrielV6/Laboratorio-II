#include "InterlocutorComercialV.h"
#include "Validaciones.h"

InterlocutorComercialV::InterlocutorComercialV(string nombreArchivo)
{
	this->interlocutorComercial = InterlocutorComercial(nombreArchivo);
	this->nombreArchivo = nombreArchivo;
	this->interlocutorComercialRN = InterlocutorComercialRN(nombreArchivo);
}

InterlocutorComercialV::~InterlocutorComercialV()
{
}
/// <summary>
/// M�todo que permite dar de alta un Interlocutor y lo graba en el archivo que contiene los interlocutores.
/// </summary>
void InterlocutorComercialV::NuevoInterlocutor()
{
	this->interlocutorComercial = InterlocutorComercial(this->nombreArchivo);
	unsigned int dni;
	string datos;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Nuevo ingreso de datos del Interlocutor comercial" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Documento Nr.: ";
		cin >> datos;
		dni = stoi(datos);//Usar para pasar de string a int
		if (this->interlocutorComercialRN.ExisteInterlocutorComercial(dni)) // LLamar metodo de regla de negocio que valida si existe el DNI
		{
			cout << "Documento ingresado ya esta dado de alta!!!" << endl;
			system("cls");
		}
		else
			break;
	} while (true);
	this->interlocutorComercial.setDni(dni);
	do
	{
		datos = Validaciones::DatoObligarorioCad("Nombre");
		this->interlocutorComercial.setNombre(datos);
		
		datos = Validaciones::DatoObligarorioCad("Apellido");
		this->interlocutorComercial.setApellido(datos);

		cout << "Correo electronico: ";
		cin >> datos;
		this->interlocutorComercial.setEmail(datos);
		Fecha fechaIngreso;
		cout << "Fecha Alta: ";
		fechaIngreso.cargarFecha();
		this->interlocutorComercial.setFechaIngresoId(fechaIngreso);
		Direccion direccion;
		cout << "Direccion: ";
		direccion.CargarDireccion();
		this->interlocutorComercial.setDireccionId(direccion);
		cout << "Datos ingresados:" << endl;
		cout << interlocutorComercial.toStringInterlocutor() << endl << endl;
		cout << "Dar de alta " << endl;
		datos = Validaciones::DatoObligarorioCad("Si = 'S' || No = 'N'");
		if (datos == "S")
		{
			this->interlocutorComercialRN.AltaInterlocutorComercial(this->interlocutorComercial);
			break;
		}
	} while (true);
}
/// <summary>
/// Funci�n global para listar todos los interlocutores del archivo.
/// </summary>
void InterlocutorComercialV::ListarInterlocutores()
{
	vector<InterlocutorComercial> interlocutores = this->interlocutorComercialRN.VectorInterlocutores();
	for (auto intLoc : interlocutores)
	{
		cout << intLoc.toStringInterlocutor() << endl;
	}
}

void InterlocutorComercialV::MenuModificarInterlocutor()
{
	long dni;
	int opcion;
	
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Modificar datos del Interlocutor comercial" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Documento Nr.: ";
		cin >> dni;
		this->interlocutorComercial = this->interlocutorComercialRN.BuscarInterlocutorComercial(dni);
		if (this->interlocutorComercial.getDni() != dni) // LLamar metodo de regla de negocio que valida si existe el DNI
		{
			cout << "Documento ingresado no esta dado de alta!!!" << endl;
			system("pause");
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Interlocutor: " << this->interlocutorComercial.toStringInterlocutor() << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Modificar nombre" << endl;
		cout << "2. Modificar apellido" << endl;
		cout << "3. Modificar e-mail" << endl;
		cout << "4. Modificar estado (Activo)" << endl;
		cout << "0. Volver al menú anteriror" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		string datos;
		switch (opcion)
		{
		case 1:
		{
			 datos = Validaciones::DatoObligarorioCad("Nombre");
			this->interlocutorComercial.setNombre(datos);
			break;
		}
		case 2:
		{
			datos = Validaciones::DatoObligarorioCad("Nombre");
			this->interlocutorComercial.setApellido(datos);
			break;
		}
		case 3:
		{
			cout << "E-mail: ";
			cin >> datos;
			this->interlocutorComercial.setEmail(datos);
			break;
		}
		case 4:
		{
			cout << "Modificar estado 'S' o 'N' : ";
			cin >> datos;
			if (datos == "S")
				this->interlocutorComercial.setActivo(!this->interlocutorComercial.getActivo());
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
			if (!this->interlocutorComercialRN.ModificaInterlocutorComercial(this->interlocutorComercial))
				cout << "Fallo la modificación intente nuevamante" << endl;
			else
				cout << "Modificación correcta" << endl;
		}
		system("pause");
	} while (opcion != 0);
}

void InterlocutorComercialV::ModificarInterlocutor()
{
	MenuModificarInterlocutor();
}
/// <summary>
/// Metodo que muestra un menu de opciones para las altas bajas y modificaciones de interlocutores.
/// </summary>
void InterlocutorComercialV::MenuInterlocutorComecial()
{
	bool salir = false;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Menu Interlocutor Comercial" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Nuevo Interlocutor" << endl;
		cout << "2. Listar Interlocutores" << endl;
		cout << "3. Modificar Interlocutor" << endl;
		cout << "0. Salir del menú interlocutor" << endl;
		cout << "-------------------------------------------------" << endl;
		int opcion;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			this->NuevoInterlocutor();
			break;
		case 2:
			this->ListarInterlocutores();
			break;
		case 3:
			this->ModificarInterlocutor();
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

void InterlocutorComercialV::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string InterlocutorComercialV::getNombreArchivo()
{
	return this->nombreArchivo;
}
void InterlocutorComercialV::setInterlocutorComercial(InterlocutorComercial& interlocutorComercial)
{
	this->interlocutorComercial = interlocutorComercial;
}
