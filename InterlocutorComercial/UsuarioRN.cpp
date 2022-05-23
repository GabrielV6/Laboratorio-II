#include "UsuarioRN.h"

UsuarioRN::UsuarioRN(string nombreArchivo)
{
	this->usuarioAD = UsuarioAD(nombreArchivo);
}
UsuarioRN::~UsuarioRN()
{}
bool UsuarioRN::AltaUsuario(Usuario& usuario)
{	//Ver si se hace una busqueda en el archivo de usuarioss para asignar el númerador de id
	usuario.setId_us(usuario.getDni());
	return this->usuarioAD.GuardarEnArchivoUsuario(usuario);
}
bool UsuarioRN::ModificaUsuario(Usuario& usuario)
{
	return this->usuarioAD.ActualizarEnArchivoUsuario(usuario);
}
bool UsuarioRN::ExisteUsuario(long dni)
{
	Usuario usuarioExiste = this->BuscarUsuario(dni);
	if (usuarioExiste.getNombre() != "" || usuarioExiste.getApellido() != "")
		return false;
	return true;
}
Usuario UsuarioRN::BuscarUsuario(long dni)
{
	Usuario usuarioAD = this->usuarioAD.getUsuarioArchivo(dni);
	if (usuarioAD.getDni() == dni)
		return usuarioAD;
	return Usuario();
}
string UsuarioRN::ControlModificaciones(Usuario& usuario)
{
	if (usuario.getNombre() == "")
		return "No se cargo el nombre al usuario\n";
	if (usuario.getApellido() == "")
		return "No se cargo el apellido al usuario\n";;
	string correo = usuario.getEmail();
	string letra = "@";
	if (!strstr(correo.c_str(), letra.c_str()))
		return "No se cargo correctamente el correo al usuario\n";;

	return "OK";
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