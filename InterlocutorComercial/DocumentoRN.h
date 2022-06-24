#pragma once
#include "DocumentoAD.h"
#include "InterlocutorComercialAD.h"
#include "MedidorAD.h"
#include "CuentaContratoAD.h"
#include "MedidorV.h"
#include "TarifaAD.h"

class DocumentoRN
{
private:
	DocumentoAD documentoAD;
	string nombreArchivo;
	InterlocutorComercial interlocutorComercial;
	Medidor medidor;
	CuentaContrato cc;
	Tarifa tarifa;

	//DECLARAR UN INTERLOCUTOR Y UN MEDIDOR
public:
	DocumentoRN(string nombreArchivo = "");
	~DocumentoRN();
	Documento BuscarDocumento(string id);///VER ESTO
	Documento BuscarDocumento(int id);
	float CalcularConsumo(float lectura);
	bool ControlModificaciones(Documento& documento);
	bool AltaDocumento(Documento& documento);
	long CantidadDocumentosEnSistema();
	string getNombreArchivo();
	vector<Documento> VectorDocumentos();
	void setNombreArchivo(string nombreArchivo);
	//METODO QUE BUSQUE UN MEDIDOR POR ID 
	Medidor getMedidor(int id, string nomarch);
	//METODO QUE BUSQUE UN INTERLOCUTOR POR ID
	InterlocutorComercial getInterlocutorComercial(int id, string nomarch);
	//METODO QUE BUSCA POR ID CUENTA CONTRATO
	CuentaContrato getCuentaContrato(int id, string nomarch);
	Tarifa getTarifa(int id, string nomarch);
	///METODO QUE CALCULE EL CONSUMO TRAIGO LECTURA ANTERIOR MEDIDOR POR ID, 
	//CARGO POR PANTALLA LECTURA ACTUAL 
	///LISTAR MEDIDORES
	//Metodo que valida el id ingresado del medidor
	bool validarIdMedidor(int id);


};
