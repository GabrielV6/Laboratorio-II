#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class InterfaceSalida
{
public:
	InterfaceSalida();
	~InterfaceSalida();
	void setTextoSalida(string texto);
	string getTextoSalida();
	void setTextosSalida(vector<string> textos);
	vector<string> getTestosSalida();
	bool GrabarTextosSalida(vector<string> textos, string nombreArchivo);
	void MostrarTextosSalida(vector<string> textos, string tituloTexo);
	bool LeeTextosEntrada(string nombreArchivo);
	bool LeeTextosEntradaInterlocutor(string nombreArchivo);
	void MenuPrincipal();
	void ConsumoTrimestralPorAnio(int anio);
	void PromedioRecaudacion();
	void MenuConsultas();
	void MenuExportacion();
	int ExportarIC();
	void ClienteDatosComerciales(int dni);
	float FacturasPorcentaje(int anio, bool pago);

private:
	string textoSalida;
	vector<string> textosSalida;
	string separador = "-------------------------------------------------------------------------------------------------------------";
};