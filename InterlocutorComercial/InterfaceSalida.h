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
	bool GrabarTextosSalida(vector<string> textos, string nombreArchivo);
private:
	
	vector<string> textosSalida;

};