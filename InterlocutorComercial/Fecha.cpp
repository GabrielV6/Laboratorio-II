//implementar todos los metodos de la clase Fecha.h
#include "Fecha.h"

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
	string dato;
	dato = IngresoDato("Dia");
	this->dia = stoi(dato);
	dato = IngresoDato("Mes");
	this->mes = stoi(dato);
	dato = IngresoDato("Año");
	this->anio = stoi(dato);
}
string Fecha::IngresoDato(string nombreDato)
{
	string dato = "";
	do
	{
		cout << "Ingrese el " + nombreDato + " : ";
		cin >> dato;
		if (dato == "")
			cout << "Dato obligatorio " + nombreDato + " no puede quedar en blanco\nPor favor, ingrese nuevamente" << endl;
		else
			break;
	} while (true);
	return dato;
}
string Fecha::toStringFecha()
{
	return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
}
Fecha::~Fecha()
{
}
