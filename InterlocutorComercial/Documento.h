#pragma once

#include "Fecha.h"



class Documento //documento impositivo--
{
private:
	int numero;// numero(88888888)
	Fecha fecha;
	int idInter;//id interlocutor comercial
	int idCC;  //id cuenta contrato
	int idMed;//id medidor
	int idTar;//id tarifa
	int numPosicionarch;
	bool pago = false; ///nace en false
	float importe;
	int consumo;
	char tipo; //FACTURA A O B (COMERCIAL A, RESIDENCIAL B )
	
public:
	Documento();
	~Documento();
	void setNumero(int numero);
	void setFecha(Fecha fecha);
	void setIdinter(int id);//
	void setIdcc(int id);
	void setIdmed(int id);
	void setIdtar(int id);
	void setPosicionarch(int pos);
	void setPago(bool pago);
	void setImporte(float importe);
	void setConsumo(int consumo);
	void setTipo(char tipo);
	int getNumero();
	Fecha getFecha();
	int getIdinter();
	int getIdcc();
	int getIdmed();
	int getIdtar();
	int getPosicionarch();
	bool getPago();
	float getImporte();
	int getConsumo();
	char getTipo();
	string toStringDocumento();

};