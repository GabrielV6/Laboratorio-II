#include "UsuarioRN.h"

UsuarioRN::UsuarioRN(string nombreArchivo)
{
	this->usuarioAD = UsuarioAD(nombreArchivo);
}
UsuarioRN::~UsuarioRN()
{}
bool UsuarioRN::AltaUsuario(Usuario& usuario)
{
	return this->usuarioAD.GuardarEnArchivoUsuario(usuario);
}
Usuario UsuarioRN::BuscarUsuario(long dni)
{
	Usuario usuarioAD = this->usuarioAD.getUsuarioArchivo(dni);
	if (usuarioAD.getDni() == dni)
		return usuarioAD;
	return Usuario();
}
bool UsuarioRN::ControlModificaciones(Usuario& usuario)
{
	///Hacer la validadciones correspondientes al usuario pasado por parametro
	return true;
}
long UsuarioRN::CantidadUsuariosEnSistema()
{
	return this->usuarioAD.TotalUsuariosEnArchivo();
}
string UsuarioRN::getNombreArchivo()
{
	return this->nombreArchivo;
}
vector<Usuario> UsuarioRN::VectorUsuarios()
{
	return this->usuarioAD.getUsuariosArchivo();
}
void UsuarioRN::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}