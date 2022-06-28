#include "CuentaContratoAD.h"

CuentaContratoAD::CuentaContratoAD(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}

CuentaContratoAD::~CuentaContratoAD()
{
	this->cuentasC.clear();
}

void CuentaContratoAD::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}

string CuentaContratoAD::getNombreArchivo()
{
	return this->nombreArchivo;
}

int CuentaContratoAD::TotalCuentaContratoEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	
	int cantidad = 0;
	
	archivo.seekg(0, ios::end);
	
	int pos = archivo.tellg();
	
	cantidad = pos / sizeof(CuentaContrato);
	
	archivo.close();
	
	return cantidad;
}


bool CuentaContratoAD::GuardarEnArchivoCuentaContrato(CuentaContrato& contrato)
{
	//ofstream archivo;
	FILE* archivo;
	//archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	archivo = fopen("cuentasContrato.dat", "ab");
	
	//if (archivo.fail())
	if (archivo == NULL)
		return false;
	
	int posArchivo = TotalCuentaContratoEnArchivo();

	contrato.setNumPosicionArchivo(posArchivo);
		
	//archivo.write((char*)&contrato, sizeof(CuentaContrato));
	fwrite(&contrato, sizeof contrato , 1, archivo);
	//archivo.close();
	fclose(archivo);
	return true;

}

bool CuentaContratoAD::ActualizarEnArchivoCuentaContrato(CuentaContrato& contrato)
{

	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0);
	
	if (archivo.fail())
		return false;
	
	//cout << "Posicion: " << to_string(archivo.tellp()) << endl;
	archivo.seekp(contrato.getNumPosicionArhivo() * sizeof(CuentaContrato), ios::cur);
	archivo.write((char*)&contrato, sizeof(CuentaContrato));
	archivo.close();
	
	return true;
}

CuentaContrato CuentaContratoAD::getCuentaContratoArchivo(int id_cc)
{
	CuentaContrato contrato;
	//ifstream archivo;
	FILE* archivo;

	//archivo.open(this->getNombreArchivo(), ios::in);
	archivo = fopen("cuentasContrato.dat", "rb");

	//if (archivo.fail())
	if (archivo == NULL)
		return contrato;

	//while (archivo.read((char*)&contrato, sizeof(CuentaContrato)))
	while (fread((char*)&contrato, sizeof(CuentaContrato), 1, archivo))
	{
		//if (!archivo.eof())
		if (!(archivo == NULL))
			if (contrato.getId_cc() == id_cc)
			{
				//archivo.close();
				fclose(archivo);
				return contrato;
			}
	}
	//archivo.close();

	fclose(archivo);
	contrato = CuentaContrato();

	return contrato;
}


vector<CuentaContrato> CuentaContratoAD::getCuentasContratoArchivo()
{
	CuentaContrato contrato;
	vector<CuentaContrato> contratos;
	//ifstream archivo;
	FILE* archivo;
	//archivo.open(this->getNombreArchivo(), ios::in);
	archivo = fopen("cuentasContrato.dat", "rb");

	//if (archivo.fail())
	if(archivo==NULL)
		return contratos;

	//while (archivo.read((char*)&intComAD, sizeof(CuentaContrato)))
	 while (fread((char*)&contrato, sizeof(CuentaContrato), 1, archivo))
	{
		//if (!archivo.eof())
		if(!(archivo == NULL))
		{
			contratos.push_back(contrato);
		}
	}
	//archivo.close();
	fclose(archivo);
	return contratos;
}
