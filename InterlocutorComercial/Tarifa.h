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
	bool _tipoDeTarifa; // Domestico (true) o Industrial (false)
	int _numPosicionArch;
	bool _estado;
public:

	Tarifa(int id = 0, float cargoFijo = 0, float cargoVar = 0, float impuesto = 0, bool tipoTarifa = true, int numPosicion = 0, bool estado = false);
	~Tarifa();
	void setIdTarifa(int idTarifa);
	void setCargoFijo(float cargoFijo);
	void setCargoVariable(float cargoVariable);
	void setImpuestos(float impuestos);
	void setTipoDeTarifa(bool tipoDeTarifa);
	void setNumPosicionArchivo(int numPosArch);
	void setEstado(bool estado);

	int getIdTarifa();
	float getCargoFijo();
	float getCargoVariable();
	float getImpuestos();
	bool getTipoDeTarifa();
	int getNumPosicionArhivo();
	bool getEstado();

	string toStringTarifa();
};