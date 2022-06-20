#include "Medidor.h"


Medidor::Medidor(int id, int idCuentaContrato, bool estado, float consumo, int nPosicion)
{
    this->_id = id;
    this->_idCuentaContrato = idCuentaContrato;
    this->_estado = estado;
    this->_consumo = consumo;
    this->_numPosicionArch = nPosicion;

}

Medidor::~Medidor() {
   
}


void Medidor::setId(int id) {
    this->_id = id;
}

Medidor::Medidor()
{
    this->_id = 0;
    this->_idCuentaContrato = 0;
    this->_estado = true;
    this->_consumo = 0;
    this->_numPosicionArch = 0;
}

void Medidor::setIdCuentaContrato(int idCuentaContrato)
{
    this->_idCuentaContrato = idCuentaContrato;
}


void Medidor::setEstado(bool estado) {
    this->_estado = estado;
}

void Medidor::setConsumo(float consumo) {
    this->_consumo = consumo;
}

void Medidor::setNumPosicionArchivo(int numPosArch)
{
    this->_numPosicionArch = numPosArch;
}

int Medidor::getId() {
    return this->_id;
}

int Medidor::getIdCuentaContrato() {
    return this->_idCuentaContrato;
}

bool Medidor::getEstado() {
    return this->_estado;
}

float Medidor::getConsumo() {
    return this->_consumo;
}

int Medidor::getNumPosicionArhivo()
{
    return this->_numPosicionArch;
}
