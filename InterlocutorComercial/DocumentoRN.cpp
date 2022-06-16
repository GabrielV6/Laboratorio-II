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
	Documento docAD = this->documentoAD.getDocumentoArchivo(id);
	if (docAD.getId() == id)
		return docAD;
	return Documento();
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
