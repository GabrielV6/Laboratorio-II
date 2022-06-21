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
}
InterlocutorComercial::~InterlocutorComercial()
{}
void InterlocutorComercial::setId_ic(int id_ic)
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
void InterlocutorComercial::setDni(int dni)
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
void InterlocutorComercial::setNumPosicionArchivo(int numPosArch)
{
	this->numPosicionArch = numPosArch;
}
void InterlocutorComercial::setActivo(bool activo)
{
	this->activo = activo;
}
int InterlocutorComercial::getId_ic()
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
int InterlocutorComercial::getDni()
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
int InterlocutorComercial::getNumPosicionArhivo()
{
	return this->numPosicionArch;
}
bool InterlocutorComercial::getActivo()
{
	return this->activo;
}

/// <summary>
/// Método que devuelve una cadena con todos los datos del interlocutor
/// </summary>
/// <returns>Cadena</returns>
string InterlocutorComercial::toStringInterlocutor(bool verId, bool verDir)
{
	string cadena = "Nombre: " + this->getNombre() + ", Apellido: " + this->getApellido()
		+ ", DNI: " + to_string(this->getDni()) + ", Email: " + this->getEmail() +
		", Fecha Alta: " + this->getFechaIngresoId().toStringFecha();
	if (verId)
		cadena = "Id: " + to_string(this->id_ic) + ", " + cadena;
	if (verDir)
		cadena = cadena + "\nDireccion: " + this->getDireccionId().toStringDireccion();
	return cadena;
}