#include "TarifaADBis.h"

TarifaADBis::TarifaADBis(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
TarifaADBis::~TarifaADBis()
{
}
void TarifaADBis::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string TarifaADBis::getNombreArchivo()
{
	return this->nombreArchivo;
}
/// <summary>
/// M�todo que devuelve la cantidad de Tarifas que hay en el archivo de datos.
/// </summary>
/// <returns>entero</returns>
int TarifaADBis::TotalTarifaEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	int cantidad = 0;
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	cantidad = pos / sizeof(Tarifa);
	return cantidad;

}
/// <summary>
/// M�todo que guarda la Tarifa en el archivo de datos y devuelve verdadero cuando resulta correta la grabaci�n.
/// </summary>
/// <returns>Booleano</returns>
bool TarifaADBis::GuardarEnArchivoTarifa(Tarifa& tarifa)
{
	
	ofstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	
	long posArchivo = TotalTarifaEnArchivo();
	tarifa.setNumPosicionArchivo(posArchivo);
	archivo.write((char*)&tarifa, sizeof(Tarifa));
	archivo.close();
	return true;
}
/// <summary>
/// Este m�todo permite modificar en el archivo la Tarifa enviada por parametro
/// </summary>
/// <param name="Tarifa"></param>
/// <returns></returns>
bool TarifaADBis::ActualizarEnArchivoTarifa(Tarifa& tarifa)
{
	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0); //se ubica en el inicio del archivo
	if (archivo.fail())
		return false;
	archivo.seekp(tarifa.getNumPosicionArhivo() * sizeof(Tarifa), ios::cur);
	archivo.write((char*)&tarifa, sizeof(Tarifa));
	archivo.close();
	return true;
}
/// <summary>
/// M�todo que devuleve un objeto tipo Tarifa  que este dentro del archivo de datos
/// </summary>
/// <param name="posicion"></param>
/// <returns>Tarifa</returns>
Tarifa TarifaADBis::getTarifaArchivo(int id_tarifa)
{
	Tarifa tarifa;
	FILE* archivo;
	archivo = fopen(this->getNombreArchivo().c_str(), "rb");
	if (archivo == NULL)
		return tarifa;
	while (fread((char*)&tarifa, sizeof(Tarifa), 1, archivo))
	{
		if (!archivo == NULL && tarifa.getIdTarifa() == id_tarifa)
		{ 
			fclose(archivo);
			return tarifa;
		}
	}
	fclose(archivo);
	return tarifa;
}

/// <summary>
/// Funci�n que devuleve todas las Tarifa  del archivo en un vector
/// </summary>
vector<Tarifa> TarifaADBis::getTarifasArchivo()
{
	Tarifa intComAD;
	vector<Tarifa> tarifas;
	FILE* archivo;
	archivo = fopen(this->getNombreArchivo().c_str(), "rb");
	if (archivo == NULL)
		return tarifas;
	while (fread((char*)&intComAD, sizeof(Tarifa), 1, archivo))
	{
		if (!archivo == NULL)
		{
			tarifas.push_back(intComAD);
		}
	}
	fclose(archivo);
	return tarifas;
}
