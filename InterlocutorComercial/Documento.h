#pragma once

#include "Fecha.h"


////crear una clase documento
class Documento //documento impositivo--
{
private:
	char id[14]; ////vector de char: codigo (F,C,D,R), tipo(A,B,R), 
	//char letra; // a b 
	int numero;// numero(88888888)
	Fecha fecha;
	int idInter;//id interlocutor comercial
	int idCC;  //id cuenta contrato
	int idMed;//id medidor
	int idTar;//id tarifa
	int numPosicionarch;
	bool pago = false; ///nace en false
	///CONSUMO, HACER METODO -> SERIA LA RESTA DEL LECT ACTUAL CON LA ANTERIOR, TENGO
	///cargo fijo, cargo variable, impuesto, importeTotal
public:
	Documento();
	Documento(string d);/// VER QUE PARAMETRO POR OMISION CONSTRUCTOR USA 
	~Documento();
	void setId(string id);
	//void setCodigo(char codigo);
	//void setLetra(char letra);
	//void setSerie(int serie);
	void setNumero(int numero);
	void setFecha(Fecha fecha);
	void setIdinter(int id);//
	void setIdcc(int id);
	void setIdmed(int id);
	void setIdtar(int id);
	void setPosicionarch(int pos);
	void setPago(bool);
	string getId();
	//char getCodigo();
	//char getLetra();
	//int getSerie();
	int getNumero();
	Fecha getFecha();
	int getIdinter();
	int getIdcc();
	int getIdmed();
	int getIdtar();
	int getPosicionarch();
	bool getPago();
	string toStringDocumento();

};