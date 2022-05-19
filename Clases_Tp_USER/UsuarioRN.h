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
	Usuario BuscarUsuario(long dni);
	bool ControlModificaciones(Usuario& usuario);
	bool AltaUsuario(Usuario& usuario);
	long CantidadUsuariosEnSistema();
	string getNombreArchivo();
	vector<Usuario> VectorUsuarios();
	void setNombreArchivo(string nombreArchivo);
};