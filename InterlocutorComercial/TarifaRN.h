#pragma once
#include "TarifaADBis.h"

class TarifaRN
{
private:
	TarifaADBis tarifaAD;
	string nombreArchivo;
public:
	TarifaRN(string nombreArchivo="");	
	~TarifaRN();
	Tarifa BuscarTarifa(int codigoDeTarifa);
	bool AltaTarifa(Tarifa& tarifa);
	int IdTarifa(Tarifa& tarifa);
	int CantidadTarifaEnSistema();
    bool ModificarTarifa(Tarifa& tarifa);
    bool ExisteTarifa(int id_tarifa);
	string getNombreArchivo();
	vector<Tarifa> VectorTarifas();
	void setNombreArchivo(string nombreArchivo);
};
