#pragma once
#include <vector>
#include "InterlocutorComercial.h"
class InterlocutorComercialAD
{
public:

	InterlocutorComercialAD(string nombreArchivo = "");
	~InterlocutorComercialAD();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	/// <summary>
	/// Método que devuelve la cantidad de interlocutores comerciales que hay en el archivo de datos.
	/// </summary>
	/// <returns>entero largo</returns>
	int TotalInterlocutoresEnArchivo();
	/// <summary>
	/// Método que guarda el interlocutor en el archivo de datos y devuelve verdadero cuando resulta correto la grabación.
	/// </summary>
	/// <returns>Booleano</returns>
	bool GuardarEnArchivoInterlocutor(InterlocutorComercial& interlocuror);
	/// <summary>
	/// Este método permite modificar en el archivo el interlocutor enviado por parametro
	/// </summary>
	/// <param name="interlocutor"></param>
	/// <returns></returns>
	bool ActualizarEnArchivoIneterlocurtor(InterlocutorComercial& interlocutor);
	/// <summary>
	/// Método que devuleve un objeto tipo interlocutor comercial que este dentro del archivo de datos
	/// </summary>
	/// <param name="posicion"></param>
	/// <returns>InterlocutorComercial</returns> 
	InterlocutorComercial getInterlocutorArchivo(int dni);
	InterlocutorComercial getInterlocutorArchivoId(int id);
	/// <summary>
	/// Función que devuleve todos los interlocutores del archivo en un vector
	/// </summary>
	vector<InterlocutorComercial> getInterlocutoresArchivo();
private:
	string nombreArchivo;
	InterlocutorComercial interlocutorComercial;
};