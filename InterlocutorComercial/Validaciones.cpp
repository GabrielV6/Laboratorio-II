#include "Validaciones.h"

int Validaciones::DatoObligarorioNum(string nombreDato)
{
	string dato = "";
	int valorRetorno = 0;
	do
	{
		cout << "Ingrese " + nombreDato + " : ";
		cin >> dato;
		try
		{
			valorRetorno = stoi(dato);
			break;
		}
		catch (const std::exception&)
		{
			cout << "Dato obligatorio " + nombreDato + " incorrecta\nPor favor, ingrese nuevamente" << endl;
		}
		/*if (dato.c_str() == "")
			cout << "Dato obligatorio " + nombreDato + " no puede quedar en blanco\nPor favor, ingrese nuevamente" << endl;
		else
			break;*/
	} while (true);
	return valorRetorno;
}

char Validaciones::DatoObligarorioChar(string nombreDato)
{
	char dato;
	do
	{
		cout << "Ingrese " + nombreDato + " : ";
		cin >> dato;

		if (dato == ' ')
			cout << "Dato obligatorio " + nombreDato + " no puede quedar en blanco\nPor favor, ingrese nuevamente" << endl;
		else
			break;
	} while (true);
	return dato;
}

string Validaciones::DatoObligarorioCad(string nombreDato)
{	
	string dato;
	do
	{
		cout << "Ingrese " + nombreDato + " : ";
		do
		{
			getline(cin, dato);
		} while (dato.length() == 0);

		if (dato == "")
			cout << "Dato obligatorio " + nombreDato + " no puede quedar en blanco\nPor favor, ingrese nuevamente" << endl;
		else
			break;
	} while (true);
	return dato;
}