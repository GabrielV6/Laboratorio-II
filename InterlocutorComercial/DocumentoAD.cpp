#include "DocumentoAD.h"
#include <vector>
DocumentoAD::DocumentoAD(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
DocumentoAD::~DocumentoAD()
{
}
void DocumentoAD::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string DocumentoAD::getNombreArchivo()
{
	return this->nombreArchivo;
}
/// <summary>
/// M�todo que devuelve la cantidad de interlocutores comerciales que hay en el archivo de datos.
/// </summary>
/// <returns>entero largo</returns>
int DocumentoAD::TotalDocumentosEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	long cantidad = 0;
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	cantidad = pos / sizeof(Documento);
	return cantidad;
}
/// <summary>
/// M�todo que guarda la documento en el archivo de datos y devuelve verdadero cuando resulta correcta la grabaci�n.
/// </summary>
/// <returns>Booleano</returns>
bool DocumentoAD::GuardarEnArchivoDocumento(Documento& documento)
{
	Documento documentoAD = documento;
	ofstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	//Busca cuantas documentos hay en el archivo y le asigna esa cantidad a la posicion relativa de la documento en el archivo.	
	long posArchivo = TotalDocumentosEnArchivo();
	archivo.write((char*)&documentoAD, sizeof(Documento));
	archivo.close();
	return true;

}
/// <summary>
/// Este m�todo permite modificar en el archivo la documento enviada por parametro
/// </summary>
/// <param name="documento"></param>
/// <returns></returns>
/// 
/// 
/// 


bool DocumentoAD::ActualizarEnArchivoDocumento(Documento& documento)
{

	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0);
	if (archivo.fail())
		return false;
	archivo.seekp(documento.getPosicionarch() * sizeof(Documento), ios::cur);

	//cout << "Posicion: " << to_string(archivo.tellp()) << endl;
	archivo.write((char*)&documento, sizeof(Documento));
	archivo.close();
	return true;
}
/// <summary>
/// M�todo que devuleve un objeto tipo documento que este dentro del archivo de datos
/// </summary>
/// <param name="posicion"></param>
/// <returns>Documento</returns>
Documento DocumentoAD::getDocumentoArchivo(string id)
{
	Documento documentoAD;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return documentoAD;

	while (archivo.read((char*)&documentoAD, sizeof(Documento)))
	{
		if (!archivo.eof())
			if (documentoAD.getId() == id)
			{
				archivo.close();
				return documentoAD;
			}
	}
	archivo.close();
	documentoAD = Documento();
	return documentoAD;
}

/// <summary>
/// Funci�n que devuleve todos los documentos del archivo en un vector
/// </summary>
vector<Documento> DocumentoAD::getDocumentosArchivo()
{
	Documento documentoAD;
	vector<Documento> documentos;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return documentos;
	while (archivo.read((char*)&documentoAD, sizeof(Documento)))
	{
		if (!archivo.eof())
		{
			documentos.push_back(documentoAD);
		}
	}
	return documentos;
}