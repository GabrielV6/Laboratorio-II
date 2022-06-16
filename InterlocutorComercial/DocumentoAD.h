#pragma once
#include <fstream>
#include "Documento.h"
#include <vector>

class DocumentoAD
{
public:

	DocumentoAD(string nombreArchivo = "");
	~DocumentoAD();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	/// <summary>
	/// M�todo que devuelve la cantidad de documentos  que hay en el archivo de datos.
	/// </summary>
	/// <returns>entero largo</returns>
	long TotalDocumentosEnArchivo();
	/// <summary>
	/// M�todo que guarda el documento en el archivo de datos y devuelve verdadero cuando resulta correto la grabaci�n.
	/// </summary>
	/// <returns>Booleano</returns>
	bool GuardarEnArchivoDocumento(Documento& documento);
	/// <summary>
	/// Este m�todo permite modificar en el archivo el documento enviado por parametro
	/// </summary>
	/// <param name="documento"></param>
	/// <returns></returns>
	bool ActualizarEnArchivoDocumento(Documento& documento);
	/// <summary>
	/// M�todo que devuleve un objeto tipo documento  que este dentro del archivo de datos
	/// </summary>
	/// <param name="posicion"></param>
	/// <returns>Documento</returns>
	Documento getDocumentoArchivo(string id);
	/// <summary>
	/// Funci�n que devuleve todos los documentos del archivo en un vector
	/// </summary>
	vector<Documento> getDocumentosArchivo();
private:
	string nombreArchivo;
	Documento documento;
};
