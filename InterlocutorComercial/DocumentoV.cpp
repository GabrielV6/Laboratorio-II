#include "DocumentoV.h"
#include "Fecha.h"
#include "Validaciones.h"
#include "MedidorV.h"
#include <iomanip>


DocumentoV::DocumentoV(string nombreArchivo)
{
	this->documento = Documento();
	this->nombreArchivo = nombreArchivo;
	this->documentoRN = DocumentoRN(nombreArchivo);
}
DocumentoV::~DocumentoV()
{
}
///
void DocumentoV::RegistrarPago()
{
	this->documento = Documento();
	int numero;
	char dato;
	int rangoDocumentos = 100;
	do {
		system("cls||clear");
		cout << "-------------------------------------------------" << endl;
		cout << "Nuevo Registro de pago de Documento " << endl;
		cout << "--------------------------------------------------" << endl;
		numero = Validaciones::DatoObligarorioNum("Numero del Documento");
		//VALIDAR QUE EL NUMERO DE FACTURA EXISTA 
		
		if (!this->documentoRN.ValidarDocumentoNumero(numero)||numero<rangoDocumentos) {
			cout << "El numero ingresado no es valido " << endl;

		}
		//seteo que se pago la factura y guardo en archivo
		else
		{
			this->documento = this->documentoRN.getDocumento();
			if (this->documento.getPago() == true)
			{
				cout << "EL DOCUMENTO YA ESTA PAGO" << endl << endl;
			}
			else {
				this->documento.setPago(true);
				if (this->documentoRN.ControlModificaciones(documento))
					cout << "EL PAGO FUE REGISTRADO EXITOSAMENTE" << endl;
			}
		}
		cout << "Desea cargar otro numero de documento?" << endl;
		dato = Validaciones::DatoObligarorioChar("'S' o 'N' para volver al menu");
		if (toupper(dato) != 'S') {
			return;
		}
	} while (true);

}

/// 
/// 
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
	Fecha fecha;
	int id;
	bool volver = false;
	float lecturaActual;
	char dato;

	do {
		cout << "-------------------------------------------------" << endl;
		cout << "\tNuevo ingreso de datos del Documento " << endl;
		cout << "--------------------------------------------------" << endl;
		id = Validaciones::DatoObligarorioNum("Id del Medidor");

		if (!this->documentoRN.validarIdMedidor(id) ) {
			cout << "El ID del medidor ingresado no es valido" << endl;
			cout << "Desea ingresar otro ID?" << endl;
			
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S') {
				system("cls||clear");
				continue;
			}
			else {
				return;
			}
		}
		if (this->documentoRN.validarFechaDocumento(id)) {
			cout << this->separador << endl;
			cout << "\t\t\t\t\t\tATENCION: " << endl;
			cout << this->separador << endl;
			cout << "\t\tEL ID DEL MEDIDOR INGRESADO YA TIENE UN DOCUMENTO GENERADO EN ESTE PERIDO" << endl;
			cout << this->separador << endl;
			cout<<"|Lo sentimos pero por regla de la empresa no puede generar mas de un documento por mes para el mismo ID|" << endl; 
			cout << this->separador << endl;
			cout << "Desea ingresar otro ID?" << endl;
			dato = Validaciones::DatoObligarorioChar("'S' o 'N'");
			if (toupper(dato) == 'S') {
				system("cls||clear");
				continue;
				volver = true;
			}
			else {
				return;
			}
		}
		else {
			lecturaActual = Validaciones::DatoObligarorioDecimal("la lectura actual");
			///SE CALCULA EL CONSUMO PARA ESTE DOCUMENTO
			int consumo = this->documentoRN.CalcularConsumo(lecturaActual);
			if (consumo >= 0)
			{
				system("cls||clear");
				cout << this->separador << endl;
				cout << "\t\t\t\t\tATENCION! " << endl;
				cout << this->separador << endl;
				cout << "\t\t\tESTA CREANDO UN NUEVO DOCUMENTO CON EL NUMERO | " << documentoRN.IdDocumento(documento)<<" |" << endl;
				cout << this->separador << endl;
				cout << "PARA EL CLIENTE" << endl;				
				cout <<"\t\t\t|APELLIDO:\t" << this->documentoRN.getInterlocutorComercial().getApellido()<<"|"<< endl;
				cout << "\t\t\t|NOMBRE: \t" << this->documentoRN.getInterlocutorComercial().getNombre() << "|" << endl;				
				cout << this->separador << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tLectura anterior: " << documentoRN.getMedidor().getLectura() << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tLectura actual: " << lecturaActual << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tPor un consumo de: " << consumo << " KWH" << endl;
				cout << this->separador << endl;
				cout << "Desea continuar creando el documento?" << endl;
				cout << this->separador << endl;

				dato = Validaciones::DatoObligarorioChar("'S' para crear el documento o 'N' para cancelar y volver al menu principal");
				if (toupper(dato) == 'S')
				{
					fecha.cargarFecha();
					//fecha.cargarFechaActual();
					this->documento.setFecha(fecha);
					this->documento.setIdinter(this->documentoRN.getInterlocutorComercial().getId_ic());
					this->documento.setIdcc(this->documentoRN.getCuentaContrato().getId_cc());
					this->documento.setIdtar(this->documentoRN.getTarifa().getIdTarifa());
					this->documento.setIdmed(id);
					this->documento.setConsumo(consumo);
					this->documento.setImporte(this->documentoRN.CalcularImporte(consumo));
					this->documentoRN.GuardarLectura(id, lecturaActual);

					//cout << " el importe total es: $ " << documento.getImporte() << endl;
					//SE GUARDA LA FACTURA EN DISCO
					if (this->documentoRN.AltaDocumento(this->documento)) {
						cout << this->separador << endl;
						cout << "\t\t\t\tDOCUMENTO CREADO EXITOSAMENTE" << endl;
						cout << this->separador << endl;
						cout << "NUMERO DE DOCUMENTO: " << documento.getNumero() << "\t\tNUMERO DE CLIENTE: " << documento.getIdinter() << "\t\t\tFecha de creacion:" << documento.getFecha().toStringFecha() << endl;
						cout << this->separador << endl;
						cout << "\t\t\t\t\t\t\t\t\t\tCargo Fijo:\t $ " << this->documentoRN.getTarifa().getCargoFijo() << endl;
						cout << "\t\t\t\t\t\t\t\t\t\tCargo Variable:\t $ " << this->documentoRN.getTarifa().getCargoVariable() << endl;
						cout << "\t\t\t\t\t\t\t\t\t\tImpuestos:\t $ " << this->documentoRN.getTarifa().getImpuestos() << endl;
						cout << "\t\t\t\t\t\t\t\t\t\tTotal consumo:\t " << this->documento.getConsumo() << " KWH" << endl;
						cout << this->separador << endl;
						cout << "\t\t\t\t\t\t\t\t\t\tTotal a Pagar:\t $ " << fixed <<setprecision(2) << documento.getImporte() << endl;
						cout << this->separador << endl;

						cout << this->separador << endl;
						Validaciones::SystemPause();
						cout << this->separador << endl;
						cout << "Desea cargar otro documento con un nuevo Id de medidor?" << endl;
						dato = Validaciones::DatoObligarorioChar("'S' o 'N' para volver al menu principal");
						if (toupper(dato) == 'S')
						{
							system("cls||clear");
							volver = true;

						}
						else {
							return;
						}
					}
					else {
						cout << this->separador << endl;
						cout << "ATENCION NO SE CREO EL DOCUMENTO" << endl;
						cout << this->separador << endl;
						Validaciones::SystemPause();
						break;
					}

				}
				else {
					return;
				}
			}
			//SI EL CONSUMO DA NEGATIVO. INGRESO UNA LECTURA ACTUAL MENOR A LA ANTERIOR O UNA LECTURA NEGATIVA
			else {
				cout << this->separador << endl;
				cout << "******************ATENCION EL CONSUMO CALCULADO ES NEGATIVO***************" << endl;
				cout << "-----------POSIBLE CONEXION CLANDESTINA O DEFECTO EN LECTURA DEL INSPECTOR----------------" << endl;
				cout << "-----------------------REPORTAR A SUPERVISOR-------------------" << endl;
				cout << this->separador << endl;
				Validaciones::SystemPause();
				system("cls||clear");
				break;
			}
		}


	} while (true || volver != true);


}


