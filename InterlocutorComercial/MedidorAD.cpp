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

int MedidorAD::TotalMedidoresEnArchivo()
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

//Se reemplazara ifstream por FILE * ya que no se lee la totalidad del archivo

Medidor MedidorAD::getMedidorArchivo(int id)
{
	Medidor intComAD;
	//ifstream archivo;
	FILE* archivo;
	//archivo.open(this->getNombreArchivo(), ios::in);
	archivo = fopen("medidores.dat", "rb");
	//if (archivo.fail())
	if (archivo == NULL)
		return intComAD;

	//while (archivo.read((char*)&intComAD, sizeof(Medidor)))
	while (fread((char*)&intComAD, sizeof(Medidor), 1, archivo))
	{
		//if (!archivo.eof())
		if (!archivo == NULL)
			if (intComAD.getId() == id)
			{
				//archivo.close();
				fclose(archivo);
				return intComAD;
			}
	}
	//archivo.close();
	fclose(archivo);
	intComAD = Medidor();
	return intComAD;
}

//Se reemplazara ifstream por FILE * ya que no se lee la totalidad del archivo

vector<Medidor> MedidorAD::getMedidoresArchivo()
{	
	Medidor intComAD;
	vector<Medidor> medidores;
	//ifstream archivo;
	FILE* archivo;
	//archivo.open(this->getNombreArchivo(), ios::in);
	archivo = fopen("medidores.dat", "rb");
	//if (archivo.fail())
	  if(archivo==NULL)
		return medidores;
	//while (archivo.read((char*)&intComAD, sizeof(Medidor)))
	  while (fread((char*)&intComAD, sizeof(Medidor), 1, archivo))
	{
		//if (!archivo.eof())
		  if(!archivo == NULL)
		{
			medidores.push_back(intComAD);
		}
	}
	//archivo.close();
	fclose(archivo);
	return medidores;
}


