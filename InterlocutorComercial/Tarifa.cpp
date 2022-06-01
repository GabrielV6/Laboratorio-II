#include "Tarifa.h"
#include <cstring>


Tarifa::Tarifa()
{
   this->id_tarifa = 0;
   this->cargoFijo = 0;
   this->cargoVariable = 0;
   this->impuestos = 0;
   this->tipoDeTarifa = true;
   this->estado = false;
   this->numPosicionArch = -1;
   this->nombreDeArchivo=  "";
}

Tarifa::Tarifa(string nombreArchivo)
{
	this-> nombreDeArchivo = nombreDeArchivo;
	this->id_tarifa = 0;
    this->cargoFijo = 0;
    this->cargoVariable = 0;
    this->impuestos = 0;
    this->tipoDeTarifa = true;
	this->estado = false;
	this->numPosicionArch = -1;
}
// setters
void Tarifa::setIdTarifa(int id_tarifa)
{
        this->id_tarifa = id_tarifa;
}
void Tarifa::setCargoFijo(float cargoFijo)
{
        this->cargoFijo = cargoFijo;
}
void Tarifa::setCargoVariable(float cargoVariable)
{
        this->cargoVariable = cargoVariable;
}
void Tarifa::setImpuestos(float impuestos)
{
    this->impuestos = impuestos;
}

void Tarifa::setTipoDeTarifa(bool tipoDeTarifa)
{
    this->tipoDeTarifa = tipoDeTarifa;
}

void Tarifa::setNumPosicionArchivo(long numPosArch)
{
	this->numPosicionArch = numPosArch;
}

void Tarifa::setEstado(bool estado)
{
    this->estado = estado;
}
// getters
int Tarifa::getIdTarifa()
{
    return this->id_tarifa;
}
float Tarifa::getCargoFijo()
{
    return this->cargoFijo;
}
float Tarifa::getCargoVariable()
{
    return this->cargoVariable;
}
float Tarifa::getImpuestos()
{
    return this->impuestos;
}
bool Tarifa::getEstado()
{
    return this->estado;
}

void Tarifa::cargarTarifa()
{
    cout << "Ingrese el Cargo Fijo: ";
    cin >> this->cargoFijo;
    cout << "Ingrese el Cargo Variable: ";
    cin >> this->cargoVariable;
    cout << "Ingrese los Impuestos: ";
    cin >> this->impuestos;
    cout << "Ingrese el Tipo de tarifa: ";
    cin >> this->tipoDeTarifa;
}

long Tarifa::getNumPosicionArhivo()
{
	return this->numPosicionArch;
}
string Tarifa::toStringTarifa()
{
    return to_string(this->cargoFijo) + "/" + to_string(this->cargoVariable) + "/" + to_string(this->impuestos)  + "/" + to_string(this->tipoDeTarifa);
}
Tarifa::~Tarifa()
{
}
