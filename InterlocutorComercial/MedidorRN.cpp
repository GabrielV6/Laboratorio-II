#include "MedidorRN.h"
const int Rango_Numerico = 10001;

MedidorRN::MedidorRN(string nombreArchivo)
{
	this->medidorAD = MedidorAD(nombreArchivo);
	this-> nombreArchivo= nombreArchivo;
}

MedidorRN::MedidorRN()
{

}

MedidorRN::~MedidorRN()
{

}


Medidor MedidorRN::BuscarCMedidor(int idMedidor)
{
	Medidor intComAD = this->medidorAD.getMedidorArchivo(idMedidor);
	if (intComAD.getId() == idMedidor)
		return intComAD;
	return Medidor();
}



bool MedidorRN::ModificaMedidor(Medidor& medidor)
{
	return this->medidorAD.ActualizarEnArchivoMedidor(medidor);
}


bool MedidorRN::AltaMedidor(Medidor& medidor)
{	

	if (medidor.getId() != 0) {
		int id = this->medidorAD.TotalMedidoresEnArchivo();
		if (id == -1) {
			id = 0;
		}
		id += Rango_Numerico;

		medidor.setId(id);
		return this->medidorAD.GuardarEnArchivoMedidor(medidor);
	}
	
	return false;
}

int MedidorRN::IdMedidor(Medidor& medidor)
{
	int id = this->medidorAD.TotalMedidoresEnArchivo();
	if (id == -1) {
		id = 0;
	}
	id += Rango_Numerico;

	medidor.setId(id);
	return medidor.getId();
}

int MedidorRN::CantidadMedidores()
{
	return this->medidorAD.TotalMedidoresEnArchivo();
}

string MedidorRN::getNombreArchivo()
{
	return this->nombreArchivo;
}

vector<Medidor> MedidorRN::getMedidores()
{
	return this->medidorAD.getMedidoresArchivo();
}

void MedidorRN::setNombreArchivo(string nombre)
{
	this->nombreArchivo = nombre;
}


