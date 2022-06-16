#include "MedidorAD.h"

MedidorAD::~MedidorAD() {
    this->_medidores.clear();
}

MedidorAD::MedidorAD(string nombreArchivo) {
    this->_nombreArchivo = nombreArchivo;
}
void MedidorAD::setNombreArchivo(string nombreArchivo) {
    this->_nombreArchivo = nombreArchivo;
}
string MedidorAD::getNombreArchivo() {
    return this->_nombreArchivo;
}

long MedidorAD::TotalMedidoresEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	long cantidad = 0;
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	cantidad = pos / sizeof(Medidor);
	return cantidad;
}

bool MedidorAD::GuardarEnArchivoMedidor(Medidor& medidor) {
    
	//Medidor medidorAD = medidor; 
	ofstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	//Busca cuantos medidores hay en el archivo y le asigna esa cantidad a la posicion relativa del medidor en el archivo.	
	long posArchivo = TotalMedidoresEnArchivo();
	medidor.setNumPosicionArchivo(posArchivo);
	// se convierte la direccion de memoria a un puntero de char
	archivo.write((char*)&medidor, sizeof(Medidor)); 
	archivo.close();
	return true;
}

bool MedidorAD::ActualizarEnArchivoMedidor(Medidor& medidor)
{
	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0); //se ubica en el inicio del archivo
	if (archivo.fail())
		return false;

	archivo.seekp(medidor.getNumPosicionArhivo() * sizeof(Medidor), ios::cur);

	//cout << "Posicion: " << to_string(archivo.tellp()) << endl;
	archivo.write((char*)&medidor, sizeof(Medidor));
	archivo.close();
	return true;
}

Medidor MedidorAD::getMedidorArchivo(int id)
{
	Medidor intComAD;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return intComAD;

	while (archivo.read((char*)&intComAD, sizeof(Medidor)))
	{
		if (!archivo.eof())
			if (intComAD.getId() == id)
			{
				archivo.close();
				return intComAD;
			}
	}
	archivo.close();
	intComAD = Medidor();
	return intComAD;
}

vector<Medidor> MedidorAD::getMedidoresArchivo()
{
	Medidor intComAD;
	vector<Medidor> interlocutores;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return interlocutores;
	while (archivo.read((char*)&intComAD, sizeof(Medidor)))
	{
		if (!archivo.eof())
		{
			interlocutores.push_back(intComAD);
		}
	}
	return interlocutores;
}


