#include "Direccion.h"
#include "Validaciones.h"

Direccion::Direccion()
{
	this->setCalle("");
	this->setNumero(0);
	this->setDescripcion("");
	this->setCodPostal("");
	this->setLocalidad("");
	this->setProvincia("");
}
Direccion::~Direccion()
{
}
void Direccion::setCalle(string calle)
{
	strcpy(this->calle, calle.c_str());
}
void Direccion::setNumero(unsigned int numero)
{
	this->numero = numero;
}
void Direccion::setDescripcion(string descripcion)
{
	strcpy(this->descripcion, descripcion.c_str());
}
void Direccion::setCodPostal(string codPostal)
{
	strcpy(this->codPostal, codPostal.c_str());
}
void Direccion::setLocalidad(string localidad)
{
	strcpy(this->loclidad, localidad.c_str());
}
void Direccion::setProvincia(string provincia)
{
	strcpy(this->provincia, provincia.c_str());
}
string Direccion::getCalle()
{
	return this->calle;
}
unsigned int Direccion::getNumero()
{
	return this->numero;
}
string Direccion::getDescripcion()
{
	return this->descripcion;
}
string Direccion::getCodPostal()
{
	return this->codPostal;
}
string Direccion::getLocalidad()
{
	return this->loclidad;
}
string Direccion::getProvincia()
{
	return this->provincia;
}
void Direccion::CargarDireccion()
{
	string dato = Validaciones::DatoObligarorioCad("Calle");
	this->setCalle(dato);
	int num  = Validaciones::DatoObligarorioNum("Numero");
	this->numero = num;
	
	dato = Validaciones::DatoObligarorioCad("Descripcion");
	this->setDescripcion(dato);
	
	dato = Validaciones::DatoObligarorioCad("Codigo Postal");
	this->setCodPostal(dato);

	dato = Validaciones::DatoObligarorioCad("Localidad");
	this->setLocalidad(dato);

	dato = Validaciones::DatoObligarorioCad("Provincia");
	this->setProvincia(dato);
}

string Direccion::toStringDireccion()
{
	return "Calle: " + this->getCalle() + ", numero: " + to_string(this->numero) + ", Desc. Casa Dpto: " + this->getDescripcion() +
		", Cod. Postal: " + this->getCodPostal() + ", localidad: " + this->getLocalidad() + ", provincia: " + this->getProvincia();
}