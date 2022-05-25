#include "ContratoAD.h"

ContratoAD::ContratoAD(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}

ContratoAD::~ContratoAD()
{
}
void ContratoAD::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}

string ContratoAD::getNombreArchivo()
{
	return this->nombreArchivo;
}

long ContratoAD::TotalContratosEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	Contrato contatoAD;
	long cantidad = 0;
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	cantidad = pos / sizeof(Contrato);
	archivo.close();
	return cantidad;
}

bool ContratoAD::GuardarEnArchivoContrato(Contrato& contrato)
{
	ofstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	//Busca cuantos interlocutores hay en el archivo y le asigna esa cantidad a la posicion relativa del interlocutor en el archivo.	
	long posArchivo = TotalContratosEnArchivo();
	contrato.setPoscicionArchivo(posArchivo);
	archivo.write((char*)&contrato, sizeof(InterlocutorComercial));
	archivo.close();
	return true;
}

bool ContratoAD::ActualizarEnArchivoContrato(Contrato& contrato)
{
	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0);
	if (archivo.fail())
		return false;
	//Se ubica en la posicion que debe actualizar del archivo
	archivo.seekp(contrato.getPosicionArchivo() * sizeof(InterlocutorComercial), ios::cur);
	archivo.write((char*)&contrato, sizeof(InterlocutorComercial));
	archivo.close();
	return true;
}

Contrato ContratoAD::getContratoArchivo(long idContrato)
{
	Contrato contrato = Contrato();
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return contrato;

	while (archivo.read((char*)&contrato, sizeof(InterlocutorComercial)))
	{
		if (!archivo.eof())
			if (contrato.getIdContrato() == idContrato)
			{
				archivo.close();
				return contrato;
			}
	}
	archivo.close();
	return contrato;
}

vector<Contrato> ContratoAD::getContratosArchivo()
{
	Contrato contrato;
	vector<Contrato> contratos;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return contratos;
	while (archivo.read((char*)&contrato, sizeof(InterlocutorComercial)))
	{
		if (!archivo.eof())
			contratos.push_back(contrato);
	}
	return contratos;
}