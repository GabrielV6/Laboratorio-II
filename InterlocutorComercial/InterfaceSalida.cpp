#include "InterfaceSalida.h"
#include "CuentaContratoAD.h"
#include "MedidorAD.h"
#include "Validaciones.h"
#include "InterlocutorComercialV.h"
#include "MedidorV.h"
//#include "Validaciones.h"
#include "DocumentoV.h"
#include "TarifaV.h"
#include "CuentaContratoV.h"


InterfaceSalida::InterfaceSalida()
{}

InterfaceSalida::~InterfaceSalida()
{}

void InterfaceSalida::setTextoSalida(string texto)
{
	this->textoSalida = texto;
}

string InterfaceSalida::getTextoSalida()
{
	return this->textoSalida;
}

void InterfaceSalida::setTextosSalida(vector<string> textos)
{
	this->textosSalida = textos;
}

vector<string> InterfaceSalida::getTestosSalida()
{
	return this->textosSalida;
}

/// <summary>
/// M�todo que graba el texto que estan en el vecotr dentro de archivo indicado en el parametro nombreArchivo.
/// </summary>
/// <returns>Booleano</returns>
bool InterfaceSalida::GrabarTextosSalida(vector<string> textos, string nombreArchivo)
{
	ofstream archivo;
	archivo.open(nombreArchivo, ios::app | ios::out);

	if (archivo.fail())
		return false;

	for (auto& texto : textos)
		archivo << texto + "\n";

	archivo.close();
	return true;
}


bool InterfaceSalida::LeeTextosEntradaInterlocutor(string nombreArchivo)
{
	ifstream archivo;
	archivo.open(nombreArchivo, ios::in);

	if (archivo.fail())
		return false;
	string str = "";
	char pattern = ',';
	int posInit = 0;
	vector<string> results;
	while (getline(archivo, str))
	{
		InterlocutorComercial interlocutorArch;
		string splitted;
		Direccion direccion;
		Fecha fecha;
		int indice = 0;
		int posFound = 0;

		while (posFound >= 0)
		{
			
			int dia, mes, anio;
			posFound = str.find(pattern, posInit);
			splitted = str.substr(posInit, posFound - posInit);
			switch (indice)
			{
			case 0:
				interlocutorArch.setId_ic(stoi(splitted));
				break;
			case 1:
				interlocutorArch.setNombre(splitted);
				break;
			case 2:
				interlocutorArch.setApellido(splitted);
				// medArch.setEstado(splitted == "true" ? true : false);
				break;
			case 3:
				interlocutorArch.setEmail(splitted);
				break;
			case 4:
			{
				anio = stoi(splitted);
				fecha.setAnio(anio);
				break;
			}
			case 5:
			{
				mes = stoi(splitted);
				fecha.setMes(stoi(splitted));
				break;
			}
			case 6:
			{
				dia = stoi(splitted);
				fecha.setDia(dia);
				interlocutorArch.setFechaIngresoId(fecha);
				break;
			}
			case 7:
				direccion.setCalle(splitted);
				break;
			case 8:
				direccion.setNumero(stoi(splitted));
				break;
			case 9:
				direccion.setCodPostal(splitted);
				break;
			case 10:
				direccion.setLocalidad(splitted);
				break;
			case 11:
			{
				direccion.setProvincia(splitted);
				interlocutorArch.setDireccionId(direccion);
				break;
			}
			case 12:
				interlocutorArch.setId_ic(stoi(splitted));
				break;
			case 13:
				interlocutorArch.setActivo(splitted == "true" ? true : false);
				break;
			default:
				break;
			}
			indice++;
			posInit = posFound + 1;
		}
		InterlocutorComercialAD interlocutorAD(NOMBRE_ARCH_IC);
		interlocutorAD.GuardarEnArchivoInterlocutor(interlocutorArch);
	}
	archivo.close();
	return true;
}

bool InterfaceSalida::LeeTextosEntrada(string nombreArchivo)
{
	ifstream archivo;
	archivo.open(nombreArchivo, ios::in);

	if (archivo.fail())
		return false;
	string str = "";
	char pattern = ';';
	int posInit = 0;
	vector<string> results;
	while (getline(archivo, str))
	{
		Medidor medArch;
		string splitted;
		int indice = 0;
		int posFound = 0;
		while (posFound >= 0)
		{
			posFound = str.find(pattern, posInit);
			splitted = str.substr(posInit, posFound - posInit);
			switch (indice)
			{
			case 0:
				medArch.setId(stoi(splitted));
				break;
			case 1:
				medArch.setIdCuentaContrato(stoi(splitted));
				break;
			case 2:
				medArch.setEstado(splitted == "true" ? true : false);
				break;
			case 3:
				medArch.setLectura(stof(splitted));
				break;
			case 4:
				medArch.setNumPosicionArchivo(stoi(splitted));
				break;
			default:
				break;
			}
			indice++;
			posInit = posFound + 1;
		}
		MedidorAD medAD("medidores.dat");
		medAD.GuardarEnArchivoMedidor(medArch);
	}

	archivo.close();
	return true;
}

