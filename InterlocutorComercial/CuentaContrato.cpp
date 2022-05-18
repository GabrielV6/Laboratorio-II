#include "CuentaContrato.h"

CuentaContrato::CuentaContrato()
{
	this->id_cc = 0;
	this->id_ic = 0;
	strcpy_s(this->formaDePago, "");
	this->categoriaDeCliente = false;
    this->tipoDeInteres = false;
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = true;
	this->numPosicionArch = -1;
	strcpy_s(this->nombreArchivo, "");
}
CuentaContrato::CuentaContrato(string nombreArchivo)
{
	strcpy_s(this->nombreArchivo, nombreArchivo.c_str());
	this->id_cc = 0;
	this->id_ic = 0;
	strcpy_s(this->formaDePago, "");
	this->categoriaDeCliente = false;
    this->tipoDeInteres = false;
	this->fechaIngresoID = Fecha();
	this->direccionID = Direccion();
	this->activo = true;
	this->numPosicionArch = -1;
}
CuentaContrato::~CuentaContrato()
{}
void CuentaContrato::setId_cc(long id_cc)
{
	this->id_ic = id_cc;
}
void CuentaContrato::setId_ic(long id_ic)
{
	this->id_ic = id_ic;
}
void CuentaContrato::setFormaDePago(string formaDePago)
{
	strcpy_s(this->formaDePago, formaDePago.c_str());
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
void CuentaContrato::setNumPosicionArchivo(long numPosArch)
{
	this->numPosicionArch = numPosArch;
}
void CuentaContrato::setNombreArchivo(string nomArch)
{
	strcpy_s(this->nombreArchivo, nomArch.c_str());
}
void CuentaContrato::setActivo(bool activo)
{
	this->activo = activo;
}
long CuentaContrato::getId_cc()
{
	return this->id_cc;
}
long CuentaContrato::getId_ic()
{
	return this->id_ic;
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
long CuentaContrato::getNumPosicionArhivo()
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