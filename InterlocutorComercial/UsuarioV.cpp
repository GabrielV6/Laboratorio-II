#include "UsuarioV.h"

UsuarioV::UsuarioV(string nombreArchivo)
{
	this->usuario = Usuario(nombreArchivo);
	this->nombreArchivo = nombreArchivo;
	this->usuarioRN = UsuarioRN(nombreArchivo);
}
UsuarioV::~UsuarioV()
{
}
/// <summary>
/// M�todo que permite dar de alta un usuario y lo graba en el archivo que contiene los usuarios.
/// </summary>
void UsuarioV::NuevoUsuario()
{
	this->usuario = Usuario(this->nombreArchivo);
	long dni;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Nuevo ingreso de datos del usuario" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Documento Nr.: ";
		cin >> dni;
		if (this->usuarioRN.BuscarUsuario(dni).getDni() == dni) // LLamar metodo de regla de negocio que valida si existe el DNI
		{
			cout << "Documento ingresado ya esta dado de alta!!!" << endl;
			system("cls");
		}
		else
			break;
	} while (true);
	this->usuario.setDni(dni);
	string datos;
	cout << "Nombre: ";
	cin >> datos;
	this->usuario.setNombre(datos);
	cout << "Apellido: ";
	cin >> datos;
	this->usuario.setApellido(datos);
	cout << "Correo electronico: ";
	cin >> datos;
	this->usuario.setEmail(datos);
	Fecha fechaIngreso;
	cout << "Fecha Alta: ";
	fechaIngreso.cargarFecha();
	this->usuario.setFechaIngresoId(fechaIngreso);
	Direccion direccion;
	cout << "Direccion: ";
	direccion.CargarDireccion();
	this->usuario.setDireccionId(direccion);
	// this->GuardarEnArchivo();
}
/// <summary>
/// Funcion global para listar todos los usuarios del archivo.
/// </summary>
void UsuarioV::ListarUsuarios()
{
	vector<Usuario> usuarios = this->usuarioRN.VectorUsuarios();
	for (auto intLoc : usuarios)
	{
		cout << intLoc.toStringUsuario() << endl;
	}
}

void UsuarioV::MenuModificarUsuario()
{
	long dni;
	int opcion;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Modificar datos del usuario" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Documento Nr.: ";
		cin >> dni;
		this->usuario = this->usuarioRN.BuscarUsuario(dni);
		if (this->usuario.getDni() == dni) // LLamar metodo de regla de negocio que valida si existe el DNI
		{
			cout << "Documento ingresado no esta dado de alta!!!" << endl;
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Usuario: " << this->usuario.toStringUsuario() << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Modificar nombre" << endl;
		cout << "2. Modificar apellido" << endl;
		cout << "3. Modificar e-mail" << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		string datos;
		switch (opcion)
		{
		case 1:
			cout << "Nombre: ";
			cin >> datos;
			this->usuario.setNombre(datos);
			break;
		case 2:
			cout << "Apellido: ";
			cin >> datos;
			this->usuario.setApellido(datos);
			break;
		case 3:
			cout << "E-mail: ";
			cin >> datos;
			this->usuario.setEmail(datos);
			break;
		case 0:

			break;
		default:
			cout << "Opcion invalida!!!" << endl;
			break;
		}
	} while (opcion != 0);
}
void UsuarioV::ModificarUsuario()
{
	MenuModificarUsuario();
	this->usuarioRN.ControlModificaciones(this->usuario);
}
/// <summary>
/// Metodo que muestra un menu de opciones para las altas bajas y modificaciones de usuarios.
/// </summary>
void UsuarioV::MenuUsuario()
{
	bool salir = false;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Menu usuario" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Nuevo usuario" << endl;
		cout << "2. Listar usuarios" << endl;
		cout << "3. Modificar usuario" << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		int opcion;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			this->NuevoUsuario();
			break;
		case 2:
			this->ListarUsuarios();
			break;
		case 3:
			this->ModificarUsuario();
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

void UsuarioV::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string UsuarioV::getNombreArchivo()
{
	return this->nombreArchivo;
}
void UsuarioV::setUsuario(Usuario &usuario)
{
	this->usuario = usuario;
}
