#pragma once
#include <vector>
#include "Tarifa.h"
class TarifaAD
{
public:

	TarifaAD(string nombreArchivo = "");
	~TarifaAD();
	void setNombreArchivo(string nombreArchivo);

	string getNombreArchivo();

	int TotalTarifaEnArchivo();
	bool GuardarEnArchivoTarifa(Tarifa& tarifa);
	bool ActualizarEnArchivoTarifa(Tarifa& tarifa);
	Tarifa getTarifaArchivo(int codigoDeTarifa);
	vector<Tarifa> getTarifaArchivo();
private:
	string nombreArchivo;
	Tarifa tarifa;
};

