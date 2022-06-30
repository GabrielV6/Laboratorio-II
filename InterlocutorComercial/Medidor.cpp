#include "Medidor.h"


Medidor::Medidor(int id, int idCuentaContrato, bool estado, int lectura, int nPosicion)
{
    this->_id = id;
    this->_idCuentaContrato = idCuentaContrato;
    this->_estado = estado;
    this->_lectura = lectura;
    this->_numPosicionArch = nPosicion;

}

/*Medidor::Medidor()
{
    this->_id = 0;
    this->_idCuentaContrato = 0;
    this->_estado = false;
    this->_lectura = 0;
    this->_numPosicionArch = 0;
}
*/

Medidor::~Medidor() {
   
}

void Medidor::setId(int id) {
    this->_id = id;
}


void Medidor::setIdCuentaContrato(int idCuentaContrato)
{
    this->_idCuentaContrato = idCuentaContrato;
}


void Medidor::setEstado(bool estado) {
    this->_estado = estado;
}

void Medidor::setLectura(int lectura) {
    this->_lectura = lectura;
}

void Medidor::setNumPosicionArchivo(int numPosArch)
{
    this->_numPosicionArch = numPosArch;
}

string Medidor::toStringMedidor()
{   
    if (this->getIdCuentaContrato() == 0) {
        string aux = "Sin Asignacion";
        string valor = this->getEstado() ? "Instalado" : "Desinstalado";
        cout << "------------------------------------------------------------------------------------------------------------" << endl;
        string cadena = "ID " + to_string(this->getId()) + "\t, Cuenta Contrato: " + aux
            + "\t, Lectura: " + to_string(this->getLectura()) + "\t, Estado: " + valor;
   
        return cadena;
    }
	else {
		string aux = to_string(this->getIdCuentaContrato());
		string valor = this->getEstado() ? "Instalado" : "Desinstalado";
		cout << "------------------------------------------------------------------------------------------------------------" << endl;
		string cadena = "ID " + to_string(this->getId()) + "\t, Cuenta Contrato: " + to_string(this->getIdCuentaContrato())
			+ "\t, Lectura: " + to_string(this->getLectura()) + "\t, Estado: " + valor;
		return cadena;
	}
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

int Medidor::getLectura() {
    return this->_lectura;
}

int Medidor::getNumPosicionArhivo()
{
    return this->_numPosicionArch;
}
