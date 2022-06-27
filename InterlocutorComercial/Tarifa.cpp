#include "Tarifa.h"

Tarifa::Tarifa(int id, float cargoFijo, float cargoVar, float impuestos, int tipoTarifa, int numPosicion, bool estado)
{
    this->_idTarifa = id;
    this->_cargoFijo = cargoFijo;
    this->_cargoVariable = cargoVar;
    this->_impuestos = impuestos;
    this->_tipoDeTarifa = tipoTarifa;
    this->_numPosicionArch = numPosicion;
    this->_estado = estado;
}

Tarifa::~Tarifa()
{
}

void Tarifa::setIdTarifa(int idTarifa)
{
    this->_idTarifa = idTarifa;
}

void Tarifa::setCargoFijo(float cargoFijo)
{
    this->_cargoFijo = cargoFijo;
}

void Tarifa::setCargoVariable(float cargoVariable)
{
    this->_cargoVariable = cargoVariable;
}

void Tarifa::setImpuestos(float impuestos)
{
    this->_impuestos = impuestos;
}

void Tarifa::setTipoDeTarifa(int tipoDeTarifa)
{
     this->_tipoDeTarifa = tipoDeTarifa;
}

void Tarifa::setNumPosicionArchivo(int numPosArch)
{
    this->_numPosicionArch = numPosArch;
}

void Tarifa::setEstado(bool estado)
{
    this->_estado = estado;
}

int Tarifa::getIdTarifa()
{
    return this->_idTarifa;
}

float Tarifa::getCargoFijo()
{
    return this->_cargoFijo;;
}

float Tarifa::getCargoVariable()
{
    return this->_cargoVariable;
}

float Tarifa::getImpuestos()
{
    return this->_impuestos;
}

int Tarifa::getTipoDeTarifa()
{
    return this->_tipoDeTarifa;
}

int Tarifa::getNumPosicionArhivo()
{
    return this->_numPosicionArch;
}

bool Tarifa::getEstado()
{
    return this->_estado;
}

string Tarifa::toStringTarifa()
{
    string cadena = "ID: " + to_string(this->getIdTarifa()) + ", Cargo Fijo: " + to_string(this->getCargoFijo())
        + ", Cargo Variable: " + to_string(this->getCargoVariable()) + ", Impuesto: " + to_string(this->getImpuestos())
        + ", Tipo de Tarifa: " + to_string(this->getTipoDeTarifa()) + " Estado: " + to_string(this->getEstado());

    return cadena;
}