#include "InterlocutorComercialV.h"
#include "Validaciones.h"

InterlocutorComercialV::InterlocutorComercialV(string nombreArchivo)
{
	this->interlocutorComercial = InterlocutorComercial();
	this->nombreArchivo = nombreArchivo;
	this->interlocutorComercialRN = InterlocutorComercialRN(nombreArchivo);
}

InterlocutorComercialV::~InterlocutorComercialV()
{
}
/// <summary>
/// M�todo que permite dar de alta un Interlocutor y lo graba en el archivo que contiene los interlocutores.
/// Los interlocutores se dan de alta en estado incativo --> luego cuando se asigna una cuenta contrato se activa 
/// </summary>
void InterlocutorComercialV::NuevoInterlocutor()
{
	this->interlocutorComercial = InterlocutorComercial();
	unsigned int dni;
	string datos;
	char dato;
	do
	{
		cout << this->separador << endl;
		cout << "Nuevo ingreso de datos del Interlocutor comercial" << endl;
		cout << this->separador << endl;
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
		fechaIngreso.cargarFechaActual();
		cout << fechaIngreso.toStringFecha() << endl;
		this->interlocutorComercial.setFechaIngresoId(fechaIngreso);
		Direccion direccion;
		cout << "Direccion: ";
		direccion.CargarDireccion();
		this->interlocutorComercial.setDireccionId(direccion);
		cout << "Datos ingresados:" << endl;
		cout << interlocutorComercial.toStringInterlocutor(false, true) << endl << endl;
		cout << "Dar de alta " << endl;
		dato = Validaciones::DatoObligarorioChar("Si = 'S' || No = 'N'");
		if (toupper(dato) == 'S')
		{
			this->interlocutorComercialRN.AltaInterlocutorComercial(this->interlocutorComercial);
			break;
		}
	} while (true);
}
/// <summary>
/// Funci�n global para listar todos los interlocutores del archivo.
/// </summary>
void InterlocutorComercialV::ListarInterlocutores(int opcion)
{
	vector<InterlocutorComercial> interlocutores = this->interlocutorComercialRN.VectorInterlocutores();
	system("cls");
	string tipo = "";
	if (opcion == 1 || opcion == 5)
		tipo = "Todos";
	if (opcion == 2 || opcion == 6)
		tipo = "Activos";
	if (opcion == 3 || opcion == 7)
		tipo = "Inactivos";
	cout << separador << endl;
	cout << "Listado de Interlocutor Comercial " + tipo << endl;
	cout << separador << endl;
	for (auto &intLoc : interlocutores)
	{
		switch (opcion)
		{
		case 1:
		{
			cout << DarDatosListado(intLoc, 0) << endl;
			break;
		}
		case 2:
		{
			if (intLoc.getActivo())
				cout << DarDatosListado(intLoc, 0) << endl;
			break;
		}
		case 3:
		{
			if (!intLoc.getActivo())
				cout << DarDatosListado(intLoc, 0) << endl;
			break;
		}
		case 5:
		{
			cout << DarDatosListado(intLoc, 1) << endl;
			break;
		}
		case 6:
		{
			if (intLoc.getActivo())
				cout << DarDatosListado(intLoc, 1) << endl;
			break;
		}
		case 7:
		{
			if (!intLoc.getActivo())
				cout << DarDatosListado(intLoc, 1) << endl;
			break;
		}
		default:
			break;
		}
		cout << separador << endl;
	}
	cout << separador << endl;
	system("pause");
}

string InterlocutorComercialV::DarDatosListado(InterlocutorComercial intLoc, int num)
{
	string datos = "";
	if (num == 0)
		datos = intLoc.toStringInterlocutor(true, true);
	if (num == 1)
		datos = to_string(intLoc.getId_ic()) + "\t" + intLoc.getNombre() + "\t" + intLoc.getApellido() + "\t" + to_string(intLoc.getDni()) +
		"\t" + intLoc.getEmail() + "\t" + intLoc.getFechaIngresoId().toStringFecha();
	return datos;
}

