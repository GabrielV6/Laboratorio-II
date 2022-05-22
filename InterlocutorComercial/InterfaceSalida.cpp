#include "InterfaceSalida.h"

InterfaceSalida::InterfaceSalida()
{}
InterfaceSalida::~InterfaceSalida()
{}
void InterfaceSalida::setTextoSalida(string texto)
{
	this->textoSalida = texto;
}
string InterfaceSalida::getTextoSalida()
{
	return this->textoSalida;
}
void InterfaceSalida::setTextosSalida(vector<string> textos) 
{
	this->textosSalida = textos;
}
vector<string> InterfaceSalida::getTestoSalida()
{
	return this->textosSalida;
}


/// <summary>
/// Método que graba el texto que estan en el vecotr dentro de archivo indicado en el parametro nombreArchivo.
/// </summary>
/// <returns>Booleano</returns>
bool InterfaceSalida::GrabarTextosSalida(vector<string> textos, string nombreArchivo)
{
	ofstream archivo;
	archivo.open(nombreArchivo, ios::app | ios::out);

	if (archivo.fail())
		return false;

	for (auto& texto : textos)
		archivo << texto + "\n";

	archivo.close();
	return true;
}

void InterfaceSalida::MostrarTextosSalida(vector<string> textos, string tituloTexo)
{	
	cout << "--------------------------------------------------------------------------" << endl;
	cout << tituloTexo << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	for (auto& texto : textos)
		cout << texto << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}