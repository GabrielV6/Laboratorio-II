/*
Implementar todos los metodos de la clase contrato.h
*/
#include "Contrato.h"
Contrato::Contrato()
{
    this->idContrato = 0;
    this->idInterlocutorComercial = 0;
    this->idCuentaContrato = 0;
    this->idMedidor = 0;
    this->idInstalacion = 0;
    strcpy_s(this->zona, "");
    this->fechaAltaContrato = Fecha();
    this->fechaBajaContrato = Fecha();
    this->tarifas = 0;
    this->consumoPromedio = 0;
}
Contrato::Contrato(int idContrato, long idInterlocutorComercial, int idCuentaContrato, int idMedidor, int idInstalacion, string zona, Fecha fecAlta, Fecha fecBaja, float tarifas, float consumoPromedio)
{
    this->idContrato = idContrato;
    this->idInterlocutorComercial = idInterlocutorComercial;
    this->idCuentaContrato = idCuentaContrato;
    this->idMedidor = idMedidor;
    this->idInstalacion = idInstalacion;
    strcpy_s(this->zona, zona.c_str());
    this->fechaAltaContrato = fecAlta;
    this->fechaBajaContrato = fecBaja;
    this->tarifas = tarifas;
    this->consumoPromedio = consumoPromedio;
}
void Contrato::setIdContrato(int idContrato)
{
    this->idContrato = idContrato;
}
int Contrato::getIdContrato()
{
    return this->idContrato;
}
void Contrato::setIdInterlocutorComercial(long idInterlocutorComercial)
{
    this->idInterlocutorComercial = idInterlocutorComercial;
}
long Contrato::getIdInterlocutorComercial()
{
    return this->idInterlocutorComercial;
}
void Contrato::setIdCuentaContrato(int idCuentaContrato)
{
    this->idCuentaContrato = idCuentaContrato;
}
int Contrato::getIdCuentaContrato()
{
    return this->idCuentaContrato;
}
void Contrato::setIdMedidor(int idMedidor)
{
    this->idMedidor = idMedidor;
}
int Contrato::getIdMedidor()
{
    return this->idMedidor;
}
void Contrato::setIdInstalacion(int idInstalacion)
{
    this->idInstalacion = idInstalacion;
}
int Contrato::getIdInstalacion()
{
    return this->idInstalacion;
}
void Contrato::setZona(string zona)
{
    strcpy_s(this->zona, zona.c_str());
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
void Contrato::setTarifas(float tarifas)
{
    this->tarifas = tarifas;
}
float Contrato::getTarifas()
{
    return this->tarifas;
}
void Contrato::setConsumoPromedio(float consumoPromedio)
{
    this->consumoPromedio = consumoPromedio;
}
float Contrato::getConsumoPromedio()
{
    return this->consumoPromedio;
}
string Contrato::toStringContrato()
{
    string toStr;
    toStr +=  "ID Contrato: " + to_string(this->idContrato) + "\n";
    toStr +=  "ID Interlocutor Comercial: " + to_string(this->idInterlocutorComercial) + "\n";
    toStr +=  "ID Cuenta Contrato: " + to_string(this->idCuentaContrato) + "\n";
    toStr +=  "ID Medidor: " + to_string(this->idMedidor) + "\n";
    toStr +=  "ID Instalacion: " + to_string(this->idInstalacion) + "\n";
    toStr +=  "Zona: " + this->getZona() + "\n";
    toStr +=  "Tarifas: " + to_string(this->tarifas) + "\n";
    toStr +=  "Consumo Promedio: " + to_string(this->consumoPromedio) + "\n";
}   
