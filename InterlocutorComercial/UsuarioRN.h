#pragma once
#include "UsuarioAD.h"
class UsuarioRN
{
private:
	UsuarioAD usuarioAD;
	string nombreArchivo;
public:
	UsuarioRN(string nombreArchivo = "");
	~UsuarioRN();
	bool ExisteUsuario(long dni);
	Usuario BuscarUsuario(long dni);
	string ControlModificaciones(Usuario& usuario);
	bool AltaUsuario(Usuario& usuario);
	bool ModificaUsuario(Usuario& usuario);
	long CantidadUsuariosEnSistema();
	string getNombreArchivo();
	vector<Usuario> VectorUsuarios();
	void setNombreArchivo(string nombreArchivo);
};