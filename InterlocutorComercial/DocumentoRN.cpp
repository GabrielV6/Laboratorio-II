#include "DocumentoRN.h"
#include "MedidorV.h"
#include "TarifaAD.h"
#include "InterlocutorComercialAD.h"
#include "Validaciones.h"
#include <vector>

const int RANGO_NUMERICO = 100;

DocumentoRN::DocumentoRN(string nombreArchivo)
{
	this->documentoAD = DocumentoAD(nombreArchivo);
	this->nombreArchivo = nombreArchivo;

}
DocumentoRN::~DocumentoRN()
{
}
Documento DocumentoRN::getDocumento()
{
	return documento;
}
void DocumentoRN::setDocumento(Documento& documento)
{
	this->documento = documento;
}
//GENERA EL NUMERO DE FACTURA INICIANDO EN 100 POR LA CONSTANTE
int DocumentoRN::IdDocumento(Documento& documento)
{
	int numero = this->documentoAD.TotalDocumentosEnArchivo();
	if (numero == -1) {
		numero = 0;
	}
	numero += RANGO_NUMERICO;

	documento.setNumero(numero);
	return documento.getNumero();
}
//GUARDA EL DOCUMENTO EN EL ARCHIVO  
bool DocumentoRN::AltaDocumento(Documento& documento)
{

	// generar ID y setear ID de docuemntos antes de enviar el objeto a GuardarEnDisco
	if (documento.getNumero() != 0) {
		int numero = this->documentoAD.TotalDocumentosEnArchivo();
		if (numero == -1) {
			numero = 0;
		}
		documento.setPosicionarch(numero);
		numero += RANGO_NUMERICO;

		documento.setNumero(numero);
		return this->documentoAD.GuardarEnArchivoDocumento(documento);
	}

	return this->documentoAD.GuardarEnArchivoDocumento(documento);
}
//RECIBE UN NUMERO DE FACTURA Y DEVUELVE UN DOCUMENTO
Documento DocumentoRN::BuscarDocumento(int numero)
{
	Documento documentoAD = this->documentoAD.getDocumentoArchivo(numero);
	if (documentoAD.getNumero() == numero)
		return documentoAD;
	return Documento();
}

//VALIDA QUE EL NUMERO DE FACTURA EXISTA
bool DocumentoRN::ValidarDocumentoNumero(int numero)
{
	this->documento = DocumentoAD(NOMBRE_ARCH_DOC).getDocumentoArchivo(numero);

	if (this->documento.getNumero() == numero)
		return true;

	return false;


}
bool DocumentoRN::ControlModificaciones(Documento& documento)
{	
	this->documentoAD.setNombreArchivo(NOMBRE_ARCH_DOC);
	return this->documentoAD.ActualizarEnArchivoDocumento(documento);

}
long DocumentoRN::CantidadDocumentosEnSistema()
{
	return this->documentoAD.TotalDocumentosEnArchivo();
}
string DocumentoRN::getNombreArchivo()
{
	return this->nombreArchivo;
}

vector<Documento> DocumentoRN::getDocumentos()
{
	return this->documentoAD.getDocumentosArchivo();
}
//
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
Medidor DocumentoRN::getMedidorArchivo(int id, string nomarch)
{
	MedidorAD medidorAd(nomarch);
	return medidorAd.getMedidorArchivo(id);

}
Medidor DocumentoRN::getMedidor()
{

	return this->medidor;
}
void DocumentoRN::setMedidor(Medidor& medidor)
{
	this->medidor = medidor;
}

//SETEAR LA LECTURA DEL MEDIDOR DEBE TOMAR LA NUEVA LECTURA
void DocumentoRN::GuardarLectura(int id, float lecturaActual)
{
	this->medidorRN.setNombreArchivo(NOMBRE_ARCH_MED);
	medidor = medidorRN.BuscarCMedidor(id);
	medidor.setLectura(lecturaActual);
	medidorRN.ModificaMedidor(medidor);
}


//METODO QUE BUSQUE UN INTERLOCUTOR POR ID
InterlocutorComercial DocumentoRN::getInterlocutorComercialArchivo(int id, string nomarch)
{
	InterlocutorComercialAD interlocutorAD(nomarch);
	return interlocutorAD.getInterlocutorArchivoId(id);
}
InterlocutorComercial DocumentoRN::getInterlocutorComercial()
{

	return this->interlocutorComercial;
}
//MERTODO QUE BUSCA INTERLOCUTOR POR ID Y DEVUELVE EL NOMBRE


//METODO QUE BUSCA UNA CUENTA CONTRATO POR ID
CuentaContrato DocumentoRN::getCuentaContratoArchivo(int id, string nomarch)
{
	CuentaContratoAD cuentaContratoAD(nomarch);
	return cuentaContratoAD.getCuentaContratoArchivo(id);
}
CuentaContrato DocumentoRN::getCuentaContrato()
{
	return this->cc;
}
Tarifa DocumentoRN::getTarifaArchivo(int id, string nomarch)
{
	TarifaAD tarifaAD(nomarch);
	return tarifaAD.getTarifaArchivo(id);
}
Tarifa DocumentoRN::getTarifa()
{
	return this->tarifa;
}

int DocumentoRN::CalcularConsumo(int lectura)
{
	int consumo = -1;

	if (lectura >= this->medidor.getLectura())
		consumo = lectura - this->medidor.getLectura();




	return consumo;
}
//METODO QUE DEVUELVE EL IMPORTE TOTAL A PAGAR
float DocumentoRN::CalcularImporte(int consumo)
{
	float importe;

	this->tarifa = this->getTarifaArchivo(this->cc.getId_Tarifa(), NOMBRE_ARCH_TAR);


	return importe = tarifa.getImpuestos() + tarifa.getCargoFijo() + (tarifa.getCargoVariable() * consumo);

}
//BUSCO EL MEDIDOR Y LO VALIDO PARA SABER QUE ESTA CORRECTO
bool DocumentoRN::validarIdMedidor(int id)
{

	this->medidor = this->getMedidorArchivo(id, NOMBRE_ARCH_MED);

	if (this->medidor.getId() == id && this->medidor.getIdCuentaContrato() != 0) {
		this->cc = this->getCuentaContratoArchivo(this->medidor.getIdCuentaContrato(), NOMBRE_ARCH_CC);
		this->interlocutorComercial = this->getInterlocutorComercialArchivo(this->medidor.getIdCuentaContrato(), NOMBRE_ARCH_IC);
		this->tarifa = this->getTarifaArchivo(this->cc.getId_Tarifa(), NOMBRE_ARCH_TAR);
		return true;
	}

	return false;
}
///METODO QUE BUSCA POR ID SI YA SE CARGO UNA FACTURA EN ESA FECHA. SI ES EL MISMO MES DEVUELVE TRUE Y NO SE FACTURA
bool DocumentoRN::validarFechaDocumento(int id)
{
	Fecha aux;
	aux.cargarFechaActual();
	vector <Documento> documento = this->documentoAD.getDocumentosArchivo();
	for (int i = 0; i < documento.size(); i++)
	{
		if (documento[i].getFecha().getMes() == aux.getMes() && documento[i].getIdmed() == id)
		{
			return true;
		}
	}
	return false;
}

