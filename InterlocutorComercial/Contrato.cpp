/*
Implementar todos los metodos de la clase contrato.h
*/
#include "Contrato.h"
Contrato::Contrato()
{
    this->idContrato = 0;
    this->IdInterlocutorComercial = 0;
    this->idCuentaContrato = 0;
    this->idMedidor = 0;
    this->idInstalacion = 0;
    strcpy(this->zona, "");
    this->fechaAltaContrato = Fecha();
    this->fechaBajaContrato = Fecha();
    this->codigoTarifa = 0;
    this->consumoPromedio = 0;
    this->posicionArchivo = 0;
    this->activo = false;
}
void Contrato::setIdContrato(int idContrato)
{
    this->idContrato = idContrato;
}
unsigned int Contrato::getIdContrato()
{
    return this->idContrato;
}
void Contrato::setIdInterlocutorComercial(unsigned int iD_Ic)
{
    this->IdInterlocutorComercial = iD_Ic;
}
unsigned int Contrato::getIdInterlocutorComercial()
{
    return this->IdInterlocutorComercial;
}
void Contrato::setIdCuentaContrato(int idCuentaContrato)
{
    this->idCuentaContrato = idCuentaContrato;
}
unsigned int Contrato::getIdCuentaContrato()
{
    return this->idCuentaContrato;
}
void Contrato::setIdMedidor(int idMedidor)
{
    this->idMedidor = idMedidor;
}
unsigned int Contrato::getIdMedidor()
{
    return this->idMedidor;
}
void Contrato::setIdInstalacion(int idInstalacion)
{
    this->idInstalacion = idInstalacion;
}
unsigned int Contrato::getIdInstalacion()
{
    return this->idInstalacion;
}
void Contrato::setZona(string zona)
{
    strcpy(this->zona, zona.c_str());
}
string Contrato::getZona()
{
    return this->zona;
}
void Contrato::setFechaAltaContrato(Fecha fecAlta)
{
    this->fechaAltaContrato = fecAlta;
}
Fecha Contrato::getFechaAltaContrato()
{
    return this->fechaAltaContrato;
}
void Contrato::setFechaBajaContrato(Fecha fecBaja)
{
    this->fechaBajaContrato = fecBaja;
}
Fecha Contrato::getFechaBajaContrato()
{
    return this->fechaBajaContrato;
}
void Contrato::setCodigoTarifa(unsigned int codigoTarifa)
{
    this->codigoTarifa = codigoTarifa;
}
unsigned int Contrato::getCodigoTarifa()
{
    return this->codigoTarifa;
}
void Contrato::setConsumoPromedio(float consumoPromedio)
{
    this->consumoPromedio = consumoPromedio;
}
float Contrato::getConsumoPromedio()
{
    return this->consumoPromedio;
}
void Contrato::setPoscicionArchivo(long posicionArchivo)
{
    this->posicionArchivo = posicionArchivo;
}
long Contrato::getPosicionArchivo()
{
    return this->posicionArchivo;
}
void Contrato::setActivo(bool activo)
{
    this->activo = activo;
}
bool Contrato::getActivo()
{
    return this->activo;
}
string Contrato::toStringContrato()
{
    string toStr;
    toStr +=  "ID Contrato: " + to_string(this->idContrato) + "\n";
    toStr +=  "ID Interlocutor Comercial: " + to_string(this->IdInterlocutorComercial) + "\n";
    toStr +=  "ID Cuenta Contrato: " + to_string(this->idCuentaContrato) + "\n";
    toStr +=  "ID Medidor: " + to_string(this->idMedidor) + "\n";
    toStr +=  "ID Instalacion: " + to_string(this->idInstalacion) + "\n";
    toStr +=  "Zona: " + this->getZona() + "\n";
    toStr +=  "Tarifa: " + to_string(this->codigoTarifa) + "\n";
    toStr +=  "Consumo Promedio: " + to_string(this->consumoPromedio) + "\n";
    return toStr;
}   