void InterfaceSalida::MostrarTextosSalida(vector<string> textos, string tituloTexo)
{
	cout << this->separador << endl;
	cout << tituloTexo << endl;
	cout << this->separador << endl;
	for (auto& texto : textos)
		cout << texto << endl;
	cout << this->separador << endl;
}

void InterfaceSalida::MenuPrincipal()
{
	int opcion = 0;
	do
	{
		cout << this->separador << endl;
		cout << "\t\tCONSULTAS DE GESTION ENERGETICA" << endl;
		cout << this->separador << endl;
		cout << "|\t1. Para menu Interlocutor Comercial" << endl;
		cout << "|\t2. Para menu Cuenta Contrato" << endl;
		cout << "|\t3. Para menu Medidor" << endl;
		cout << "|\t4. Para menu Tarifa" << endl;
		cout << "|\t5. Para menu Facturacion" << endl;
		cout << "|\t6. Para menu Consultas" << endl;
		cout << "|\t7. Para menu Exportacion CVS" << endl;
		cout << "|\t0. Para Salir" << endl;
		cout << this->separador << endl;
		opcion = Validaciones::DatoObligarorioNum("Opcion:");

		if (opcion == 0)
		{
			char salir;
			cout << "Desea salir del sistema " << endl;
			salir = Validaciones::DatoObligarorioChar(" S para salir");
			if (toupper(salir) == 'S')
			{
				system("cls||clear");
				cout << "GRACIAS POR USAR EL SISTEMA DE GESTION ENERGETICA!!!" << endl;
				Validaciones::SystemPause();
				exit(1);
			}
		}

		system("cls||clear");
		switch (opcion)
		{
		case 1:
		{
			system("cls||clear");
			InterlocutorComercialV interVista(NOMBRE_ARCH_IC);
			interVista.MenuInterlocutorComecial();
			break;
		}
		case 2:
		{
			system("cls||clear");
			CuentaContratoV cuentaContratoV(NOMBRE_ARCH_CC);
			cuentaContratoV.MenuCuentaContrato();
			break;
		}
		case 3:
		{
			system("cls||clear");
			MedidorV medidor(NOMBRE_ARCH_MED);
			medidor.MenuMedidor();
			break;
		}
		case 4:
		{
			system("cls||clear");
			TarifaV tarifa(NOMBRE_ARCH_TAR);
			tarifa.MenuTarifa();
			break;
		}
		case 5:
		{
			system("cls||clear");
			DocumentoV documento(NOMBRE_ARCH_DOC);
			documento.MenuDocumento();
			break;
		}
		case 6:
		{
			system("cls||clear");
			this->MenuConsultas();
			break;
		}
		case 7:
		{
			system("cls||clear");
			this->MenuExportacion();
			break;
		}
		default:
			break;
		}
	} while (true);
}

void InterfaceSalida::MenuExportacion()
{
	int opcion = 0;
	do
	{
		system("cls||clear");
		cout << this->separador << endl;
		cout << "\t*** EXPORTACION DE DATOS FORMATO CSV ***" << endl;
		cout << this->separador << endl;
		cout << "|1. Exportacion de Interlocutores Comerciales" << endl;
		cout << "|0. Para volver" << endl;
		cout << this->separador << endl;
		opcion = Validaciones::DatoObligarorioNum("Opcion");
		switch (opcion)
		{
		case 1:
		{
			system("cls||clear");
			int ok = this->ExportarIC();
			if (this->ExportarIC() == 0)
				cout << "\tExportación correcta" << endl;
			Validaciones::SystemPause();
			break;
		}
		case 2:
		{

			break;
		}
		case 0:
		{
			return;
		}
		default:
			break;
		}
	} while (true);
}

