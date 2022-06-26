#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Direccion
{
private:
	char calle[30];
	unsigned int numero;
	char descripcion[50];
	char codPostal[20];
	char loclidad[30];
	char provincia[30];
public:
	Direccion();
	~Direccion();
	void setCalle(string calle);
	void setNumero(unsigned int numero);
	void setCodPostal(string codPostal);
	void setLocalidad(string localidad);
	void setProvincia(string provincia);
	string getCalle();
	unsigned int getNumero();
	string getDescripcion();
	string getCodPostal();
	string getLocalidad();
	string getProvincia();
	void CargarDireccion();
	string toStringDireccion();
};