#pragma once
#include "TarifaAD.h"
class TarifaRN
{
private:
	TarifaAD tarifaAD;
	string nombreArchivo;
public:
	TarifaRN(string nombreArchivo);
	TarifaRN();
	~TarifaRN();
	Tarifa BuscarTarifa(int codigoDeTarifa);

	bool AltaTarifa(Tarifa& tarifa);
	int CantidadTarifaEnSistema();
    bool ModificarTarifa(Tarifa& tarifa);
    bool ExisteTarifa(int id_tarifa);


	string getNombreArchivo();
	vector<Tarifa> VectorTarifa();
	void setNombreArchivo(string nombreArchivo);
};
