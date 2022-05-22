#include "Direccion.h"

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
	strcpy_s(this->calle, calle.c_str());
}
void Direccion::setNumero(unsigned int numero)
{
	this->numero = numero;
}
void Direccion::setDescripcion(string descripcion)
{
	strcpy_s(this->descripcion, descripcion.c_str());
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
	string dato = IngresoDato("Calle");
	this->setCalle(dato);

	dato = IngresoDato("Numero");
	this->numero = stoi(dato);
	
	dato = IngresoDato("Descripcion");
	this->setDescripcion(dato);
	
	dato = IngresoDato("Codigo Postal");
	this->setCodPostal(dato);

	dato = IngresoDato("Localidad");
	this->setLocalidad(dato);

	dato = IngresoDato("Provincia");
	this->setProvincia(dato);
}

string Direccion::toStringDireccion()
{
	return "Calle: " + this->getCalle() + ", numero: " + to_string(this->numero) + ", Desc. Casa Dpto: " + this->getDescripcion() +
		", Cod. Postal: " + this->getCodPostal() + ", localidad: " + this->getLocalidad() + ", provincia: " + this->getProvincia();
}

string Direccion::IngresoDato(string nombreDato)
{
	string dato = "";
	do
	{
		cout << "Ingrese " + nombreDato + " : ";
		cin >> dato;
		if (dato == "")
			cout << "Dato obligatorio " + nombreDato + " no puede quedar en blanco\nPor favor, ingrese nuevamente" << endl;
		else
			break;
	} while (true);
	return dato;
}