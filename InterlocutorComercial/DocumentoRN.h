#pragma once
#include "DocumentoAD.h"


class DocumentoRN
{
private:
	DocumentoAD documentoAD;
	string nombreArchivo;
public:
	DocumentoRN(string nombreArchivo = "");
	~DocumentoRN();
	Documento BuscarDocumento(string id);
	bool ControlModificaciones(Documento& documento);
	bool AltaDocumento(Documento& documento);
	long CantidadDocumentosEnSistema();
	string getNombreArchivo();
	vector<Documento> VectorDocumentos();
	void setNombreArchivo(string nombreArchivo);
};
