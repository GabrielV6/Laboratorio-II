#include "MedidorAD.h"

MedidorAD::~MedidorAD() {
    this->_medidores.clear();
}

MedidorAD::MedidorAD(string nombreArchivo) {
    this->_nombreArchivo = nombreArchivo;
}
void MedidorAD::setNombreArchivo(string nombreArchivo) {
    this->_nombreArchivo = nombreArchivo;
}
string MedidorAD::getNombreArchivo() {
    return this->_nombreArchivo;
}



