#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class InterfaceSalida
{
public:
	InterfaceSalida();
	~InterfaceSalida();
	void setTextoSalida(string texto);
	string getTextoSalida();
	void setTextosSalida(vector<string> textos);
	vector<string> getTestoSalida();
	bool GrabarTextosSalida(vector<string> textos, string nombreArchivo);
	void MostrarTextosSalida(vector<string> textos, string tituloTexo);
private:
	string textoSalida;
	vector<string> textosSalida;

};