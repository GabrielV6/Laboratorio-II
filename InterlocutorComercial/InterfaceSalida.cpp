#include "InterfaceSalida.h"
#include "CuentaContratoAD.h"
#include "MedidorAD.h"

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

bool InterfaceSalida::LeeTextosEntrada(string nombreArchivo)
{

	ifstream archivo;
	archivo.open(nombreArchivo, ios::in);

	if (archivo.fail())
		return false;
	string str = "";
	char pattern = ';';
	int posInit = 0;
	vector<string> results;
	while (getline(archivo, str))
	{
		Medidor medArch;
		string splitted;
		int indice = 0;
		int posFound = 0;
		while (posFound >= 0)
		{
			posFound = str.find(pattern, posInit);
			splitted = str.substr(posInit, posFound - posInit);
			switch (indice)
			{
			case 0:
				medArch.setId(stoi(splitted));
				break;
			case 1:
				medArch.setIdCuentaContrato(stoi(splitted));
				break;
			case 2:
				medArch.setEstado(splitted == "true" ? true : false);
				break;
			case 3:
				medArch.setLectura(stoi(splitted));
				break;
			case 4:
				medArch.setNumPosicionArchivo(stoi(splitted));
				break;
			default:
				break;
			}
			indice++;
			posInit = posFound + 1;	
		}
		MedidorAD medAD("medidores.dat");
		medAD.GuardarEnArchivoMedidor(medArch);
	}

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