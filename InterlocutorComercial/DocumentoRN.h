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
	Documento documento;
	DocumentoAD documentoAD;
	string nombreArchivo;
	InterlocutorComercial interlocutorComercial;
	Medidor medidor;
	MedidorRN medidorRN;
	CuentaContrato cc;
	Tarifa tarifa;
	Medidor getMedidorArchivo(int id, string nomarch);///AGREGAR LOS GET "ARCHIVO"

	//DECLARAR UN INTERLOCUTOR Y UN MEDIDOR
public:
	DocumentoRN(string nombreArchivo = "");
	~DocumentoRN();
	int IdDocumento(Documento& documento);
	Documento BuscarDocumento(int numero);
	bool ValidarDocumentoNumero(int numero);
	//Documento BuscarDocumento(int id);
	float CalcularConsumo(float lectura);
	bool ControlModificaciones(Documento& documento);
	bool AltaDocumento(Documento& documento);
	long CantidadDocumentosEnSistema();
	string getNombreArchivo();
	vector<Documento> VectorDocumentos();
	vector<Documento> getDocumentos();///AGREGUE IGUAL QUE GABY MEDIDOR
	void setNombreArchivo(string nombreArchivo);
	//METODO QUE BUSQUE UN MEDIDOR POR ID 
	Documento getDocumento();
	void setDocumento(Documento& documento);
	//void ListarDocumentosImpagos();
	//void ListarDocumentosPagos();
	Medidor getMedidor();
	void setMedidor(Medidor& medidor);

	void GuardarLectura(int id,float lecturaActual);


	//METODO QUE BUSQUE UN INTERLOCUTOR POR ID
	InterlocutorComercial getInterlocutorComercialArchivo(int id, string nomarch);
	InterlocutorComercial getInterlocutorComercial();
	//METODO QUE BUSCA POR ID CUENTA CONTRATO
	CuentaContrato getCuentaContratoArchivo(int id, string nomarch);
	CuentaContrato getCuentaContrato();
	Tarifa getTarifaArchivo(int id, string nomarch);
	Tarifa getTarifa();
	///METODO QUE CALCULE EL CONSUMO TRAIGO LECTURA ANTERIOR MEDIDOR POR ID, 
	//CARGO POR PANTALLA LECTURA ACTUAL 
	///LISTAR MEDIDORES
	//Metodo que valida el id ingresado del medidor
	float CalcularImporte(float consumo);
	bool validarIdMedidor(int id);
	bool validarFechaDocumento(int id);
		


};
