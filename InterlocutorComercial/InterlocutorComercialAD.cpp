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
/// M�todo que devuelve la cantidad de interlocutores comerciales que hay en el archivo de datos.
/// </summary>
/// <returns>entero largo</returns>
int InterlocutorComercialAD::TotalInterlocutoresEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	long cantidad = 0;
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	cantidad = pos / sizeof(InterlocutorComercial);
	return cantidad;
}
/// <summary>
/// M�todo que guarda el interlocutor en el archivo de datos y devuelve verdadero cuando resulta correto la grabaci�n.
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
	intComAD.setNumPosicionArchivo(posArchivo);
	archivo.write((char*)&intComAD, sizeof(InterlocutorComercial));
	archivo.close();
	return true;
}
/// <summary>
/// Este m�todo permite modificar en el archivo el interlocutor enviado por parametro
/// </summary>
/// <param name="interlocutor"></param>
/// <returns></returns>
bool InterlocutorComercialAD::ActualizarEnArchivoIneterlocurtor(InterlocutorComercial& interlocutor)
{
	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0); //se ubica en el inicio del archivo
	if (archivo.fail())
		return false;
	
	archivo.seekp(interlocutor.getNumPosicionArhivo() * sizeof(InterlocutorComercial), ios::cur);

	//cout << "Posicion: " << to_string(archivo.tellp()) << endl;
	archivo.write((char*)&interlocutor, sizeof(InterlocutorComercial));
	archivo.close();
	return true;
}
/// <summary>
/// M�todo que devuleve un objeto tipo interlocutor comercial que este dentro del archivo de datos
/// </summary>
/// <param name="posicion"></param>
/// <returns>InterlocutorComercial</returns>
InterlocutorComercial InterlocutorComercialAD::getInterlocutorArchivo(int dni)
{
	InterlocutorComercial intComAD;	

	vector<InterlocutorComercial> interlocutores = this->getInterlocutoresArchivo();
	for (auto &interlocutor : interlocutores)
	{
		if (interlocutor.getDni() == dni)
		{
			intComAD = interlocutor;
			return intComAD;
		}
	}
	
	intComAD = InterlocutorComercial();
	return intComAD;
}
/// <summary>
/// M�todo que devuleve un objeto tipo interlocutor comercial que este dentro del archivo de datos busca por id
/// </summary>
/// <param name="id"></param>
/// <returns>InterlocutorComercial</returns>
InterlocutorComercial InterlocutorComercialAD::getInterlocutorArchivoId(int id)
{
	InterlocutorComercial intComAD;
	vector<InterlocutorComercial> interlocutores = this->getInterlocutoresArchivo();
	for (auto& interlocutor : interlocutores)
	{
		if (interlocutor.getId_ic() == id)
		{
			intComAD = interlocutor;
			return intComAD;
		}
	}
	intComAD = InterlocutorComercial();
	return intComAD;
}

/// <summary>
/// Funci�n que devuleve todos los interlocutores del archivo en un vector
/// </summary>
vector<InterlocutorComercial> InterlocutorComercialAD::getInterlocutoresArchivo()
{
	InterlocutorComercial intComAD;
	vector<InterlocutorComercial> interlocutores;
	FILE* archivo;
	archivo = fopen(this->getNombreArchivo().c_str(), "rb");
	if (archivo == NULL)
		return interlocutores;
	while (fread((char*)&intComAD, sizeof(InterlocutorComercial), 1, archivo))
	{
		if (!(archivo == NULL))
		{
			interlocutores.push_back(intComAD);
		}
	}
	return interlocutores;
}