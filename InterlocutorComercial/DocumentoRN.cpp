#include "DocumentoRN.h"
#include "MedidorV.h"
#include "TarifaAD.h"
#include "InterlocutorComercialAD.h"
#include "Validaciones.h"

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
//SETEAR LA LECTURA DEL MEDIDOR DEBE TOMAR LA NUEVA LECTURA
/*void Medidor DocumentoRN::setMedidor()
{
	
}
*/
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
	//this->medidor=getMedidor();
	if(lectura>=this->medidor.getLectura())
	consumo = lectura - this->medidor.getLectura();
	
	/// cargo fijo, cargo variable, 


	return consumo;
}
float DocumentoRN::CalcularImporte(float consumo)
{
	float importe;
	
	this->tarifa = this->getTarifaArchivo(this->cc.getId_Tarifa(), NOMBRE_ARCH_TAR); 
	///FALTA DIFERENCIA EL TIPO DE TARIFA
	
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
