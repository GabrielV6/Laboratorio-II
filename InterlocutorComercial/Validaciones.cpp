#include "Validaciones.h"

int Validaciones::DatoObligarorioNum(string nombreDato)
{
	string dato = "";
	do
	{
		cout << "Ingrese " + nombreDato + " : ";
		cin >> dato;
		if (dato == "")
			cout << "Dato obligatorio " + nombreDato + " no puede quedar en blanco\nPor favor, ingrese nuevamente" << endl;
		else
			break;
	} while (true);
	return stoi(dato);
}

string Validaciones::DatoObligarorioCad(string nombreDato)
{
	string dato = "";
	do
	{
		cout << "Ingrese " + nombreDato + " : ";
		cin >> dato;
		if (dato == "")
			cout << "Dato obligatorio " + nombreDato + " no puede quedar en blanco\nPor favor, ingrese nuevamente" << endl;
		else
			break;
	} while (true);
	return dato;
}