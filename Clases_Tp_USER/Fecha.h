//Crear una clase Fecha que contenga los atributos día, mes y año.
//Crear los métodos setDia, setMes y setAnio para establecer los valores de los atributos.
//Crear los métodos getDia, getMes y getAnio para obtener los valores de los atributos.
//Crear el método toString que devuelva una cadena de texto con el formato dd/mm/aaaa.
//Crear el método destructor.
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fecha
{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int dia = 1, int mes = 1, int anio = 1900);
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	int getDia();
	int getMes();
	int getAnio();
	void cargarFecha();
	string toStringFecha();
	~Fecha();
};