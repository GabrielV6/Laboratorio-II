#include "CuentaContratoAD.h"

CuentaContratoAD::CuentaContratoAD(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
CuentaContratoAD::~CuentaContratoAD()
{
}
void CuentaContratoAD::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string CuentaContratoAD::getNombreArchivo()
{
	return this->nombreArchivo;
}
/// <summary>
/// M�todo que devuelve la cantidad de cuentas contrato que hay en el archivo de datos.
/// </summary>
/// <returns>entero largo</returns>
long CuentaContratoAD::TotalCuentaContratoEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	CuentaContrato intComAD;
	long cantidad = 0;
	while (archivo.read((char*)&intComAD, sizeof(CuentaContrato)))
	{
		if (!archivo.eof())
			cantidad++;
	}
	archivo.close();
	return cantidad;
}
/// <summary>
/// M�todo que guarda la cuenta contrato en el archivo de datos y devuelve verdadero cuando resulta correto la grabaci�n.
/// </summary>
/// <returns>Booleano</returns>
bool CuentaContratoAD::GuardarEnArchivoCuentaContrato(CuentaContrato& contrato)
{
	CuentaContrato intComAD = contrato;
	ofstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	//Busca cuantas cuenta contrato hay en el archivo y le asigna esa cantidad a la posicion relativa del contrato en el archivo.	
	long posArchivo = TotalCuentaContratoEnArchivo();
	archivo.write((char*)&intComAD, sizeof(CuentaContrato));
	archivo.close();
	return true;

}
/// <summary>
/// Este m�todo permite modificar en el archivo de la cuenta contrato enviado por parametro
/// </summary>
/// <param name="contrato"></param>
/// <returns></returns>
bool CuentaContratoAD::ActualizarEnArchivoCuentaContrato(CuentaContrato& contrato)
{

	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0);
	if (archivo.fail())
		return false;
	int pos = 0;
	int cantidad = 0;
	cantidad = TotalCuentaContratoEnArchivo();
	archivo.seekp(contrato.getNumPosicionArhivo() * sizeof(CuentaContrato), ios::cur);

	//cout << "Posicion: " << to_string(archivo.tellp()) << endl;
	archivo.write((char*)&contrato, sizeof(CuentaContrato));
	archivo.close();
	return true;
}
/// <summary>
/// M�todo que devuleve un objeto tipo cuenta contrato que este dentro del archivo de datos
/// </summary>
/// <param name="posicion"></param>
/// <returns>CuentaContrato</returns>
CuentaContrato CuentaContratoAD::getCuentaContratoArchivo(long id_cc)
{
	CuentaContrato intComAD;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return intComAD;

	while (archivo.read((char*)&intComAD, sizeof(CuentaContrato)))
	{
		if (!archivo.eof())
			if (intComAD.getId_cc() == id_cc)
			{
				archivo.close();
				return intComAD;
			}
	}
	archivo.close();
	intComAD = CuentaContrato();
	return intComAD;
}

/// <summary>
/// Funci�n que devuleve todas las cuenta contrato del archivo en un vector
/// </summary>
vector<CuentaContrato> CuentaContratoAD::getCuentasContratoArchivo()
{
	CuentaContrato intComAD;
	vector<CuentaContrato> contratos;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return contratos;
	while (archivo.read((char*)&intComAD, sizeof(CuentaContrato)))
	{
		if (!archivo.eof())
		{
			contratos.push_back(intComAD);
		}
	}
	return contratos;
}