#include "Documento.h"
#include <iomanip>
#include <sstream>
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
	this->tipo = 'B';
	this->consumo = -1;
	this->numPosicionarch = -1;
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
	void Documento::setConsumo(int c)
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
	int Documento::getConsumo()
	{
		return this->consumo;
	}
	char Documento::getTipo()
	{
		return this->tipo;
	}
	string Documento::toStringDocumento()
	{
		float pi = this->getImporte();
		stringstream aux;
		aux << fixed << setprecision(2) << pi;
		string s = aux.str();

		string valor = this->getPago() ? "Pago" : "Impago";
		string cadena = "Numero: " + to_string(this->getNumero()) + ", Tipo de documento: " + this->getTipo()
			+ ", Fecha creacion: " + this->getFecha().toStringFecha() + ", ID Inter: " + to_string(this->getIdinter())
			+ ", ID Medidor: " + to_string(this->idMed)
			+ ", Id Tarifa: " + to_string(this->getIdtar()) + ", Consumo: " +to_string(this->getConsumo()) + "KWH, Estado : " + valor
			+ ", Importe: $ " + s;
		return  cadena;
	}
	Documento::~Documento()
	{
	}



