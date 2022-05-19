#include "UsuarioAD.h"

UsuarioAD::UsuarioAD(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
UsuarioAD::~UsuarioAD()
{
}
void UsuarioAD::setNombreArchivo(string nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}
string UsuarioAD::getNombreArchivo()
{
	return this->nombreArchivo;
}
/// <summary>
/// M�todo que devuelve la cantidad de usuarios que hay en el archivo de datos.
/// </summary>
/// <returns>entero largo</returns>
long UsuarioAD::TotalusuariosEnArchivo()
{
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return -1;
	Usuario usuarioAD;
	long cantidad = 0;
	while (archivo.read((char*)&usuarioAD, sizeof(Usuario)))
	{
		if (!archivo.eof())
			cantidad++;
	}
	archivo.close();
	return cantidad;
}
/// <summary>
/// M�todo que guarda el usuario en el archivo de datos y devuelve verdadero cuando resulta correto la grabaci�n.
/// </summary>
/// <returns>Booleano</returns>
bool UsuarioAD::GuardarEnArchivoUsuario(Usuario& usuario)
{
	Usuario usuarioAD = usuario;
	ofstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::app | ios::out);
	if (archivo.fail())
		return false;
	//Busca cuantos usuarios hay en el archivo y le asigna esa cantidad a la posicion relativa del usuario en el archivo.	
	long posArchivo = TotalusuariosEnArchivo();
	archivo.write((char*)&usuarioAD, sizeof(Usuario));
	archivo.close();
	return true;

}
/// <summary>
/// Este m�todo permite modificar en el archivo el usuario enviado por parametro
/// </summary>
/// <param name="usuario"></param>
/// <returns></returns>
bool UsuarioAD::ActualizarEnArchivoUsuario(Usuario& usuario)
{

	fstream archivo;
	archivo.open(this->getNombreArchivo(), ios::binary | ios::in | ios::out);
	archivo.seekg(0);
	if (archivo.fail())
		return false;
	int pos = 0;
	int cantidad = 0;
	cantidad = TotalusuariosEnArchivo();
	archivo.seekp(usuario.getNumPosicionArhivo() * sizeof(Usuario), ios::cur);

	//cout << "Posicion: " << to_string(archivo.tellp()) << endl;
	archivo.write((char*)&usuario, sizeof(Usuario));
	archivo.close();
	return true;
}
/// <summary>
/// M�todo que devuleve un objeto tipo usuario que este dentro del archivo de datos
/// </summary>
/// <param name="posicion"></param>
/// <returns>Usuario</returns>
Usuario UsuarioAD::getUsuarioArchivo(long dni)
{
	Usuario usuarioAD;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return usuarioAD;

	while (archivo.read((char*)&usuarioAD, sizeof(Usuario)))
	{
		if (!archivo.eof())
			if (usuarioAD.getDni() == dni)
			{
				archivo.close();
				return usuarioAD;
			}
	}
	archivo.close();
	usuarioAD = Usuario();
	return usuarioAD;
}

/// <summary>
/// Funci�n que devuleve todos los usuarios del archivo en un vector
/// </summary>
vector<Usuario> UsuarioAD::getusuariosArchivo()
{
	Usuario usuarioAD;
	vector<Usuario> usuarios;
	ifstream archivo;
	archivo.open(this->getNombreArchivo(), ios::in);
	if (archivo.fail())
		return usuarios;
	while (archivo.read((char*)&usuarioAD, sizeof(Usuario)))
	{
		if (!archivo.eof())
		{
			usuarios.push_back(usuarioAD);
		}
	}
	return usuarios;
}