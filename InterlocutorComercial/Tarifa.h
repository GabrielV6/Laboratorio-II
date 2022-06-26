#pragma once

#include <iostream>
#include <string>
using namespace std;

class Tarifa
{
private:
	int _idTarifa;
	float _cargoFijo;
	float _cargoVariable;
	float _impuestos;
	int _tipoDeTarifa; // Domestico (0) o Industrial (1)
	int _numPosicionArch;
	bool _estado;
public:

	Tarifa(int id = 0, float cargoFijo = 0, float cargoVar = 0, float impuesto = 0, int tipoTarifa = 0, int numPosicion = 0, bool estado = true);
	~Tarifa();
	void setIdTarifa(int idTarifa);
	void setCargoFijo(float cargoFijo);
	void setCargoVariable(float cargoVariable);
	void setImpuestos(float impuestos);
	void setTipoDeTarifa(int tipoDeTarifa);
	void setNumPosicionArchivo(int numPosArch);
	void setEstado(bool estado);

	int getIdTarifa();
	float getCargoFijo();
	float getCargoVariable();
	float getImpuestos();
	int getTipoDeTarifa();
	int getNumPosicionArhivo();
	bool getEstado();

	string toStringTarifa();
};