void InterfaceSalida::MenuConsultas()
{
	int opcion = 0;
	do
	{
		system("cls||clear");
		cout << this->separador << endl;
		cout << "\t***CONSULTAS DE GESTION ENERGETICA***" << endl;
		cout << "\t**********REPORTES**********" << endl;
		cout << this->separador << endl;
		cout << "|\t1. Consulta energia estacionaria" << endl;
		cout << "|\t2. Promedio de recaudacion" << endl;
		cout << "|\t3. Consulta cliente datos comerciales" << endl;
		cout << "|\t0. Para volver" << endl;
		cout << this->separador << endl;
		opcion = Validaciones::DatoObligarorioNum("Opcion");

		system("cls||clear");
		switch (opcion)
		{
		case 1:
		{
			system("cls||clear");
			int anio;
			anio = Validaciones::DatoObligarorioNum("Anio a consultar: ");
			ConsumoPorEstacion(anio);
			break;
		}
		case 2:
		{
			PromedioRecaudacion();
			break;
		}
		case 3:
		{
			system("cls||clear");
			int dni;
			dni = Validaciones::DatoObligarorioNum("DNI a consultar: ");
			this->ClienteDatosComerciales(dni);
			break;
		}
		case 0:
		{
			return;
		}
		default:
			break;
		}
	} while (true);
}

void InterfaceSalida::ConsumoPorEstacion(int anio)
{
	DocumentoAD documentoAD(NOMBRE_ARCH_DOC);
	vector<Documento> documentos;
	documentos = documentoAD.getDocumentosArchivo();
	float totalConsumoVerano = 0, totalConsumoOtonio = 0, totalConsumoInvierno = 0, totalConsumoPrimavera = 0;
	int cantidadDocVerano = 0, cantidadDocOtonio = 0, cantidadDocInvierno = 0, cantidadDocPrimavera = 0;
	for (auto& doc : documentos)
	{
		if (doc.getFecha().getAnio() == anio)
		{
			// Verano
			if (doc.getFecha().getMes() >= 12 && doc.getFecha().getDia() >= 21 && doc.getFecha().getMes() <= 3 && doc.getFecha().getDia() <= 20)
			{
				totalConsumoVerano += doc.getConsumo();
				cantidadDocVerano++;
			}
			// Otoño
			if (doc.getFecha().getMes() >= 4 && doc.getFecha().getDia() >= 21 && doc.getFecha().getMes() <= 6 && doc.getFecha().getDia() <= 20)
			{
				totalConsumoOtonio += doc.getConsumo();
				cantidadDocOtonio++;
			}
			// Invierno
			if (doc.getFecha().getMes() >= 7 && doc.getFecha().getDia() >= 21 && doc.getFecha().getMes() <= 9 && doc.getFecha().getDia() <= 20)
			{
				totalConsumoInvierno += doc.getConsumo();
				cantidadDocInvierno++;
			}
			// Primavera
			if (doc.getFecha().getMes() >= 10 && doc.getFecha().getDia() >= 21 && doc.getFecha().getMes() <= 12 && doc.getFecha().getDia() <= 20)
			{
				totalConsumoPrimavera += doc.getConsumo();
				cantidadDocPrimavera++;
			}
		}
	}
	system("cls||clear");
	string cadena;
	vector<string> datosAExportar;
	cout << separador << endl;
	cadena = "|CONSUMOS Y PROMEDIOS DEL AÑO: ";
	cout << "|" << cadena << anio << endl;
	datosAExportar.push_back(cadena);
	cout << separador << endl;
	if (cantidadDocVerano > 0)
	{
		cadena = "VERANO - Total consumo: " + to_string(totalConsumoVerano) + "\t Promedio: " + to_string(totalConsumoVerano / cantidadDocVerano);
		cout << "|" << cadena << endl;
		cadena = "Verano," + to_string(totalConsumoVerano) + "," + to_string(totalConsumoVerano / cantidadDocVerano);
		datosAExportar.push_back(cadena);
	}
	else
	{
		cadena = "VERANO - No hay consumos registrados ";
		cout << "|" << cadena << endl;
		datosAExportar.push_back(cadena);
	}
	if (cantidadDocOtonio > 0)
	{
		cadena = "OTOÑO - Total consumo: " + to_string(totalConsumoOtonio) + "\t Promedio: " + to_string(totalConsumoOtonio / cantidadDocOtonio);
		cout << "|" << cadena << endl;
		cadena = "Otoño," + to_string(totalConsumoOtonio) + "," + to_string(totalConsumoOtonio / cantidadDocOtonio);
		datosAExportar.push_back(cadena);
	}
	else
	{
		cadena = "OTOÑO - No hay consumos registrados ";
		cout << "|" << cadena << endl;
		datosAExportar.push_back(cadena);
	}
	if (cantidadDocInvierno > 0)
	{
		cadena = "INVIERNO - Total consumo: " + to_string(totalConsumoInvierno) + "\t Promedio: " + to_string(totalConsumoInvierno / cantidadDocInvierno);
		cout << "|" << cadena << endl;
		cadena = "Invierno," + to_string(totalConsumoInvierno) + "," + to_string(totalConsumoInvierno / cantidadDocInvierno);
		datosAExportar.push_back(cadena);
	}
	else
	{
		cadena = "INVIERNO - No hay consumos registrados ";
		cout << "|" << cadena << endl;
		datosAExportar.push_back(cadena);
	}
	if (cantidadDocPrimavera > 0)
	{
		cadena = "PRIMAVERA - Total consumo: " + to_string(totalConsumoPrimavera) + "\t Promedio: " + to_string(totalConsumoPrimavera / cantidadDocPrimavera);
		cout << "|" << cadena << endl;
		cadena = "Primavera," + to_string(totalConsumoPrimavera) + "," + to_string(totalConsumoPrimavera / cantidadDocPrimavera);
		datosAExportar.push_back(cadena);
	}
	else
	{
		cadena = "PRIMAVERA - No hay consumos registrados ";
		cout << "|" << cadena << endl;
		datosAExportar.push_back(cadena);
	}
	cout << separador << endl;
	Validaciones::SystemPause();
	cout << "Desea exportar los datos a un archivo formato 'csv' ?" << endl;
	char dato = Validaciones::DatoObligarorioChar(" 'S' o cualquier otra letra para salir");
	if (dato == 'S')
	{
		this->GrabarTextosSalida(datosAExportar, "ConsumosPromedios" + to_string(anio) + ".csv");
		cout << "Datos exportados" << endl;
	}
}

