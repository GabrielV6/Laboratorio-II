#include "InterlocutorComercial.h"
InterlocutorComercial::InterlocutorComercial()
{
	this->id_ic = 0;
	this->dni = 0;
	strcpy(this->nombre, "");
	strcpy(this->apellido, "");
	strcpy(this->email, "");
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = false;
	this->numPosicionArch = -1;
	strcpy(this->nombreArchivo, "");
}
InterlocutorComercial::InterlocutorComercial(string nombreArchivo)
{
	strcpy(this->nombreArchivo, nombreArchivo.c_str());
	this->id_ic = 0;
	this->dni = 0;
	strcpy(this->nombre, "");
	strcpy(this->apellido, "");
	strcpy(this->email, "");
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = false;
	this->numPosicionArch = -1;
}
InterlocutorComercial::~InterlocutorComercial()
{}
void InterlocutorComercial::setId_ic(long id_ic)
{
	this->id_ic = id_ic;
}
void InterlocutorComercial::setNombre(string nombre)
{
	strcpy(this->nombre, nombre.c_str());
}
void InterlocutorComercial::setApellido(string apellido)
{
	strcpy(this->apellido, apellido.c_str());
}
void InterlocutorComercial::setDni(long dni)
{
	this->dni = dni;
}
void InterlocutorComercial::setEmail(string email)
{
	strcpy(this->email, email.c_str());
}
void InterlocutorComercial::setFechaIngresoId(Fecha fechaIn)
{
	this->fechaIngresoID = fechaIn;
}
void InterlocutorComercial::setDireccionId(Direccion& direccionId)
{
	this->direccionID = direccionId;
}
void InterlocutorComercial::setNumPosicionArchivo(long numPosArch)
{
	this->numPosicionArch = numPosArch;
}
void InterlocutorComercial::setNombreArchivo(string nomArch)
{
	strcpy(this->nombreArchivo, nomArch.c_str());
}
void InterlocutorComercial::setActivo(bool activo)
{
	this->activo = activo;
}
long InterlocutorComercial::getId_ic()
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
long InterlocutorComercial::getDni()
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
Direccion& InterlocutorComercial::getDireccionId()
{
	return this->direccionID;
}
long InterlocutorComercial::getNumPosicionArhivo()
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