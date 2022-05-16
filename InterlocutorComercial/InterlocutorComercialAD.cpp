#include "InterlocutorComercialAD.h"

InterlocutorComercialAD::InterlocutorComercialAD(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
InterlocutorComercialAD::~InterlocutorComercialAD()
{
}
void InterlocutorComercialAD::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string InterlocutorComercialAD::getNombreArchivo()
{
	return this->nombreArchivo;
}
/// <summary>
/// Método que devuelve la cantidad de interlocutores comerciales que hay en el archivo de datos.
/// </summary>
/// <returns>entero largo</returns>
long InterlocutorComercialAD::TotalInterlocutoresEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	InterlocutorComercial intComAD;
	long cantidad = 0;
	while (archivo.read((char*)&intComAD, sizeof(InterlocutorComercial)))
	{
		if (!archivo.eof())
			cantidad++;
	}
	archivo.close();
	return cantidad;
}
/// <summary>
/// Método que guarda el interlocutor en el archivo de datos y devuelve verdadero cuando resulta correto la grabación.
/// </summary>
/// <returns>Booleano</returns>
bool InterlocutorComercialAD::GuardarEnArchivoInterlocutor(InterlocutorComercial& interlocuror)
{
	InterlocutorComercial intComAD = interlocuror;
	ofstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	//Busca cuantos interlocutores hay en el archivo y le asigna esa cantidad a la posicion relativa del interlocutor en el archivo.	
	long posArchivo = TotalInterlocutoresEnArchivo();
	archivo.write((char*)&intComAD, sizeof(InterlocutorComercial));
	archivo.close();
	return true;

}
/// <summary>
/// Este método permite modificar en el archivo el interlocutor enviado por parametro
/// </summary>
/// <param name="interlocutor"></param>
/// <returns></returns>
bool InterlocutorComercialAD::ActualizarEnArchivoIneterlocurtor(InterlocutorComercial& interlocutor)
{

	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0);
	if (archivo.fail())
		return false;
	int pos = 0;
	int cantidad = 0;
	cantidad = TotalInterlocutoresEnArchivo();
	archivo.seekp(interlocutor.getNumPosicionArhivo() * sizeof(InterlocutorComercial), ios::cur);

	//cout << "Posicion: " << to_string(archivo.tellp()) << endl;
	archivo.write((char*)&interlocutor, sizeof(InterlocutorComercial));
	archivo.close();
	return true;
}
/// <summary>
/// Método que devuleve un objeto tipo interlocutor comercial que este dentro del archivo de datos
/// </summary>
/// <param name="posicion"></param>
/// <returns>InterlocutorComercial</returns>
InterlocutorComercial InterlocutorComercialAD::getInterlocutorArchivo(long dni)
{
	InterlocutorComercial intComAD;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return intComAD;

	while (archivo.read((char*)&intComAD, sizeof(InterlocutorComercial)))
	{
		if (!archivo.eof())
			if (intComAD.getDni() == dni)
			{
				archivo.close();
				return intComAD;
			}
	}
	archivo.close();
	intComAD = InterlocutorComercial();
	return intComAD;
}

/// <summary>
/// Función que devuleve todos los interlocutores del archivo en un vector
/// </summary>
vector<InterlocutorComercial> InterlocutorComercialAD::getInterlocutoresArchivo()
{
	InterlocutorComercial intComAD;
	vector<InterlocutorComercial> interlocutores;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return interlocutores;
	while (archivo.read((char*)&intComAD, sizeof(InterlocutorComercial)))
	{
		if (!archivo.eof())
		{
			interlocutores.push_back(intComAD);
		}
	}
	return interlocutores;
}