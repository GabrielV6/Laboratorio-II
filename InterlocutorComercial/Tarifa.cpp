#include "Tarifa.h"

Tarifa::Tarifa()
{
 // hacer constructor
}
// setters
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
void Tarifa::setCodigoDeTarifa(int codigoDeTarifa)
{
    this->codigoDeTarifa = codigoDeTarifa;
}
void Tarifa::setTipoDeTarifa(int tipoDeTarifa)
{
    this->tipoDeTarifa = tipoDeTarifa;
}
// getters
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
int Tarifa::getCodigoDeTarifa()
{
    return this->codigoDeTarifa;
}
bool Tarifa::getCodigoDeTarifa()
{
    return this->codigoDeTarifa;
}

void Tarifa::cargarTarifa()
{
    cout << "Ingrese el Cargo Fijo: ";
    cin >> this->cargoFijo;
    cout << "Ingrese el Cargo Variable: ";
    cin >> this->cargoVariable;
    cout << "Ingrese los Impuestos: ";
    cin >> this->impuestos;
    cout << "Ingrese el Codigo de tarifa: ";
    cin >> this->codigoDeTarifa;
    cout << "Ingrese el Tipo de tarifa: ";
    cin >> this->tipoDeTarifa;
}
string Tarifa::toStringTarifa()
{
    return to_string(this->cargoFijo) + "/" + to_string(this->cargoVariable) + "/" + to_string(this->impuestos) + "/" + to_string(this->codigoDeTarifa) + "/" + to_string(this->tipoDeTarifa);
}
Tarifa::~Tarifa()
{
}