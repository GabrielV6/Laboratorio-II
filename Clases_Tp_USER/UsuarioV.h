#pragma once
#include "UsuarioRN.h"

class UsuarioV
{   
    private:
    Usuario Usuario;
    string nombreArchivo;
    UsuarioRN UsuarioRN;
    public:
    UsuarioV(string nombreArchivo);
    ~UsuarioV();
    void NuevoUsuario();
    void ListarUsuarios();
    void ModificarUsuario();
    void MenuModificarUsuario();
    void MenuUsuario();
    void setNombreArchivo(string nombreArchivo);
    string getNombreArchivo();
    void setUsuario(Usuario& Usuario);
};