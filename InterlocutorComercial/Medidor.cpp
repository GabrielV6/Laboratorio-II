#include "Medidor.h"


Medidor::~Medidor() {
   
}

Medidor::Medidor(int id, bool estado, float erc, float eri, float eat, float ert, float erp) {
    this->_id = id;
    this->_estado = estado;
    this->_erc = erc;
    this->_eri = eri;
    this->_eat = eat;
    this->_ert = ert;
    this->_erp = erp;
}

Medidor::Medidor() {
    this->_id = 0;
    this->_estado = false;
    this->_erc = 0;
    this->_eri = 0;
    this->_eat = 0;
    this->_ert = 0;
    this->_erp = 0;
}

void Medidor::setId(int id) {
    this->_id = id;
}

void Medidor::setEstado(bool estado) {
    this->_estado = estado;
}

void Medidor::setErc(float erc) {
    if (erc >= 0) {
        this->_erc = erc;
    }
    else {
        cout << "El valor de ERC no puede ser negativo" << endl;
    }
}

void Medidor::setEri(float eri) {
    if (eri >= 0) {
        this->_eri = eri;
    }
    else {
        cout << "El valor de ERI no puede ser negativo" << endl;
    }
}

void Medidor::setEat(float eat) {
    if (eat >= 0) {
        this->_eat = eat;
    }
    else {
        cout << "El valor de EAT no puede ser negativo" << endl;
    }
}

void Medidor::setErt(float ert) {
    if (ert >= 0) {
        this->_ert = ert;
    }
    else {
        cout << "El valor de ERT no puede ser negativo" << endl;
    }
}

void Medidor::setErp(float erp) {
    if (erp >= 0) {
        this->_erp = erp;
    }
    else {
        cout << "El valor de ERP no puede ser negativo" << endl;
    }
}

int Medidor::getId() {
    return this->_id;
}

bool Medidor::getEstado() {
    return this->_estado;
}

float Medidor::getErc() {
    return this->_erc;
}

float Medidor::getEri() {
    return this->_eri;
}

float Medidor::getEat() {
    return this->_eat;
}

float Medidor::getErt() {
    return this->_ert;
}

float Medidor::getErp() {
    return this->_erp;
}
