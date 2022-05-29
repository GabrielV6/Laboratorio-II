//implementar todos los metodos de la clase Fecha.h
#include "Fecha.h"
#include "Validaciones.h"

Fecha::Fecha(int dia, int mes, int anio)
{
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}
void Fecha::setDia(int dia)
{
	if (dia > 0 && dia < 32)
		this->dia = dia;
}
void Fecha::setMes(int mes)
{
	if (mes > 0 && mes < 13)
		this->mes = mes;
}
void Fecha::setAnio(int anio)
{
	this->anio = anio;
}
int Fecha::getDia()
{
	return this->dia;
}
int Fecha::getMes()
{
	return this->mes;
}
int Fecha::getAnio()
{
	return this->anio;
}
void Fecha::cargarFecha()
{
	//Validar todos los datos de tipo numericos
	int dato;
	dato = Validaciones::DatoObligarorioNum("Dia");
	this->dia = dato;
	dato = Validaciones::DatoObligarorioNum("Mes");
	this->mes = dato;
	dato = Validaciones::DatoObligarorioNum("Año");
	this->anio = dato;
}

string Fecha::toStringFecha()
{
	return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
}
Fecha::~Fecha()
{
}
