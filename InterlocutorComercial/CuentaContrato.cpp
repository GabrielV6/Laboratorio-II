#include "CuentaContrato.h"

CuentaContrato::CuentaContrato()
{
	this->id_cc = 0;
	this->id_ic = 0;
	this->id_tarifa = 0;
	this->numPosicionArch = 0;
	this->activo = false;
}
CuentaContrato::~CuentaContrato()
{

}
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
void CuentaContrato::setNumPosicionArchivo(int numPosArch)
{
	this->numPosicionArch = numPosArch;
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

int CuentaContrato::getNumPosicionArhivo()
{
	return this->numPosicionArch;
}
bool CuentaContrato::getActivo()
{

	return this->activo;
}


string CuentaContrato::toStringCuentaContrato()
{
	string cadena = "ID Cuenta Contrato: " + to_string(this->getId_cc()) + ", ID Interlocutor Comercial: " + to_string(this->getId_ic())
		+ ", ID Tarifa: " + to_string(this->getId_Tarifa());

	return cadena;
}