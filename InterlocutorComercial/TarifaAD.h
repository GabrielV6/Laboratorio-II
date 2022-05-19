#pragma once
#include <vector>
#include "Tarifa.h"
class TarifaAD
{
public:

	TarifaAD(string nombreArchivo = "");
	~TarifaAD();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	/// <summary>
	/// M�todo que devuelve la cantidad de registro de Tarifas que hay en el archivo de datos.
	/// </summary>
	/// <returns>entero largo</returns>
	long TotalTarifaEnArchivo();
	/// <summary>
	/// M�todo que guarda la tarifa en el archivo de datos y devuelve verdadero cuando resulta correto la grabaci�n.
	/// </summary>
	/// <returns>Booleano</returns>
	bool GuardarEnArchivoTarifa(Tarifa& tarifa);
	/// <summary>
	/// Este m�todo permite modificar en el archivo la tarifa enviado por parametro
	/// </summary>
	/// <param name="tarifa"></param>
	/// <returns></returns>
	bool ActualizarEnArchivoTarifa(Tarifa& tarifa);
	/// <summary>
	/// M�todo que devuleve un objeto tipo Tarifa que este dentro del archivo de datos
	/// </summary>
	/// <param name="posicion"></param>
	/// <returns>Tarifa</returns>
	Tarifa getInterlocutorTarifa(int codigoDeTarifa);
	/// <summary>
	/// Funci�n que devuleve todas tarifas del archivo en un vector ordenado por codigo de tarifa
	/// </summary>
	vector<Tarifa> getTarifasArchivo();
private:
	string nombreArchivo;
	Tarifa tarifa;
};