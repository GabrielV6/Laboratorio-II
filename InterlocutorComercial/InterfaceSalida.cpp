#include "InterfaceSalida.h"

/// <summary>
/// M�todo que guarda el interlocutor en el archivo de datos y devuelve verdadero cuando resulta correto la grabaci�n.
/// </summary>
/// <returns>Booleano</returns>
bool InterfaceSalida::GrabarTextosSalida(vector<string> textos, string nombreArchivo)
{
	ofstream archivo;
	archivo.open(nombreArchivo, ios::app | ios::out);

	if (archivo.fail())
		return false;

	for (auto texto : textos)
		archivo << texto + "\n";

	archivo.close();
	return true;
}