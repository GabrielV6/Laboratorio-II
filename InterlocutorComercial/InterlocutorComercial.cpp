#include "InterlocutorComercial.h"
InterlocutorComercial::InterlocutorComercial()
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
InterlocutorComercial::InterlocutorComercial(string nombreArchivo)
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
InterlocutorComercial::~InterlocutorComercial()
{}
void InterlocutorComercial::setId_ic(unsigned int id_ic)
{
	this->id_ic = id_ic;
}
void InterlocutorComercial::setNombre(string nombre)
{
	strcpy_s(this->nombre, nombre.c_str());
}
void InterlocutorComercial::setApellido(string apellido)
{
	strcpy_s(this->apellido, apellido.c_str());
}
void InterlocutorComercial::setDni(unsigned int dni)
{
	this->dni = dni;
}
void InterlocutorComercial::setEmail(string email)
{
	strcpy_s(this->email, email.c_str());
}
void InterlocutorComercial::setFechaIngresoId(Fecha fechaIn)
{
	this->fechaIngresoID = fechaIn;
}
void InterlocutorComercial::setDireccionId(Direccion direccionId)
{
	this->direccionID = direccionID;
}
void InterlocutorComercial::setNumPosicionArchivo(unsigned int numPosArch)
{
	this->numPosicionArch = numPosArch;
}
void InterlocutorComercial::setNombreArchivo(string nomArch)
{
	strcpy_s(this->nombreArchivo, nomArch.c_str());
}
void InterlocutorComercial::setActivo(bool activo)
{
	this->activo = activo;
}
unsigned int InterlocutorComercial::getId_ic()
{
	return this->id_ic;
}
string InterlocutorComercial::getNombre()
{
	return this->nombre;
}
string InterlocutorComercial::getApellido()
{
	return this->apellido;
}
unsigned int InterlocutorComercial::getDni()
{
	return this->dni;
}
string InterlocutorComercial::getEmail()
{
	return this->email;
}
Fecha InterlocutorComercial::getFechaIngresoId()
{
	return this->fechaIngresoID;
}
Direccion InterlocutorComercial::getDireccionId()
{
	return this->direccionID;
}
unsigned int InterlocutorComercial::getNumPosicionArhivo()
{
	return this->numPosicionArch;
}
string InterlocutorComercial::getNombreArchivo()
{
	return this->nombreArchivo;
}
bool InterlocutorComercial::getActivo()
{
	return this->activo;
}

/// <summary>
/// Método que devuelve una cadena con todos los datos del interlocutor
/// </summary>
/// <returns>Cadena</returns>
string InterlocutorComercial::toStringInterlocutor()
{
	return "Nombre: " + this->getNombre() + ", Apellido: " + this->getApellido() + ", DNI: " + to_string(this->getDni()) + ", Email: " + this->getEmail() +
		", Fecha Alta:" + this->getFechaIngresoId().toStringFecha() + ", Direccion: " + this->getDireccionId().toStringDireccion();
}