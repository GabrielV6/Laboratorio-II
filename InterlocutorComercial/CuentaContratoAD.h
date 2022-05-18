#pragma once
#include <vector>
#include "CuentaContrato.h"

class CuentaContratoAD
{
public:

	CuentaContratoAD(string nombreArchivo = "");
	~CuentaContratoAD();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	/// <summary>
	/// M�todo que devuelve la cantidad de cuentas contrato que hay en el archivo de datos.
	/// </summary>
	/// <returns>entero largo</returns>
	long TotalCuentaContratoEnArchivo();
	/// <summary>
	/// M�todo que guarda la cuenta contrato en el archivo de datos y devuelve verdadero cuando resulta correto la grabaci�n.
	/// </summary>
	/// <returns>Booleano</returns>
	bool GuardarEnArchivoCuentaContrato(CuentaContrato& contrato);
	/// <summary>
	/// Este m�todo permite modificar en el archivo la cuenta contrato enviado por parametro
	/// </summary>
	/// <param name="contrato"></param>
	/// <returns></returns>
	bool ActualizarEnArchivoCuentaContrato(CuentaContrato& contrato);
	/// <summary>
	/// M�todo que devuleve un objeto tipo cuenta contrato que este dentro del archivo de datos
	/// </summary>
	/// <param name="posicion"></param>
	/// <returns>CuentaContrato</returns>
	CuentaContrato getCuentaContratoArchivo(long id_cc);
	/// <summary>
	/// Funci�n que devuleve todas las cuenta del archivo en un vector
	/// </summary>
	vector<CuentaContrato> getCuentasContratoArchivo();
private:
	string nombreArchivo;
	CuentaContrato cuentaContrato;
};