/// <summary>
/// Funci�n global para listar todos los documentos del archivo.
/// </summary>


void DocumentoV::ListarDocumentos()
{
	vector<Documento> documentos = this->documentoRN.getDocumentos();

	for (int i = 0; i < documentos.size(); i++)
	{
		cout << documentos[i].toStringDocumento() << endl;
	}

}
//LISTAR DOCUMENTOS IMPAGOS

void DocumentoV::ListarDocumentosImpagos()
{
	vector<Documento> documentos = this->documentoRN.getDocumentos();

	for (int i = 0; i < documentos.size(); i++)
	{
		if(documentos[i].getPago()==false)
		cout << documentos[i].toStringDocumento() << endl;
	}
}
//listar DOCUMENTOS PAGOS

void DocumentoV::ListarDocumentosPagos()
{
	vector<Documento> documentos = this->documentoRN.getDocumentos();

	for (int i = 0; i < documentos.size(); i++)
	{
		if (documentos[i].getPago() == true)
			cout << documentos[i].toStringDocumento() << endl;
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
		cout << "|\t\tMenu Principal de Documento" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "|\t1. Nuevo Documento" << endl;
		cout << "|\t2. Registrar el Pago de Documento" << endl;
		cout << "|\t3. Listar Documentos" << endl;
		cout << "|\t4. Listar Documentos Pagos" << endl;
		cout << "|\t5. Listar Documentos Impagos" << endl;
		cout << "|\t6. Listar Medidores disponibles" << endl;
		cout << "|\t0. Salir" << endl;
		cout << "-------------------------------------------------" << endl;
		int opcion;
		cout << "-------------------------------------------------" << endl;
		cout << "\t   Ingrese una opcion: ";
		//cout << this->separador << endl;
		cin >> opcion;
		
		cout << "-------------------------------------------------" << endl;
		
		switch (opcion)
		{
		case 1:
			this->NuevoDocumento();
			break;
		case 2:
			this->RegistrarPago();
			break;

		case 3:
			this->ListarDocumentos();
			
			break;
		
		case 4:
			this->ListarDocumentosPagos();
			break;

		case 5:
			this->ListarDocumentosImpagos();
			break;
		
		case 6:
			{
			MedidorV medidorV("medidores.dat");
			//Le pasas false para traer los medidores desinstalados=Disponibles
			medidorV.ListarMedidor(true);
			break;
			}
		case 0:
			salir = true;
			system("cls||clear");
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

