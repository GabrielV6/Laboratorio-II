#include "TarifaRN.h"

TarifaRN::TarifaRN(string nombreArchivo)
{
	this->tarifaAD = TarifaAD(nombreArchivo);
}
TarifaRN::TarifaRN(){}
TarifaRN::~TarifaRN()
{}
bool TarifaRN::AltaTarifa(Tarifa& tarifa)
{
	//Asignar ID
	int id = (this->tarifaAD.TotalTarifaEnArchivo() + 1);
	tarifa.setIdTarifa(id);
	return this->tarifaAD.GuardarEnArchivoTarifa(tarifa);
}
bool TarifaRN::ModificarTarifa(Tarifa& tarifa)
{
	return this->tarifaAD.ActualizarEnArchivoTarifa(tarifa);
}
bool TarifaRN::ExisteTarifa(int id_tarifa)
{
	Tarifa tarifa= this->BuscarTarifa(id_tarifa);
	if (tarifa.getIdTarifa() == id_tarifa )
		return true;
	else
        return false;
}
Tarifa TarifaRN::BuscarTarifa(int id_tarifa)
{
	Tarifa tarifa = this->tarifaAD.getTarifaArchivo(id_tarifa);
	if (tarifa.getIdTarifa() == id_tarifa)
		return tarifa;
	return Tarifa();
}

int TarifaRN::CantidadTarifaEnSistema()
{
	return this->tarifaAD.TotalTarifaEnArchivo();
}
string TarifaRN::getNombreArchivo()
{
	return this->nombreArchivo;
}
vector<Tarifa> TarifaRN::VectorTarifa()
{
	return this->tarifaAD.getTarifaArchivo();
}
void TarifaRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
