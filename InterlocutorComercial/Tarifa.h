#pragma once
#include <iostream>
#include <string>
using namespace std;

class Tarifa
{
private:	
	float cargoFijo;
	float cargoVariable;
	float impuestos;
	int codigoDeTarifa;
	bool tipoDeTarifa; // Domestico o Industrial
public:
	Tarifa();
	void setCargoFijo(float cargoFijo);
	void setCargoVariable(float cargoVariable);
	void setImpuestos(float impuestos);
	void setCodigoDeTarifa( int codigoDeTarifa);
	void setTipoDeTarifa (bool tipoDeTarifa);

	float getCargoFijo();
	float getCargovariable();
	float getImpuestos();
	int getCodigoDeTarifa();
	bool getTipoDeTarifa();
	
	void cargarTarifa();
	string toStringTarifa();
	~Tarifa();
};