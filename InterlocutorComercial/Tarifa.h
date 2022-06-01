#pragma once
#include <iostream>
#include <string>
using namespace std;

class Tarifa
{
private:
    int id_tarifa;
    string nombreDeArchivo;
	float cargoFijo;
	float cargoVariable;
	float impuestos;
	bool tipoDeTarifa; // Domestico (true) o Industrial
	long numPosicionArch;
	bool estado;
public:
	Tarifa();
	Tarifa(string nombreArchivo);
	void setIdTarifa(int idTarifa);
	void setCargoFijo(float cargoFijo);
	void setCargoVariable(float cargoVariable);
	void setImpuestos(float impuestos);
	void setTipoDeTarifa (bool tipoDeTarifa);
	void setNumPosicionArchivo(long numPosArch);
	void setEstado(bool estado);

    int getIdTarifa();
	float getCargoFijo();
	float getCargoVariable();
	float getImpuestos();
	bool getTipoDeTarifa();
	long getNumPosicionArhivo();
    bool getEstado();

	void cargarTarifa();
	string toStringTarifa();
	~Tarifa();
};
