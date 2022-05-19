#pragma once
#include "TarifaAD.h"
class TarifaRN
{
private:
	TarifaAD tarifaAD;
	string nombreArchivo;
public:
	TarifaRN(string nombreArchivo = "");
	~TarifaRN();
	Tarifa BuscarTarifa(int codigoDeTarifa);
	bool ControlModificaciones(Tarifa& tarifa);
	bool AltaCuentaTarifa(Tarifa& tarifa);
	long CantidadTarifaEnSistema();
	string getNombreArchivo();
	vector<Tarifa> VectorTarifa();
	void setNombreArchivo(string nombreArchivo);
};