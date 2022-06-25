#include "TarifaRN.h"
const int Rango_Numerico = 1;

TarifaRN::TarifaRN(string nombreArchivo)
{
	this->tarifaAD = TarifaAD(nombreArchivo);
	this->nombreArchivo = nombreArchivo;
}

TarifaRN::~TarifaRN()
{
}

Tarifa TarifaRN::BuscarTarifa(int codigoDeTarifa)
{
	Tarifa intComAD = this->tarifaAD.getTarifaArchivo(codigoDeTarifa);
	if (intComAD.getIdTarifa() == codigoDeTarifa)
		return intComAD;
	return Tarifa();
}

bool TarifaRN::ModificarTarifa(Tarifa& tarifa)
{
	return this->tarifaAD.ActualizarEnArchivoTarifa(tarifa);
}

bool TarifaRN::AltaTarifa(Tarifa& tarifa)
{
	if (tarifa.getIdTarifa() != 0) {
		int id = this->tarifaAD.TotalTarifasEnArchivo();
		if (id == -1) {
			id = 0;
		}
		id += Rango_Numerico;

		tarifa.setIdTarifa(id);
		return this->tarifaAD.GuardarEnArchivoTarifa(tarifa);
	}

	return false;
}

int TarifaRN::IdTarifa(Tarifa& tarifa)
{
	int id = this->tarifaAD.TotalTarifasEnArchivo();
	if (id == -1) {
		id = 0;
	}
	id += Rango_Numerico;

	tarifa.setIdTarifa(id);
	return tarifa.getIdTarifa();
}

int TarifaRN::CantidadTarifaEnSistema()
{
	return this->tarifaAD.TotalTarifasEnArchivo();
}

string TarifaRN::getNombreArchivo()
{
	return this->nombreArchivo;
}

vector<Tarifa> TarifaRN::getTarifas()
{
	return this->tarifaAD.getTarifasArchivo();
}

void TarifaRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}