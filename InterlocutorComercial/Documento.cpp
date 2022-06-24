#include "Documento.h"


Documento::Documento()
{
	strcpy(this->id, "");
	//this->codigo = ' ';
	//this->letra = ' ';
	//this->serie = 0;
	this->numero = 0;
	this->fecha = Fecha();
	this->idInter = 0;
	this->idCC = 0;  //id cuenta contrato
	this->idMed = 0;//id medidor
	this->idTar = 0;
	this->pago = false;
}
Documento::Documento(string d)
{
	
	strcpy(this->id,d.c_str());
	//this->codigo = ' ';
	///this->letra = ' ';
	//this->serie = 0;
	this->numero = 0;
	this->fecha = Fecha();
	this->idInter = 0;
	this->idCC = 0;  //id cuenta contrato
	this->idMed = 0;//id medidor
	this->idTar = 0;

}

	void Documento::setId(string id)
	{
		strcpy(this->id, id.c_str());
		
	}
	/*void Documento::setCodigo(char codigo)
	{
		this->codigo = codigo;
	}
	void Documento::setLetra(char letra)
	{
		this->letra = letra;
	}
	void Documento::setSerie(int serie)
	{
		this->serie = serie;
	}
	*/
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

	
	string Documento::getId()
	{
		return this->id;
	}
	/*char Documento::getCodigo()
	{
		return this->codigo;
	}
	char Documento::getLetra()
	{
		return this->letra;
	}
	int Documento::getSerie()
	{
		return this->serie;
	}
	*/
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

	/*void Documento::cargarDocumento()
	{
		cout << "Ingrese el Cargo Fijo: ";
		cin >> this->cargoFijo;
		cout << "Ingrese el Cargo Variable: ";
		cin >> this->cargoVariable;
		cout << "Ingrese los Impuestos: ";
		cin >> this->impuestos;
		cout << "Ingrese el Tipo de tarifa: ";
		cin >> this->tipoDeTarifa;
	}
	*/
	/// <summary>
	/// /VER ESTO
	/// </summary>
	/// <returns></returns>
	long Documento::getNumPosicionArhivo()
	{
		return this->numPosicionArch;
	}
	*/

	char id[14]; ////vector de char: codigo (F,C,D,R), tipo(A,B,R), serie(0002,0005), numero(88888888)
	char codigo; // (documento=f, nota credito=c, nota debito=d, remito=r)
	char letra; // a b r
	int serie; //numero de documento, remito etc
	int numero;
	Fecha fecha;
	int idInter;//id interlocutor comercial
	int idCC;  //id cuenta contrato
	int idMed;//id medidor
	int idTar;//id tarifa
	int numPosicionarch;
	string Documento::toStringDocumento()
	{
		return this->getId() + "/" + "/" + to_string(this->numero)
			+ "/" + this->fecha.toStringFecha() + "/" + to_string(this->idInter)+ "/" + to_string(this->idMed)+ "/" + to_string(this->idTar);
	}
	Documento::~Documento()
	{
	}



