#include "DocumentoRN.h"

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
	Medidor medidor = this->getMedidor(id,"medidores.dat");
	if (medidor.getId() != id)
		return documento;
	CuentaContrato cuentaContrato = this->getCuentaContrato(medidor.getId(), "cuentascontrato.dat");///FALTA GET ID CUENTA CONTRATO
	InterlocutorComercial interlocutorComercial = this->getInterlocutorComercial(cuentaContrato.getId_ic(), "interlocutores.dat");
	documento.setIdinter(interlocutorComercial.getId_ic());
	documento.setIdcc(cuentaContrato.getId_cc());
	documento.setIdmed(medidor.getId());
			
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

//METODO QUE BUSCA UNA CUENTA CONTRATO POR ID
CuentaContrato DocumentoRN::getCuentaContrato(int id, string nomarch)
{	
	CuentaContratoAD cuentaContratoAD(nomarch);
	return cuentaContratoAD.getCuentaContratoArchivo(id);
}

