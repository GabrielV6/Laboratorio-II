#include "CuentaContrato.h"

CuentaContrato::CuentaContrato()
{
	this->id_cc = 0;
	this->id_ic = 0;
	this->id_tarifa = 0;
	strcat(this->formaDePago, "");
	this->categoriaDeCliente = false;
    this->tipoDeInteres = false;
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = true;
	this->numPosicionArch = -1;
	strcpy(this->nombreArchivo, "");
}
CuentaContrato::CuentaContrato(string nombreArchivo)
{
	strcpy(this->nombreArchivo, nombreArchivo.c_str());
	this->id_cc = 0;
	this->id_ic = 0;
	this->id_tarifa = 0;
	strcpy(this->formaDePago, "");
	this->categoriaDeCliente = false;
    this->tipoDeInteres = false;
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = true;
	this->numPosicionArch = -1;
}
CuentaContrato::~CuentaContrato()
{}
void CuentaContrato::setId_cc(int id_cc)
{
	this->id_ic = id_cc;
}
void CuentaContrato::setId_ic(int id_ic)
{
	this->id_ic = id_ic;
}
void CuentaContrato::setId_tarifa(int id_ta)
{
	this->id_tarifa = id_ta;
}
void CuentaContrato::setFormaDePago(string formaDePago)
{
	strcpy(this->formaDePago, formaDePago.c_str());
}
void CuentaContrato::setCategoriaDeCliente(bool categoriaDeCliente)
{
	this->categoriaDeCliente = categoriaDeCliente;
}
void CuentaContrato::setTipoDeInteres(bool tipoDeInteres)
{
	this->tipoDeInteres = tipoDeInteres;
}
void CuentaContrato::setFechaIngresoId(Fecha fechaIn)
{
	this->fechaIngresoID = fechaIn;
}
void CuentaContrato::setDireccionId(Direccion direccionId)
{
	this->direccionID = direccionID;
}
void CuentaContrato::setNumPosicionArchivo(int numPosArch)
{
	this->numPosicionArch = numPosArch;
}
void CuentaContrato::setNombreArchivo(string nomArch)
{
	strcpy(this->nombreArchivo, nomArch.c_str());
}
void CuentaContrato::setActivo(bool activo)
{
	this->activo = activo;
}
int CuentaContrato::getId_cc()
{
	return this->id_cc;
}
int CuentaContrato::getId_ic()
{
	return this->id_ic;
}
int CuentaContrato::getId_Tarifa()
{
	return this->id_tarifa;
}
string CuentaContrato::getFormaDePago()
{
	return this->formaDePago;
}
bool CuentaContrato::getCategoriaDeCliente()
{
	return this->categoriaDeCliente;
}
bool CuentaContrato::getTipoDeInteres()
{
	return this->tipoDeInteres;
}

Fecha CuentaContrato::getFechaIngresoId()
{
	return this->fechaIngresoID;
}
Direccion CuentaContrato::getDireccionId()
{
	return this->direccionID;
}
int CuentaContrato::getNumPosicionArhivo()
{
	return this->numPosicionArch;
}
string CuentaContrato::getNombreArchivo()
{
	return this->nombreArchivo;
}
bool CuentaContrato::getActivo()
{
	return this->activo;
}

/// <summary>
/// Método que devuelve una cadena con todos los datos de la Cuenta Contrato
/// </summary>
/// <returns>Cadena</returns>
string CuentaContrato::toStringCuentaContrato()
{
	return "ID Cuenta Contrato: " + to_string(this->getId_cc()) + ", ID Interlocutor Comercial: " + to_string(this->getId_ic()) + ", Forma de pago: " + this->getFormaDePago() + ", Categoria de cliente: " + to_string(this->getCategoriaDeCliente()) +
		", Tipo de interes: " + to_string(this->getTipoDeInteres())+ ", Fecha Alta:" + this->getFechaIngresoId().toStringFecha() + ", Direccion: " + this->getDireccionId().toStringDireccion();
}