#include "Direccion.h"

Direccion::Direccion()
{	
	this->setCalle("");	
	this->setNumero(0);	
	this->setCasaDpto("");	
	this->setCodPostal("");	
	this->setLocalidad("");	
	this->setProvincia("");
}
Direccion::~Direccion()
{
}
void Direccion::setCalle(string calle)
{
	strcpy_s(this->calle, calle.c_str());
}
void Direccion::setNumero(int numero)
{
	this->numero = numero;
}
void Direccion::setCasaDpto(string casaDpto)
{
	strcpy_s(this->casaDpto, casaDpto.c_str());
}
void Direccion::setCodPostal(string codPostal)
{
	strcpy_s(this->codPostal, codPostal.c_str());
}
void Direccion::setLocalidad(string localidad)
{
	strcpy_s(this->loclidad, localidad.c_str());
}
void Direccion::setProvincia(string provincia)
{
	strcpy_s(this->provincia, provincia.c_str());
}
string Direccion::getCalle()
{
	return this->calle;
}
int Direccion::getNumero()
{
	return this->numero;
}
string Direccion::getCasaDpto()
{
	return this->casaDpto;
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
	cout << "Ingrese la calle: ";
	cin >> this->calle;
	cout << "Ingrese el numero: ";
	cin >> this->numero;
	cout << "Ingrese descripcion casa departamento: ";
	cin >> this->casaDpto;
	cout << "Ingrese el codigo postal: ";
	cin >> this->codPostal;
	cout << "Ingrese la localidad: ";
	cin >> this->loclidad;
	cout << "Ingrese la provincia: ";
	cin >> this->provincia;
}
string Direccion::toStringDireccion()
{
	return "Calle: " + this->getCalle() + ", numero: " + to_string(this->numero) + ", Desc. Casa Dpto: " + this->getCasaDpto() +
		", Cod. Postal: " + this->getCodPostal() + ", localidad: " + this->getLocalidad() + ", provincia: " + this->getProvincia();
}