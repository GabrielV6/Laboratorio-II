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

int DocumentoRN::IdDocumento(Documento& documento)
{
	int id = this->documentoAD.TotalDocumentosEnArchivo();
	if (id == -1) {
		id = 0;
	}
	id += RANGO_NUMERICO;

	documento.setNumero(id);
	return documento.getNumero();
}

bool DocumentoRN::AltaDocumento(Documento& documento)
{

	// generar ID y setear ID de docuemntos antes de enviar el objeto a GuardarEnDisco
	if (documento.getNumero() != 0) {
		int id = this->documentoAD.TotalDocumentosEnArchivo();
		if (id == -1) {
			id = 0;
		}
		id += RANGO_NUMERICO;

		documento.setNumero(id);
		return this->documentoAD.GuardarEnArchivoDocumento(documento);
	}

	return this->documentoAD.GuardarEnArchivoDocumento(documento);
}
Documento DocumentoRN::BuscarDocumento(int id)
{
	Documento documentoAD = this->documentoAD.getDocumentoArchivo(id);
	if (documentoAD.getNumero() == id)
		return documentoAD;
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
//AGREGUE COMO GABY EN MEDIDORES
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
Medidor DocumentoRN::setMedidor()
{
	return this->medidor;
}

//SETEAR LA LECTURA DEL MEDIDOR DEBE TOMAR LA NUEVA LECTURA
void DocumentoRN::GuardarLectura(int id,float lecturaActual)
{

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
Tarifa DocumentoRN::getTarifaArchivo(int id, string nomarch )
{ 
	TarifaAD tarifaAD(nomarch);
	return tarifaAD.getTarifaArchivo(id);
}
Tarifa DocumentoRN::getTarifa()
{
	return this->tarifa;
}

float DocumentoRN::CalcularConsumo(float lectura)
{	
	float consumo = -1;
	
	if(lectura>=this->medidor.getLectura())
	consumo = lectura - this->medidor.getLectura();
	
 


	return consumo;
}
//METODO QUE DEVUELVE EL IMPORTE TOTAL A PAGAR
float DocumentoRN::CalcularImporte(float consumo)
{
	float importe;
	
	this->tarifa = this->getTarifaArchivo(1/*this->cc.getId_Tarifa() */ , NOMBRE_ARCH_TAR);

	
	return importe = tarifa.getImpuestos() + tarifa.getCargoFijo()+(tarifa.getCargoVariable() * consumo);
	
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
		if (documento[i].getFecha().getMes() == aux.getMes()&& documento[i].getIdmed()==id)
		{
		return true;
		}
}
	return false;
}