//Funcion de promedio
float CalRecaudacion(int dni, int opcion);

void InterfaceSalida::PromedioRecaudacion()
{
	//Promedio de recaudacion por cada cliente -> solo documentos pagos
	//Promedio de recaudacion anual ->  para todos los clientes con documentos pagos

	int opcion;

	system("cls||clear");
	do {
		int dni = -1;
		float retorno = 0;

		cout << this->separador << endl;
		cout << "***CONSULTAS DE GESTION ENERGETICA***" << endl;
		cout << "**********REPORTES**********" << endl;
		cout << this->separador << endl;
		cout << "|1. Promedio de recaudacion Anual (Para todos los clientes)" << endl;
		cout << "|2. Promedio de recaudacion Anual (Por cliente)" << endl;
		cout << "|0. Para volver" << endl;
		cout << this->separador << endl;
		opcion = Validaciones::DatoObligarorioNum("Opcion: ");

		switch (opcion) {
		case 1: {
			cout << endl;
			cout << this->separador << endl;
			retorno = CalRecaudacion(dni, opcion);
			if (retorno == -1) {
				retorno = 0;
			}
			cout << "El promedio total todos los cliente es : $" << retorno << endl;
			cout << this->separador << endl;
			Validaciones::SystemPause();
			break;
		}
		case 2: {

			dni = Validaciones::DatoObligarorioNum("Ingrese DNI: ");
			cout << endl;
			cout << this->separador << endl;
			retorno = CalRecaudacion(dni, opcion);
			if (retorno == -1) {
				cout << "El cliente no existe" << endl;
				Validaciones::SystemPause();
				break;
			}
			//PENDIENTE: ME FALTA BAJAR A CSV EL REPORTE DEL CLIENTE CON TODAS SUS FACTURAS ....
			cout << "El promedio total para el cliente #" << dni << " es : $" << retorno << endl;
			cout << this->separador << endl;
			Validaciones::SystemPause();
			break;
		}
		case 0:
		{
			system("cls||clear");
			return;
		}
		default: {
			break;
		}

		}
		system("cls||clear");

	} while (true);

}

float CalRecaudacion(int dni, int opcion) {

	DocumentoAD documentoAD(NOMBRE_ARCH_DOC);
	vector<Documento> documentos;
	documentos = documentoAD.getDocumentosArchivo();

	const bool PAGO = true; // Si el pago es false (esta pendiente) y no se cuenta
	const int VAR = 1;
	bool salida = true;
	float promedioCliente = 0, promedioAnual = 0;
	int contadorCliente = 0, contadorAnual = 0;

	if (dni != -1) {

		for (int i = 0; i < documentos.size(); i++) {
			if (documentos[i].getIdinter() == dni) {
				salida = false;
			}
		}

		if (salida == true && opcion != VAR)
			return -1;
	}

	for (int i = 0; i < documentos.size(); i++) {

		if (documentos[i].getPago() == PAGO && opcion == VAR) {
			promedioAnual += documentos[i].getImporte();
			contadorAnual++;
		}
		else {
			if (documentos[i].getPago() == PAGO && documentos[i].getIdinter() == dni) {
				promedioCliente += documentos[i].getImporte();
				contadorCliente++;
			}
		}

	}


	if (opcion == VAR) {

		if (promedioAnual != 0 && contadorAnual != 0) {
			return float(promedioAnual / contadorAnual);
		}
		return -1;

	}
	else {
		return float(promedioCliente / contadorCliente);
	}
}

