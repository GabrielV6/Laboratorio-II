#pragma once

#include "Tarifa.h"
#include "TarifaAD.h"

class TarifaRN {
private:
	TarifaAD tarifaAD;
	string nombreArchivo;

public:

	TarifaRN(string nombreArchivo = "");
	~TarifaRN();

	Tarifa BuscarTarifa(int codigoDeTarifa);
	bool ModificarTarifa(Tarifa& tarifa);
	bool AltaTarifa(Tarifa& tarifa);
	int IdTarifa(Tarifa& tarifa);
	int CantidadTarifaEnSistema();

	string getNombreArchivo();
	vector<Tarifa> getTarifas();
	void setNombreArchivo(string nombreArchivo);
};