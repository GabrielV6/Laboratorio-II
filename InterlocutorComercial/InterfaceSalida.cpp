#include "InterfaceSalida.h"
#include "CuentaContratoAD.h"
#include "MedidorAD.h"
#include "Validaciones.h"
#include "InterlocutorComercialV.h"
#include "MedidorV.h"
#include "Validaciones.h"
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
vector<string> InterfaceSalida::getTestoSalida()
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
		cout << "CONSULTAS DE GESTION ENERGETICA" << endl;
		cout << this->separador << endl;
		cout << "|1. Para menu Interlocutor Comercial" << endl;
		cout << "|2. Para menu Cuenta Contrato" << endl;
		cout << "|3. Para menu Medidor" << endl;
		cout << "|4. Para menu Tarifa" << endl;
		cout << "|5. Para menu Facturacion" << endl;
		cout << "|6. Para menu Consultas" << endl;
		cout << "|7. Para generar archiv CVS" << endl;
		cout << "|0. Para Salir" << endl;
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
			//GENERA LOS ARCHIVOS CSV Y LOS GUARDA EN .DAT
			//InterfaceSalida intSal;
			//intSal.LeeTextosEntrada("MedidorCsv.csv");

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
		cout << this->separador << endl;
		cout << "***CONSULTAS DE GESTION ENERGETICA***" << endl;
		cout << this->separador << endl;
		cout << "|1. Consulta energia estacionaria" << endl;
		cout << "|0. Para volver" << endl;
		cout << this->separador << endl;
		opcion = Validaciones::DatoObligarorioNum("Opcion");

		system("cls||clear");
		switch (opcion)
		{
		case 1:
		{
			system("cls||clear");
			int anio;
			anio = Validaciones::DatoObligarorioNum("Año a consultar ");
			ConsumoPorEstacion(anio);
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
			if (doc.getFecha().getMes() >= 1 && doc.getFecha().getMes() <= 3)
			{
				totalConsumoVerano += doc.getConsumo();
				cantidadDocVerano++;
			}
			// Otoño
			if (doc.getFecha().getMes() >= 4 && doc.getFecha().getMes() <= 6)
			{
				totalConsumoOtonio += doc.getConsumo();
				cantidadDocOtonio++;
			}
			// Invierno
			if (doc.getFecha().getMes() >= 7 && doc.getFecha().getMes() <= 9)
			{
				totalConsumoInvierno += doc.getConsumo();
				cantidadDocInvierno++;
			}
			// Primavera
			if (doc.getFecha().getMes() >= 10 && doc.getFecha().getMes() <= 12)
			{
				totalConsumoPrimavera += doc.getConsumo();
				cantidadDocPrimavera++;
			}
		}
	}
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