#include "DocumentoV.h"
#include "Fecha.h"
#include "Validaciones.h"
#include "MedidorV.h"






DocumentoV::DocumentoV(string nombreArchivo)
{
	this->documento = Documento(nombreArchivo);
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
	this->documento = Documento(this->nombreArchivo);
	int id;
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Nuevo ingreso de datos del Documento " << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Ingrese el Id del Medidor: ";
		cin >> id;
		//hacer un metodo validar id de medidor VALIDAR SI EL ID ES EL MISMO QUE ME TRAE OK, SINO NO EXISTE EL MEDIDOR
		this->documento = this->documentoRN.BuscarDocumento(id);

		if (this->documento.getIdmed() != id) // LLamar metodo de regla de negocio que valida si existe el ID
		{
			cout << "ID medidor no encontrado!!!" << endl;
			system("pause");
			system("cls");
		}
		else
			
			break;
	} while (true);
	
	int lecturaActual;
	char dato;
	do {
		
		cout << "Ingrese la lectura actual: ";
		cin >> lecturaActual;
		{
			cout << "Se va a generar una factura nueva, para el cliente "<<<<"para el consumo"<<" "<<lecturaActual << endl;
			cout << "Desea continuar?" << endl;
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S')
				///this->(!this->Documento.getActivo());
			break;
		}
		/// <summary>
		/// MOSTRAR UN CARTEL QUE DIGA "SE VA GENERAR UNA FACTURA, PARA EL CLIENTE (NOMBRE APELLIDO) PARA ESTE
		/// CONSUMO (MOSTRAR EL CALCULO DE CONSUMO). DESEA CONTINUAR? SI / NO.  
		/// 
		/// 
		/// </summary>
	
		///FALTA METODO DE CARGA AUTOMATICA DE N° SERIE (0002,0005),numero(88888888)

	} while (true);
	//string id;
	//cout << "Id: ";
	//cin >> id;

}/////OJOOOOO
/// <summary>
/// Funci�n global para listar todos los documentos del archivo.
/// </summary>
void DocumentoV::ListarDocumentos()
{
	vector<Documento> documentos = this->documentoRN.VectorDocumentos();
	for (auto doc : documentos)
	{
		cout << doc.toStringDocumento() << endl;
	}
}

void DocumentoV::MenuModificarDocumento()
{
	string id;
	int opcion;

	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Modificar datos del Documento " << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Documento Id.: ";
		cin >> id;
		this->documento = this->documentoRN.BuscarDocumento(id);
		if (this->documento.getId() == id) // LLamar metodo de regla de negocio que valida si existe el ID
		{
			cout << "Documento ingresado no esta dado de alta!!!" << endl;
			system("cls");
		}
		else
			break;
	} while (true);
	do
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Documento: " << this->documento.toStringDocumento() << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1. Modificar id" << endl;
		cout << "0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		string id;
		switch (opcion)
		{
		case 1:
			id = Validaciones::DatoObligarorioCad("ID");
			this->documento.setId(id);
			break;
		case 0:

			break;
		default:
			cout << "Opcion invalida!!!" << endl;
			break;
		}
	} while (opcion != 0);
}
void DocumentoV::ModificarDocumento()
{
	MenuModificarDocumento();
	this->documentoRN.ControlModificaciones(this->documento);
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
		cout << "3. Modificar Documento" << endl;
		cout << "4. Listar medidores disponibles" << endl;
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
			this->ModificarDocumento();
			break;
		case 4:
		{
			MedidorV medidorV("medidores.dat");
			medidorV.ListarMedidor();

			break;
		}
		case 0:
			salir = true;
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

