#include "Usuario.h"
Usuario::Usuario()
{
	this->id_ic = 0;
	this->dni = 0;
	strcpy_s(this->nombre, "");
	strcpy_s(this->apellido, "");
	strcpy_s(this->email, "");
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = false;
	this->numPosicionArch = -1;
	strcpy_s(this->nombreArchivo, "");
}
Usuario::Usuario(string nombreArchivo)
{
	strcpy_s(this->nombreArchivo, nombreArchivo.c_str());
	this->id_ic = 0;
	this->dni = 0;
	strcpy_s(this->nombre, "");
	strcpy_s(this->apellido, "");
	strcpy_s(this->email, "");
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = false;
	this->numPosicionArch = -1;
}
Usuario::~Usuario()
{}
void Usuario::setId_ic(long id_ic)
{
	this->id_ic = id_ic;
}
void Usuario::setNombre(string nombre)
{
	strcpy_s(this->nombre, nombre.c_str());
}
void Usuario::setApellido(string apellido)
{
	strcpy_s(this->apellido, apellido.c_str());
}
void Usuario::setDni(long dni)
{
	this->dni = dni;
}
void Usuario::setEmail(string email)
{
	strcpy_s(this->email, email.c_str());
}
void Usuario::setFechaIngresoId(Fecha fechaIn)
{
	this->fechaIngresoID = fechaIn;
}
void Usuario::setDireccionId(Direccion direccionId)
{
	this->direccionID = direccionID;
}
void Usuario::setNumPosicionArchivo(long numPosArch)
{
	this->numPosicionArch = numPosArch;
}
void Usuario::setNombreArchivo(string nomArch)
{
	strcpy_s(this->nombreArchivo, nomArch.c_str());
}
void Usuario::setActivo(bool activo)
{
	this->activo = activo;
}
long Usuario::getId_ic()
{
	return this->id_ic;
}
string Usuario::getNombre()
{
	return this->nombre;
}
string Usuario::getApellido()
{
	return this->apellido;
}
long Usuario::getDni()
{
	return this->dni;
}
string Usuario::getEmail()
{
	return this->email;
}
Fecha Usuario::getFechaIngresoId()
{
	return this->fechaIngresoID;
}
Direccion Usuario::getDireccionId()
{
	return this->direccionID;
}
long Usuario::getNumPosicionArhivo()
{
	return this->numPosicionArch;
}
string Usuario::getNombreArchivo()
{
	return this->nombreArchivo;
}
bool Usuario::getActivo()
{
	return this->activo;
}

/// <summary>
/// Método que devuelve una cadena con todos los datos del usuario
/// </summary>
/// <returns>Cadena</returns>
string Usuario::toStringUsuario()
{
	return "Nombre: " + this->getNombre() + ", Apellido: " + this->getApellido() + ", DNI: " + to_string(this->getDni()) + ", Email: " + this->getEmail() +
		", Fecha Alta:" + this->getFechaIngresoId().toStringFecha() + ", Direccion: " + this->getDireccionId().toStringDireccion();
}