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

long MedidorAD::TotalMedidoresEnArchivo()
{

   
}

bool MedidorAD::GuardarEnArchivoMedidor(Medidor& medidor)
{
    
}

bool MedidorAD::ActualizarEnArchivoMedidor(Medidor& medidor)
{
    
}

Medidor MedidorAD::getMedidorArchivo(long dni)
{
    
}

vector<Medidor> MedidorAD::getMedidoresArchivo()
{
    
}

