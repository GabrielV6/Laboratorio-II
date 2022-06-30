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
		system("cls||clear");
		cout << this->separador << endl;
		cout << "Nuevo ingreso de datos del Interlocutor comercial" << endl;
		cout << this->separador << endl;
		dni = Validaciones::DatoObligarorioNum("Documento Nro");
		if (this->interlocutorComercialRN.ExisteInterlocutorComercial(dni)) // LLamar metodo de regla de negocio que valida si existe el DNI
		{
			cout << "Documento mal ingresado o ya esta dado de alta!!!" << endl;
			cout << "Cargar un nuevo ";
			dato = Validaciones::DatoObligarorioChar("'S' o cualquier otra letra para salir");
			if (toupper(dato) != 'S')
				return;
		}
		else
			break;
	} while (true);
	this->interlocutorComercial.setDni(dni);
	do
	{
		Fecha fechaIngreso;
		cout << "Fecha Alta: ";
		fechaIngreso.cargarFechaActual();
		cout << fechaIngreso.toStringFecha() << endl;
		this->interlocutorComercial.setFechaIngresoId(fechaIngreso);

		datos = Validaciones::DatoObligarorioCad("Nombre");
		this->interlocutorComercial.setNombre(datos);

		datos = Validaciones::DatoObligarorioCad("Apellido");
		this->interlocutorComercial.setApellido(datos);

		datos = Validaciones::DatoObligarorioCad("Correo:");
		this->interlocutorComercial.setEmail(datos);

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
	system("cls||clear");
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
	for (auto& intLoc : interlocutores)
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
	}
	cout << separador << endl;
	Validaciones::SystemPause();
}

string InterlocutorComercialV::DarDatosListado(InterlocutorComercial intLoc, int num)
{
	string datos = "";
	if (num == 0)
		datos = intLoc.toStringInterlocutor(true, true);
	if (num == 1)
	{
		string espacios = "                                       ";
		string dato = espacios;
		dato = dato.insert(0, to_string(intLoc.getId_ic()));
		datos = dato.erase(10);

		dato = espacios;
		dato = dato.insert(0, intLoc.getNombre());
		datos += dato.erase(16);

		dato = espacios;
		dato = dato.insert(0, intLoc.getApellido());
		datos += dato.erase(20);

		dato = espacios;
		dato = dato.insert(0, to_string(intLoc.getDni()));
		datos += dato.erase(12);

		dato = espacios;
		dato = dato.insert(0, intLoc.getEmail());
		datos += dato.erase(36);

		dato = espacios;
		dato = dato.insert(0, intLoc.getFechaIngresoId().toStringFecha());
		datos += dato.erase(10);
	}
	return datos;
}

int InterlocutorComercialV::MenuListarInerlocutor()
{
	int opcion;
	do
	{
		system("cls||clear");
		cout << this->separador << endl;
		cout << "|\tOPCIONES DE INTERLOCUTOR COMERCIAL" << endl;
		cout << this->separador << endl;
		cout << "|\t1. Listar todos los Interlocutroes" << endl;
		cout << "|\t2. Listar Interlocutores activos" << endl;
		cout << "|\t3. Listar Interlocutores inactivos" << endl;
		cout << "|\t0. Salir de las opciones de interlocutor" << endl;
		cout << this->separador << endl;
		opcion = Validaciones::DatoObligarorioNum("una opcion");
		if (opcion >= 0 && opcion <= 4)
			break;

	} while (true);
	char dato;
	if (opcion > 0)
	{
		cout << "Para ver solo resumen ingrese 'R', modo completo cuaquier otra" << endl;
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
		system("cls||clear");
		cout << this->separador << endl;
		cout << "|\tModificar datos del Interlocutor comercial" << endl;
		cout << this->separador << endl;
		cout << "Documento ";
		dni = Validaciones::DatoObligarorioNum("Nro");
		//cin >> dni;
		this->interlocutorComercial = this->interlocutorComercialRN.BuscarInterlocutorComercial(dni);
		if (dni == 0 || this->interlocutorComercial.getDni() != dni ) 
		{
			cout << "Documento ingresado no esta dado de alta, ";
			char dato = Validaciones::DatoObligarorioChar("'M' para modificar o cualquier otra letra para salir");
			if (toupper(dato) != 'M')
				return;			
		}
		else
			break;
	} while (true);
	do
	{
		system("cls||clear");
		cout << this->separador << endl;
		cout << "Interlocutor: " << this->interlocutorComercial.toStringInterlocutor(false, true) << endl;
		cout << this->separador << endl;
		cout << "|\t1. Modificar nombre" << endl;
		cout << "|\t2. Modificar apellido" << endl;
		cout << "|\t3. Modificar e-mail" << endl;
		cout << "|\t4. Modificar direccion" << endl;
		cout << "|\t5. Modificar estado (Activo/Inactivo)" << endl;
		cout << "|\t0. Volver al menú anteriror" << endl;
		cout << this->separador << endl;
		//cout << "Opcion: ";
		opcion = Validaciones::DatoObligarorioNum("Opcion");
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
			cout << "Direccion actual: ";
			cout << this->interlocutorComercial.getDireccionId().toStringDireccion() << endl;
			cout << separador << endl;
			Direccion direc;
			direc.CargarDireccion();
			this->interlocutorComercial.setDireccionId(direc);
			break;
		}
		case 5:
		{
			cout << "Modificar estado ";
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S')
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
		Validaciones::SystemPause();
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
		system("cls||clear");
		cout << this->separador << endl;
		cout << "|\tMenu Interlocutor Comercial" << endl;
		cout << this->separador << endl;
		cout << "|\t1. Nuevo Interlocutor" << endl;
		cout << "|\t2. Listar Interlocutores" << endl;
		cout << "|\t3. Modificar Interlocutor" << endl;
		cout << "|\t0. Salir del menu interlocutor" << endl;
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
			system("cls||clear");
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
