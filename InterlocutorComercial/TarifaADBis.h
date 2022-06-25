#pragma once
#include <vector>
#include <fstream>
#include "Tarifa.h"

class TarifaADBis
{
public:
	TarifaADBis(string nombreArchivo = "");
	~TarifaADBis();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	int TotalTarifaEnArchivo();
	bool GuardarEnArchivoTarifa(Tarifa& tarifa);
	bool ActualizarEnArchivoTarifa(Tarifa& tarifa);
	Tarifa getTarifaArchivo(int codigoDeTarifa);
	vector<Tarifa> getTarifasArchivo();
private:
	string nombreArchivo;
	Tarifa tarifa;
};