int InterfaceSalida::ExportarIC()
{
	InterlocutorComercialAD interComAD(NOMBRE_ARCH_IC);
	vector<InterlocutorComercial> interlocutores = interComAD.getInterlocutoresArchivo();
	vector<string> salidaInterlocutor;
	for (auto& interlocutor : interlocutores)
		salidaInterlocutor.push_back(interlocutor.toStringInterlocutor(true, true));
	try
	{
		this->GrabarTextosSalida(salidaInterlocutor, "ExpoInterlocutoresComerciales.csv");
	}
	catch (const std::exception&)
	{
		return -1;
	}
	return 0;
}

void InterfaceSalida::ClienteDatosComerciales(int dni)
{
	system("cls||clear");
	string cadena;
	vector<string> datosAExportar;
	cout << separador << endl;
	cadena = "|\t\tCONSULTA DE CLINETE DATOS COMERCIALES DOCUMENTO NRO: " + to_string(dni);
	cout << cadena << endl;
	cadena = "CONSULTA DE CLINETE DATOS COMERCIALES DOCUMENTO NRO: " + to_string(dni);
	datosAExportar.push_back(cadena);

	InterlocutorComercial intLoc = InterlocutorComercialAD(NOMBRE_ARCH_IC).getInterlocutorArchivo(dni);
	if (intLoc.getDni() != dni)
	{
		cout << "Documento no encontrado, por favor corrobore el dato ingresado!!!" << endl;
		Validaciones::SystemPause();
		return;
	}
	CuentaContrato ctaContrato = CuentaContratoAD(NOMBRE_ARCH_CC).getCuentaContratoArchivo(intLoc.getId_ic());
	if (intLoc.getId_ic() != ctaContrato.getId_cc())
	{
		cout << "Cliente sin cuenta, para vesializar datos comerciales se debe crear una cuenta para el cliente con DNI: " << dni << endl;
		Validaciones::SystemPause();
		return;
	}
	Medidor medidor = MedidorAD(NOMBRE_ARCH_MED).getMedidorArchivo(ctaContrato.getId_Medidor());
	Tarifa tarifa = TarifaAD(NOMBRE_ARCH_TAR).getTarifaArchivo(ctaContrato.getId_Tarifa());
	cout << separador << endl;
	string activo = intLoc.getActivo() ? "Activo" : "Inactivo";
	cadena = "|Cliente Nro: " + to_string(intLoc.getId_ic()) + "\tEstado: " + activo +
		"\t\tNombre y Apellido: " + intLoc.getNombre() + ", " + intLoc.getApellido();	
	cout << cadena << endl;
	cadena = "Cliente," + to_string(intLoc.getId_ic()) + "," + to_string(intLoc.getDni()) + "," + activo + "," + intLoc.getNombre() + "," + intLoc.getApellido();
	datosAExportar.push_back(cadena);
	cadena = "\tTarifa: " + to_string(tarifa.getIdTarifa()) + "\tCargo Fijo: " + to_string(tarifa.getCargoFijo()) + 
		"\tCargo Variable: " + to_string(tarifa.getCargoVariable()) + "\tImpuesto: " + to_string(tarifa.getImpuestos());
	cout << cadena << endl;
	cadena = "Tarifa," + to_string(tarifa.getIdTarifa()) + "," + to_string(tarifa.getCargoFijo()) + "," + to_string(tarifa.getCargoVariable()) + "," + to_string(tarifa.getImpuestos());
	datosAExportar.push_back(cadena);
	cadena = "\tMedidor Nro: " + to_string(medidor.getId()) + " Ultima lectura: " + to_string(medidor.getLectura());
	cout << cadena << endl;
	cout << separador << endl;
	cadena = "Medidor," + to_string(medidor.getId()) + "," + to_string(medidor.getLectura());
	datosAExportar.push_back(cadena);
	Validaciones::SystemPause();
	cout << "Desea exportar los datos a un archivo formato 'csv' ?" << endl;
	char dato = Validaciones::DatoObligarorioChar(" 'S' o cualquier otra letra para salir");
	if (dato == 'S')
	{
		this->GrabarTextosSalida(datosAExportar, "DatosComerciales" + to_string(dni) + ".csv");
		cout << "Datos exportados" << endl;
	}
}