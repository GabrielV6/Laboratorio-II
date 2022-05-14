#pragma once
#include <iostream>
#include <string>
using namespace std;

class Direccion
{
private:
	char calle[30];
	int numero;
	char casaDpto[50];
	char codPostal[20];
	char loclidad[30];
	char provincia[30];
public:
	Direccion();
	~Direccion();
	void setCalle(string calle);
	void setNumero(int numero);
	void setCasaDpto(string casaDpto);
	void setCodPostal(string codPostal);
	void setLocalidad(string localidad);
	void setProvincia(string provincia);
	string getCalle();
	int getNumero();
	string getCasaDpto();
	string getCodPostal();
	string getLocalidad();
	string getProvincia();
	void CargarDireccion();
	string toStringDireccion();
};