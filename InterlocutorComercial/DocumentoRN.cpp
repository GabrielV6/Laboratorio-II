#include "DocumentoRN.h"
#include "MedidorV.h"
#include "TarifaAD.h"
#include "InterlocutorComercialAD.h"

DocumentoRN::DocumentoRN(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
DocumentoRN::~DocumentoRN()
{
}
bool DocumentoRN::AltaDocumento(Documento& documento)
{
	return this->documentoAD.GuardarEnArchivoDocumento(documento);
}
Documento DocumentoRN::BuscarDocumento(string id)
{
	Documento documentoAD = this->documentoAD.getDocumentoArchivo(id);
	if (documentoAD.getId() == id)
		return documentoAD;
	return Documento();
}
Documento DocumentoRN::BuscarDocumento(int id)
{	
	Documento documento;
	this->medidor = this->getMedidor(id,"medidores.dat");
	if (medidor.getId() != id)
		return documento;
	this->cc = this->getCuentaContrato(medidor.getId(), "cuentascontrato.dat");///FALTA GET ID CUENTA CONTRATO
	this->interlocutorComercial = this->getInterlocutorComercial(cc.getId_ic(), "interlocutores.dat");
	//this->tarifa = this->getTarifa(cc.getIdTarifa(), "tarifa.dat");///FALTA ID TARIFA, CTA CONTRATO
	documento.setIdinter(interlocutorComercial.getId_ic());
	documento.setIdcc(cc.getId_cc());
	documento.setIdmed(medidor.getId());
	//documento.setId(tarifa.getIdTarifa());
			
	return documento;
}
bool DocumentoRN::ControlModificaciones(Documento& documento)
{
	/// Hacer la validadciones correspondientes al Documento pasado por parametro
	return true;
}
long DocumentoRN::CantidadDocumentosEnSistema()
{
	return this->documentoAD.TotalDocumentosEnArchivo();
}
string DocumentoRN::getNombreArchivo()
{
	return this->nombreArchivo;
}

vector<Documento> DocumentoRN::VectorDocumentos()
{
	return this->documentoAD.getDocumentosArchivo();
}
void DocumentoRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
///METODO QUE LISTA MEDIDORES

//METODO QUE BUSCA UN MEDIDOR POR ID
Medidor DocumentoRN::getMedidor(int id, string nomarch)
{	
	MedidorAD medidorAD(nomarch);
	return medidorAD.getMedidorArchivo(id);

}
//METODO QUE BUSQUE UN INTERLOCUTOR POR ID
InterlocutorComercial DocumentoRN::getInterlocutorComercial(int id, string nomarch)
{
	InterlocutorComercialAD interlocutorAD(nomarch);
	return interlocutorAD.getInterlocutorArchivo(id);
}
//MERTODO QUE BUSCA INTERLOCUTOR POR ID Y DEVUELVE EL NOMBRE
CuentaContrato DocumentoRN::getCuentaContrato(int id, string nomarch)
{
	InterlocutorComercial interlocutor(nomarch);
	return getNombre();
	
}
//METODO QUE BUSCA UNA CUENTA CONTRATO POR ID
CuentaContrato DocumentoRN::getCuentaContrato(int id, string nomarch)
{	
	CuentaContratoAD cuentaContratoAD(nomarch);
	return cuentaContratoAD.getCuentaContratoArchivo(id);
}


