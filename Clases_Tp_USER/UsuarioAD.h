#pragma once
#include <vector>
#include "Usuario.h"
class UsuarioAD
{
public:

	UsuarioAD(string nombreArchivo = "");
	~UsuarioAD();
	void setNombreArchivo(string nombreArchivo);
	string getNombreArchivo();
	/// <summary>
	/// Metodo que devuelve la cantidad de usuarios que hay en el archivo de datos.
	/// </summary>
	/// <returns>entero largo</returns>
	long TotalUsuariosEnArchivo();
	/// <summary>
	/// Metodo que guarda el usuario en el archivo de datos y devuelve verdadero cuando resulta correto la grabacion.
	/// </summary>
	/// <returns>Booleano</returns>
	bool GuardarEnArchivoUsuario(Usuario& usuario);
	/// <summary>
	/// Este Metodo permite modificar en el archivo el usuario enviado por parametro
	/// </summary>
	/// <param name="usuario"></param>
	/// <returns></returns>
	bool ActualizarEnArchivoUsuario(Usuario& usuario);
	/// <summary>
	/// Metodo que devuleve un objeto tipo usuario que este dentro del archivo de datos
	/// </summary>
	/// <param name="posicion"></param>
	/// <returns>Usuario</returns>
	Usuario getUsuarioArchivo(long dni);
	/// <summary>
	/// Funcion que devuelve todos los usuarios del archivo en un vector
	/// </summary>
	vector<Usuario> getUsuariosArchivo();
private:
	string nombreArchivo;
	Usuario usuario;
};