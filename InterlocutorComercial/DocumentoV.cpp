#include "DocumentoV.h"
#include "Fecha.h"
#include "Validaciones.h"
#include "MedidorV.h"






DocumentoV::DocumentoV(string nombreArchivo)
{
	this->documento = Documento();
	this->nombreArchivo = nombreArchivo;
	this->documentoRN = DocumentoRN(nombreArchivo);
}
DocumentoV::~DocumentoV()
{
}
/// <summary>
/// M�todo que permite dar de alta un Documento y lo graba en el archivo que contiene los documentos.
/// </summary>
void DocumentoV::NuevoDocumento()
{	
	/// <summary>
	/// DEBE INGRESAR UN NUMERO DE ID DE MEDIDOR, CON ESE ID ME TRAE EL ID DEL INTERLOCUTOR PARA LLENAR EL DOCUMENTO PARA ESE INTER
	/// VALIDAR SI EL ID ES EL MISMO QUE ME TRAE OK, SINO NO EXISTE EL MEDIDOR
	/// </summary>
	this->documento = Documento();
	int id;
	char dat;
	bool volver = false;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Nuevo ingreso de datos del Documento " << endl;
		cout << "--------------------------------------------------" << endl;
		//cout << "Ingrese el Id del Medidor: ";
		//cin >> id;
		id = Validaciones::DatoObligarorioNum("Id del Medidor : ");
		//VALIDA EL ID QUE EXISTA EN EL ARCHIVO MEDIDORES Y CARGA EL RESTO DE LOS OBJETOS PARA EL DOCUMENTO
		if (!this->documentoRN.validarIdMedidor(id))
		{
			cout << "El ID ingresado no es valido" << endl;
			cout << "Desea ingresar otro ID?" << endl;
			dat = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dat) == 'S') {
				system("cls");
				continue;
			}
			else
			{
				volver == true;
				system("cls");
				return;
			}
		}
		else {
			break;
		}
	} while (volver==false);
	
	float lecturaActual;
	char dato;
	do {
		
		lecturaActual= Validaciones::DatoObligarorioNum("la lectura actual:");
		///LLAMAR A METODO CALCULAR CONSUMO
		float consumo = this->documentoRN.CalcularConsumo(lecturaActual);
		if (consumo >= 0)
		{
			cout << "Se va a generar una factura nueva, para el cliente: " << endl;
			cout << this->documentoRN.getInterlocutorComercial().getNombre();
			cout << this->documentoRN.getInterlocutorComercial().getApellido();
			cout << " con el consumo: " << consumo << endl;
			cout << "Desea continuar?" << endl;
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S')
			{	
				float importe = this->documentoRN.CalcularImporte(consumo);
				cout << " el importe total es: " << importe << endl;
				//grabo Factura
				if (this->documentoRN.AltaDocumento(this->documento)) {
					cout << this->separador << endl;
					cout << "SE CREO UN DOCUMENTO EXITOSAMENTE" << endl;
					cout << this->separador << endl;
					system("pause");
					break;
				}
				else {
					cout << this->separador << endl;
					cout << "ATENCION NO SE CREO EL DOCUMENTO" << endl;
					cout << this->separador << endl;
					system("pause");
					break;
				}

			}
			else {
				return;
			}
		}

	} while (true);


}

/// <summary>
/// Funci�n global para listar todos los documentos del archivo.
/// </summary>
/*void DocumentoV::ListarDocumentos()
{
	vector<Documento> documentos = this->documentoRN.VectorDocumentos();
	for (auto doc : documentos)
	{
		cout << doc.toStringDocumento() << endl;
	}
}
*/
void DocumentoV::ListarDocumentos()
{
	vector<Documento> documentos = this->documentoRN.getDocumentos();//getDocumentos();
	
		for (auto doc : documentos)
		{
			cout << doc.toStringDocumento() << endl;
		}
	
}
/// <summary>
/// Metodo que muestra un menu de opciones para las altas bajas y modificaciones de documentos.
/// </summary>
void DocumentoV::MenuDocumento()
{
	bool salir = false;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Menu Documento" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Nuevo Documento" << endl;
		cout << "2. Listar Documentos" << endl;
		cout << "3. Listar medidores disponibles" << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		int opcion;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			this->NuevoDocumento();
			break;
		case 2:
			this->ListarDocumentos();
			
			break;
		
		case 3:
		{
			MedidorV medidorV("medidores.dat");
			//Le pasas false para traer los medidores desinstalados=Disponibles
			medidorV.ListarMedidor(false);

			break;
		}
		case 0:
			salir = true;
			system("cls");
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	} while (salir == false);
}


void DocumentoV::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string DocumentoV::getNombreArchivo()
{
	return this->nombreArchivo;
}

void DocumentoV::setDocumento(Documento& documento)
{
	this->documento = documento;
}

 Documento DocumentoV::getDocumento()
{
	return this->documento;
}
 DocumentoRN DocumentoV::getDocumentoRN()
 {
	 return this->documentoRN;
 }

