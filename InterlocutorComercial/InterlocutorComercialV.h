#pragma once
#include "InterlocutorComercialRN.h"

class InterlocutorComercialV
{   
    private:
    InterlocutorComercial interlocutorComercial;
    string nombreArchivo;
    InterlocutorComercialRN interlocutorComercialRN;
    string separador = "-------------------------------------------------------------------------------------------------------------";
    public:
    InterlocutorComercialV(string nombreArchivo);
    ~InterlocutorComercialV();
    void NuevoInterlocutor();
    void ListarInterlocutores(int opcion);
    void ModificarInterlocutor();
    void MenuModificarInterlocutor();
    void MenuInterlocutorComecial();
    void setNombreArchivo(string nombreArchivo);
    string getNombreArchivo();
    void setInterlocutorComercial(InterlocutorComercial& interlocutorComercial);
    int MenuListarInerlocutor();
    string DarDatosListado(InterlocutorComercial intLoc, int num);
};