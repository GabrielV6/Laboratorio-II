#include "Documento.h"


Documento::Documento()
{
	
	this->numero = 0;
	this->fecha = Fecha();
	this->idInter = 0;
	this->idCC = 0;  //id cuenta contrato
	this->idMed = 0;//id medidor
	this->idTar = 0;
	this->pago = false;
	this->importe = 0;
}

	
	void Documento::setNumero(int numero)
	{
		this->numero = numero;
	}
	void Documento::setFecha(Fecha fecha)
	{
		this->fecha = fecha;
	}

		void Documento::setIdinter(int id)
	{
			this->idInter = id;
			
	}
	void Documento::setIdcc(int id)
	{
		this->idCC = id;
	}
	void Documento::setIdmed(int id)
	{
		this->idMed = id;
	}
	void Documento::setIdtar(int id)
	{
		this->idTar= id;
	}
	void Documento::setPosicionarch(int pos)
	{
		this->numPosicionarch = pos;

	}
	void Documento::setPago(bool p)
	{
		this->pago = p;
	}
	void Documento::setImporte(float i)
	{
		this->importe = i;
	}
	void Documento::setConsumo(float c)
	{
		this->consumo = c;
	}
	void Documento::setTipo(char t)
	{
		this->tipo = t;
	}

	int Documento::getNumero()
	{
		return this->numero;
	}
	Fecha Documento::getFecha()
	{
		return this->fecha;
	}
	int Documento::getIdinter()
	{
		return this->idInter;
	}
	int Documento::getIdcc()
	{
		return this->idCC;
	}
	int Documento::getIdmed()
	{
		return this->idMed;
	}
	int Documento::getIdtar() {

		return this->idTar;
	}
	int Documento::getPosicionarch() {

		return this->numPosicionarch;
	}
	bool Documento::getPago()
	{
		return this->pago;
	}
	float Documento::getImporte()
	{
		return this->importe;
	}
	float Documento::getConsumo()
	{
		return this->consumo;
	}
	char Documento::getTipo()
	{
		return this->tipo;
	}
	string Documento::toStringDocumento()
	{
		string cadena= "Numero: " + to_string(this->getNumero())+ 
			", Tipo de consumo: " + this->getTipo()+
			", Fecha creacion: " + this->getFecha().toStringFecha()+
			", ID Inter: " + to_string(this->getIdinter())+ ", ID Medidor: " + to_string(this->idMed)
			+ ", Id Tarifa: " + to_string(this->getIdtar()) + ", Importe: $ "+ to_string(this->getImporte());
		return  cadena;
	}
	Documento::~Documento()
	{
	}



