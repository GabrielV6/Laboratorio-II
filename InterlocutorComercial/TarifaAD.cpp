#include <fstream>
#include "TarifaAD.h"
#include "Validaciones.h"

TarifaAD::TarifaAD(string nombreArchivo)
{
}

TarifaAD::~TarifaAD()
{
	this->_tarifas.clear();
}

void TarifaAD::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}

string TarifaAD::getNombreArchivo()
{
	return this->nombreArchivo;
}

int TarifaAD::TotalTarifasEnArchivo()
{
	ifstream archivo;
	archivo.open(NOMBRE_ARCH_TAR, ios::in);
	if (archivo.fail())
		return -1;
	int cantidad = 0;
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	cantidad = pos / sizeof(Tarifa);
	return cantidad;
}

bool TarifaAD::GuardarEnArchivoTarifa(Tarifa& tarifa)
{
	ofstream archivo;
	archivo.open(NOMBRE_ARCH_TAR, ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	//Busca cuantos medidores hay en el archivo y le asigna esa cantidad a la posicion relativa del medidor en el archivo.	
	long posArchivo = TotalTarifasEnArchivo();
	tarifa.setNumPosicionArchivo(posArchivo);
	// se convierte la direccion de memoria a un puntero de char
	archivo.write((char*)&tarifa, sizeof(Tarifa));
	archivo.close();
	return true;
}

bool TarifaAD::ActualizarEnArchivoTarifa(Tarifa& tarifa)
{
	fstream archivo;
	archivo.open(NOMBRE_ARCH_TAR, ios::binary | ios::in | ios::out);
	archivo.seekg(0); //se ubica en el inicio del archivo
	if (archivo.fail())
		return false;

	archivo.seekp(tarifa.getNumPosicionArhivo() * sizeof(Tarifa), ios::cur);

	archivo.write((char*)&tarifa, sizeof(Tarifa));
	archivo.close();
	return true;
}

Tarifa TarifaAD::getTarifaArchivo(int id)
{
	Tarifa intComAD;
	//ifstream archivo;
	FILE* archivo;
	//archivo.open(this->getNombreArchivo(), ios::in);
	archivo = fopen("tarifas.dat", "rb");
	//if (archivo.fail())
	if (archivo == NULL)
		return intComAD;

	//while (archivo.read((char*)&intComAD, sizeof(Medidor)))
	while (fread((char*)&intComAD, sizeof(Tarifa), 1, archivo))
	{
		//if (!archivo.eof())
		if (!(archivo == NULL))
			if (intComAD.getIdTarifa() == id)
			{
				//archivo.close();
				fclose(archivo);
				return intComAD;
			}
	}
	//archivo.close();
	fclose(archivo);
	intComAD = Tarifa();
	return intComAD;
}

vector<Tarifa> TarifaAD::getTarifasArchivo()
{
	Tarifa intComAD;
	vector<Tarifa> tarifas;
	//ifstream archivo;
	FILE* archivo;
	//archivo.open(this->getNombreArchivo(), ios::in);
	archivo = fopen("tarifas.dat", "rb");
	//if (archivo.fail())
	if (archivo == NULL)
		return tarifas;
	//while (archivo.read((char*)&intComAD, sizeof(Medidor)))
	while (fread((char*)&intComAD, sizeof(Tarifa), 1, archivo))
	{
		//if (!archivo.eof())
		if (!(archivo == NULL))
		{
			tarifas.push_back(intComAD);
		}
	}
	//archivo.close();
	fclose(archivo);
	return tarifas;
}