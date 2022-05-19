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
    cout << "Ingrese el dia: ";
    cin >> this->dia;
    cout << "Ingrese el mes: ";
    cin >> this->mes;
    cout << "Ingrese el anio: ";
    cin >> this->anio;
}
string Fecha::toStringFecha()
{
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
}
Fecha::~Fecha()
{
}
