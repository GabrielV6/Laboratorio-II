#pragma once

#include <vector>
#include "Tarifa.h"

class TarifaAD {
private:
	string nombreArchivo;
	vector<Tarifa> _tarifas;
public:
	TarifaAD(string nombreArchivo = "");
	~TarifaAD();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	int TotalTarifasEnArchivo();
	bool GuardarEnArchivoTarifa(Tarifa& tarifa);
	bool ActualizarEnArchivoTarifa(Tarifa& tarifa);
	Tarifa getTarifaArchivo(int id);
	vector<Tarifa> getTarifasArchivo();

};