int InterlocutorComercialV::MenuListarInerlocutor()
{
	int opcion;
	do
	{
		system("cls");
		cout << this->separador << endl;
		cout << "Opciones de Listado de Interlocutor Comercial" << endl;
		cout << this->separador << endl;
		cout << "1. Listar todos los Interlocutroes" << endl;
		cout << "2. Listar Interlocutores activos" << endl;
		cout << "3. Listar Interlocutores inactivos" << endl;
		cout << "0. Salir de las opciones de interlocutor" << endl;
		cout << this->separador << endl;
		cout << "Ingrese una opcion: ";
		opcion = Validaciones::DatoObligarorioNum("Opcion");
		if (opcion >= 0 && opcion <= 4)
			break;

	} while (true);
	char dato;
	if (opcion > 0)
	{
		cout << "Listar Interlocutores, para modo Resumen ingrese 'R' o modo completo cuaquier otra" << endl;
		dato = Validaciones::DatoObligarorioChar("Tipo");
	}
	switch (opcion)
	{
	case 1:
	{
		if (toupper(dato) == 'R')
			opcion = 5;
		break;
	}
	case 2:
	{
		if (toupper(dato) == 'R')
			opcion = 6;
		break;
	}
	case 3:
	{
		if (toupper(dato) == 'R')
			opcion = 7;
		break;
	}
	default:
		break;
	}
	return opcion;
}

void InterlocutorComercialV::MenuModificarInterlocutor()
{
	long dni;
	int opcion;

	do
	{
		cout << this->separador << endl;
		cout << "Modificar datos del Interlocutor comercial" << endl;
		cout << this->separador << endl;
		cout << "Documento ";
		dni = Validaciones::DatoObligarorioNum("Nro");
		//cin >> dni;
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
		system("cls");
		cout << this->separador << endl;
		cout << "Interlocutor: " << this->interlocutorComercial.toStringInterlocutor(false, true) << endl;
		cout << this->separador << endl;
		cout << "1. Modificar nombre" << endl;
		cout << "2. Modificar apellido" << endl;
		cout << "3. Modificar e-mail" << endl;
		cout << "4. Modificar estado (Activo/Inactivo)" << endl;
		cout << "5. Modificar direccion" << endl;
		cout << "0. Volver al menú anteriror" << endl;
		cout << this->separador << endl;
		//cout << "Opcion: ";
		opcion = Validaciones::DatoObligarorioNum("Opcion:");
		//cin >> opcion;
		string datos;
		char dato;
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
			cout << "Modificar estado ";
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S')
				this->interlocutorComercial.setActivo(!this->interlocutorComercial.getActivo());
			break;
		}
		case 5:
		{
			cout << "Direccion actual: ";
			cout << this->interlocutorComercial.getDireccionId().toStringDireccion() << endl;
			cout << separador << endl;
			Direccion direc;
			direc.CargarDireccion();
			this->interlocutorComercial.setDireccionId(direc);
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
		system("cls");
		cout << this->separador << endl;
		cout << "Menu Interlocutor Comercial" << endl;
		cout << this->separador << endl;
		cout << "1. Nuevo Interlocutor" << endl;
		cout << "2. Listar Interlocutores" << endl;
		cout << "3. Modificar Interlocutor" << endl;
		cout << "0. Salir del menu interlocutor" << endl;
		cout << this->separador << endl;
		int opcion;
		//cout << "Ingrese una opcion: ";
		opcion = Validaciones::DatoObligarorioNum("una opcion");
		//cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
			this->NuevoInterlocutor();
			break;
		}
		case 2:
		{
			int opcionAux = this->MenuListarInerlocutor();
			if (opcionAux > 0)
				this->ListarInterlocutores(opcionAux);
			break;
		}
		case 3:
		{
			this->ModificarInterlocutor();
			break;
		}
		case 0:
			system("cls");
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
