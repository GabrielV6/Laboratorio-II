#include "TarifaRN.h"

const int RANGO_NUMERICO = 1;

TarifaRN::TarifaRN(string nombreArchivo)
{
	this->tarifaAD = TarifaADBis(nombreArchivo);
}

TarifaRN::~TarifaRN()
{}

bool TarifaRN::AltaTarifa(Tarifa& tarifa)
{
	
	if (tarifa.getIdTarifa() != 0) {
		int id = this->tarifaAD.TotalTarifaEnArchivo();
		if (id == -1) {
			id = 0;
		}
		id += RANGO_NUMERICO;
		
		tarifa.setIdTarifa(id);
		return this->tarifaAD.GuardarEnArchivoTarifa(tarifa);
	}

	return false;	
}
int TarifaRN::IdTarifa(Tarifa& tarifa)
{	

	int id = this->tarifaAD.TotalTarifaEnArchivo();
	if (id == -1) {
		id = 0;
	}
	id += RANGO_NUMERICO;

	tarifa.setIdTarifa(id);
	return tarifa.getIdTarifa();
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
vector<Tarifa> TarifaRN::VectorTarifas()
{
	return this->tarifaAD.getTarifasArchivo();
}
void TarifaRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
