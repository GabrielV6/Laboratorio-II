#include "MedidorRN.h"

MedidorRN::MedidorRN(string nombreArchivo)
{
	this->medidorAD = MedidorAD(nombreArchivo);
}

MedidorRN::~MedidorRN()
{
}

Medidor MedidorRN::BuscarCMedidor(long idMedidor)
{
	Medidor intComAD = this->medidorAD.getMedidorArchivo(idMedidor);
	if (intComAD.getId() == idMedidor)
		return intComAD;
	return Medidor();
}


bool MedidorRN::AltaMedidor(Medidor& medidor)
{
	int id = (this->medidorAD.TotalMedidoresEnArchivo() + 1) * 1000;
	medidor.setId(id);
	return this->medidorAD.GuardarEnArchivoMedidor(medidor);
}

int MedidorRN::CantidadMedidores()
{
	return this->medidorAD.TotalMedidoresEnArchivo();
}

string MedidorRN::getNombreArchivo()
{
	return this->nombreArchivo;
}

vector<Medidor> MedidorRN::getMedidores(bool soloActivos)
{
	return this->medidorAD.getMedidoresArchivo();
}

void MedidorRN::setNombreArchivo(string nombre)
{
	this->nombreArchivo = nombre;
}


